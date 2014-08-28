// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by {{code_generator}}. DO NOT MODIFY!

#include "config.h"
{% filter conditional(conditional_string) %}
#include "{{v8_class}}.h"

{% for filename in cpp_includes if filename != '%s.h' % v8_class %}
#include "{{filename}}"
{% endfor %}

namespace blink {

static void initializeScriptWrappableForInterface({{cpp_class}}* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&{{v8_class}}::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace blink

{#
In ScriptWrappable::init, the use of a local function declaration has an
issue on Windows: the local declaration does not pick up the surrounding
namespace. Therefore, we provide this function in the global namespace.
More info on the MSVC bug here (Bug 664619):
The namespace of local function declarations in C++ by Uray M. János
http://connect.microsoft.com/VisualStudio/feedback/details/664619/the-namespace-of-local-function-declarations-in-c
#}
void webCoreInitializeScriptWrappableForInterface(blink::{{cpp_class}}* object)
{
    blink::initializeScriptWrappableForInterface(object);
}

namespace blink {
{% set to_active_dom_object = '%s::toActiveDOMObject' % v8_class
                              if is_active_dom_object else '0' %}
{% set to_event_target = '%s::toEventTarget' % v8_class
                         if is_event_target else '0' %}
{% set visit_dom_wrapper = '%s::visitDOMWrapper' % v8_class
                           if has_visit_dom_wrapper else '0' %}
{% set parent_wrapper_type_info = '&V8%s::wrapperTypeInfo' % parent_interface
                                  if parent_interface else '0' %}
{% set wrapper_type_prototype = 'WrapperTypeExceptionPrototype' if is_exception else
                                'WrapperTypeObjectPrototype' %}
const WrapperTypeInfo {{v8_class}}::wrapperTypeInfo = { gin::kEmbedderBlink, {{v8_class}}::domTemplate, {{v8_class}}::derefObject, {{to_active_dom_object}}, {{to_event_target}}, {{visit_dom_wrapper}}, {{v8_class}}::installConditionallyEnabledMethods, {{v8_class}}::installConditionallyEnabledProperties, {{parent_wrapper_type_info}}, {{wrapper_type_prototype}}, {{gc_type}} };

namespace {{cpp_class}}V8Internal {

template <typename T> void V8_USE(T) { }

{# Attributes #}
{% from 'attributes.cpp' import constructor_getter_callback,
       attribute_getter, attribute_getter_callback,
       attribute_setter, attribute_setter_callback,
       attribute_getter_implemented_in_private_script,
       attribute_setter_implemented_in_private_script
       with context %}
{% for attribute in attributes if not attribute.constructor_type %}
{% if attribute.should_be_exposed_to_script %}
{% for world_suffix in attribute.world_suffixes %}
{% if not attribute.has_custom_getter %}
{{attribute_getter(attribute, world_suffix)}}
{% endif %}
{{attribute_getter_callback(attribute, world_suffix)}}
{% if not attribute.is_read_only or attribute.put_forwards %}
{% if not attribute.has_custom_setter %}
{{attribute_setter(attribute, world_suffix)}}
{% endif %}
{{attribute_setter_callback(attribute, world_suffix)}}
{% endif %}
{% endfor %}
{% endif %}
{% endfor %}
{% block constructor_getter %}{% endblock %}
{% for attribute in attributes if attribute.needs_constructor_getter_callback %}
{% for world_suffix in attribute.world_suffixes %}
{{constructor_getter_callback(attribute, world_suffix)}}
{% endfor %}
{% endfor %}
{% block replaceable_attribute_setter_and_callback %}{% endblock %}
{% block security_check_functions %}{% endblock %}
{# Methods #}
{% from 'methods.cpp' import generate_method, overload_resolution_method,
       method_callback, origin_safe_method_getter, generate_constructor,
       method_implemented_in_private_script
       with context %}
{% for method in methods %}
{% if method.should_be_exposed_to_script %}
{% for world_suffix in method.world_suffixes %}
{% if not method.is_custom %}
{{generate_method(method, world_suffix)}}
{% endif %}
{% if method.overloads %}
{{overload_resolution_method(method.overloads, world_suffix)}}
{% endif %}
{% if not method.overload_index or method.overloads %}
{# A single callback is generated for overloaded methods #}
{{method_callback(method, world_suffix)}}
{% endif %}
{% if method.is_do_not_check_security %}
{{origin_safe_method_getter(method, world_suffix)}}
{% endif %}
{% endfor %}
{% endif %}
{% endfor %}
{% block origin_safe_method_setter %}{% endblock %}
{# Constructors #}
{% for constructor in constructors %}
{{generate_constructor(constructor)}}
{% endfor %}
{% block overloaded_constructor %}{% endblock %}
{% block event_constructor %}{% endblock %}
{# Special operations (methods) #}
{% block indexed_property_getter %}{% endblock %}
{% block indexed_property_getter_callback %}{% endblock %}
{% block indexed_property_setter %}{% endblock %}
{% block indexed_property_setter_callback %}{% endblock %}
{% block indexed_property_deleter %}{% endblock %}
{% block indexed_property_deleter_callback %}{% endblock %}
{% block named_property_getter %}{% endblock %}
{% block named_property_getter_callback %}{% endblock %}
{% block named_property_setter %}{% endblock %}
{% block named_property_setter_callback %}{% endblock %}
{% block named_property_query %}{% endblock %}
{% block named_property_query_callback %}{% endblock %}
{% block named_property_deleter %}{% endblock %}
{% block named_property_deleter_callback %}{% endblock %}
{% block named_property_enumerator %}{% endblock %}
{% block named_property_enumerator_callback %}{% endblock %}
} // namespace {{cpp_class}}V8Internal

{% block visit_dom_wrapper %}{% endblock %}
{% block shadow_attributes %}{% endblock %}
{% block install_attributes %}{% endblock %}
{% block install_accessors %}{% endblock %}
{% block install_methods %}{% endblock %}
{% block named_constructor %}{% endblock %}
{% block initialize_event %}{% endblock %}
{% block constructor_callback %}{% endblock %}
{% block configure_shadow_object_template %}{% endblock %}
{% block install_dom_template %}{% endblock %}
{% block get_dom_template %}{% endblock %}
{% block has_instance %}{% endblock %}
{% block to_native_with_type_check %}{% endblock %}
{% block install_conditional_attributes %}{% endblock %}
{% block install_conditional_methods %}{% endblock %}
{% block to_active_dom_object %}{% endblock %}
{% block to_event_target %}{% endblock %}
{% block get_shadow_object_template %}{% endblock %}
{% block wrap %}{% endblock %}
{% block create_wrapper %}{% endblock %}
{% block deref_object_and_to_v8_no_inline %}{% endblock %}
{% for method in methods if method.is_implemented_in_private_script %}
{{method_implemented_in_private_script(method)}}
{% endfor %}
{% for attribute in attributes if attribute.is_implemented_in_private_script %}
{{attribute_getter_implemented_in_private_script(attribute)}}
{% if not attribute.is_read_only or attribute.put_forwards %}
{{attribute_setter_implemented_in_private_script(attribute)}}
{% endif %}
{% endfor %}
} // namespace blink
{% endfilter %}
