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
#include "V8TestTypedefs.h"

#include "RuntimeEnabledFeatures.h"
#include "V8SVGPoint.h"
#include "V8SerializedScriptValue.h"
#include "V8TestCallback.h"
#include "V8TestSubObj.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/ScriptController.h"
#include "bindings/v8/SerializedScriptValue.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "core/page/Frame.h"
#include "core/platform/chromium/TraceEvent.h"
#include "core/svg/properties/SVGPropertyTearOff.h"
#include "wtf/UnusedParam.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(TestTypedefs* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::setTypeInfoInObject(object, &V8TestTypedefs::info);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

// In ScriptWrappable::init, the use of a local function declaration has an issue on Windows:
// the local declaration does not pick up the surrounding namespace. Therefore, we provide this function
// in the global namespace.
// (More info on the MSVC bug here: http://connect.microsoft.com/VisualStudio/feedback/details/664619/the-namespace-of-local-function-declarations-in-c)
void webCoreInitializeScriptWrappableForInterface(WebCore::TestTypedefs* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
WrapperTypeInfo V8TestTypedefs::info = { V8TestTypedefs::GetTemplate, V8TestTypedefs::derefObject, 0, 0, 0, V8TestTypedefs::installPerContextPrototypeProperties, 0, WrapperTypeObjectPrototype };

namespace TestTypedefsV8Internal {

template <typename T> void V8_USE(T) { }

static void unsignedLongLongAttrAttrGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    v8SetReturnValue(info, static_cast<double>(imp->unsignedLongLongAttr()));
    return;
}

static void unsignedLongLongAttrAttrGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestTypedefsV8Internal::unsignedLongLongAttrAttrGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void unsignedLongLongAttrAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    V8TRYCATCH_VOID(unsigned long long, v, toUInt64(value));
    imp->setUnsignedLongLongAttr(v);
    return;
}

static void unsignedLongLongAttrAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestTypedefsV8Internal::unsignedLongLongAttrAttrSetter(name, value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void immutableSerializedScriptValueAttrGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    v8SetReturnValue(info, imp->immutableSerializedScriptValue() ? imp->immutableSerializedScriptValue()->deserialize() : v8::Handle<v8::Value>(v8::Null(info.GetIsolate())));
    return;
}

static void immutableSerializedScriptValueAttrGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestTypedefsV8Internal::immutableSerializedScriptValueAttrGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void immutableSerializedScriptValueAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    V8TRYCATCH_VOID(RefPtr<SerializedScriptValue>, v, SerializedScriptValue::create(value, info.GetIsolate()));
    imp->setImmutableSerializedScriptValue(WTF::getPtr(v));
    return;
}

static void immutableSerializedScriptValueAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestTypedefsV8Internal::immutableSerializedScriptValueAttrSetter(name, value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void attrWithGetterExceptionAttrGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    ExceptionState es(info.GetIsolate());
    int v = imp->attrWithGetterException(es);
    if (UNLIKELY(es.throwIfNeeded()))
        return;
    v8SetReturnValueInt(info, v);
    return;
}

static void attrWithGetterExceptionAttrGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestTypedefsV8Internal::attrWithGetterExceptionAttrGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void attrWithGetterExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    V8TRYCATCH_VOID(int, v, toInt32(value));
    imp->setAttrWithGetterException(v);
    return;
}

static void attrWithGetterExceptionAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestTypedefsV8Internal::attrWithGetterExceptionAttrSetter(name, value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void attrWithSetterExceptionAttrGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    v8SetReturnValueInt(info, imp->attrWithSetterException());
    return;
}

static void attrWithSetterExceptionAttrGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestTypedefsV8Internal::attrWithSetterExceptionAttrGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void attrWithSetterExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    V8TRYCATCH_VOID(int, v, toInt32(value));
    ExceptionState es(info.GetIsolate());
    imp->setAttrWithSetterException(v, es);
    es.throwIfNeeded();
    return;
}

static void attrWithSetterExceptionAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestTypedefsV8Internal::attrWithSetterExceptionAttrSetter(name, value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void stringAttrWithGetterExceptionAttrGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    ExceptionState es(info.GetIsolate());
    String v = imp->stringAttrWithGetterException(es);
    if (UNLIKELY(es.throwIfNeeded()))
        return;
    v8SetReturnValueString(info, v, info.GetIsolate());
    return;
}

static void stringAttrWithGetterExceptionAttrGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestTypedefsV8Internal::stringAttrWithGetterExceptionAttrGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void stringAttrWithGetterExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, v, value);
    imp->setStringAttrWithGetterException(v);
    return;
}

static void stringAttrWithGetterExceptionAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestTypedefsV8Internal::stringAttrWithGetterExceptionAttrSetter(name, value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void stringAttrWithSetterExceptionAttrGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    v8SetReturnValueString(info, imp->stringAttrWithSetterException(), info.GetIsolate());
    return;
}

static void stringAttrWithSetterExceptionAttrGetterCallback(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestTypedefsV8Internal::stringAttrWithSetterExceptionAttrGetter(name, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void stringAttrWithSetterExceptionAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(info.Holder());
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, v, value);
    ExceptionState es(info.GetIsolate());
    imp->setStringAttrWithSetterException(v, es);
    es.throwIfNeeded();
    return;
}

static void stringAttrWithSetterExceptionAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestTypedefsV8Internal::stringAttrWithSetterExceptionAttrSetter(name, value, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void TestTypedefsConstructorGetter(v8::Local<v8::String> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    v8::Handle<v8::Value> data = info.Data();
    ASSERT(data->IsExternal());
    V8PerContextData* perContextData = V8PerContextData::from(info.Holder()->CreationContext());
    if (!perContextData)
        return;
    v8SetReturnValue(info, perContextData->constructorForType(WrapperTypeInfo::unwrap(data)));
}
static void TestTypedefsReplaceableAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    info.This()->ForceSet(name, value);
}

static void TestTypedefsReplaceableAttrSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    TestTypedefsV8Internal::TestTypedefsReplaceableAttrSetter(name, value, info);
}

static void funcMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    if (args.Length() <= 0) {
        imp->func();

        return;
    }
    V8TRYCATCH_VOID(Vector<int>, x, toNativeArray<int>(args[0], args.GetIsolate()));
    imp->func(x);

    return;
}

static void funcMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::funcMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void setShadowMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 3) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    V8TRYCATCH_VOID(float, width, static_cast<float>(args[0]->NumberValue()));
    V8TRYCATCH_VOID(float, height, static_cast<float>(args[1]->NumberValue()));
    V8TRYCATCH_VOID(float, blur, static_cast<float>(args[2]->NumberValue()));
    if (args.Length() <= 3) {
        imp->setShadow(width, height, blur);

        return;
    }
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, color, args[3]);
    if (args.Length() <= 4) {
        imp->setShadow(width, height, blur, color);

        return;
    }
    V8TRYCATCH_VOID(float, alpha, static_cast<float>(args[4]->NumberValue()));
    imp->setShadow(width, height, blur, color, alpha);

    return;
}

static void setShadowMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::setShadowMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void methodWithSequenceArgMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 1) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    V8TRYCATCH_VOID(Vector<RefPtr<SerializedScriptValue> >, sequenceArg, (toRefPtrNativeArray<SerializedScriptValue, V8SerializedScriptValue>(args[0], args.GetIsolate())));
    v8SetReturnValue(args, static_cast<double>(imp->methodWithSequenceArg(sequenceArg)));
    return;
}

static void methodWithSequenceArgMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::methodWithSequenceArgMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void nullableArrayArgMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 1) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    V8TRYCATCH_VOID(Vector<String>, arrayArg, toNativeArray<String>(args[0], args.GetIsolate()));
    imp->nullableArrayArg(arrayArg);

    return;
}

static void nullableArrayArgMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::nullableArrayArgMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void funcWithClampMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 1) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    unsigned long long arg1 = 0;
    V8TRYCATCH_VOID(double, arg1NativeValue, args[0]->NumberValue());
    if (!std::isnan(arg1NativeValue))
        arg1 = clampTo<unsigned long long>(arg1NativeValue);
    if (args.Length() <= 1) {
        imp->funcWithClamp(arg1);

        return;
    }
    unsigned long long arg2 = 0;
    V8TRYCATCH_VOID(double, arg2NativeValue, args[1]->NumberValue());
    if (!std::isnan(arg2NativeValue))
        arg2 = clampTo<unsigned long long>(arg2NativeValue);
    imp->funcWithClamp(arg1, arg2);

    return;
}

static void funcWithClampMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::funcWithClampMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void immutablePointFunctionMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    v8SetReturnValue(args, WTF::getPtr(SVGPropertyTearOff<SVGPoint>::create(imp->immutablePointFunction())), args.Holder());
    return;
}

static void immutablePointFunctionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::immutablePointFunctionMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void stringArrayFunctionMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 1) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    ExceptionState es(args.GetIsolate());
    V8TRYCATCH_VOID(Vector<String>, values, toNativeArray<String>(args[0], args.GetIsolate()));
    Vector<String> result = imp->stringArrayFunction(values, es);
    if (es.throwIfNeeded())
        return;
    v8SetReturnValue(args, v8Array(result, args.GetIsolate()));
    return;
}

static void stringArrayFunctionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::stringArrayFunctionMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void stringArrayFunction2Method(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 1) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    ExceptionState es(args.GetIsolate());
    V8TRYCATCH_VOID(Vector<String>, values, toNativeArray<String>(args[0], args.GetIsolate()));
    Vector<String> result = imp->stringArrayFunction2(values, es);
    if (es.throwIfNeeded())
        return;
    v8SetReturnValue(args, v8Array(result, args.GetIsolate()));
    return;
}

static void stringArrayFunction2MethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::stringArrayFunction2Method(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void methodWithExceptionMethod(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TestTypedefs* imp = V8TestTypedefs::toNative(args.Holder());
    ExceptionState es(args.GetIsolate());
    imp->methodWithException(es);
    if (es.throwIfNeeded())
        return;

    return;
}

static void methodWithExceptionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestTypedefsV8Internal::methodWithExceptionMethod(args);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void constructor(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args.Length() < 2) {
        throwNotEnoughArgumentsError(args.GetIsolate());
        return;
    }
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, hello, args[0]);
    if (args.Length() <= 1 || !args[1]->IsFunction()) {
        throwTypeError(args.GetIsolate());
        return;
    }
    RefPtr<TestCallback> testCallback = V8TestCallback::create(args[1], getScriptExecutionContext());

    RefPtr<TestTypedefs> impl = TestTypedefs::create(hello, testCallback);
    v8::Handle<v8::Object> wrapper = args.Holder();

    V8DOMWrapper::associateObjectWithWrapper<V8TestTypedefs>(impl.release(), &V8TestTypedefs::info, wrapper, args.GetIsolate(), WrapperConfiguration::Dependent);
    args.GetReturnValue().Set(wrapper);
}

} // namespace TestTypedefsV8Internal

static const V8DOMConfiguration::BatchedAttribute V8TestTypedefsAttrs[] = {
    // Attribute 'unsignedLongLongAttr'
    {"unsignedLongLongAttr", TestTypedefsV8Internal::unsignedLongLongAttrAttrGetterCallback, TestTypedefsV8Internal::unsignedLongLongAttrAttrSetterCallback, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'immutableSerializedScriptValue'
    {"immutableSerializedScriptValue", TestTypedefsV8Internal::immutableSerializedScriptValueAttrGetterCallback, TestTypedefsV8Internal::immutableSerializedScriptValueAttrSetterCallback, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'TestSubObj'
    {"TestSubObj", TestTypedefsV8Internal::TestTypedefsConstructorGetter, 0, 0, 0, &V8TestSubObj::info, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None | v8::DontEnum), 0 /* on instance */},
    // Attribute 'attrWithGetterException'
    {"attrWithGetterException", TestTypedefsV8Internal::attrWithGetterExceptionAttrGetterCallback, TestTypedefsV8Internal::attrWithGetterExceptionAttrSetterCallback, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'attrWithSetterException'
    {"attrWithSetterException", TestTypedefsV8Internal::attrWithSetterExceptionAttrGetterCallback, TestTypedefsV8Internal::attrWithSetterExceptionAttrSetterCallback, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'stringAttrWithGetterException'
    {"stringAttrWithGetterException", TestTypedefsV8Internal::stringAttrWithGetterExceptionAttrGetterCallback, TestTypedefsV8Internal::stringAttrWithGetterExceptionAttrSetterCallback, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'stringAttrWithSetterException'
    {"stringAttrWithSetterException", TestTypedefsV8Internal::stringAttrWithSetterExceptionAttrGetterCallback, TestTypedefsV8Internal::stringAttrWithSetterExceptionAttrSetterCallback, 0, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::BatchedMethod V8TestTypedefsMethods[] = {
    {"func", TestTypedefsV8Internal::funcMethodCallback, 0, 0},
    {"setShadow", TestTypedefsV8Internal::setShadowMethodCallback, 0, 3},
    {"methodWithSequenceArg", TestTypedefsV8Internal::methodWithSequenceArgMethodCallback, 0, 1},
    {"nullableArrayArg", TestTypedefsV8Internal::nullableArrayArgMethodCallback, 0, 1},
    {"funcWithClamp", TestTypedefsV8Internal::funcWithClampMethodCallback, 0, 1},
    {"immutablePointFunction", TestTypedefsV8Internal::immutablePointFunctionMethodCallback, 0, 0},
    {"stringArrayFunction", TestTypedefsV8Internal::stringArrayFunctionMethodCallback, 0, 1},
    {"stringArrayFunction2", TestTypedefsV8Internal::stringArrayFunction2MethodCallback, 0, 1},
    {"methodWithException", TestTypedefsV8Internal::methodWithExceptionMethodCallback, 0, 0},
};

void V8TestTypedefs::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    TRACE_EVENT_SCOPED_SAMPLING_STATE("Blink", "DOMConstructor");
    if (!args.IsConstructCall()) {
        throwTypeError("DOM object constructor cannot be called as a function.", args.GetIsolate());
        return;
    }

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject) {
        args.GetReturnValue().Set(args.Holder());
        return;
    }

    TestTypedefsV8Internal::constructor(args);
}

static v8::Handle<v8::FunctionTemplate> ConfigureV8TestTypedefsTemplate(v8::Handle<v8::FunctionTemplate> desc, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestTypedefs", v8::Local<v8::FunctionTemplate>(), V8TestTypedefs::internalFieldCount,
        V8TestTypedefsAttrs, WTF_ARRAY_LENGTH(V8TestTypedefsAttrs),
        V8TestTypedefsMethods, WTF_ARRAY_LENGTH(V8TestTypedefsMethods), isolate, currentWorldType);
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.
    desc->SetCallHandler(V8TestTypedefs::constructorCallback);
    desc->SetLength(2);
    v8::Local<v8::ObjectTemplate> instance = desc->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> proto = desc->PrototypeTemplate();
    UNUSED_PARAM(instance); // In some cases, it will not be used.
    UNUSED_PARAM(proto); // In some cases, it will not be used.

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Handle<v8::FunctionTemplate> V8TestTypedefs::GetTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap(currentWorldType).find(&info);
    if (result != data->templateMap(currentWorldType).end())
        return result->value.newLocal(isolate);

    TRACE_EVENT_SCOPED_SAMPLING_STATE("Blink", "BuildDOMTemplate");
    v8::HandleScope handleScope(isolate);
    v8::Handle<v8::FunctionTemplate> templ =
        ConfigureV8TestTypedefsTemplate(data->rawTemplate(&info, currentWorldType), isolate, currentWorldType);
    data->templateMap(currentWorldType).add(&info, UnsafePersistent<v8::FunctionTemplate>(isolate, templ));
    return handleScope.Close(templ);
}

bool V8TestTypedefs::HasInstance(v8::Handle<v8::Value> value, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, currentWorldType);
}

bool V8TestTypedefs::HasInstanceInAnyWorld(v8::Handle<v8::Value> value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&info, value, MainWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, IsolatedWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&info, value, WorkerWorld);
}


v8::Handle<v8::Object> V8TestTypedefs::createWrapper(PassRefPtr<TestTypedefs> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl.get());
    ASSERT(!DOMDataStore::containsWrapper<V8TestTypedefs>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::getTypeInfoFromObject(impl.get());
        // Might be a XXXConstructor::info instead of an XXX::info. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == info.derefObjectFunction);
    }


    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &info, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;
    installPerContextProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8TestTypedefs>(impl, &info, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}
void V8TestTypedefs::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

} // namespace WebCore
