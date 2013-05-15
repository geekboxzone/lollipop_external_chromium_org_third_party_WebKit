# This file is generated by gyp; do not edit.

include $(CLEAR_VARS)

LOCAL_MODULE_CLASS := STATIC_LIBRARIES
LOCAL_MODULE := third_party_WebKit_Source_core_core_gyp_webcore_remaining_gyp
LOCAL_MODULE_SUFFIX := .a
LOCAL_MODULE_TAGS := optional
gyp_intermediate_dir := $(call local-intermediates-dir)
gyp_shared_intermediate_dir := $(call intermediates-dir-for,GYP,shared)

# Make sure our deps are built first.
GYP_TARGET_DEPENDENCIES := \
	$(call intermediates-dir-for,GYP,third_party_WebKit_Source_core_core_gyp_webcore_prerequisites_gyp)/webcore_prerequisites.stamp \
	$(call intermediates-dir-for,STATIC_LIBRARIES,skia_skia_gyp)/skia_skia_gyp.a

GYP_GENERATED_OUTPUTS :=

# Make sure our deps and generated files are built first.
LOCAL_ADDITIONAL_DEPENDENCIES := $(GYP_TARGET_DEPENDENCIES) $(GYP_GENERATED_OUTPUTS)

LOCAL_GENERATED_SOURCES :=

GYP_COPIED_SOURCE_ORIGIN_DIRS :=

LOCAL_SRC_FILES := \
	third_party/WebKit/Source/core/accessibility/AXObjectCache.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityARIAGrid.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityARIAGridCell.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityARIAGridRow.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityImageMapLink.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityList.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityListBox.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityListBoxOption.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityMediaControls.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityMenuList.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityMenuListOption.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityMenuListPopup.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityMockObject.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityNodeObject.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityObject.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityProgressIndicator.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityRenderObject.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityScrollView.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityScrollbar.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilitySlider.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilitySpinButton.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilitySVGRoot.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityTable.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityTableCell.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityTableColumn.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityTableHeaderContainer.cpp \
	third_party/WebKit/Source/core/accessibility/AccessibilityTableRow.cpp \
	third_party/WebKit/Source/core/animation/Animation.cpp \
	third_party/WebKit/Source/core/animation/AnimationEffect.cpp \
	third_party/WebKit/Source/core/animation/DocumentTimeline.cpp \
	third_party/WebKit/Source/core/animation/TimedItem.cpp \
	third_party/WebKit/Source/core/css/BasicShapeFunctions.cpp \
	third_party/WebKit/Source/core/css/CSSAspectRatioValue.cpp \
	third_party/WebKit/Source/core/css/CSSBasicShapes.cpp \
	third_party/WebKit/Source/core/css/CSSBorderImage.cpp \
	third_party/WebKit/Source/core/css/CSSBorderImageSliceValue.cpp \
	third_party/WebKit/Source/core/css/CSSCanvasValue.cpp \
	third_party/WebKit/Source/core/css/CSSCalculationValue.cpp \
	third_party/WebKit/Source/core/css/CSSCharsetRule.cpp \
	third_party/WebKit/Source/core/css/CSSComputedStyleDeclaration.cpp \
	third_party/WebKit/Source/core/css/CSSCrossfadeValue.cpp \
	third_party/WebKit/Source/core/css/CSSCursorImageValue.cpp \
	third_party/WebKit/Source/core/css/CSSDefaultStyleSheets.cpp \
	third_party/WebKit/Source/core/css/CSSFontFace.cpp \
	third_party/WebKit/Source/core/css/CSSFontFaceLoadEvent.cpp \
	third_party/WebKit/Source/core/css/CSSFontFaceRule.cpp \
	third_party/WebKit/Source/core/css/CSSFontFaceSource.cpp \
	third_party/WebKit/Source/core/css/CSSFontFaceSrcValue.cpp \
	third_party/WebKit/Source/core/css/CSSFontSelector.cpp \
	third_party/WebKit/Source/core/css/CSSFunctionValue.cpp \
	third_party/WebKit/Source/core/css/CSSGradientValue.cpp \
	third_party/WebKit/Source/core/css/CSSGroupingRule.cpp \
	third_party/WebKit/Source/core/css/CSSHostRule.cpp \
	third_party/WebKit/Source/core/css/CSSImageGeneratorValue.cpp \
	third_party/WebKit/Source/core/css/CSSImageSetValue.cpp \
	third_party/WebKit/Source/core/css/CSSImageValue.cpp \
	third_party/WebKit/Source/core/css/CSSImportRule.cpp \
	third_party/WebKit/Source/core/css/CSSInheritedValue.cpp \
	third_party/WebKit/Source/core/css/CSSInitialValue.cpp \
	third_party/WebKit/Source/core/css/CSSLineBoxContainValue.cpp \
	third_party/WebKit/Source/core/css/CSSMediaRule.cpp \
	third_party/WebKit/Source/core/css/CSSOMUtils.cpp \
	third_party/WebKit/Source/core/css/CSSPageRule.cpp \
	third_party/WebKit/Source/core/css/CSSParser.cpp \
	third_party/WebKit/Source/core/css/CSSParserValues.cpp \
	third_party/WebKit/Source/core/css/CSSPrimitiveValue.cpp \
	third_party/WebKit/Source/core/css/CSSProperty.cpp \
	third_party/WebKit/Source/core/css/CSSPropertySourceData.cpp \
	third_party/WebKit/Source/core/css/CSSReflectValue.cpp \
	third_party/WebKit/Source/core/css/CSSRule.cpp \
	third_party/WebKit/Source/core/css/CSSRuleList.cpp \
	third_party/WebKit/Source/core/css/CSSSegmentedFontFace.cpp \
	third_party/WebKit/Source/core/css/CSSSelector.cpp \
	third_party/WebKit/Source/core/css/CSSSelectorList.cpp \
	third_party/WebKit/Source/core/css/CSSStyleRule.cpp \
	third_party/WebKit/Source/core/css/CSSStyleSheet.cpp \
	third_party/WebKit/Source/core/css/CSSSupportsRule.cpp \
	third_party/WebKit/Source/core/css/CSSTimingFunctionValue.cpp \
	third_party/WebKit/Source/core/css/CSSToStyleMap.cpp \
	third_party/WebKit/Source/core/css/CSSUnicodeRangeValue.cpp \
	third_party/WebKit/Source/core/css/CSSValue.cpp \
	third_party/WebKit/Source/core/css/CSSValueList.cpp \
	third_party/WebKit/Source/core/css/CSSValuePool.cpp \
	third_party/WebKit/Source/core/css/DeprecatedStyleBuilder.cpp \
	third_party/WebKit/Source/core/css/DOMWindowCSS.cpp \
	third_party/WebKit/Source/core/css/DocumentRuleSets.cpp \
	third_party/WebKit/Source/core/css/ElementRuleCollector.cpp \
	third_party/WebKit/Source/core/css/FontFeatureValue.cpp \
	third_party/WebKit/Source/core/css/FontLoader.cpp \
	third_party/WebKit/Source/core/css/FontValue.cpp \
	third_party/WebKit/Source/core/css/InspectorCSSOMWrappers.cpp \
	third_party/WebKit/Source/core/css/LengthFunctions.cpp \
	third_party/WebKit/Source/core/css/MediaFeatureNames.cpp \
	third_party/WebKit/Source/core/css/MediaList.cpp \
	third_party/WebKit/Source/core/css/MediaQuery.cpp \
	third_party/WebKit/Source/core/css/MediaQueryEvaluator.cpp \
	third_party/WebKit/Source/core/css/MediaQueryExp.cpp \
	third_party/WebKit/Source/core/css/MediaQueryList.cpp \
	third_party/WebKit/Source/core/css/MediaQueryListListener.cpp \
	third_party/WebKit/Source/core/css/MediaQueryMatcher.cpp \
	third_party/WebKit/Source/core/css/PageRuleCollector.cpp \
	third_party/WebKit/Source/core/css/PropertySetCSSStyleDeclaration.cpp \
	third_party/WebKit/Source/core/css/RGBColor.cpp \
	third_party/WebKit/Source/core/css/RuleFeature.cpp \
	third_party/WebKit/Source/core/css/RuleSet.cpp \
	third_party/WebKit/Source/core/css/SVGCSSComputedStyleDeclaration.cpp \
	third_party/WebKit/Source/core/css/SVGCSSParser.cpp \
	third_party/WebKit/Source/core/css/SVGCSSStyleSelector.cpp \
	third_party/WebKit/Source/core/css/SelectorChecker.cpp \
	third_party/WebKit/Source/core/css/SelectorCheckerFastPath.cpp \
	third_party/WebKit/Source/core/css/SelectorFilter.cpp \
	third_party/WebKit/Source/core/css/ShadowValue.cpp \
	third_party/WebKit/Source/core/css/StyleInvalidationAnalysis.cpp \
	third_party/WebKit/Source/core/css/StyleMedia.cpp \
	third_party/WebKit/Source/core/css/StylePropertySerializer.cpp \
	third_party/WebKit/Source/core/css/StylePropertySet.cpp \
	third_party/WebKit/Source/core/css/StylePropertyShorthand.cpp \
	third_party/WebKit/Source/core/css/StyleRule.cpp \
	third_party/WebKit/Source/core/css/StyleRuleImport.cpp \
	third_party/WebKit/Source/core/css/StyleSheet.cpp \
	third_party/WebKit/Source/core/css/StyleSheetContents.cpp \
	third_party/WebKit/Source/core/css/StyleSheetList.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSArrayFunctionValue.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSFilterRule.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSFilterValue.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSKeyframeRule.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSKeyframesRule.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSMatrix.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSMixFunctionValue.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSRegionRule.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSShaderValue.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSSVGDocumentValue.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSTransformValue.cpp \
	third_party/WebKit/Source/core/css/WebKitCSSViewportRule.cpp \
	third_party/WebKit/Source/core/css/resolver/FilterOperationResolver.cpp \
	third_party/WebKit/Source/core/css/resolver/ScopedStyleResolver.cpp \
	third_party/WebKit/Source/core/css/resolver/StyleResolver.cpp \
	third_party/WebKit/Source/core/css/resolver/StyleResolverState.cpp \
	third_party/WebKit/Source/core/css/resolver/TransformBuilder.cpp \
	third_party/WebKit/Source/core/css/resolver/ViewportStyleResolver.cpp \
	third_party/WebKit/Source/core/editing/AppendNodeCommand.cpp \
	third_party/WebKit/Source/core/editing/ApplyBlockElementCommand.cpp \
	third_party/WebKit/Source/core/editing/ApplyStyleCommand.cpp \
	third_party/WebKit/Source/core/editing/BreakBlockquoteCommand.cpp \
	third_party/WebKit/Source/core/editing/CompositeEditCommand.cpp \
	third_party/WebKit/Source/core/editing/CreateLinkCommand.cpp \
	third_party/WebKit/Source/core/editing/DeleteFromTextNodeCommand.cpp \
	third_party/WebKit/Source/core/editing/DeleteSelectionCommand.cpp \
	third_party/WebKit/Source/core/editing/EditCommand.cpp \
	third_party/WebKit/Source/core/editing/EditingStyle.cpp \
	third_party/WebKit/Source/core/editing/Editor.cpp \
	third_party/WebKit/Source/core/editing/EditorCommand.cpp \
	third_party/WebKit/Source/core/editing/FormatBlockCommand.cpp \
	third_party/WebKit/Source/core/editing/FrameSelection.cpp \
	third_party/WebKit/Source/core/editing/HTMLInterchange.cpp \
	third_party/WebKit/Source/core/editing/IndentOutdentCommand.cpp \
	third_party/WebKit/Source/core/editing/InsertIntoTextNodeCommand.cpp \
	third_party/WebKit/Source/core/editing/InsertLineBreakCommand.cpp \
	third_party/WebKit/Source/core/editing/InsertListCommand.cpp \
	third_party/WebKit/Source/core/editing/InsertNodeBeforeCommand.cpp \
	third_party/WebKit/Source/core/editing/InsertParagraphSeparatorCommand.cpp \
	third_party/WebKit/Source/core/editing/InsertTextCommand.cpp \
	third_party/WebKit/Source/core/editing/MarkupAccumulator.cpp \
	third_party/WebKit/Source/core/editing/MergeIdenticalElementsCommand.cpp \
	third_party/WebKit/Source/core/editing/ModifySelectionListLevel.cpp \
	third_party/WebKit/Source/core/editing/MoveSelectionCommand.cpp \
	third_party/WebKit/Source/core/editing/RemoveCSSPropertyCommand.cpp \
	third_party/WebKit/Source/core/editing/RemoveFormatCommand.cpp \
	third_party/WebKit/Source/core/editing/RemoveNodeCommand.cpp \
	third_party/WebKit/Source/core/editing/RemoveNodePreservingChildrenCommand.cpp \
	third_party/WebKit/Source/core/editing/RenderedPosition.cpp \
	third_party/WebKit/Source/core/editing/ReplaceNodeWithSpanCommand.cpp \
	third_party/WebKit/Source/core/editing/ReplaceSelectionCommand.cpp \
	third_party/WebKit/Source/core/editing/SetNodeAttributeCommand.cpp \
	third_party/WebKit/Source/core/editing/SetSelectionCommand.cpp \
	third_party/WebKit/Source/core/editing/SimplifyMarkupCommand.cpp \
	third_party/WebKit/Source/core/editing/SmartReplaceICU.cpp \
	third_party/WebKit/Source/core/editing/SpellChecker.cpp \
	third_party/WebKit/Source/core/editing/SpellingCorrectionCommand.cpp \
	third_party/WebKit/Source/core/editing/SplitElementCommand.cpp \
	third_party/WebKit/Source/core/editing/SplitTextNodeCommand.cpp \
	third_party/WebKit/Source/core/editing/SplitTextNodeContainingElementCommand.cpp \
	third_party/WebKit/Source/core/editing/SurroundingText.cpp \
	third_party/WebKit/Source/core/editing/TextCheckingHelper.cpp \
	third_party/WebKit/Source/core/editing/TextInsertionBaseCommand.cpp \
	third_party/WebKit/Source/core/editing/TextIterator.cpp \
	third_party/WebKit/Source/core/editing/TypingCommand.cpp \
	third_party/WebKit/Source/core/editing/UnlinkCommand.cpp \
	third_party/WebKit/Source/core/editing/VisiblePosition.cpp \
	third_party/WebKit/Source/core/editing/VisibleSelection.cpp \
	third_party/WebKit/Source/core/editing/VisibleUnits.cpp \
	third_party/WebKit/Source/core/editing/WrapContentsInDummySpanCommand.cpp \
	third_party/WebKit/Source/core/editing/chromium/EditorChromium.cpp \
	third_party/WebKit/Source/core/editing/chromium/FrameSelectionChromium.cpp \
	third_party/WebKit/Source/core/editing/htmlediting.cpp \
	third_party/WebKit/Source/core/editing/markup.cpp \
	third_party/WebKit/Source/core/fileapi/Blob.cpp \
	third_party/WebKit/Source/core/fileapi/BlobBuilder.cpp \
	third_party/WebKit/Source/core/fileapi/BlobURL.cpp \
	third_party/WebKit/Source/core/fileapi/File.cpp \
	third_party/WebKit/Source/core/fileapi/FileException.cpp \
	third_party/WebKit/Source/core/fileapi/FileList.cpp \
	third_party/WebKit/Source/core/fileapi/FileReader.cpp \
	third_party/WebKit/Source/core/fileapi/FileReaderLoader.cpp \
	third_party/WebKit/Source/core/fileapi/FileReaderSync.cpp \
	third_party/WebKit/Source/core/fileapi/ThreadableBlobRegistry.cpp \
	third_party/WebKit/Source/core/history/BackForwardController.cpp \
	third_party/WebKit/Source/core/history/HistoryItem.cpp \
	third_party/WebKit/Source/core/inspector/ConsoleMessage.cpp \
	third_party/WebKit/Source/core/inspector/ContentSearchUtils.cpp \
	third_party/WebKit/Source/core/inspector/DOMEditor.cpp \
	third_party/WebKit/Source/core/inspector/DOMPatchSupport.cpp \
	third_party/WebKit/Source/core/inspector/HeapGraphSerializer.cpp \
	third_party/WebKit/Source/core/inspector/IdentifiersFactory.cpp \
	third_party/WebKit/Source/core/inspector/InjectedScript.cpp \
	third_party/WebKit/Source/core/inspector/InjectedScriptBase.cpp \
	third_party/WebKit/Source/core/inspector/InjectedScriptCanvasModule.cpp \
	third_party/WebKit/Source/core/inspector/InjectedScriptHost.cpp \
	third_party/WebKit/Source/core/inspector/InjectedScriptManager.cpp \
	third_party/WebKit/Source/core/inspector/InjectedScriptModule.cpp \
	third_party/WebKit/Source/core/inspector/InspectorAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorApplicationCacheAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorBaseAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorCSSAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorCanvasAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorClient.cpp \
	third_party/WebKit/Source/core/inspector/InspectorConsoleAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorController.cpp \
	third_party/WebKit/Source/core/inspector/InspectorCounters.cpp \
	third_party/WebKit/Source/core/inspector/InspectorDOMAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorDOMDebuggerAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorDOMStorageAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorDatabaseAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorDatabaseResource.cpp \
	third_party/WebKit/Source/core/inspector/InspectorDebuggerAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorFileSystemAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorFrontendHost.cpp \
	third_party/WebKit/Source/core/inspector/InspectorHeapProfilerAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorHistory.cpp \
	third_party/WebKit/Source/core/inspector/InspectorIndexedDBAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorInputAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorInstrumentation.cpp \
	third_party/WebKit/Source/core/inspector/InspectorLayerTreeAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorMemoryAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorOverlay.cpp \
	third_party/WebKit/Source/core/inspector/InspectorPageAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorProfilerAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorResourceAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorRuntimeAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorState.cpp \
	third_party/WebKit/Source/core/inspector/InspectorStyleSheet.cpp \
	third_party/WebKit/Source/core/inspector/InspectorStyleTextEditor.cpp \
	third_party/WebKit/Source/core/inspector/InspectorTimelineAgent.cpp \
	third_party/WebKit/Source/core/inspector/InspectorValues.cpp \
	third_party/WebKit/Source/core/inspector/InspectorWorkerAgent.cpp \
	third_party/WebKit/Source/core/inspector/InstrumentingAgents.cpp \
	third_party/WebKit/Source/core/inspector/JavaScriptCallFrame.cpp \
	third_party/WebKit/Source/core/inspector/MemoryInstrumentationImpl.cpp \
	third_party/WebKit/Source/core/inspector/NetworkResourcesData.cpp \
	third_party/WebKit/Source/core/inspector/PageConsoleAgent.cpp \
	third_party/WebKit/Source/core/inspector/PageDebuggerAgent.cpp \
	third_party/WebKit/Source/core/inspector/PageRuntimeAgent.cpp \
	third_party/WebKit/Source/core/inspector/ScriptArguments.cpp \
	third_party/WebKit/Source/core/inspector/ScriptCallFrame.cpp \
	third_party/WebKit/Source/core/inspector/ScriptCallStack.cpp \
	third_party/WebKit/Source/core/inspector/ScriptProfile.cpp \
	third_party/WebKit/Source/core/inspector/ScriptProfileNode.cpp \
	third_party/WebKit/Source/core/inspector/TimelineRecordFactory.cpp \
	third_party/WebKit/Source/core/inspector/TimelineTraceEventProcessor.cpp \
	third_party/WebKit/Source/core/inspector/WorkerConsoleAgent.cpp \
	third_party/WebKit/Source/core/inspector/WorkerDebuggerAgent.cpp \
	third_party/WebKit/Source/core/inspector/WorkerInspectorController.cpp \
	third_party/WebKit/Source/core/inspector/WorkerRuntimeAgent.cpp \
	third_party/WebKit/Source/core/loader/CachedMetadata.cpp \
	third_party/WebKit/Source/core/loader/CookieJar.cpp \
	third_party/WebKit/Source/core/loader/CrossOriginAccessControl.cpp \
	third_party/WebKit/Source/core/loader/CrossOriginPreflightResultCache.cpp \
	third_party/WebKit/Source/core/loader/DocumentLoadTiming.cpp \
	third_party/WebKit/Source/core/loader/DocumentLoader.cpp \
	third_party/WebKit/Source/core/loader/DocumentThreadableLoader.cpp \
	third_party/WebKit/Source/core/loader/DocumentWriter.cpp \
	third_party/WebKit/Source/core/loader/EmptyClients.cpp \
	third_party/WebKit/Source/core/loader/FormState.cpp \
	third_party/WebKit/Source/core/loader/FormSubmission.cpp \
	third_party/WebKit/Source/core/loader/FrameLoadRequest.cpp \
	third_party/WebKit/Source/core/loader/FrameLoader.cpp \
	third_party/WebKit/Source/core/loader/FrameLoaderStateMachine.cpp \
	third_party/WebKit/Source/core/loader/HistoryController.cpp \
	third_party/WebKit/Source/core/loader/IconController.cpp \
	third_party/WebKit/Source/core/loader/ImageLoader.cpp \
	third_party/WebKit/Source/core/loader/LinkLoader.cpp \
	third_party/WebKit/Source/core/loader/MixedContentChecker.cpp \
	third_party/WebKit/Source/core/loader/NavigationAction.cpp \
	third_party/WebKit/Source/core/loader/NavigationScheduler.cpp \
	third_party/WebKit/Source/core/loader/PingLoader.cpp \
	third_party/WebKit/Source/core/loader/Prerenderer.cpp \
	third_party/WebKit/Source/core/loader/PrerendererClient.cpp \
	third_party/WebKit/Source/core/loader/ProgressTracker.cpp \
	third_party/WebKit/Source/core/loader/ResourceLoadNotifier.cpp \
	third_party/WebKit/Source/core/loader/ResourceLoader.cpp \
	third_party/WebKit/Source/core/loader/SinkDocument.cpp \
	third_party/WebKit/Source/core/loader/SubframeLoader.cpp \
	third_party/WebKit/Source/core/loader/SubstituteData.cpp \
	third_party/WebKit/Source/core/loader/TextResourceDecoder.cpp \
	third_party/WebKit/Source/core/loader/TextTrackLoader.cpp \
	third_party/WebKit/Source/core/loader/ThreadableLoader.cpp \
	third_party/WebKit/Source/core/loader/UniqueIdentifier.cpp \
	third_party/WebKit/Source/core/loader/WorkerThreadableLoader.cpp \
	third_party/WebKit/Source/core/loader/appcache/DOMApplicationCache.cpp \
	third_party/WebKit/Source/core/loader/archive/ArchiveResource.cpp \
	third_party/WebKit/Source/core/loader/archive/ArchiveResourceCollection.cpp \
	third_party/WebKit/Source/core/loader/archive/MHTMLArchive.cpp \
	third_party/WebKit/Source/core/loader/archive/MHTMLParser.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedCSSStyleSheet.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedFont.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedImage.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedRawResource.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedResource.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedResourceHandle.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedResourceLoader.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedResourceRequest.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedResourceRequestInitiators.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedScript.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedShader.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedSVGDocument.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedTextTrack.cpp \
	third_party/WebKit/Source/core/loader/cache/CachedXSLStyleSheet.cpp \
	third_party/WebKit/Source/core/loader/cache/MemoryCache.cpp \
	third_party/WebKit/Source/core/page/AutoscrollController.cpp \
	third_party/WebKit/Source/core/page/BarProp.cpp \
	third_party/WebKit/Source/core/page/CaptionUserPreferences.cpp \
	third_party/WebKit/Source/core/page/Chrome.cpp \
	third_party/WebKit/Source/core/page/Console.cpp \
	third_party/WebKit/Source/core/page/ContentSecurityPolicy.cpp \
	third_party/WebKit/Source/core/page/ContextMenuController.cpp \
	third_party/WebKit/Source/core/page/Crypto.cpp \
	third_party/WebKit/Source/core/page/DeviceController.cpp \
	third_party/WebKit/Source/core/page/DiagnosticLoggingKeys.cpp \
	third_party/WebKit/Source/core/page/DOMSecurityPolicy.cpp \
	third_party/WebKit/Source/core/page/DOMSelection.cpp \
	third_party/WebKit/Source/core/page/DOMTimer.cpp \
	third_party/WebKit/Source/core/page/DOMWindow.cpp \
	third_party/WebKit/Source/core/page/DOMWindowPagePopup.cpp \
	third_party/WebKit/Source/core/page/DOMWindowProperty.cpp \
	third_party/WebKit/Source/core/page/DragController.cpp \
	third_party/WebKit/Source/core/page/EventHandler.cpp \
	third_party/WebKit/Source/core/page/EventSource.cpp \
	third_party/WebKit/Source/core/page/FocusController.cpp \
	third_party/WebKit/Source/core/page/Frame.cpp \
	third_party/WebKit/Source/core/page/FrameActionScheduler.cpp \
	third_party/WebKit/Source/core/page/FrameDestructionObserver.cpp \
	third_party/WebKit/Source/core/page/FrameTree.cpp \
	third_party/WebKit/Source/core/page/FrameView.cpp \
	third_party/WebKit/Source/core/page/GroupSettings.cpp \
	third_party/WebKit/Source/core/page/History.cpp \
	third_party/WebKit/Source/core/page/Location.cpp \
	third_party/WebKit/Source/core/page/MemoryInfo.cpp \
	third_party/WebKit/Source/core/page/MouseEventWithHitTestResults.cpp \
	third_party/WebKit/Source/core/page/Navigator.cpp \
	third_party/WebKit/Source/core/page/NavigatorBase.cpp \
	third_party/WebKit/Source/core/page/Page.cpp \
	third_party/WebKit/Source/core/page/PageConsole.cpp \
	third_party/WebKit/Source/core/page/PageGroup.cpp \
	third_party/WebKit/Source/core/page/PageGroupLoadDeferrer.cpp \
	third_party/WebKit/Source/core/page/PagePopupController.cpp \
	third_party/WebKit/Source/core/page/PagePopupClient.cpp \
	third_party/WebKit/Source/core/page/PageSerializer.cpp \
	third_party/WebKit/Source/core/page/PageVisibilityState.cpp \
	third_party/WebKit/Source/core/page/Performance.cpp \
	third_party/WebKit/Source/core/page/PerformanceEntry.cpp \
	third_party/WebKit/Source/core/page/PerformanceNavigation.cpp \
	third_party/WebKit/Source/core/page/PerformanceResourceTiming.cpp \
	third_party/WebKit/Source/core/page/PerformanceTiming.cpp \
	third_party/WebKit/Source/core/page/PerformanceUserTiming.cpp \
	third_party/WebKit/Source/core/page/PointerLockController.cpp \
	third_party/WebKit/Source/core/page/PrintContext.cpp \
	third_party/WebKit/Source/core/page/RuntimeCSSEnabled.cpp \
	third_party/WebKit/Source/core/page/RuntimeEnabledFeaturesCustom.cpp \
	third_party/WebKit/Source/core/page/Screen.cpp \
	third_party/WebKit/Source/core/page/Settings.cpp \
	third_party/WebKit/Source/core/page/SpatialNavigation.cpp \
	third_party/WebKit/Source/core/page/SpeechInput.cpp \
	third_party/WebKit/Source/core/page/SpeechInputEvent.cpp \
	third_party/WebKit/Source/core/page/SpeechInputResult.cpp \
	third_party/WebKit/Source/core/page/SpeechInputResultList.cpp \
	third_party/WebKit/Source/core/page/SuspendableTimer.cpp \
	third_party/WebKit/Source/core/page/TouchAdjustment.cpp \
	third_party/WebKit/Source/core/page/TouchDisambiguation.cpp \
	third_party/WebKit/Source/core/page/UseCounter.cpp \
	third_party/WebKit/Source/core/page/UserContentURLPattern.cpp \
	third_party/WebKit/Source/core/page/WindowFeatures.cpp \
	third_party/WebKit/Source/core/page/WindowFocusAllowedIndicator.cpp \
	third_party/WebKit/Source/core/page/WorkerNavigator.cpp \
	third_party/WebKit/Source/core/page/animation/AnimationBase.cpp \
	third_party/WebKit/Source/core/page/animation/AnimationController.cpp \
	third_party/WebKit/Source/core/page/animation/CompositeAnimation.cpp \
	third_party/WebKit/Source/core/page/animation/CSSPropertyAnimation.cpp \
	third_party/WebKit/Source/core/page/animation/ImplicitAnimation.cpp \
	third_party/WebKit/Source/core/page/animation/KeyframeAnimation.cpp \
	third_party/WebKit/Source/core/page/scrolling/ScrollingConstraints.cpp \
	third_party/WebKit/Source/core/page/scrolling/ScrollingCoordinator.cpp \
	third_party/WebKit/Source/core/plugins/DOMMimeType.cpp \
	third_party/WebKit/Source/core/plugins/DOMMimeTypeArray.cpp \
	third_party/WebKit/Source/core/plugins/DOMPlugin.cpp \
	third_party/WebKit/Source/core/plugins/DOMPluginArray.cpp \
	third_party/WebKit/Source/core/plugins/IFrameShimSupport.cpp \
	third_party/WebKit/Source/core/plugins/PluginData.cpp \
	third_party/WebKit/Source/core/plugins/PluginListBuilder.cpp \
	third_party/WebKit/Source/core/storage/Storage.cpp \
	third_party/WebKit/Source/core/storage/StorageEvent.cpp \
	third_party/WebKit/Source/core/workers/AbstractWorker.cpp \
	third_party/WebKit/Source/core/workers/DedicatedWorkerContext.cpp \
	third_party/WebKit/Source/core/workers/DedicatedWorkerThread.cpp \
	third_party/WebKit/Source/core/workers/SharedWorker.cpp \
	third_party/WebKit/Source/core/workers/SharedWorkerContext.cpp \
	third_party/WebKit/Source/core/workers/SharedWorkerThread.cpp \
	third_party/WebKit/Source/core/workers/Worker.cpp \
	third_party/WebKit/Source/core/workers/WorkerContext.cpp \
	third_party/WebKit/Source/core/workers/WorkerContextProxy.cpp \
	third_party/WebKit/Source/core/workers/WorkerEventQueue.cpp \
	third_party/WebKit/Source/core/workers/WorkerLocation.cpp \
	third_party/WebKit/Source/core/workers/WorkerMessagingProxy.cpp \
	third_party/WebKit/Source/core/workers/WorkerRunLoop.cpp \
	third_party/WebKit/Source/core/workers/WorkerScriptLoader.cpp \
	third_party/WebKit/Source/core/workers/WorkerThread.cpp \
	third_party/WebKit/Source/core/xml/parser/XMLDocumentParser.cpp \
	third_party/WebKit/Source/core/xml/parser/XMLDocumentParserScope.cpp \
	third_party/WebKit/Source/core/xml/DOMParser.cpp \
	third_party/WebKit/Source/core/xml/NativeXPathNSResolver.cpp \
	third_party/WebKit/Source/core/xml/XMLErrors.cpp \
	third_party/WebKit/Source/core/xml/XMLHttpRequest.cpp \
	third_party/WebKit/Source/core/xml/XMLHttpRequestProgressEventThrottle.cpp \
	third_party/WebKit/Source/core/xml/XMLHttpRequestUpload.cpp \
	third_party/WebKit/Source/core/xml/XMLSerializer.cpp \
	third_party/WebKit/Source/core/xml/XMLTreeViewer.cpp \
	third_party/WebKit/Source/core/xml/XPathEvaluator.cpp \
	third_party/WebKit/Source/core/xml/XPathException.cpp \
	third_party/WebKit/Source/core/xml/XPathExpression.cpp \
	third_party/WebKit/Source/core/xml/XPathExpressionNode.cpp \
	third_party/WebKit/Source/core/xml/XPathFunctions.cpp \
	third_party/WebKit/Source/core/xml/XPathNSResolver.cpp \
	third_party/WebKit/Source/core/xml/XPathNodeSet.cpp \
	third_party/WebKit/Source/core/xml/XPathParser.cpp \
	third_party/WebKit/Source/core/xml/XPathPath.cpp \
	third_party/WebKit/Source/core/xml/XPathPredicate.cpp \
	third_party/WebKit/Source/core/xml/XPathResult.cpp \
	third_party/WebKit/Source/core/xml/XPathStep.cpp \
	third_party/WebKit/Source/core/xml/XPathUtil.cpp \
	third_party/WebKit/Source/core/xml/XPathValue.cpp \
	third_party/WebKit/Source/core/xml/XPathVariableReference.cpp \
	third_party/WebKit/Source/core/xml/XSLImportRule.cpp \
	third_party/WebKit/Source/core/xml/XSLStyleSheetLibxslt.cpp \
	third_party/WebKit/Source/core/xml/XSLTExtensions.cpp \
	third_party/WebKit/Source/core/xml/XSLTProcessor.cpp \
	third_party/WebKit/Source/core/xml/XSLTProcessorLibxslt.cpp \
	third_party/WebKit/Source/core/xml/XSLTUnicodeSort.cpp


# Flags passed to both C and C++ files.
MY_CFLAGS := \
	--param=ssp-buffer-size=4 \
	-fno-exceptions \
	-fno-strict-aliasing \
	-Wno-unused-parameter \
	-Wno-missing-field-initializers \
	-fvisibility=hidden \
	-pipe \
	-fPIC \
	-fno-strict-aliasing \
	-Wno-format \
	-m32 \
	-mmmx \
	-march=pentium4 \
	-msse2 \
	-mfpmath=sse \
	-fuse-ld=gold \
	-ffunction-sections \
	-funwind-tables \
	-g \
	-fno-short-enums \
	-finline-limit=64 \
	-Wa,--noexecstack \
	-U_FORTIFY_SOURCE \
	-Wno-extra \
	-Wno-ignored-qualifiers \
	-Wno-type-limits \
	-Wno-address \
	-Wno-format-security \
	-Wno-return-type \
	-Wno-sequence-point \
	-fno-stack-protector \
	-Os \
	-g \
	-fomit-frame-pointer \
	-fdata-sections \
	-ffunction-sections

MY_CFLAGS_C :=

MY_DEFS := \
	'-D_FILE_OFFSET_BITS=64' \
	'-DUSE_LINUX_BREAKPAD' \
	'-DNO_TCMALLOC' \
	'-DDISABLE_NACL' \
	'-DCHROMIUM_BUILD' \
	'-DUSE_LIBJPEG_TURBO=1' \
	'-DUSE_PROPRIETARY_CODECS' \
	'-DENABLE_GPU=1' \
	'-DUSE_OPENSSL=1' \
	'-DENABLE_EGLIMAGE=1' \
	'-DENABLE_LANGUAGE_DETECTION=1' \
	'-DWEBCORE_NAVIGATOR_VENDOR="Google Inc."' \
	'-DWEBKIT_IMPLEMENTATION=1' \
	'-DENABLE_3D_PLUGIN=1' \
	'-DENABLE_BATTERY_STATUS=0' \
	'-DENABLE_CANVAS_USES_MAILBOX=0' \
	'-DENABLE_CSS3_TEXT=0' \
	'-DENABLE_CSS_DEVICE_ADAPTATION=0' \
	'-DENABLE_CSS_EXCLUSIONS=1' \
	'-DENABLE_CSS_REGIONS=1' \
	'-DENABLE_CUSTOM_SCHEME_HANDLER=0' \
	'-DENABLE_ENCRYPTED_MEDIA=1' \
	'-DENABLE_SVG=1' \
	'-DENABLE_SVG_FONTS=1' \
	'-DENABLE_TOUCH_ICON_LOADING=1' \
	'-DENABLE_WEBGL=1' \
	'-DENABLE_XHR_TIMEOUT=0' \
	'-DWTF_USE_CONCATENATED_IMPULSE_RESPONSES=1' \
	'-DENABLE_CALENDAR_PICKER=0' \
	'-DENABLE_DATALIST_ELEMENT=0' \
	'-DENABLE_FAST_MOBILE_SCROLLING=1' \
	'-DENABLE_INPUT_SPEECH=0' \
	'-DENABLE_INPUT_TYPE_COLOR=0' \
	'-DENABLE_LEGACY_NOTIFICATIONS=0' \
	'-DENABLE_MEDIA_CAPTURE=1' \
	'-DENABLE_NOTIFICATIONS=0' \
	'-DENABLE_ORIENTATION_EVENTS=1' \
	'-DENABLE_PAGE_POPUP=0' \
	'-DENABLE_PRINTING=0' \
	'-DENABLE_NAVIGATOR_CONTENT_UTILS=0' \
	'-DWTF_USE_NATIVE_FULLSCREEN_VIDEO=1' \
	'-DENABLE_8BIT_TEXTRUN=1' \
	'-DENABLE_BINDING_INTEGRITY=1' \
	'-DENABLE_OPENTYPE_VERTICAL=1' \
	'-DWTF_USE_HARFBUZZ=1' \
	'-DU_USING_ICU_NAMESPACE=0' \
	'-DSK_BUILD_NO_IMAGE_ENCODE' \
	'-DSK_DEFERRED_CANVAS_USES_GPIPE=1' \
	'-DGR_GL_CUSTOM_SETUP_HEADER="GrGLConfig_chrome.h"' \
	'-DGR_AGGRESSIVE_SHADER_OPTS=1' \
	'-DSK_ENABLE_INST_COUNT=0' \
	'-DSK_USE_POSIX_THREADS' \
	'-DSK_BUILD_FOR_ANDROID' \
	'-DCHROME_PNG_WRITE_SUPPORT' \
	'-DPNG_USER_CONFIG' \
	'-DLIBXML_STATIC' \
	'-DLIBXSLT_STATIC' \
	'-DUSE_SYSTEM_LIBJPEG' \
	'-DANDROID' \
	'-D__GNU_SOURCE=1' \
	'-DUSE_STLPORT=1' \
	'-D_STLP_USE_PTR_SPECIALIZATIONS=1' \
	'-DCHROME_BUILD_ID=""' \
	'-DDYNAMIC_ANNOTATIONS_ENABLED=1' \
	'-DWTF_USE_DYNAMIC_ANNOTATIONS=1' \
	'-D_DEBUG'

LOCAL_CFLAGS := $(MY_CFLAGS_C) $(MY_CFLAGS) $(MY_DEFS)

# Include paths placed before CFLAGS/CPPFLAGS
LOCAL_C_INCLUDES := \
	$(gyp_shared_intermediate_dir)/shim_headers/icui18n/target \
	$(gyp_shared_intermediate_dir)/shim_headers/icuuc/target \
	$(gyp_shared_intermediate_dir)/shim_headers/ashmem/target \
	$(LOCAL_PATH)/third_party/khronos \
	$(LOCAL_PATH)/gpu \
	$(LOCAL_PATH) \
	$(LOCAL_PATH)/third_party \
	$(LOCAL_PATH)/third_party/WebKit/Source \
	$(gyp_shared_intermediate_dir)/webkit \
	$(gyp_shared_intermediate_dir)/webkit/bindings \
	$(LOCAL_PATH)/third_party/angle/include/GLSLANG \
	$(LOCAL_PATH)/third_party/WebKit/Source/Platform/chromium \
	$(GYP_ABS_ANDROID_TOP_DIR)/external/icu4c/common \
	$(GYP_ABS_ANDROID_TOP_DIR)/external/icu4c/i18n \
	$(LOCAL_PATH)/skia/config \
	$(LOCAL_PATH)/third_party/skia/src/core \
	$(LOCAL_PATH)/third_party/skia/include/config \
	$(LOCAL_PATH)/third_party/skia/include/core \
	$(LOCAL_PATH)/third_party/skia/include/effects \
	$(LOCAL_PATH)/third_party/skia/include/pdf \
	$(LOCAL_PATH)/third_party/skia/include/gpu \
	$(LOCAL_PATH)/third_party/skia/include/gpu/gl \
	$(LOCAL_PATH)/third_party/skia/include/pathops \
	$(LOCAL_PATH)/third_party/skia/include/pipe \
	$(LOCAL_PATH)/third_party/skia/include/ports \
	$(LOCAL_PATH)/third_party/skia/include/utils \
	$(LOCAL_PATH)/skia/ext \
	$(LOCAL_PATH)/third_party/iccjpeg \
	$(LOCAL_PATH)/third_party/leveldatabase/src/include \
	$(LOCAL_PATH)/third_party/leveldatabase/src \
	$(LOCAL_PATH)/third_party/leveldatabase \
	$(LOCAL_PATH)/third_party/libwebp \
	$(LOCAL_PATH)/third_party/libpng \
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
	$(GYP_ABS_ANDROID_TOP_DIR)/external/jpeg \
	$(GYP_ABS_ANDROID_TOP_DIR)/frameworks/wilhelm/include \
	$(GYP_ABS_ANDROID_TOP_DIR)/bionic \
	$(GYP_ABS_ANDROID_TOP_DIR)/external/stlport/stlport

LOCAL_C_INCLUDES := $(GYP_COPIED_SOURCE_ORIGIN_DIRS) $(LOCAL_C_INCLUDES)

# Flags passed to only C++ (and not C) files.
LOCAL_CPPFLAGS := \
	-fno-rtti \
	-fno-threadsafe-statics \
	-fvisibility-inlines-hidden \
	-Wno-c++0x-compat \
	-Wno-deprecated \
	-Wno-error=c++0x-compat \
	-Wno-non-virtual-dtor \
	-Wno-sign-promo \
	-Wno-non-virtual-dtor

### Rules for final target.

LOCAL_LDFLAGS := \
	-Wl,-z,now \
	-Wl,-z,relro \
	-Wl,-z,noexecstack \
	-fPIC \
	-m32 \
	-fuse-ld=gold \
	-nostdlib \
	-Wl,--no-undefined \
	-Wl,--exclude-libs=ALL \
	-Wl,--gc-sections \
	-Wl,-O1 \
	-Wl,--as-needed


LOCAL_STATIC_LIBRARIES := \
	skia_skia_gyp

# Enable grouping to fix circular references
LOCAL_GROUP_STATIC_LIBRARIES := true

LOCAL_SHARED_LIBRARIES := \
	libstlport \
	libdl

# Add target alias to "gyp_all_modules" target.
.PHONY: gyp_all_modules
gyp_all_modules: third_party_WebKit_Source_core_core_gyp_webcore_remaining_gyp

# Alias gyp target name.
.PHONY: webcore_remaining
webcore_remaining: third_party_WebKit_Source_core_core_gyp_webcore_remaining_gyp

include $(BUILD_STATIC_LIBRARY)
