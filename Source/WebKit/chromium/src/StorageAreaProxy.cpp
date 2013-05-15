/*
 * Copyright (C) 2009 Google Inc. All Rights Reserved.
 *           (C) 2008 Apple Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GOOGLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GOOGLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "StorageAreaProxy.h"

#include "StorageNamespaceProxy.h"
#include "core/dom/Document.h"
#include "core/dom/EventNames.h"
#include "core/dom/ExceptionCode.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/page/DOMWindow.h"
#include "core/page/Frame.h"
#include "core/page/Page.h"
#include "core/page/PageGroup.h"
#include "core/storage/Storage.h"
#include "core/storage/StorageEvent.h"
#include "weborigin/SecurityOrigin.h"

#include <public/WebStorageArea.h>
#include <public/WebString.h>
#include <public/WebURL.h>
#include "WebFrameImpl.h"
#include "WebPermissionClient.h"
#include "WebViewImpl.h"

namespace WebCore {

StorageAreaProxy::StorageAreaProxy(PassOwnPtr<WebKit::WebStorageArea> storageArea, StorageType storageType)
    : m_storageArea(storageArea)
    , m_storageType(storageType)
    , m_canAccessStorageCachedResult(false)
    , m_canAccessStorageCachedFrame(0)
{
}

StorageAreaProxy::~StorageAreaProxy()
{
}

unsigned StorageAreaProxy::length(ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return 0;
    }
    ec = 0;
    return m_storageArea->length();
}

String StorageAreaProxy::key(unsigned index, ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return String();
    }
    ec = 0;
    return m_storageArea->key(index);
}

String StorageAreaProxy::getItem(const String& key, ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return String();
    }
    ec = 0;
    return m_storageArea->getItem(key);
}

void StorageAreaProxy::setItem(const String& key, const String& value, ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return;
    }
    WebKit::WebStorageArea::Result result = WebKit::WebStorageArea::ResultOK;
    m_storageArea->setItem(key, value, frame->document()->url(), result);
    ec = (result == WebKit::WebStorageArea::ResultOK) ? 0 : QUOTA_EXCEEDED_ERR;
}

void StorageAreaProxy::removeItem(const String& key, ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return;
    }
    ec = 0;
    m_storageArea->removeItem(key, frame->document()->url());
}

void StorageAreaProxy::clear(ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return;
    }
    ec = 0;
    m_storageArea->clear(frame->document()->url());
}

bool StorageAreaProxy::contains(const String& key, ExceptionCode& ec, Frame* frame)
{
    if (!canAccessStorage(frame)) {
        ec = SECURITY_ERR;
        return false;
    }
    return !getItem(key, ec, frame).isNull();
}

bool StorageAreaProxy::canAccessStorage(Frame* frame)
{
    if (!frame || !frame->page())
        return false;
    if (m_canAccessStorageCachedFrame == frame)
        return m_canAccessStorageCachedResult;
    WebKit::WebFrameImpl* webFrame = WebKit::WebFrameImpl::fromFrame(frame);
    WebKit::WebViewImpl* webView = webFrame->viewImpl();
    bool result = !webView->permissionClient() || webView->permissionClient()->allowStorage(webFrame, m_storageType == LocalStorage);
    m_canAccessStorageCachedFrame = frame;
    m_canAccessStorageCachedResult = result;
    return result;
}

size_t StorageAreaProxy::memoryBytesUsedByCache()
{
    return m_storageArea->memoryBytesUsedByCache();
}

void StorageAreaProxy::dispatchLocalStorageEvent(const String& key, const String& oldValue, const String& newValue,
                                                 SecurityOrigin* securityOrigin, const KURL& pageURL, WebKit::WebStorageArea* sourceAreaInstance, bool originatedInProcess)
{
    // FIXME: This looks suspicious. Why doesn't this use allPages instead?
    const HashSet<Page*>& pages = PageGroup::sharedGroup()->pages();
    for (HashSet<Page*>::const_iterator it = pages.begin(); it != pages.end(); ++it) {
        for (Frame* frame = (*it)->mainFrame(); frame; frame = frame->tree()->traverseNext()) {
            Storage* storage = frame->document()->domWindow()->optionalLocalStorage();
            if (storage && frame->document()->securityOrigin()->equal(securityOrigin) && !isEventSource(storage, sourceAreaInstance))
                frame->document()->enqueueWindowEvent(StorageEvent::create(eventNames().storageEvent, key, oldValue, newValue, pageURL, storage));
        }
        InspectorInstrumentation::didDispatchDOMStorageEvent(key, oldValue, newValue, LocalStorage, securityOrigin, *it);
    }
}

static Page* findPageWithSessionStorageNamespace(const WebKit::WebStorageNamespace& sessionNamespace)
{
    // FIXME: This looks suspicious. Why doesn't this use allPages instead?
    const HashSet<Page*>& pages = PageGroup::sharedGroup()->pages();
    for (HashSet<Page*>::const_iterator it = pages.begin(); it != pages.end(); ++it) {
        const bool dontCreateIfMissing = false;
        StorageNamespaceProxy* proxy = static_cast<StorageNamespaceProxy*>((*it)->sessionStorage(dontCreateIfMissing));
        if (proxy && proxy->isSameNamespace(sessionNamespace))
            return *it;
    }
    return 0;
}

void StorageAreaProxy::dispatchSessionStorageEvent(const String& key, const String& oldValue, const String& newValue,
                                                   SecurityOrigin* securityOrigin, const KURL& pageURL, const WebKit::WebStorageNamespace& sessionNamespace,
                                                   WebKit::WebStorageArea* sourceAreaInstance, bool originatedInProcess)
{
    Page* page = findPageWithSessionStorageNamespace(sessionNamespace);
    if (!page)
        return;

    for (Frame* frame = page->mainFrame(); frame; frame = frame->tree()->traverseNext()) {
        Storage* storage = frame->document()->domWindow()->optionalSessionStorage();
        if (storage && frame->document()->securityOrigin()->equal(securityOrigin) && !isEventSource(storage, sourceAreaInstance))
            frame->document()->enqueueWindowEvent(StorageEvent::create(eventNames().storageEvent, key, oldValue, newValue, pageURL, storage));
    }
    InspectorInstrumentation::didDispatchDOMStorageEvent(key, oldValue, newValue, SessionStorage, securityOrigin, page);
}

bool StorageAreaProxy::isEventSource(Storage* storage, WebKit::WebStorageArea* sourceAreaInstance)
{
    ASSERT(storage);
    StorageAreaProxy* areaProxy = static_cast<StorageAreaProxy*>(storage->area());
    return areaProxy->m_storageArea == sourceAreaInstance;
}

} // namespace WebCore
