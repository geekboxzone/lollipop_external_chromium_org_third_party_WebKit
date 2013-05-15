/*
    This file is part of the Blink open source project.
    This file has been auto-generated by CodeGeneratorV8.pm. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include "V8TestNamedConstructor.h"

#include "RuntimeEnabledFeatures.h"
#include "V8Document.h"
#include "bindings/v8/ScriptController.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/page/Frame.h"
#include "wtf/UnusedParam.h"

#if ENABLE(BINDING_INTEGRITY)
#if defined(OS_WIN)
#pragma warning(disable: 4483)
extern "C" { extern void (*const __identifier("??_7TestNamedConstructor@WebCore@@6B@")[])(); }
#else
extern "C" { extern void* _ZTVN7WebCore20TestNamedConstructorE[]; }
#endif
#endif // ENABLE(BINDING_INTEGRITY)

namespace WebCore {

#if ENABLE(BINDING_INTEGRITY)
// This checks if a DOM object that is about to be wrapped is valid.
// Specifically, it checks that a vtable of the DOM object is equal to
// a vtable of an expected class.
// Due to a dangling pointer, the DOM object you are wrapping might be
// already freed or realloced. If freed, the check will fail because
// a free list pointer should be stored at the head of the DOM object.
// If realloced, the check will fail because the vtable of the DOM object
// differs from the expected vtable (unless the same class of DOM object
// is realloced on the slot).
inline void checkTypeOrDieTrying(TestNamedConstructor* object)
{
    void* actualVTablePointer = *(reinterpret_cast<void**>(object));
#if defined(OS_WIN)
    void* expectedVTablePointer = reinterpret_cast<void*>(__identifier("??_7TestNamedConstructor@WebCore@@6B@"));
#else
    void* expectedVTablePointer = &_ZTVN7WebCore20TestNamedConstructorE[2];
#endif
    if (actualVTablePointer != expectedVTablePointer)
        CRASH();
}
#endif // ENABLE(BINDING_INTEGRITY)

#if defined(OS_WIN)
// In ScriptWrappable, the use of extern function prototypes inside templated static methods has an issue on windows.
// These prototypes do not pick up the surrounding namespace, so drop out of WebCore as a workaround.
} // namespace WebCore
using WebCore::ScriptWrappable;
using WebCore::V8TestNamedConstructor;
using WebCore::TestNamedConstructor;
#endif
void initializeScriptWrappableForInterface(TestNamedConstructor* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::setTypeInfoInObject(object, &V8TestNamedConstructor::info);
}
#if defined(OS_WIN)
namespace WebCore {
#endif
WrapperTypeInfo V8TestNamedConstructor::info = { V8TestNamedConstructor::GetTemplate, V8TestNamedConstructor::derefObject, V8TestNamedConstructor::toActiveDOMObject, 0, 0, V8TestNamedConstructor::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

namespace TestNamedConstructorV8Internal {

template <typename T> void V8_USE(T) { }

} // namespace TestNamedConstructorV8Internal

WrapperTypeInfo V8TestNamedConstructorConstructor::info = { V8TestNamedConstructorConstructor::GetTemplate, V8TestNamedConstructor::derefObject, V8TestNamedConstructor::toActiveDOMObject, 0, 0, V8TestNamedConstructor::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

static v8::Handle<v8::Value> V8TestNamedConstructorConstructorCallback(const v8::Arguments& args)
{
    if (!args.IsConstructCall())
        return throwTypeError("DOM object constructor cannot be called as a function.", args.GetIsolate());

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject)
        return args.Holder();

    Document* document = currentDocument();

    // Make sure the document is added to the DOM Node map. Otherwise, the TestNamedConstructor instance
    // may end up being the only node in the map and get garbage-collected prematurely.
    toV8(document, args.Holder(), args.GetIsolate());

    if (args.Length() < 1)
        return throwNotEnoughArgumentsError(args.GetIsolate());

    ExceptionCode ec = 0;
    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, str1, args[0]);
    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, str2, args[1]);
    V8TRYCATCH_FOR_V8STRINGRESOURCE(V8StringResource<>, str3, argumentOrNull(args, 2));

    RefPtr<TestNamedConstructor> impl = TestNamedConstructor::createForJSConstructor(document, str1, str2, str3, ec);
    v8::Handle<v8::Object> wrapper = args.Holder();
    if (ec)
        goto fail;

    V8DOMWrapper::associateObjectWithWrapper(impl.release(), &V8TestNamedConstructorConstructor::info, wrapper, args.GetIsolate(), WrapperConfiguration::Dependent);
    return wrapper;
    fail:
    return setDOMException(ec, args.GetIsolate());
}

v8::Persistent<v8::FunctionTemplate> V8TestNamedConstructorConstructor::GetTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    static v8::Persistent<v8::FunctionTemplate> cachedTemplate;
    if (!cachedTemplate.IsEmpty())
        return cachedTemplate;

    v8::HandleScope scope;
    v8::Local<v8::FunctionTemplate> result = v8::FunctionTemplate::New(V8TestNamedConstructorConstructorCallback);

    v8::Local<v8::ObjectTemplate> instance = result->InstanceTemplate();
    instance->SetInternalFieldCount(V8TestNamedConstructor::internalFieldCount);
    result->SetClassName(v8::String::NewSymbol("TestNamedConstructor"));
    result->Inherit(V8TestNamedConstructor::GetTemplate(isolate, currentWorldType));

    cachedTemplate.Reset(isolate, result);
    return cachedTemplate;
}

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestNamedConstructorTemplate(v8::Persistent<v8::FunctionTemplate> desc, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestNamedConstructor", v8::Persistent<v8::FunctionTemplate>(), V8TestNamedConstructor::internalFieldCount,
        0, 0,
        0, 0, isolate, currentWorldType);
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestNamedConstructor::GetTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap(currentWorldType).find(&info);
    if (result != data->templateMap(currentWorldType).end())
        return result->value;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ =
        ConfigureV8TestNamedConstructorTemplate(data->rawTemplate(&info, currentWorldType), isolate, currentWorldType);
    data->templateMap(currentWorldType).add(&info, templ);
    return templ;
}

bool V8TestNamedConstructor::HasInstance(v8::Handle<v8::Value> value, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, currentWorldType);
}

bool V8TestNamedConstructor::HasInstanceInAnyWorld(v8::Handle<v8::Value> value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, MainWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, IsolatedWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, WorkerWorld);
}

ActiveDOMObject* V8TestNamedConstructor::toActiveDOMObject(v8::Handle<v8::Object> object)
{
    return toNative(object);
}


v8::Handle<v8::Object> V8TestNamedConstructor::createWrapper(PassRefPtr<TestNamedConstructor> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl.get());
    ASSERT(DOMDataStore::getWrapper(impl.get(), isolate).IsEmpty());

#if ENABLE(BINDING_INTEGRITY)
    checkTypeOrDieTrying(impl.get());
#endif

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &info, impl.get(), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper(impl, &info, wrapper, isolate, hasDependentLifetime ? WrapperConfiguration::Dependent : WrapperConfiguration::Independent);
    return wrapper;
}
void V8TestNamedConstructor::derefObject(void* object)
{
    static_cast<TestNamedConstructor*>(object)->deref();
}

} // namespace WebCore
