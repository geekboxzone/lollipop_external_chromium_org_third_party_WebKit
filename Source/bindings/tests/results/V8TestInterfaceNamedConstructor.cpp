// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8TestInterfaceNamedConstructor.h"

#include "RuntimeEnabledFeatures.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/frame/DOMWindow.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(TestInterfaceNamedConstructor* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8TestInterfaceNamedConstructor::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::TestInterfaceNamedConstructor* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8TestInterfaceNamedConstructor::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterfaceNamedConstructor::domTemplate, V8TestInterfaceNamedConstructor::derefObject, V8TestInterfaceNamedConstructor::toActiveDOMObject, 0, 0, V8TestInterfaceNamedConstructor::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, RefCountedObject };

namespace TestInterfaceNamedConstructorV8Internal {

template <typename T> void V8_USE(T) { }

static void TestInterfaceNamedConstructorConstructorGetter(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Value> data = info.Data();
    ASSERT(data->IsExternal());
    V8PerContextData* perContextData = V8PerContextData::from(info.Holder()->CreationContext());
    if (!perContextData)
        return;
    v8SetReturnValue(info, perContextData->constructorForType(WrapperTypeInfo::unwrap(data)));
}

static void TestInterfaceNamedConstructorReplaceableAttributeSetter(v8::Local<v8::String> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    if (info.This()->IsObject())
        v8::Handle<v8::Object>::Cast(info.This())->ForceSet(name, v8Value);
}

static void TestInterfaceNamedConstructorReplaceableAttributeSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> v8Value, const v8::PropertyCallbackInfo<void>& info)
{
    TestInterfaceNamedConstructorV8Internal::TestInterfaceNamedConstructorReplaceableAttributeSetter(name, v8Value, info);
}

} // namespace TestInterfaceNamedConstructorV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8TestInterfaceNamedConstructorAttributes[] = {
    {"testNamedConstructorConstructorAttribute", TestInterfaceNamedConstructorV8Internal::TestInterfaceNamedConstructorConstructorGetter, TestInterfaceNamedConstructorV8Internal::TestInterfaceNamedConstructorReplaceableAttributeSetterCallback, 0, 0, const_cast<WrapperTypeInfo*>(&V8TestNamedConstructor::wrapperTypeInfo), static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::DontEnum), 0 /* on instance */},
};

const WrapperTypeInfo V8TestInterfaceNamedConstructorConstructor::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterfaceNamedConstructorConstructor::domTemplate, V8TestInterfaceNamedConstructor::derefObject, V8TestInterfaceNamedConstructor::toActiveDOMObject, 0, 0, V8TestInterfaceNamedConstructor::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, RefCountedObject };

static void V8TestInterfaceNamedConstructorConstructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    if (!info.IsConstructCall()) {
        throwTypeError(ExceptionMessages::constructorNotCallableAsFunction("Audio"), isolate);
        return;
    }

    if (ConstructorMode::current(isolate) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    Document* documentPtr = currentDOMWindow(isolate)->document();
    ASSERT(documentPtr);
    Document& document = *documentPtr;

    // Make sure the document is added to the DOM Node map. Otherwise, the TestInterfaceNamedConstructor instance
    // may end up being the only node in the map and get garbage-collected prematurely.
    toV8(documentPtr, info.Holder(), isolate);

    ExceptionState exceptionState(ExceptionState::ConstructionContext, "TestInterfaceNamedConstructor", info.Holder(), isolate);
    if (UNLIKELY(info.Length() < 1)) {
        throwMinimumArityTypeError(exceptionState, 1, info.Length());
        return;
    }
    V8StringResource<> stringArg;
    bool defaultUndefinedOptionalBooleanArg;
    int defaultUndefinedOptionalLongArg;
    V8StringResource<> defaultUndefinedOptionalStringArg;
    V8StringResource<> defaultNullStringOptionalstringArg;
    V8StringResource<> optionalStringArg;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        TOSTRING_VOID_INTERNAL(stringArg, info[0]);
        TONATIVE_VOID_INTERNAL(defaultUndefinedOptionalBooleanArg, info[1]->BooleanValue());
        TONATIVE_VOID_EXCEPTIONSTATE_INTERNAL(defaultUndefinedOptionalLongArg, toInt32(info[2], exceptionState), exceptionState);
        TOSTRING_VOID_INTERNAL(defaultUndefinedOptionalStringArg, info[3]);
        TOSTRING_VOID_INTERNAL(defaultNullStringOptionalstringArg, argumentOrNull(info, 4));
        if (UNLIKELY(info.Length() <= 5)) {
            RefPtr<TestInterfaceNamedConstructor> impl = TestInterfaceNamedConstructor::createForJSConstructor(document, stringArg, defaultUndefinedOptionalBooleanArg, defaultUndefinedOptionalLongArg, defaultUndefinedOptionalStringArg, defaultNullStringOptionalstringArg, exceptionState);
            v8::Handle<v8::Object> wrapper = info.Holder();
            V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceNamedConstructor>(impl.release(), &V8TestInterfaceNamedConstructorConstructor::wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
            v8SetReturnValue(info, wrapper);
            return;
        }
        TOSTRING_VOID_INTERNAL(optionalStringArg, info[5]);
    }
    RefPtr<TestInterfaceNamedConstructor> impl = TestInterfaceNamedConstructor::createForJSConstructor(document, stringArg, defaultUndefinedOptionalBooleanArg, defaultUndefinedOptionalLongArg, defaultUndefinedOptionalStringArg, defaultNullStringOptionalstringArg, optionalStringArg, exceptionState);
    if (exceptionState.throwIfNeeded())
        return;

    v8::Handle<v8::Object> wrapper = info.Holder();
    V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceNamedConstructor>(impl.release(), &V8TestInterfaceNamedConstructorConstructor::wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    v8SetReturnValue(info, wrapper);
}

v8::Handle<v8::FunctionTemplate> V8TestInterfaceNamedConstructorConstructor::domTemplate(v8::Isolate* isolate)
{
    static int domTemplateKey; // This address is used for a key to look up the dom template.
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    v8::Local<v8::FunctionTemplate> result = data->existingDOMTemplate(&domTemplateKey);
    if (!result.IsEmpty())
        return result;

    TRACE_EVENT_SCOPED_SAMPLING_STATE("Blink", "BuildDOMTemplate");
    result = v8::FunctionTemplate::New(isolate, V8TestInterfaceNamedConstructorConstructorCallback);
    v8::Local<v8::ObjectTemplate> instanceTemplate = result->InstanceTemplate();
    instanceTemplate->SetInternalFieldCount(V8TestInterfaceNamedConstructor::internalFieldCount);
    result->SetClassName(v8AtomicString(isolate, "TestInterfaceNamedConstructor"));
    result->Inherit(V8TestInterfaceNamedConstructor::domTemplate(isolate));
    data->setDOMTemplate(&domTemplateKey, result);
    return result;
}

static void configureV8TestInterfaceNamedConstructorTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "TestInterfaceNamedConstructor", v8::Local<v8::FunctionTemplate>(), V8TestInterfaceNamedConstructor::internalFieldCount,
        V8TestInterfaceNamedConstructorAttributes, WTF_ARRAY_LENGTH(V8TestInterfaceNamedConstructorAttributes),
        0, 0,
        0, 0,
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8TestInterfaceNamedConstructor::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8TestInterfaceNamedConstructorTemplate);
}

bool V8TestInterfaceNamedConstructor::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8TestInterfaceNamedConstructor::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

TestInterfaceNamedConstructor* V8TestInterfaceNamedConstructor::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

ActiveDOMObject* V8TestInterfaceNamedConstructor::toActiveDOMObject(v8::Handle<v8::Object> wrapper)
{
    return toNative(wrapper);
}

v8::Handle<v8::Object> wrap(TestInterfaceNamedConstructor* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TestInterfaceNamedConstructor>(impl, isolate));
    return V8TestInterfaceNamedConstructor::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8TestInterfaceNamedConstructor::createWrapper(PassRefPtr<TestInterfaceNamedConstructor> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TestInterfaceNamedConstructor>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceNamedConstructor>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Dependent);
    return wrapper;
}

void V8TestInterfaceNamedConstructor::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

template<>
v8::Handle<v8::Value> toV8NoInline(TestInterfaceNamedConstructor* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
