# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := third_party_WebKit_Source_core_webcore_html_gyp
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_TARGET_ARCH := $(TARGET_$(GYP_VAR_PREFIX)ARCH)
gyp_intermediate_dir := $(call local-intermediates-dir,,$(GYP_VAR_PREFIX))
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared,,,$(GYP_VAR_PREFIX))

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES := \
	$(call intermediates-dir-for,GYP,third_party_WebKit_Source_core_webcore_prerequisites_gyp,,,$(GYP_VAR_PREFIX))/webcore_prerequisites.stamp \
	$(call intermediates-dir-for,STATIC_LIBRARIES,skia_skia_library_gyp,,,$(GYP_VAR_PREFIX))/skia_skia_library_gyp.a

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	third_party/WebKit/Source/core/html/ClassList.cpp \
	third_party/WebKit/Source/core/html/DOMFormData.cpp \
	third_party/WebKit/Source/core/html/DocumentNameCollection.cpp \
	third_party/WebKit/Source/core/html/FormAssociatedElement.cpp \
	third_party/WebKit/Source/core/html/FormDataList.cpp \
	third_party/WebKit/Source/core/html/HTMLAllCollection.cpp \
	third_party/WebKit/Source/core/html/HTMLAnchorElement.cpp \
	third_party/WebKit/Source/core/html/HTMLAppletElement.cpp \
	third_party/WebKit/Source/core/html/HTMLAreaElement.cpp \
	third_party/WebKit/Source/core/html/HTMLAudioElement.cpp \
	third_party/WebKit/Source/core/html/HTMLBRElement.cpp \
	third_party/WebKit/Source/core/html/HTMLBaseElement.cpp \
	third_party/WebKit/Source/core/html/HTMLBodyElement.cpp \
	third_party/WebKit/Source/core/html/HTMLButtonElement.cpp \
	third_party/WebKit/Source/core/html/HTMLCanvasElement.cpp \
	third_party/WebKit/Source/core/html/HTMLCollection.cpp \
	third_party/WebKit/Source/core/html/HTMLContentElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDListElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDataListElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDetailsElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDialogElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDimension.cpp \
	third_party/WebKit/Source/core/html/HTMLDirectoryElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDivElement.cpp \
	third_party/WebKit/Source/core/html/HTMLDocument.cpp \
	third_party/WebKit/Source/core/html/HTMLElement.cpp \
	third_party/WebKit/Source/core/html/HTMLEmbedElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFieldSetElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFontElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFormControlElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFormControlElementWithState.cpp \
	third_party/WebKit/Source/core/html/HTMLFormControlsCollection.cpp \
	third_party/WebKit/Source/core/html/HTMLFormElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFrameElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFrameElementBase.cpp \
	third_party/WebKit/Source/core/html/HTMLFrameOwnerElement.cpp \
	third_party/WebKit/Source/core/html/HTMLFrameSetElement.cpp \
	third_party/WebKit/Source/core/html/HTMLHRElement.cpp \
	third_party/WebKit/Source/core/html/HTMLHeadElement.cpp \
	third_party/WebKit/Source/core/html/HTMLHeadingElement.cpp \
	third_party/WebKit/Source/core/html/HTMLHtmlElement.cpp \
	third_party/WebKit/Source/core/html/HTMLIFrameElement.cpp \
	third_party/WebKit/Source/core/html/HTMLImageElement.cpp \
	third_party/WebKit/Source/core/html/HTMLImageLoader.cpp \
	third_party/WebKit/Source/core/html/HTMLInputElement.cpp \
	third_party/WebKit/Source/core/html/HTMLKeygenElement.cpp \
	third_party/WebKit/Source/core/html/HTMLLIElement.cpp \
	third_party/WebKit/Source/core/html/HTMLLabelElement.cpp \
	third_party/WebKit/Source/core/html/HTMLLegendElement.cpp \
	third_party/WebKit/Source/core/html/HTMLLinkElement.cpp \
	third_party/WebKit/Source/core/html/HTMLMapElement.cpp \
	third_party/WebKit/Source/core/html/HTMLMarqueeElement.cpp \
	third_party/WebKit/Source/core/html/HTMLMediaElement.cpp \
	third_party/WebKit/Source/core/html/HTMLMediaSource.cpp \
	third_party/WebKit/Source/core/html/HTMLMenuElement.cpp \
	third_party/WebKit/Source/core/html/HTMLMeterElement.cpp \
	third_party/WebKit/Source/core/html/HTMLModElement.cpp \
	third_party/WebKit/Source/core/html/HTMLNameCollection.cpp \
	third_party/WebKit/Source/core/html/HTMLNoEmbedElement.cpp \
	third_party/WebKit/Source/core/html/HTMLNoScriptElement.cpp \
	third_party/WebKit/Source/core/html/HTMLOListElement.cpp \
	third_party/WebKit/Source/core/html/HTMLObjectElement.cpp \
	third_party/WebKit/Source/core/html/HTMLOptGroupElement.cpp \
	third_party/WebKit/Source/core/html/HTMLOptionElement.cpp \
	third_party/WebKit/Source/core/html/HTMLOptionsCollection.cpp \
	third_party/WebKit/Source/core/html/HTMLOutputElement.cpp \
	third_party/WebKit/Source/core/html/HTMLParagraphElement.cpp \
	third_party/WebKit/Source/core/html/HTMLParamElement.cpp \
	third_party/WebKit/Source/core/html/HTMLPictureElement.cpp \
	third_party/WebKit/Source/core/html/HTMLPlugInElement.cpp \
	third_party/WebKit/Source/core/html/HTMLPreElement.cpp \
	third_party/WebKit/Source/core/html/HTMLProgressElement.cpp \
	third_party/WebKit/Source/core/html/HTMLQuoteElement.cpp \
	third_party/WebKit/Source/core/html/HTMLRTElement.cpp \
	third_party/WebKit/Source/core/html/HTMLRubyElement.cpp \
	third_party/WebKit/Source/core/html/HTMLScriptElement.cpp \
	third_party/WebKit/Source/core/html/HTMLSelectElement.cpp \
	third_party/WebKit/Source/core/html/HTMLShadowElement.cpp \
	third_party/WebKit/Source/core/html/HTMLSourceElement.cpp \
	third_party/WebKit/Source/core/html/HTMLSpanElement.cpp \
	third_party/WebKit/Source/core/html/HTMLStyleElement.cpp \
	third_party/WebKit/Source/core/html/HTMLSummaryElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTableCaptionElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTableCellElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTableColElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTableElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTablePartElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTableRowElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTableRowsCollection.cpp \
	third_party/WebKit/Source/core/html/HTMLTableSectionElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTemplateElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTextAreaElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTextFormControlElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTitleElement.cpp \
	third_party/WebKit/Source/core/html/HTMLTrackElement.cpp \
	third_party/WebKit/Source/core/html/HTMLUListElement.cpp \
	third_party/WebKit/Source/core/html/HTMLVideoElement.cpp \
	third_party/WebKit/Source/core/html/HTMLViewSourceDocument.cpp \
	third_party/WebKit/Source/core/html/HTMLWBRElement.cpp \
	third_party/WebKit/Source/core/html/ImageData.cpp \
	third_party/WebKit/Source/core/html/ImageDocument.cpp \
	third_party/WebKit/Source/core/html/LabelableElement.cpp \
	third_party/WebKit/Source/core/html/LabelsNodeList.cpp \
	third_party/WebKit/Source/core/html/LinkManifest.cpp \
	third_party/WebKit/Source/core/html/LinkRelAttribute.cpp \
	third_party/WebKit/Source/core/html/LinkResource.cpp \
	third_party/WebKit/Source/core/html/MediaController.cpp \
	third_party/WebKit/Source/core/html/MediaDocument.cpp \
	third_party/WebKit/Source/core/html/MediaFragmentURIParser.cpp \
	third_party/WebKit/Source/core/html/MediaKeyEvent.cpp \
	third_party/WebKit/Source/core/html/PluginDocument.cpp \
	third_party/WebKit/Source/core/html/PublicURLManager.cpp \
	third_party/WebKit/Source/core/html/RadioNodeList.cpp \
	third_party/WebKit/Source/core/html/TextDocument.cpp \
	third_party/WebKit/Source/core/html/TimeRanges.cpp \
	third_party/WebKit/Source/core/html/ValidityState.cpp \
	third_party/WebKit/Source/core/html/WindowNameCollection.cpp \
	third_party/WebKit/Source/core/html/canvas/ANGLEInstancedArrays.cpp \
	third_party/WebKit/Source/core/html/canvas/Canvas2DContextAttributes.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasContextAttributes.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasGradient.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasPathMethods.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasPattern.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasRenderingContext.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasRenderingContext2D.cpp \
	third_party/WebKit/Source/core/html/canvas/CanvasStyle.cpp \
	third_party/WebKit/Source/core/html/canvas/DataView.cpp \
	third_party/WebKit/Source/core/html/canvas/EXTBlendMinMax.cpp \
	third_party/WebKit/Source/core/html/canvas/EXTFragDepth.cpp \
	third_party/WebKit/Source/core/html/canvas/EXTShaderTextureLOD.cpp \
	third_party/WebKit/Source/core/html/canvas/EXTTextureFilterAnisotropic.cpp \
	third_party/WebKit/Source/core/html/canvas/OESElementIndexUint.cpp \
	third_party/WebKit/Source/core/html/canvas/OESStandardDerivatives.cpp \
	third_party/WebKit/Source/core/html/canvas/OESTextureFloat.cpp \
	third_party/WebKit/Source/core/html/canvas/OESTextureFloatLinear.cpp \
	third_party/WebKit/Source/core/html/canvas/OESTextureHalfFloat.cpp \
	third_party/WebKit/Source/core/html/canvas/OESTextureHalfFloatLinear.cpp \
	third_party/WebKit/Source/core/html/canvas/OESVertexArrayObject.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLBuffer.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLCompressedTextureATC.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLCompressedTextureETC1.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLCompressedTexturePVRTC.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLCompressedTextureS3TC.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLContextAttributes.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLContextEvent.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLContextGroup.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLContextObject.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLDebugRendererInfo.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLDebugShaders.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLDepthTexture.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLDrawBuffers.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLExtension.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLFramebuffer.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLGetInfo.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLLoseContext.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLObject.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLProgram.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLRenderbuffer.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLRenderingContext.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLRenderingContextBase.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLShader.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLShaderPrecisionFormat.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLSharedObject.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLTexture.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLUniformLocation.cpp \
	third_party/WebKit/Source/core/html/canvas/WebGLVertexArrayObjectOES.cpp \
	third_party/WebKit/Source/core/html/forms/BaseButtonInputType.cpp \
	third_party/WebKit/Source/core/html/forms/BaseCheckableInputType.cpp \
	third_party/WebKit/Source/core/html/forms/BaseChooserOnlyDateAndTimeInputType.cpp \
	third_party/WebKit/Source/core/html/forms/BaseClickableWithKeyInputType.cpp \
	third_party/WebKit/Source/core/html/forms/BaseDateAndTimeInputType.cpp \
	third_party/WebKit/Source/core/html/forms/BaseMultipleFieldsDateAndTimeInputType.cpp \
	third_party/WebKit/Source/core/html/forms/BaseTextInputType.cpp \
	third_party/WebKit/Source/core/html/forms/ButtonInputType.cpp \
	third_party/WebKit/Source/core/html/forms/CheckboxInputType.cpp \
	third_party/WebKit/Source/core/html/forms/ColorInputType.cpp \
	third_party/WebKit/Source/core/html/forms/DateInputType.cpp \
	third_party/WebKit/Source/core/html/forms/DateTimeFieldsState.cpp \
	third_party/WebKit/Source/core/html/forms/DateTimeLocalInputType.cpp \
	third_party/WebKit/Source/core/html/forms/EmailInputType.cpp \
	third_party/WebKit/Source/core/html/forms/FileInputType.cpp \
	third_party/WebKit/Source/core/html/forms/FormController.cpp \
	third_party/WebKit/Source/core/html/forms/HiddenInputType.cpp \
	third_party/WebKit/Source/core/html/forms/ImageInputType.cpp \
	third_party/WebKit/Source/core/html/forms/InputType.cpp \
	third_party/WebKit/Source/core/html/forms/InputTypeView.cpp \
	third_party/WebKit/Source/core/html/forms/MonthInputType.cpp \
	third_party/WebKit/Source/core/html/forms/NumberInputType.cpp \
	third_party/WebKit/Source/core/html/forms/PasswordInputType.cpp \
	third_party/WebKit/Source/core/html/forms/RadioButtonGroupScope.cpp \
	third_party/WebKit/Source/core/html/forms/RadioInputType.cpp \
	third_party/WebKit/Source/core/html/forms/RangeInputType.cpp \
	third_party/WebKit/Source/core/html/forms/ResetInputType.cpp \
	third_party/WebKit/Source/core/html/forms/SearchInputType.cpp \
	third_party/WebKit/Source/core/html/forms/StepRange.cpp \
	third_party/WebKit/Source/core/html/forms/SubmitInputType.cpp \
	third_party/WebKit/Source/core/html/forms/TelephoneInputType.cpp \
	third_party/WebKit/Source/core/html/forms/TextFieldInputType.cpp \
	third_party/WebKit/Source/core/html/forms/TextInputType.cpp \
	third_party/WebKit/Source/core/html/forms/TimeInputType.cpp \
	third_party/WebKit/Source/core/html/forms/TypeAhead.cpp \
	third_party/WebKit/Source/core/html/forms/URLInputType.cpp \
	third_party/WebKit/Source/core/html/forms/ValidationMessage.cpp \
	third_party/WebKit/Source/core/html/forms/WeekInputType.cpp \
	third_party/WebKit/Source/core/html/ime/InputMethodContext.cpp \
	third_party/WebKit/Source/core/html/imports/HTMLImport.cpp \
	third_party/WebKit/Source/core/html/imports/HTMLImportChild.cpp \
	third_party/WebKit/Source/core/html/imports/HTMLImportLoader.cpp \
	third_party/WebKit/Source/core/html/imports/HTMLImportStateResolver.cpp \
	third_party/WebKit/Source/core/html/imports/HTMLImportTreeRoot.cpp \
	third_party/WebKit/Source/core/html/imports/HTMLImportsController.cpp \
	third_party/WebKit/Source/core/html/imports/LinkImport.cpp \
	third_party/WebKit/Source/core/html/parser/BackgroundHTMLInputStream.cpp \
	third_party/WebKit/Source/core/html/parser/BackgroundHTMLParser.cpp \
	third_party/WebKit/Source/core/html/parser/CSSPreloadScanner.cpp \
	third_party/WebKit/Source/core/html/parser/CompactHTMLToken.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLConstructionSite.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLDocumentParser.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLElementStack.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLEntityParser.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLEntitySearch.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLFormattingElementList.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLMetaCharsetParser.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLParserIdioms.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLParserOptions.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLParserScheduler.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLParserThread.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLPreloadScanner.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLResourcePreloader.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLScriptRunner.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLSourceTracker.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLSrcsetParser.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLTokenizer.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLTreeBuilder.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLTreeBuilderSimulator.cpp \
	third_party/WebKit/Source/core/html/parser/HTMLViewSourceParser.cpp \
	third_party/WebKit/Source/core/html/parser/TextDocumentParser.cpp \
	third_party/WebKit/Source/core/html/parser/TextResourceDecoder.cpp \
	third_party/WebKit/Source/core/html/parser/XSSAuditor.cpp \
	third_party/WebKit/Source/core/html/parser/XSSAuditorDelegate.cpp \
	third_party/WebKit/Source/core/html/shadow/ClearButtonElement.cpp \
	third_party/WebKit/Source/core/html/shadow/DateTimeEditElement.cpp \
	third_party/WebKit/Source/core/html/shadow/DateTimeFieldElement.cpp \
	third_party/WebKit/Source/core/html/shadow/DateTimeFieldElements.cpp \
	third_party/WebKit/Source/core/html/shadow/DateTimeNumericFieldElement.cpp \
	third_party/WebKit/Source/core/html/shadow/DateTimeSymbolicFieldElement.cpp \
	third_party/WebKit/Source/core/html/shadow/DetailsMarkerControl.cpp \
	third_party/WebKit/Source/core/html/shadow/MediaControlElementTypes.cpp \
	third_party/WebKit/Source/core/html/shadow/MediaControlElements.cpp \
	third_party/WebKit/Source/core/html/shadow/MediaControls.cpp \
	third_party/WebKit/Source/core/html/shadow/MeterShadowElement.cpp \
	third_party/WebKit/Source/core/html/shadow/PickerIndicatorElement.cpp \
	third_party/WebKit/Source/core/html/shadow/ProgressShadowElement.cpp \
	third_party/WebKit/Source/core/html/shadow/ShadowElementNames.cpp \
	third_party/WebKit/Source/core/html/shadow/SliderThumbElement.cpp \
	third_party/WebKit/Source/core/html/shadow/SpinButtonElement.cpp \
	third_party/WebKit/Source/core/html/shadow/TextControlInnerElements.cpp \
	third_party/WebKit/Source/core/html/track/AudioTrack.cpp \
	third_party/WebKit/Source/core/html/track/AudioTrackList.cpp \
	third_party/WebKit/Source/core/html/track/InbandTextTrack.cpp \
	third_party/WebKit/Source/core/html/track/LoadableTextTrack.cpp \
	third_party/WebKit/Source/core/html/track/TextTrack.cpp \
	third_party/WebKit/Source/core/html/track/TextTrackCue.cpp \
	third_party/WebKit/Source/core/html/track/TextTrackCueList.cpp \
	third_party/WebKit/Source/core/html/track/TextTrackList.cpp \
	third_party/WebKit/Source/core/html/track/TrackBase.cpp \
	third_party/WebKit/Source/core/html/track/TrackEvent.cpp \
	third_party/WebKit/Source/core/html/track/VideoTrack.cpp \
	third_party/WebKit/Source/core/html/track/VideoTrackList.cpp \
	third_party/WebKit/Source/core/html/track/vtt/BufferedLineReader.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTCue.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTElement.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTParser.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTRegion.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTRegionList.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTScanner.cpp \
	third_party/WebKit/Source/core/html/track/vtt/VTTTokenizer.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS_Debug := \
	-fstack-protector \
	--param=ssp-buffer-size=4 \
	 \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wall \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-unused-local-typedefs \
	-EL \
	-mhard-float \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-unused-but-set-variable \
	-Os \
	-g \
	-fomit-frame-pointer \
	-fdata-sections \
	-ffunction-sections \
	-funwind-tables

MY_DEFS_Debug := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DBLINK_SCALE_FILTERS_AT_RECORD_TIME' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DVIDEO_HOLE=1' \
	'-DBLINK_IMPLEMENTATION=1' \
	'-DINSIDE_BLINK' \
	'-DENABLE_CUSTOM_SCHEME_HANDLER=0' \
	'-DENABLE_SVG_FONTS=1' \
	'-DWTF_USE_CONCATENATED_IMPULSE_RESPONSES=1' \
	'-DENABLE_MEDIA_CAPTURE=1' \
	'-DENABLE_OPENTYPE_VERTICAL=1' \
	'-DU_USING_ICU_NAMESPACE=0' \
	'-DSK_ENABLE_INST_COUNT=0' \
	'-DSK_SUPPORT_GPU=1' \
	'-DGR_GL_CUSTOM_SETUP_HEADER="GrGLConfig_chrome.h"' \
	'-DSK_ENABLE_LEGACY_API_ALIASING=1' \
	'-DSK_ATTR_DEPRECATED=SK_NOTHING_ARG1' \
	'-DGR_GL_IGNORE_ES3_MSAA=0' \
	'-DSK_WILL_NEVER_DRAW_PERSPECTIVE_TEXT' \
	'-DSK_SUPPORT_LEGACY_GETTOPDEVICE' \
	'-DSK_SUPPORT_LEGACY_BITMAP_CONFIG' \
	'-DSK_SUPPORT_LEGACY_DEVICE_VIRTUAL_ISOPAQUE' \
	'-DSK_SUPPORT_LEGACY_N32_NAME' \
	'-DSK_SUPPORT_LEGACY_SETCONFIG' \
	'-DSK_IGNORE_ETC1_SUPPORT' \
	'-DSK_SUPPORT_LEGACY_GETTOTALCLIP' \
	'-DSK_BUILD_FOR_ANDROID' \
	'-DSK_USE_POSIX_THREADS' \
	'-DSK_DEFERRED_CANVAS_USES_FACTORIES=1' \
	'-DCHROME_PNG_WRITE_SUPPORT' \
	'-DPNG_USER_CONFIG' \
	'-DCHROME_PNG_READ_PACK_SUPPORT' \
	'-DLIBXML_STATIC' \
	'-DLIBXSLT_STATIC' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-D__STDC_CONSTANT_MACROS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=1' \
	'-DWTF_USE_DYNAMIC_ANNOTATIONS=1' \
	'-D_DEBUG'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Debug := \
	$(gyp_shared_intermediate_dir)/shim_headers/ashmem/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(gyp_shared_intermediate_dir) \
	$(LOCAL_PATH)/third_party/WebKit/Source \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/skia/config \
	$(LOCAL_PATH)/third_party/khronos \
	$(LOCAL_PATH)/gpu \
	$(gyp_shared_intermediate_dir)/blink/core \
	$(gyp_shared_intermediate_dir)/blink/modules \
	$(gyp_shared_intermediate_dir)/blink/platform \
	$(gyp_shared_intermediate_dir)/blink/bindings/core/v8 \
	$(gyp_shared_intermediate_dir)/blink/bindings/modules/v8 \
	$(gyp_shared_intermediate_dir)/blink \
	$(LOCAL_PATH)/third_party/angle/include \
	$(PWD)/external/icu4c/common \
	$(PWD)/external/icu4c/i18n \
	$(LOCAL_PATH)/third_party/WebKit \
	$(LOCAL_PATH)/third_party/skia/src/core \
	$(LOCAL_PATH)/third_party/skia/include/core \
	$(LOCAL_PATH)/third_party/skia/include/effects \
	$(LOCAL_PATH)/third_party/skia/include/pdf \
	$(LOCAL_PATH)/third_party/skia/include/gpu \
	$(LOCAL_PATH)/third_party/skia/include/lazy \
	$(LOCAL_PATH)/third_party/skia/include/pathops \
	$(LOCAL_PATH)/third_party/skia/include/pipe \
	$(LOCAL_PATH)/third_party/skia/include/ports \
	$(LOCAL_PATH)/third_party/skia/include/utils \
	$(LOCAL_PATH)/skia/ext \
	$(LOCAL_PATH)/third_party/iccjpeg \
	$(LOCAL_PATH)/third_party/libpng \
	$(LOCAL_PATH)/third_party/libwebp \
	$(LOCAL_PATH)/third_party/libxml/linux/include \
	$(LOCAL_PATH)/third_party/libxml/src/include \
	$(LOCAL_PATH)/third_party/libxslt \
	$(LOCAL_PATH)/third_party/npapi \
	$(LOCAL_PATH)/third_party/npapi/bindings \
	$(LOCAL_PATH)/third_party/ots/include \
	$(LOCAL_PATH)/third_party/qcms/src \
	$(LOCAL_PATH)/third_party/sqlite \
	$(LOCAL_PATH)/third_party/zlib \
	$(LOCAL_PATH)/v8/include \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(PWD)/external/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Debug := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wsign-compare \
	-Wno-c++0x-compat \
	-Wno-uninitialized \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo


# Flags passed to both C and C++ files.
MY_CFLAGS_Release := \
	-fstack-protector \
	--param=ssp-buffer-size=4 \
	 \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wall \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-Wno-unused-local-typedefs \
	-EL \
	-mhard-float \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fstack-protector \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-unused-but-set-variable \
	-Os \
	-fno-ident \
	-fdata-sections \
	-ffunction-sections \
	-fomit-frame-pointer \
	-funwind-tables

MY_DEFS_Release := \
	'-DV8_DEPRECATION_WARNINGS' \
	'-DBLINK_SCALE_FILTERS_AT_RECORD_TIME' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DENABLE_WEBRTC=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_BROWSER_CDMS' \
	'-DENABLE_CONFIGURATION_POLICY' \
	'-DDISCARDABLE_MEMORY_ALWAYS_SUPPORTED_NATIVELY' \
	'-DSYSTEM_NATIVELY_SIGNALS_MEMORY_PRESSURE' \
	'-DENABLE_EGLIMAGE=1' \
	'-DCLD_VERSION=1' \
	'-DENABLE_PRINTING=1' \
	'-DENABLE_MANAGED_USERS=1' \
	'-DDATA_REDUCTION_FALLBACK_HOST="http://compress.googlezip.net:80/"' \
	'-DDATA_REDUCTION_DEV_HOST="http://proxy-dev.googlezip.net:80/"' \
	'-DSPDY_PROXY_AUTH_ORIGIN="https://proxy.googlezip.net:443/"' \
	'-DDATA_REDUCTION_PROXY_PROBE_URL="http://check.googlezip.net/connect"' \
	'-DVIDEO_HOLE=1' \
	'-DBLINK_IMPLEMENTATION=1' \
	'-DINSIDE_BLINK' \
	'-DENABLE_CUSTOM_SCHEME_HANDLER=0' \
	'-DENABLE_SVG_FONTS=1' \
	'-DWTF_USE_CONCATENATED_IMPULSE_RESPONSES=1' \
	'-DENABLE_MEDIA_CAPTURE=1' \
	'-DENABLE_OPENTYPE_VERTICAL=1' \
	'-DU_USING_ICU_NAMESPACE=0' \
	'-DSK_ENABLE_INST_COUNT=0' \
	'-DSK_SUPPORT_GPU=1' \
	'-DGR_GL_CUSTOM_SETUP_HEADER="GrGLConfig_chrome.h"' \
	'-DSK_ENABLE_LEGACY_API_ALIASING=1' \
	'-DSK_ATTR_DEPRECATED=SK_NOTHING_ARG1' \
	'-DGR_GL_IGNORE_ES3_MSAA=0' \
	'-DSK_WILL_NEVER_DRAW_PERSPECTIVE_TEXT' \
	'-DSK_SUPPORT_LEGACY_GETTOPDEVICE' \
	'-DSK_SUPPORT_LEGACY_BITMAP_CONFIG' \
	'-DSK_SUPPORT_LEGACY_DEVICE_VIRTUAL_ISOPAQUE' \
	'-DSK_SUPPORT_LEGACY_N32_NAME' \
	'-DSK_SUPPORT_LEGACY_SETCONFIG' \
	'-DSK_IGNORE_ETC1_SUPPORT' \
	'-DSK_SUPPORT_LEGACY_GETTOTALCLIP' \
	'-DSK_BUILD_FOR_ANDROID' \
	'-DSK_USE_POSIX_THREADS' \
	'-DSK_DEFERRED_CANVAS_USES_FACTORIES=1' \
	'-DCHROME_PNG_WRITE_SUPPORT' \
	'-DPNG_USER_CONFIG' \
	'-DCHROME_PNG_READ_PACK_SUPPORT' \
	'-DLIBXML_STATIC' \
	'-DLIBXSLT_STATIC' \
	'-DUSE_OPENSSL=1' \
	'-DUSE_OPENSSL_CERTS=1' \
	'-D__STDC_CONSTANT_MACROS' \
	'-D__STDC_FORMAT_MACROS' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DNDEBUG' \
	'-DNVALGRIND' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=0' \
	'-D_FORTIFY_SOURCE=2'


# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES_Release := \
	$(gyp_shared_intermediate_dir)/shim_headers/ashmem/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(gyp_shared_intermediate_dir) \
	$(LOCAL_PATH)/third_party/WebKit/Source \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/skia/config \
	$(LOCAL_PATH)/third_party/khronos \
	$(LOCAL_PATH)/gpu \
	$(gyp_shared_intermediate_dir)/blink/core \
	$(gyp_shared_intermediate_dir)/blink/modules \
	$(gyp_shared_intermediate_dir)/blink/platform \
	$(gyp_shared_intermediate_dir)/blink/bindings/core/v8 \
	$(gyp_shared_intermediate_dir)/blink/bindings/modules/v8 \
	$(gyp_shared_intermediate_dir)/blink \
	$(LOCAL_PATH)/third_party/angle/include \
	$(PWD)/external/icu4c/common \
	$(PWD)/external/icu4c/i18n \
	$(LOCAL_PATH)/third_party/WebKit \
	$(LOCAL_PATH)/third_party/skia/src/core \
	$(LOCAL_PATH)/third_party/skia/include/core \
	$(LOCAL_PATH)/third_party/skia/include/effects \
	$(LOCAL_PATH)/third_party/skia/include/pdf \
	$(LOCAL_PATH)/third_party/skia/include/gpu \
	$(LOCAL_PATH)/third_party/skia/include/lazy \
	$(LOCAL_PATH)/third_party/skia/include/pathops \
	$(LOCAL_PATH)/third_party/skia/include/pipe \
	$(LOCAL_PATH)/third_party/skia/include/ports \
	$(LOCAL_PATH)/third_party/skia/include/utils \
	$(LOCAL_PATH)/skia/ext \
	$(LOCAL_PATH)/third_party/iccjpeg \
	$(LOCAL_PATH)/third_party/libpng \
	$(LOCAL_PATH)/third_party/libwebp \
	$(LOCAL_PATH)/third_party/libxml/linux/include \
	$(LOCAL_PATH)/third_party/libxml/src/include \
	$(LOCAL_PATH)/third_party/libxslt \
	$(LOCAL_PATH)/third_party/npapi \
	$(LOCAL_PATH)/third_party/npapi/bindings \
	$(LOCAL_PATH)/third_party/ots/include \
	$(LOCAL_PATH)/third_party/qcms/src \
	$(LOCAL_PATH)/third_party/sqlite \
	$(LOCAL_PATH)/third_party/zlib \
	$(LOCAL_PATH)/v8/include \
	$(PWD)/frameworks/wilhelm/include \
	$(PWD)/bionic \
	$(PWD)/external/stlport/stlport


# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS_Release := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wsign-compare \
	-Wno-c++0x-compat \
	-Wno-uninitialized \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo


LOCAL_CFLAGS := $(MY_CFLAGS_$(GYP_CONFIGURATION)) $(MY_DEFS_$(GYP_CONFIGURATION))
LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES_$(GYP_CONFIGURATION))
LOCAL_CPPFLAGS := $(LOCAL_CPPFLAGS_$(GYP_CONFIGURATION))
LOCAL_ASFLAGS := $(LOCAL_CFLAGS)
### Rules for final target.

LOCAL_LDFLAGS_Debug := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,--fatal-warnings \
	-Wl,-z,noexecstack \
	-fPIC \
	-EL \
	-Wl,--no-keep-memory \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,--warn-shared-textrel \
	-Wl,-O1 \
	-Wl,--as-needed


LOCAL_LDFLAGS_Release := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,--fatal-warnings \
	-Wl,-z,noexecstack \
	-fPIC \
	-EL \
	-Wl,--no-keep-memory \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,-O1 \
	-Wl,--as-needed \
	-Wl,--gc-sections \
	-Wl,--warn-shared-textrel


LOCAL_LDFLAGS := $(LOCAL_LDFLAGS_$(GYP_CONFIGURATION))

LOCAL_STATIC_LIBRARIES := \
	skia_skia_library_gyp

# Enable grouping to fix circular references
LOCAL_GROUP_STATIC_LIBRARIES := true

LOCAL_SHARED_LIBRARIES := \
	libstlport \
	libdl

# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_WebKit_Source_core_webcore_html_gyp

# Alias gyp target name.
.PHONY: webcore_html
webcore_html: third_party_WebKit_Source_core_webcore_html_gyp

include $(BUILD_STATIC_LIBRARY)
