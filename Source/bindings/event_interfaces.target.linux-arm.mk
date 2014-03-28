# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := GYP
LOCAL_MODULE := third_party_WebKit_Source_bindings_event_interfaces_gyp
LOCAL_MODULE_STEM := event_interfaces
LOCAL_MODULE_SUFFIX := .stamp
LOCAL_MODULE_TAGS := optional
gyp_intermediate_dir := $(call local-intermediates-dir)
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared)

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES := \
	$(call intermediates-dir-for,GYP,third_party_WebKit_Source_bindings_interfaces_info_gyp)/interfaces_info.stamp

### Rules for action "generate_event_interfaces":
$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in: gyp_local_path := $(LOCAL_PATH)
$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in: gyp_intermediate_dir := $(abspath $(gyp_intermediate_dir))
$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in: gyp_shared_intermediate_dir := $(abspath $(gyp_shared_intermediate_dir))
$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in: export PATH := $(subst $(ANDROID_BUILD_PATHS),,$(PATH))
$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in: $(LOCAL_PATH)/third_party/WebKit/Source/bindings/scripts/generate_event_interfaces.py $(LOCAL_PATH)/third_party/WebKit/Source/bindings/scripts/utilities.py $(gyp_shared_intermediate_dir)/blink/InterfacesInfo.pickle $(GYP_TARGET_DEPENDENCIES)
	@echo "Gyp action: Generating list of Event interfaces ($@)"
	$(hide)cd $(gyp_local_path)/third_party/WebKit/Source/bindings; mkdir -p $(gyp_shared_intermediate_dir)/blink; python scripts/generate_event_interfaces.py --interfaces-info-file "$(gyp_shared_intermediate_dir)/blink/InterfacesInfo.pickle" --event-interfaces-file "$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in" --write-file-only-if-changed 0



GYP_GENERATED_OUTPUTS := \
	$(gyp_shared_intermediate_dir)/blink/EventInterfaces.in

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

### Rules for final target.
# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_WebKit_Source_bindings_event_interfaces_gyp

# Alias gyp target name.
.PHONY: event_interfaces
event_interfaces: third_party_WebKit_Source_bindings_event_interfaces_gyp

LOCAL_MODULE_PATH := $(PRODUCT_OUT)/gyp_stamp
LOCAL_UNINSTALLABLE_MODULE := true

include $(BUILD_SYSTEM)/base_rules.mk

$(LOCAL_BUILT_MODULE): $(LOCAL_ADDITIONAL_DEPENDENCIES)
	$(hide) echo "Gyp timestamp: $@"
	$(hide) mkdir -p $(dir $@)
	$(hide) touch $@