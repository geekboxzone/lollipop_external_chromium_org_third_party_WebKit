/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "config.h"
#include "core/platform/PrerenderHandle.h"

#include <wtf/PassRefPtr.h>
#include <wtf/text/WTFString.h>
#include "core/platform/KURL.h"
#include "core/platform/chromium/Prerender.h"
#include "weborigin/ReferrerPolicy.h"

namespace WebCore {

PassRefPtr<PrerenderHandle> PrerenderHandle::create(PrerenderClient* client, const KURL& url, const String& referrer, ReferrerPolicy policy)
{
    return adoptRef(new PrerenderHandle(client, url, referrer, policy));
}

PrerenderHandle::PrerenderHandle(PrerenderClient* client, const KURL& url, const String& referrer, ReferrerPolicy policy)
    : m_prerender(adoptRef(new Prerender(client, url, referrer, policy)))
{
}

PrerenderHandle::~PrerenderHandle()
{
    m_prerender->removeClient();
}

Prerender* PrerenderHandle::prerender()
{
    return m_prerender.get();
}

void PrerenderHandle::removeClient()
{
    prerender()->removeClient();
}

void PrerenderHandle::add()
{
    prerender()->add();
}

void PrerenderHandle::cancel()
{
    prerender()->cancel();
}

void PrerenderHandle::abandon()
{
    prerender()->abandon();
}

void PrerenderHandle::suspend()
{
    prerender()->suspend();
}

void PrerenderHandle::resume()
{
    prerender()->resume();
}

const KURL& PrerenderHandle::url() const
{
    return m_prerender->url();
}

const String& PrerenderHandle::referrer() const
{
    return m_prerender->url();
}

ReferrerPolicy PrerenderHandle::referrerPolicy() const
{
    return m_prerender->referrerPolicy();
}

}
