// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8TestInterfaceDocument.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/ScriptController.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/WindowProxy.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/frame/LocalFrame.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

static void initializeScriptWrappableForInterface(TestInterfaceDocument* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8TestInterfaceDocument::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace blink

void webCoreInitializeScriptWrappableForInterface(blink::TestInterfaceDocument* object)
{
    blink::initializeScriptWrappableForInterface(object);
}

namespace blink {
const WrapperTypeInfo V8TestInterfaceDocument::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterfaceDocument::domTemplate, V8TestInterfaceDocument::derefObject, 0, V8TestInterfaceDocument::toEventTarget, 0, V8TestInterfaceDocument::installConditionallyEnabledMethods, V8TestInterfaceDocument::installConditionallyEnabledProperties, &V8Document::wrapperTypeInfo, WrapperTypeObjectPrototype, WillBeGarbageCollectedObject };

namespace TestInterfaceDocumentV8Internal {

template <typename T> void V8_USE(T) { }

} // namespace TestInterfaceDocumentV8Internal

static void installV8TestInterfaceDocumentTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "TestInterfaceDocument", V8Document::domTemplate(isolate), V8TestInterfaceDocument::internalFieldCount,
        0, 0,
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8TestInterfaceDocument::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8TestInterfaceDocumentTemplate);
}

bool V8TestInterfaceDocument::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8TestInterfaceDocument::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TestInterfaceDocument* V8TestInterfaceDocument::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(blink::toInternalPointer(v8::Handle<v8::Object>::Cast(value))) : 0;
}

EventTarget* V8TestInterfaceDocument::toEventTarget(v8::Handle<v8::Object> object)
{
    return toNative(object);
}

v8::Handle<v8::Object> wrap(TestInterfaceDocument* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    v8::Handle<v8::Object> wrapper = V8TestInterfaceDocument::createWrapper(impl, creationContext, isolate);
    if (wrapper.IsEmpty())
        return wrapper;
    DOMWrapperWorld& world = DOMWrapperWorld::current(isolate);
    if (world.isMainWorld()) {
        if (LocalFrame* frame = impl->frame())
            frame->script().windowProxy(world)->updateDocumentWrapper(wrapper);
    }
    return wrapper;
}

v8::Handle<v8::Object> V8TestInterfaceDocument::createWrapper(PassRefPtrWillBeRawPtr<TestInterfaceDocument> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TestInterfaceDocument>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    if (LocalFrame* frame = impl->frame()) {
        if (frame->script().initializeMainWorld()) {
            // initializeMainWorld may have created a wrapper for the object, retry from the start.
            v8::Handle<v8::Object> wrapper = DOMDataStore::getWrapper<V8TestInterfaceDocument>(impl.get(), isolate);
            if (!wrapper.IsEmpty())
                return wrapper;
        }
    }
    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installConditionallyEnabledProperties(wrapper, isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceDocument>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}

void V8TestInterfaceDocument::derefObject(ScriptWrappableBase* internalPointer)
{
#if !ENABLE(OILPAN)
    fromInternalPointer(internalPointer)->deref();
#endif // !ENABLE(OILPAN)
}

template<>
v8::Handle<v8::Value> toV8NoInline(TestInterfaceDocument* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace blink
