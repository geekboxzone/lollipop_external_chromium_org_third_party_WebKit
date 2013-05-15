/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 * Copyright (C) 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "Internals.h"

#include "HTMLNames.h"
#include "InspectorFrontendClientLocal.h"
#include "InternalRuntimeFlags.h"
#include "InternalSettings.h"
#include "MallocStatistics.h"
#include "MockPagePopupDriver.h"
#include "RuntimeEnabledFeatures.h"
#include "TypeConversions.h"
#include "bindings/v8/SerializedScriptValue.h"
#include "core/css/StyleSheetContents.h"
#include "core/dom/ClientRect.h"
#include "core/dom/ClientRectList.h"
#include "core/dom/DOMStringList.h"
#include "core/dom/Document.h"
#include "core/dom/DocumentMarker.h"
#include "core/dom/DocumentMarkerController.h"
#include "core/dom/Element.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/NodeRenderingContext.h"
#include "core/dom/PseudoElement.h"
#include "core/dom/Range.h"
#include "core/dom/StaticNodeList.h"
#include "core/dom/TreeScope.h"
#include "core/dom/ViewportArguments.h"
#include "core/dom/shadow/ComposedShadowTreeWalker.h"
#include "core/dom/shadow/ContentDistributor.h"
#include "core/dom/shadow/ElementShadow.h"
#include "core/dom/shadow/SelectRuleFeatureSet.h"
#include "core/dom/shadow/ShadowRoot.h"
#include "core/editing/Editor.h"
#include "core/editing/SpellChecker.h"
#include "core/editing/TextIterator.h"
#include "core/history/BackForwardController.h"
#include "core/history/HistoryItem.h"
#include "core/html/FormController.h"
#include "core/html/HTMLInputElement.h"
#include "core/html/HTMLMediaElement.h"
#include "core/html/HTMLSelectElement.h"
#include "core/html/HTMLTextAreaElement.h"
#include "core/html/shadow/HTMLContentElement.h"
#include "core/inspector/InspectorClient.h"
#include "core/inspector/InspectorConsoleAgent.h"
#include "core/inspector/InspectorController.h"
#include "core/inspector/InspectorCounters.h"
#include "core/inspector/InspectorFrontendChannel.h"
#include "core/inspector/InspectorInstrumentation.h"
#include "core/inspector/InspectorOverlay.h"
#include "core/inspector/InstrumentingAgents.h"
#include "core/loader/FrameLoader.h"
#include "core/loader/cache/CachedResourceLoader.h"
#include "core/loader/cache/MemoryCache.h"
#include "core/page/Chrome.h"
#include "core/page/ChromeClient.h"
#include "core/page/DOMPoint.h"
#include "core/page/DOMWindow.h"
#include "core/page/EventHandler.h"
#include "core/page/Frame.h"
#include "core/page/FrameView.h"
#include "core/page/Page.h"
#include "core/page/PrintContext.h"
#include "core/page/Settings.h"
#include "core/page/animation/AnimationController.h"
#include "core/page/scrolling/ScrollingCoordinator.h"
#include "core/platform/Cursor.h"
#include "core/platform/Language.h"
#include "core/platform/graphics/IntRect.h"
#include "core/rendering/RenderMenuList.h"
#include "core/rendering/RenderObject.h"
#include "core/rendering/RenderTreeAsText.h"
#include "core/rendering/RenderView.h"
#include "core/workers/WorkerThread.h"
#include "weborigin/SchemeRegistry.h"
#include "wtf/dtoa.h"
#include "wtf/text/StringBuffer.h"

#if ENABLE(INPUT_TYPE_COLOR)
#include "core/platform/ColorChooser.h"
#endif

#if ENABLE(BATTERY_STATUS)
#include "modules/battery/BatteryController.h"
#endif

#if ENABLE(PAGE_POPUP)
#include "core/page/PagePopupController.h"
#endif

#include "core/platform/graphics/GraphicsLayer.h"
#include "core/platform/graphics/chromium/GraphicsLayerChromium.h"
#include "core/platform/graphics/filters/FilterOperation.h"
#include "core/platform/graphics/filters/FilterOperations.h"
#include "core/rendering/RenderLayerBacking.h"

#if ENABLE(ENCRYPTED_MEDIA_V2)
#include "CDM.h"
#include "MockCDM.h"
#endif

#include "core/page/CaptionUserPreferences.h"
#include "core/page/PageGroup.h"

#include "core/platform/mock/PlatformSpeechSynthesizerMock.h"
#include "modules/speech/DOMWindowSpeechSynthesis.h"
#include "modules/speech/SpeechSynthesis.h"

namespace WebCore {

#if ENABLE(PAGE_POPUP)
static MockPagePopupDriver* s_pagePopupDriver = 0;
#endif

using namespace HTMLNames;

class InspectorFrontendChannelDummy : public InspectorFrontendChannel {
public:
    explicit InspectorFrontendChannelDummy(Page*);
    virtual ~InspectorFrontendChannelDummy() { }
    virtual bool sendMessageToFrontend(const String& message) OVERRIDE;

private:
    Page* m_frontendPage;
};

InspectorFrontendChannelDummy::InspectorFrontendChannelDummy(Page* page)
    : m_frontendPage(page)
{
}

bool InspectorFrontendChannelDummy::sendMessageToFrontend(const String& message)
{
    return InspectorClient::doDispatchMessageOnFrontendPage(m_frontendPage, message);
}

static bool markerTypesFrom(const String& markerType, DocumentMarker::MarkerTypes& result)
{
    if (markerType.isEmpty() || equalIgnoringCase(markerType, "all"))
        result = DocumentMarker::AllMarkers();
    else if (equalIgnoringCase(markerType, "Spelling"))
        result =  DocumentMarker::Spelling;
    else if (equalIgnoringCase(markerType, "Grammar"))
        result =  DocumentMarker::Grammar;
    else if (equalIgnoringCase(markerType, "TextMatch"))
        result =  DocumentMarker::TextMatch;
    else
        return false;

    return true;
}

static SpellChecker* spellchecker(Document* document)
{
    if (!document || !document->frame() || !document->frame()->editor())
        return 0;

    return document->frame()->editor()->spellChecker();
}

const char* Internals::internalsId = "internals";

PassRefPtr<Internals> Internals::create(Document* document)
{
    return adoptRef(new Internals(document));
}

Internals::~Internals()
{
}

void Internals::resetToConsistentState(Page* page)
{
    ASSERT(page);

    page->setDeviceScaleFactor(1);
    page->setPageScaleFactor(1, IntPoint(0, 0));
    page->setPagination(Pagination());
    TextRun::setAllowsRoundingHacks(false);
    WebCore::overrideUserPreferredLanguages(Vector<String>());
    WebCore::Settings::setUsesOverlayScrollbars(false);
#if ENABLE(PAGE_POPUP)
    delete s_pagePopupDriver;
    s_pagePopupDriver = 0;
    if (page->chrome())
        page->chrome()->client()->resetPagePopupDriver();
#endif
    if (page->inspectorController())
        page->inspectorController()->setProfilerEnabled(false);
    page->group().captionPreferences()->setTestingMode(false);
    if (!page->mainFrame()->editor()->isContinuousSpellCheckingEnabled())
        page->mainFrame()->editor()->toggleContinuousSpellChecking();
    if (page->mainFrame()->editor()->isOverwriteModeEnabled())
        page->mainFrame()->editor()->toggleOverwriteModeEnabled();
}

Internals::Internals(Document* document)
    : ContextDestructionObserver(document)
    , m_runtimeFlags(InternalRuntimeFlags::create())
{
    if (document && document->page())
        document->page()->group().captionPreferences()->setTestingMode(true);
}

Document* Internals::contextDocument() const
{
    return toDocument(scriptExecutionContext());
}

Frame* Internals::frame() const
{
    if (!contextDocument())
        return 0;
    return contextDocument()->frame();
}

InternalSettings* Internals::settings() const
{
    Document* document = contextDocument();
    if (!document)
        return 0;
    Page* page = document->page();
    if (!page)
        return 0;
    return InternalSettings::from(page);
}

InternalRuntimeFlags* Internals::runtimeFlags() const
{
    return m_runtimeFlags.get();
}

unsigned Internals::workerThreadCount() const
{
    return WorkerThread::workerThreadCount();
}

String Internals::address(Node* node)
{
    char buf[32];
    sprintf(buf, "%p", node);

    return String(buf);
}

bool Internals::isPreloaded(const String& url)
{
    Document* document = contextDocument();
    return document->cachedResourceLoader()->isPreloaded(url);
}

bool Internals::isLoadingFromMemoryCache(const String& url)
{
    if (!contextDocument())
        return false;
    CachedResource* resource = memoryCache()->resourceForURL(contextDocument()->completeURL(url));
    return resource && resource->status() == CachedResource::Cached;
}

void Internals::crash()
{
    CRASH();
}

PassRefPtr<Element> Internals::createContentElement(ExceptionCode& ec)
{
    Document* document = contextDocument();
    if (!document) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return HTMLContentElement::create(document);
}

bool Internals::isValidContentSelect(Element* insertionPoint, ExceptionCode& ec)
{
    if (!insertionPoint || !insertionPoint->isInsertionPoint()) {
        ec = INVALID_ACCESS_ERR;
        return false;
    }

    return isHTMLContentElement(insertionPoint) && toHTMLContentElement(insertionPoint)->isSelectValid();
}

Node* Internals::treeScopeRootNode(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return node->treeScope()->rootNode();
}

Node* Internals::parentTreeScope(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    const TreeScope* parentTreeScope = node->treeScope()->parentTreeScope();
    return parentTreeScope ? parentTreeScope->rootNode() : 0;
}

bool Internals::hasSelectorForIdInShadow(Element* host, const String& idValue, ExceptionCode& ec)
{
    if (!host || !host->shadow()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return host->shadow()->distributor().ensureSelectFeatureSet(host->shadow()).hasSelectorForId(idValue);
}

bool Internals::hasSelectorForClassInShadow(Element* host, const String& className, ExceptionCode& ec)
{
    if (!host || !host->shadow()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return host->shadow()->distributor().ensureSelectFeatureSet(host->shadow()).hasSelectorForClass(className);
}

bool Internals::hasSelectorForAttributeInShadow(Element* host, const String& attributeName, ExceptionCode& ec)
{
    if (!host || !host->shadow()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return host->shadow()->distributor().ensureSelectFeatureSet(host->shadow()).hasSelectorForAttribute(attributeName);
}

bool Internals::hasSelectorForPseudoClassInShadow(Element* host, const String& pseudoClass, ExceptionCode& ec)
{
    if (!host || !host->shadow()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    const SelectRuleFeatureSet& featureSet = host->shadow()->distributor().ensureSelectFeatureSet(host->shadow());
    if (pseudoClass == "checked")
        return featureSet.hasSelectorForChecked();
    if (pseudoClass == "enabled")
        return featureSet.hasSelectorForEnabled();
    if (pseudoClass == "disabled")
        return featureSet.hasSelectorForDisabled();
    if (pseudoClass == "indeterminate")
        return featureSet.hasSelectorForIndeterminate();
    if (pseudoClass == "link")
        return featureSet.hasSelectorForLink();
    if (pseudoClass == "target")
        return featureSet.hasSelectorForTarget();
    if (pseudoClass == "visited")
        return featureSet.hasSelectorForVisited();

    ASSERT_NOT_REACHED();
    return false;
}

unsigned Internals::numberOfActiveAnimations() const
{
    Frame* contextFrame = frame();
    if (AnimationController* controller = contextFrame->animation())
        return controller->numberOfActiveAnimations(contextFrame->document());
    return 0;
}

void Internals::suspendAnimations(Document* document, ExceptionCode& ec) const
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    AnimationController* controller = document->frame()->animation();
    if (!controller)
        return;

    controller->suspendAnimations();
}

void Internals::resumeAnimations(Document* document, ExceptionCode& ec) const
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    AnimationController* controller = document->frame()->animation();
    if (!controller)
        return;

    controller->resumeAnimations();
}

void Internals::pauseAnimations(double pauseTime, ExceptionCode& ec)
{
    if (pauseTime < 0) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    frame()->animation()->pauseAnimationsForTesting(pauseTime);
}

bool Internals::hasShadowInsertionPoint(const Node* root, ExceptionCode& ec) const
{
    if (root && root->isShadowRoot())
        return ScopeContentDistribution::hasShadowElement(toShadowRoot(root));

    ec = INVALID_ACCESS_ERR;
    return 0;
}

bool Internals::hasContentElement(const Node* root, ExceptionCode& ec) const
{
    if (root && root->isShadowRoot())
        return ScopeContentDistribution::hasContentElement(toShadowRoot(root));

    ec = INVALID_ACCESS_ERR;
    return 0;
}

size_t Internals::countElementShadow(const Node* root, ExceptionCode& ec) const
{
    if (!root || !root->isShadowRoot()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return ScopeContentDistribution::countElementShadow(toShadowRoot(root));
}

bool Internals::attached(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return false;
    }

    return node->attached();
}

Node* Internals::nextSiblingByWalker(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    ComposedShadowTreeWalker walker(node);
    walker.nextSibling();
    return walker.get();
}

Node* Internals::firstChildByWalker(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    ComposedShadowTreeWalker walker(node);
    walker.firstChild();
    return walker.get();
}

Node* Internals::lastChildByWalker(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    ComposedShadowTreeWalker walker(node);
    walker.lastChild();
    return walker.get();
}

Node* Internals::nextNodeByWalker(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    ComposedShadowTreeWalker walker(node);
    walker.next();
    return walker.get();
}

Node* Internals::previousNodeByWalker(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    ComposedShadowTreeWalker walker(node);
    walker.previous();
    return walker.get();
}

String Internals::elementRenderTreeAsText(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    String representation = externalRepresentation(element);
    if (representation.isEmpty()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    return representation;
}

size_t Internals::numberOfScopedHTMLStyleChildren(const Node* scope, ExceptionCode& ec) const
{
    if (scope && (scope->isElementNode() || scope->isShadowRoot()))
        return scope->numberOfScopedHTMLStyleChildren();

    ec = INVALID_ACCESS_ERR;
    return 0;
}

PassRefPtr<CSSComputedStyleDeclaration> Internals::computedStyleIncludingVisitedInfo(Node* node, ExceptionCode& ec) const
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    bool allowVisitedStyle = true;
    return CSSComputedStyleDeclaration::create(node, allowVisitedStyle);
}

ShadowRoot* Internals::ensureShadowRoot(Element* host, ExceptionCode& ec)
{
    if (!host) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    if (ElementShadow* shadow = host->shadow())
        return shadow->youngestShadowRoot();

    return host->createShadowRoot(ec).get();
}

ShadowRoot* Internals::shadowRoot(Element* host, ExceptionCode& ec)
{
    // FIXME: Internals::shadowRoot() in tests should be converted to youngestShadowRoot() or oldestShadowRoot().
    // https://bugs.webkit.org/show_bug.cgi?id=78465
    return youngestShadowRoot(host, ec);
}

ShadowRoot* Internals::youngestShadowRoot(Element* host, ExceptionCode& ec)
{
    if (!host) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    if (ElementShadow* shadow = host->shadow())
        return shadow->youngestShadowRoot();
    return 0;
}

ShadowRoot* Internals::oldestShadowRoot(Element* host, ExceptionCode& ec)
{
    if (!host) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    if (ElementShadow* shadow = host->shadow())
        return shadow->oldestShadowRoot();
    return 0;
}

ShadowRoot* Internals::youngerShadowRoot(Node* shadow, ExceptionCode& ec)
{
    if (!shadow || !shadow->isShadowRoot()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return toShadowRoot(shadow)->youngerShadowRoot();
}

ShadowRoot* Internals::olderShadowRoot(Node* shadow, ExceptionCode& ec)
{
    if (!shadow || !shadow->isShadowRoot()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return toShadowRoot(shadow)->olderShadowRoot();
}

String Internals::shadowRootType(const Node* root, ExceptionCode& ec) const
{
    if (!root || !root->isShadowRoot()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    switch (toShadowRoot(root)->type()) {
    case ShadowRoot::UserAgentShadowRoot:
        return String("UserAgentShadowRoot");
    case ShadowRoot::AuthorShadowRoot:
        return String("AuthorShadowRoot");
    default:
        ASSERT_NOT_REACHED();
        return String("Unknown");
    }
}

Element* Internals::includerFor(Node* node, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return NodeRenderingContext(node).insertionPoint();
}

String Internals::shadowPseudoId(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    return element->shadowPseudoId().string();
}

void Internals::setShadowPseudoId(Element* element, const String& id, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    return element->setPseudo(id);
}

String Internals::visiblePlaceholder(Element* element)
{
    if (element && isHTMLTextFormControlElement(element)) {
        if (toHTMLTextFormControlElement(element)->placeholderShouldBeVisible())
            return toHTMLTextFormControlElement(element)->placeholderElement()->textContent();
    }

    return String();
}

#if ENABLE(INPUT_TYPE_COLOR)
void Internals::selectColorInColorChooser(Element* element, const String& colorValue)
{
    if (!element->hasTagName(inputTag))
        return;
    HTMLInputElement* inputElement = element->toInputElement();
    if (!inputElement)
        return;
    inputElement->selectColorInColorChooser(Color(colorValue));
}
#endif

Vector<String> Internals::formControlStateOfPreviousHistoryItem(ExceptionCode& ec)
{
    HistoryItem* mainItem = frame()->loader()->history()->previousItem();
    if (!mainItem) {
        ec = INVALID_ACCESS_ERR;
        return Vector<String>();
    }
    String uniqueName = frame()->tree()->uniqueName();
    if (mainItem->target() != uniqueName && !mainItem->childItemWithTarget(uniqueName)) {
        ec = INVALID_ACCESS_ERR;
        return Vector<String>();
    }
    return mainItem->target() == uniqueName ? mainItem->documentState() : mainItem->childItemWithTarget(uniqueName)->documentState();
}

void Internals::setFormControlStateOfPreviousHistoryItem(const Vector<String>& state, ExceptionCode& ec)
{
    HistoryItem* mainItem = frame()->loader()->history()->previousItem();
    if (!mainItem) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    String uniqueName = frame()->tree()->uniqueName();
    if (mainItem->target() == uniqueName)
        mainItem->setDocumentState(state);
    else if (HistoryItem* subItem = mainItem->childItemWithTarget(uniqueName))
        subItem->setDocumentState(state);
    else
        ec = INVALID_ACCESS_ERR;
}

void Internals::enableMockSpeechSynthesizer()
{
    Document* document = contextDocument();
    if (!document || !document->domWindow())
        return;
    SpeechSynthesis* synthesis = DOMWindowSpeechSynthesis::speechSynthesis(document->domWindow());
    if (!synthesis)
        return;

    synthesis->setPlatformSynthesizer(PlatformSpeechSynthesizerMock::create(synthesis));
}

void Internals::setEnableMockPagePopup(bool enabled, ExceptionCode& ec)
{
#if ENABLE(PAGE_POPUP)
    Document* document = contextDocument();
    if (!document || !document->page() || !document->page()->chrome())
        return;
    Page* page = document->page();
    if (!enabled) {
        page->chrome()->client()->resetPagePopupDriver();
        return;
    }
    if (!s_pagePopupDriver)
        s_pagePopupDriver = MockPagePopupDriver::create(page->mainFrame()).leakPtr();
    page->chrome()->client()->setPagePopupDriver(s_pagePopupDriver);
#else
    UNUSED_PARAM(enabled);
    UNUSED_PARAM(ec);
#endif
}

#if ENABLE(PAGE_POPUP)
PassRefPtr<PagePopupController> Internals::pagePopupController()
{
    return s_pagePopupDriver ? s_pagePopupDriver->pagePopupController() : 0;
}
#endif

PassRefPtr<ClientRect> Internals::absoluteCaretBounds(ExceptionCode& ec)
{
    Document* document = contextDocument();
    if (!document || !document->frame() || !document->frame()->selection()) {
        ec = INVALID_ACCESS_ERR;
        return ClientRect::create();
    }

    return ClientRect::create(document->frame()->selection()->absoluteCaretBounds());
}

PassRefPtr<ClientRect> Internals::boundingBox(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return ClientRect::create();
    }

    element->document()->updateLayoutIgnorePendingStylesheets();
    RenderObject* renderer = element->renderer();
    if (!renderer)
        return ClientRect::create();
    return ClientRect::create(renderer->absoluteBoundingBoxRectIgnoringTransforms());
}

PassRefPtr<ClientRectList> Internals::inspectorHighlightRects(Document* document, ExceptionCode& ec)
{
    if (!document || !document->page() || !document->page()->inspectorController()) {
        ec = INVALID_ACCESS_ERR;
        return ClientRectList::create();
    }

    Highlight highlight;
    document->page()->inspectorController()->getHighlight(&highlight);
    return ClientRectList::create(highlight.quads);
}

unsigned Internals::markerCountForNode(Node* node, const String& markerType, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    DocumentMarker::MarkerTypes markerTypes = 0;
    if (!markerTypesFrom(markerType, markerTypes)) {
        ec = SYNTAX_ERR;
        return 0;
    }

    return node->document()->markers()->markersFor(node, markerTypes).size();
}

DocumentMarker* Internals::markerAt(Node* node, const String& markerType, unsigned index, ExceptionCode& ec)
{
    if (!node) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    DocumentMarker::MarkerTypes markerTypes = 0;
    if (!markerTypesFrom(markerType, markerTypes)) {
        ec = SYNTAX_ERR;
        return 0;
    }

    Vector<DocumentMarker*> markers = node->document()->markers()->markersFor(node, markerTypes);
    if (markers.size() <= index)
        return 0;
    return markers[index];
}

PassRefPtr<Range> Internals::markerRangeForNode(Node* node, const String& markerType, unsigned index, ExceptionCode& ec)
{
    DocumentMarker* marker = markerAt(node, markerType, index, ec);
    if (!marker)
        return 0;
    return Range::create(node->document(), node, marker->startOffset(), node, marker->endOffset());
}

String Internals::markerDescriptionForNode(Node* node, const String& markerType, unsigned index, ExceptionCode& ec)
{
    DocumentMarker* marker = markerAt(node, markerType, index, ec);
    if (!marker)
        return String();
    return marker->description();
}

void Internals::addTextMatchMarker(const Range* range, bool isActive)
{
    range->ownerDocument()->updateLayoutIgnorePendingStylesheets();
    range->ownerDocument()->markers()->addTextMatchMarker(range, isActive);
}

void Internals::setScrollViewPosition(Document* document, long x, long y, ExceptionCode& ec)
{
    if (!document || !document->view()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    FrameView* frameView = document->view();
    bool constrainsScrollingToContentEdgeOldValue = frameView->constrainsScrollingToContentEdge();
    bool scrollbarsSuppressedOldValue = frameView->scrollbarsSuppressed();

    frameView->setConstrainsScrollingToContentEdge(false);
    frameView->setScrollbarsSuppressed(false);
    frameView->setScrollOffsetFromInternals(IntPoint(x, y));
    frameView->setScrollbarsSuppressed(scrollbarsSuppressedOldValue);
    frameView->setConstrainsScrollingToContentEdge(constrainsScrollingToContentEdgeOldValue);
}

void Internals::setPagination(Document* document, const String& mode, int gap, int pageLength, ExceptionCode& ec)
{
    if (!document || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    Page* page = document->page();

    Pagination pagination;
    if (mode == "Unpaginated")
        pagination.mode = Pagination::Unpaginated;
    else if (mode == "LeftToRightPaginated")
        pagination.mode = Pagination::LeftToRightPaginated;
    else if (mode == "RightToLeftPaginated")
        pagination.mode = Pagination::RightToLeftPaginated;
    else if (mode == "TopToBottomPaginated")
        pagination.mode = Pagination::TopToBottomPaginated;
    else if (mode == "BottomToTopPaginated")
        pagination.mode = Pagination::BottomToTopPaginated;
    else {
        ec = SYNTAX_ERR;
        return;
    }

    pagination.gap = gap;
    pagination.pageLength = pageLength;
    page->setPagination(pagination);
}

String Internals::configurationForViewport(Document* document, float devicePixelRatio, int deviceWidth, int deviceHeight, int availableWidth, int availableHeight, ExceptionCode& ec)
{
    if (!document || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }
    Page* page = document->page();

    const int defaultLayoutWidthForNonMobilePages = 980;

    ViewportArguments arguments = page->viewportArguments();
    ViewportAttributes attributes = computeViewportAttributes(arguments, defaultLayoutWidthForNonMobilePages, deviceWidth, deviceHeight, devicePixelRatio, IntSize(availableWidth, availableHeight));
    restrictMinimumScaleFactorToViewportSize(attributes, IntSize(availableWidth, availableHeight), devicePixelRatio);
    restrictScaleFactorToInitialScaleIfNotUserScalable(attributes);

    return "viewport size " + String::number(attributes.layoutSize.width()) + "x" + String::number(attributes.layoutSize.height()) + " scale " + String::number(attributes.initialScale) + " with limits [" + String::number(attributes.minimumScale) + ", " + String::number(attributes.maximumScale) + "] and userScalable " + (attributes.userScalable ? "true" : "false");
}

bool Internals::wasLastChangeUserEdit(Element* textField, ExceptionCode& ec)
{
    if (!textField) {
        ec = INVALID_ACCESS_ERR;
        return false;
    }

    if (HTMLInputElement* inputElement = textField->toInputElement())
        return inputElement->lastChangeWasUserEdit();

    // FIXME: We should be using hasTagName instead but Windows port doesn't link QualifiedNames properly.
    if (textField->tagName() == "TEXTAREA")
        return static_cast<HTMLTextAreaElement*>(textField)->lastChangeWasUserEdit();

    ec = INVALID_NODE_TYPE_ERR;
    return false;
}

bool Internals::elementShouldAutoComplete(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return false;
    }

    if (HTMLInputElement* inputElement = element->toInputElement())
        return inputElement->shouldAutocomplete();

    ec = INVALID_NODE_TYPE_ERR;
    return false;
}

String Internals::suggestedValue(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    HTMLInputElement* inputElement = element->toInputElement();
    if (!inputElement) {
        ec = INVALID_NODE_TYPE_ERR;
        return String();
    }

    return inputElement->suggestedValue();
}

void Internals::setSuggestedValue(Element* element, const String& value, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    HTMLInputElement* inputElement = element->toInputElement();
    if (!inputElement) {
        ec = INVALID_NODE_TYPE_ERR;
        return;
    }

    inputElement->setSuggestedValue(value);
}

void Internals::setEditingValue(Element* element, const String& value, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    HTMLInputElement* inputElement = element->toInputElement();
    if (!inputElement) {
        ec = INVALID_NODE_TYPE_ERR;
        return;
    }

    inputElement->setEditingValue(value);
}

void Internals::setAutofilled(Element* element, bool enabled, ExceptionCode& ec)
{
    HTMLInputElement* inputElement = element->toInputElement();
    if (!inputElement) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    inputElement->setAutofilled(enabled);
}

void Internals::scrollElementToRect(Element* element, long x, long y, long w, long h, ExceptionCode& ec)
{
    if (!element || !element->document() || !element->document()->view()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    FrameView* frameView = element->document()->view();
    frameView->scrollElementToRect(element, IntRect(x, y, w, h));
}

void Internals::paintControlTints(Document* document, ExceptionCode& ec)
{
    if (!document || !document->view()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    FrameView* frameView = document->view();
    frameView->paintControlTints();
}

PassRefPtr<Range> Internals::rangeFromLocationAndLength(Element* scope, int rangeLocation, int rangeLength, ExceptionCode& ec)
{
    if (!scope) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return TextIterator::rangeFromLocationAndLength(scope, rangeLocation, rangeLength);
}

unsigned Internals::locationFromRange(Element* scope, const Range* range, ExceptionCode& ec)
{
    if (!scope || !range) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    size_t location = 0;
    size_t unusedLength = 0;
    TextIterator::getLocationAndLengthFromRange(scope, range, location, unusedLength);
    return location;
}

unsigned Internals::lengthFromRange(Element* scope, const Range* range, ExceptionCode& ec)
{
    if (!scope || !range) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    size_t unusedLocation = 0;
    size_t length = 0;
    TextIterator::getLocationAndLengthFromRange(scope, range, unusedLocation, length);
    return length;
}

String Internals::rangeAsText(const Range* range, ExceptionCode& ec)
{
    if (!range) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    return range->text();
}

PassRefPtr<DOMPoint> Internals::touchPositionAdjustedToBestClickableNode(long x, long y, long width, long height, Document* document, ExceptionCode& ec)
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    IntSize radius(width / 2, height / 2);
    IntPoint point(x + radius.width(), y + radius.height());

    Node* targetNode;
    IntPoint adjustedPoint;

    bool foundNode = document->frame()->eventHandler()->bestClickableNodeForTouchPoint(point, radius, adjustedPoint, targetNode);
    if (foundNode)
        return DOMPoint::create(adjustedPoint.x(), adjustedPoint.y());

    return 0;
}

Node* Internals::touchNodeAdjustedToBestClickableNode(long x, long y, long width, long height, Document* document, ExceptionCode& ec)
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    IntSize radius(width / 2, height / 2);
    IntPoint point(x + radius.width(), y + radius.height());

    Node* targetNode;
    IntPoint adjustedPoint;
    document->frame()->eventHandler()->bestClickableNodeForTouchPoint(point, radius, adjustedPoint, targetNode);
    return targetNode;
}

PassRefPtr<DOMPoint> Internals::touchPositionAdjustedToBestContextMenuNode(long x, long y, long width, long height, Document* document, ExceptionCode& ec)
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    IntSize radius(width / 2, height / 2);
    IntPoint point(x + radius.width(), y + radius.height());

    Node* targetNode = 0;
    IntPoint adjustedPoint;

    bool foundNode = document->frame()->eventHandler()->bestContextMenuNodeForTouchPoint(point, radius, adjustedPoint, targetNode);
    if (foundNode)
        return DOMPoint::create(adjustedPoint.x(), adjustedPoint.y());

    return DOMPoint::create(x, y);
}

Node* Internals::touchNodeAdjustedToBestContextMenuNode(long x, long y, long width, long height, Document* document, ExceptionCode& ec)
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    IntSize radius(width / 2, height / 2);
    IntPoint point(x + radius.width(), y + radius.height());

    Node* targetNode = 0;
    IntPoint adjustedPoint;
    document->frame()->eventHandler()->bestContextMenuNodeForTouchPoint(point, radius, adjustedPoint, targetNode);
    return targetNode;
}

PassRefPtr<ClientRect> Internals::bestZoomableAreaForTouchPoint(long x, long y, long width, long height, Document* document, ExceptionCode& ec)
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    IntSize radius(width / 2, height / 2);
    IntPoint point(x + radius.width(), y + radius.height());

    Node* targetNode;
    IntRect zoomableArea;
    bool foundNode = document->frame()->eventHandler()->bestZoomableAreaForTouchPoint(point, radius, zoomableArea, targetNode);
    if (foundNode)
        return ClientRect::create(zoomableArea);

    return 0;
}


int Internals::lastSpellCheckRequestSequence(Document* document, ExceptionCode& ec)
{
    SpellChecker* checker = spellchecker(document);

    if (!checker) {
        ec = INVALID_ACCESS_ERR;
        return -1;
    }

    return checker->lastRequestSequence();
}

int Internals::lastSpellCheckProcessedSequence(Document* document, ExceptionCode& ec)
{
    SpellChecker* checker = spellchecker(document);

    if (!checker) {
        ec = INVALID_ACCESS_ERR;
        return -1;
    }

    return checker->lastProcessedSequence();
}

Vector<String> Internals::userPreferredLanguages() const
{
    return WebCore::userPreferredLanguages();
}

void Internals::setUserPreferredLanguages(const Vector<String>& languages)
{
    WebCore::overrideUserPreferredLanguages(languages);
}

unsigned Internals::wheelEventHandlerCount(Document* document, ExceptionCode& ec)
{
    if (!document) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    return document->wheelEventHandlerCount();
}

unsigned Internals::touchEventHandlerCount(Document* document, ExceptionCode& ec)
{
    if (!document) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    const TouchEventTargetSet* touchHandlers = document->touchEventTargets();
    if (!touchHandlers)
        return 0;

    unsigned count = 0;
    for (TouchEventTargetSet::const_iterator iter = touchHandlers->begin(); iter != touchHandlers->end(); ++iter)
        count += iter->value;
    return count;
}

PassRefPtr<ClientRectList> Internals::touchEventTargetClientRects(Document* document, ExceptionCode& ec)
{
    if (!document || !document->view() || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }
    if (!document->page()->scrollingCoordinator())
        return ClientRectList::create();

    document->updateLayoutIgnorePendingStylesheets();

    Vector<IntRect> absoluteRects;
    document->page()->scrollingCoordinator()->computeAbsoluteTouchEventTargetRects(document, absoluteRects);
    Vector<FloatQuad> absoluteQuads(absoluteRects.size());

    for (size_t i = 0; i < absoluteRects.size(); ++i)
        absoluteQuads[i] = FloatQuad(absoluteRects[i]);

    return ClientRectList::create(absoluteQuads);
}

PassRefPtr<NodeList> Internals::nodesFromRect(Document* document, int centerX, int centerY, unsigned topPadding, unsigned rightPadding,
    unsigned bottomPadding, unsigned leftPadding, bool ignoreClipping, bool allowShadowContent, bool allowChildFrameContent, ExceptionCode& ec) const
{
    if (!document || !document->frame() || !document->frame()->view()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    Frame* frame = document->frame();
    FrameView* frameView = document->view();
    RenderView* renderView = document->renderView();

    if (!renderView)
        return 0;

    float zoomFactor = frame->pageZoomFactor();
    LayoutPoint point = roundedLayoutPoint(FloatPoint(centerX * zoomFactor + frameView->scrollX(), centerY * zoomFactor + frameView->scrollY()));

    HitTestRequest::HitTestRequestType hitType = HitTestRequest::ReadOnly | HitTestRequest::Active;
    if (ignoreClipping)
        hitType |= HitTestRequest::IgnoreClipping;
    if (!allowShadowContent)
        hitType |= HitTestRequest::DisallowShadowContent;
    if (allowChildFrameContent)
        hitType |= HitTestRequest::AllowChildFrameContent;

    HitTestRequest request(hitType);

    // When ignoreClipping is false, this method returns null for coordinates outside of the viewport.
    if (!request.ignoreClipping() && !frameView->visibleContentRect().intersects(HitTestLocation::rectForPoint(point, topPadding, rightPadding, bottomPadding, leftPadding)))
        return 0;

    Vector<RefPtr<Node> > matches;

    // Need padding to trigger a rect based hit test, but we want to return a NodeList
    // so we special case this.
    if (!topPadding && !rightPadding && !bottomPadding && !leftPadding) {
        HitTestResult result(point);
        renderView->hitTest(request, result);
        if (result.innerNode())
            matches.append(result.innerNode()->deprecatedShadowAncestorNode());
    } else {
        HitTestResult result(point, topPadding, rightPadding, bottomPadding, leftPadding);
        renderView->hitTest(request, result);
        copyToVector(result.rectBasedTestResult(), matches);
    }

    return StaticNodeList::adopt(matches);
}

void Internals::emitInspectorDidBeginFrame()
{
    InspectorController* inspectorController = contextDocument()->frame()->page()->inspectorController();
    inspectorController->didBeginFrame();
}

void Internals::emitInspectorDidCancelFrame()
{
    InspectorController* inspectorController = contextDocument()->frame()->page()->inspectorController();
    inspectorController->didCancelFrame();
}

void Internals::setBatteryStatus(Document* document, const String& eventType, bool charging, double chargingTime, double dischargingTime, double level, ExceptionCode& ec)
{
    if (!document || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

#if ENABLE(BATTERY_STATUS)
    BatteryController::from(document->page())->didChangeBatteryStatus(eventType, BatteryStatus::create(charging, chargingTime, dischargingTime, level));
#else
    UNUSED_PARAM(eventType);
    UNUSED_PARAM(charging);
    UNUSED_PARAM(chargingTime);
    UNUSED_PARAM(dischargingTime);
    UNUSED_PARAM(level);
#endif
}

bool Internals::hasSpellingMarker(Document* document, int from, int length, ExceptionCode&)
{
    if (!document || !document->frame())
        return 0;

    return document->frame()->editor()->selectionStartHasMarkerFor(DocumentMarker::Spelling, from, length);
}

void Internals::setContinuousSpellCheckingEnabled(bool enabled, ExceptionCode&)
{
    if (!contextDocument() || !contextDocument()->frame() || !contextDocument()->frame()->editor())
        return;

    if (enabled != contextDocument()->frame()->editor()->isContinuousSpellCheckingEnabled())
        contextDocument()->frame()->editor()->toggleContinuousSpellChecking();
}

bool Internals::isOverwriteModeEnabled(Document* document, ExceptionCode&)
{
    if (!document || !document->frame())
        return 0;

    return document->frame()->editor()->isOverwriteModeEnabled();
}

void Internals::toggleOverwriteModeEnabled(Document* document, ExceptionCode&)
{
    if (!document || !document->frame())
        return;

    document->frame()->editor()->toggleOverwriteModeEnabled();
}

unsigned Internals::numberOfLiveNodes() const
{
    return InspectorCounters::counterValue(InspectorCounters::NodeCounter);
}

unsigned Internals::numberOfLiveDocuments() const
{
    return InspectorCounters::counterValue(InspectorCounters::DocumentCounter);
}

Vector<String> Internals::consoleMessageArgumentCounts(Document* document) const
{
    InstrumentingAgents* instrumentingAgents = instrumentationForPage(document->page());
    if (!instrumentingAgents)
        return Vector<String>();
    InspectorConsoleAgent* consoleAgent = instrumentingAgents->inspectorConsoleAgent();
    if (!consoleAgent)
        return Vector<String>();
    Vector<unsigned> counts = consoleAgent->consoleMessageArgumentCounts();
    Vector<String> result(counts.size());
    for (size_t i = 0; i < counts.size(); i++)
        result[i] = String::number(counts[i]);
    return result;
}

PassRefPtr<DOMWindow> Internals::openDummyInspectorFrontend(const String& url)
{
    Page* page = contextDocument()->frame()->page();
    ASSERT(page);

    DOMWindow* window = page->mainFrame()->document()->domWindow();
    ASSERT(window);

    m_frontendWindow = window->open(url, "", "", window, window);
    ASSERT(m_frontendWindow);

    Page* frontendPage = m_frontendWindow->document()->page();
    ASSERT(frontendPage);

    OwnPtr<InspectorFrontendClientLocal> frontendClient = adoptPtr(new InspectorFrontendClientLocal(page->inspectorController(), frontendPage));

    frontendPage->inspectorController()->setInspectorFrontendClient(frontendClient.release());

    m_frontendChannel = adoptPtr(new InspectorFrontendChannelDummy(frontendPage));

    page->inspectorController()->connectFrontend(m_frontendChannel.get());

    return m_frontendWindow;
}

void Internals::closeDummyInspectorFrontend()
{
    Page* page = contextDocument()->frame()->page();
    ASSERT(page);
    ASSERT(m_frontendWindow);

    page->inspectorController()->disconnectFrontend();

    m_frontendChannel.release();

    m_frontendWindow->close(m_frontendWindow->scriptExecutionContext());
    m_frontendWindow.release();
}

void Internals::setInspectorResourcesDataSizeLimits(int maximumResourcesContentSize, int maximumSingleResourceContentSize, ExceptionCode& ec)
{
    Page* page = contextDocument()->frame()->page();
    if (!page || !page->inspectorController()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    page->inspectorController()->setResourcesDataSizeLimitsFromInternals(maximumResourcesContentSize, maximumSingleResourceContentSize);
}

void Internals::setJavaScriptProfilingEnabled(bool enabled, ExceptionCode& ec)
{
    Page* page = contextDocument()->frame()->page();
    if (!page || !page->inspectorController()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    page->inspectorController()->setProfilerEnabled(enabled);
}

bool Internals::hasGrammarMarker(Document* document, int from, int length, ExceptionCode&)
{
    if (!document || !document->frame())
        return 0;

    return document->frame()->editor()->selectionStartHasMarkerFor(DocumentMarker::Grammar, from, length);
}

unsigned Internals::numberOfScrollableAreas(Document* document, ExceptionCode&)
{
    unsigned count = 0;
    Frame* frame = document->frame();
    if (frame->view()->scrollableAreas())
        count += frame->view()->scrollableAreas()->size();

    for (Frame* child = frame->tree()->firstChild(); child; child = child->tree()->nextSibling()) {
        if (child->view() && child->view()->scrollableAreas())
            count += child->view()->scrollableAreas()->size();
    }

    return count;
}

bool Internals::isPageBoxVisible(Document* document, int pageNumber, ExceptionCode& ec)
{
    if (!document) {
        ec = INVALID_ACCESS_ERR;
        return false;
    }

    return document->isPageBoxVisible(pageNumber);
}

String Internals::layerTreeAsText(Document* document, ExceptionCode& ec) const
{
    return layerTreeAsText(document, 0, ec);
}

static PassRefPtr<NodeList> paintOrderList(Element* element, ExceptionCode& ec, RenderLayer::PaintOrderListType type)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    element->document()->updateLayout();

    RenderObject* renderer = element->renderer();
    if (!renderer || !renderer->isBox()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    RenderLayer* layer = toRenderBox(renderer)->layer();
    if (!layer) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    Vector<RefPtr<Node> > nodes;
    layer->computePaintOrderList(type, nodes);
    return StaticNodeList::adopt(nodes);
}

PassRefPtr<NodeList> Internals::paintOrderListBeforePromote(Element* element, ExceptionCode& ec)
{
    return paintOrderList(element, ec, RenderLayer::BeforePromote);
}

PassRefPtr<NodeList> Internals::paintOrderListAfterPromote(Element* element, ExceptionCode& ec)
{
    return paintOrderList(element, ec, RenderLayer::AfterPromote);
}

String Internals::layerTreeAsText(Document* document, unsigned flags, ExceptionCode& ec) const
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    LayerTreeFlags layerTreeFlags = 0;
    if (flags & LAYER_TREE_INCLUDES_VISIBLE_RECTS)
        layerTreeFlags |= LayerTreeFlagsIncludeVisibleRects;
    if (flags & LAYER_TREE_INCLUDES_TILE_CACHES)
        layerTreeFlags |= LayerTreeFlagsIncludeTileCaches;
    if (flags & LAYER_TREE_INCLUDES_REPAINT_RECTS)
        layerTreeFlags |= LayerTreeFlagsIncludeRepaintRects;
    if (flags & LAYER_TREE_INCLUDES_PAINTING_PHASES)
        layerTreeFlags |= LayerTreeFlagsIncludePaintingPhases;

    return document->frame()->layerTreeAsText(layerTreeFlags);
}

String Internals::repaintRectsAsText(Document* document, ExceptionCode& ec) const
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    return document->frame()->trackedRepaintRectsAsText();
}

String Internals::scrollingStateTreeAsText(Document* document, ExceptionCode& ec) const
{
    return String();
}

String Internals::mainThreadScrollingReasons(Document* document, ExceptionCode& ec) const
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    Page* page = document->page();
    if (!page)
        return String();

    return page->mainThreadScrollingReasonsAsText();
}

PassRefPtr<ClientRectList> Internals::nonFastScrollableRects(Document* document, ExceptionCode& ec) const
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return 0;
    }

    Page* page = document->page();
    if (!page)
        return 0;

    return page->nonFastScrollableRects(document->frame());
}

void Internals::garbageCollectDocumentResources(Document* document, ExceptionCode& ec) const
{
    if (!document) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    CachedResourceLoader* cachedResourceLoader = document->cachedResourceLoader();
    if (!cachedResourceLoader)
        return;
    cachedResourceLoader->garbageCollectDocumentResources();
}

void Internals::allowRoundingHacks() const
{
    TextRun::setAllowsRoundingHacks(true);
}

void Internals::insertAuthorCSS(Document* document, const String& css) const
{
    RefPtr<StyleSheetContents> parsedSheet = StyleSheetContents::create(document);
    parsedSheet->setIsUserStyleSheet(false);
    parsedSheet->parseString(css);
    document->styleSheetCollection()->addAuthorSheet(parsedSheet);
}

void Internals::insertUserCSS(Document* document, const String& css) const
{
    RefPtr<StyleSheetContents> parsedSheet = StyleSheetContents::create(document);
    parsedSheet->setIsUserStyleSheet(true);
    parsedSheet->parseString(css);
    document->styleSheetCollection()->addUserSheet(parsedSheet);
}

String Internals::counterValue(Element* element)
{
    if (!element)
        return String();

    return counterValueForElement(element);
}

int Internals::pageNumber(Element* element, float pageWidth, float pageHeight)
{
    if (!element)
        return 0;

    return PrintContext::pageNumberForElement(element, FloatSize(pageWidth, pageHeight));
}

Vector<String> Internals::iconURLs(Document* document, int iconTypesMask) const
{
    Vector<IconURL> iconURLs = document->iconURLs(iconTypesMask);
    Vector<String> array;

    Vector<IconURL>::const_iterator iter(iconURLs.begin());
    for (; iter != iconURLs.end(); ++iter)
        array.append(iter->m_iconURL.string());

    return array;
}

Vector<String> Internals::shortcutIconURLs(Document* document) const
{
    return iconURLs(document, Favicon);
}

Vector<String> Internals::allIconURLs(Document* document) const
{
    return iconURLs(document, Favicon | TouchIcon | TouchPrecomposedIcon);
}

int Internals::numberOfPages(float pageWidth, float pageHeight)
{
    if (!frame())
        return -1;

    return PrintContext::numberOfPages(frame(), FloatSize(pageWidth, pageHeight));
}

String Internals::pageProperty(String propertyName, int pageNumber, ExceptionCode& ec) const
{
    if (!frame()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    return PrintContext::pageProperty(frame(), propertyName.utf8().data(), pageNumber);
}

String Internals::pageSizeAndMarginsInPixels(int pageNumber, int width, int height, int marginTop, int marginRight, int marginBottom, int marginLeft, ExceptionCode& ec) const
{
    if (!frame()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    return PrintContext::pageSizeAndMarginsInPixels(frame(), pageNumber, width, height, marginTop, marginRight, marginBottom, marginLeft);
}

void Internals::setDeviceScaleFactor(float scaleFactor, ExceptionCode& ec)
{
    Document* document = contextDocument();
    if (!document || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    Page* page = document->page();
    page->setDeviceScaleFactor(scaleFactor);
}

void Internals::setPageScaleFactor(float scaleFactor, int x, int y, ExceptionCode& ec)
{
    Document* document = contextDocument();
    if (!document || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    Page* page = document->page();
    page->setPageScaleFactor(scaleFactor, IntPoint(x, y));
}

void Internals::setIsCursorVisible(Document* document, bool isVisible, ExceptionCode& ec)
{
    if (!document || !document->page()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }
    document->page()->setIsCursorVisible(isVisible);
}

void Internals::webkitWillEnterFullScreenForElement(Document* document, Element* element)
{
    if (!document)
        return;
    document->webkitWillEnterFullScreenForElement(element);
}

void Internals::webkitDidEnterFullScreenForElement(Document* document, Element* element)
{
    if (!document)
        return;
    document->webkitDidEnterFullScreenForElement(element);
}

void Internals::webkitWillExitFullScreenForElement(Document* document, Element* element)
{
    if (!document)
        return;
    document->webkitWillExitFullScreenForElement(element);
}

void Internals::webkitDidExitFullScreenForElement(Document* document, Element* element)
{
    if (!document)
        return;
    document->webkitDidExitFullScreenForElement(element);
}

void Internals::registerURLSchemeAsBypassingContentSecurityPolicy(const String& scheme)
{
    SchemeRegistry::registerURLSchemeAsBypassingContentSecurityPolicy(scheme);
}

void Internals::removeURLSchemeRegisteredAsBypassingContentSecurityPolicy(const String& scheme)
{
    SchemeRegistry::removeURLSchemeRegisteredAsBypassingContentSecurityPolicy(scheme);
}

PassRefPtr<MallocStatistics> Internals::mallocStatistics() const
{
    return MallocStatistics::create();
}

PassRefPtr<TypeConversions> Internals::typeConversions() const
{
    return TypeConversions::create();
}

Vector<String> Internals::getReferencedFilePaths() const
{
    frame()->loader()->history()->saveDocumentAndScrollState();
    return FormController::getReferencedFilePaths(frame()->loader()->history()->currentItem()->documentState());
}

void Internals::startTrackingRepaints(Document* document, ExceptionCode& ec)
{
    if (!document || !document->view()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    FrameView* frameView = document->view();
    frameView->setTracksRepaints(true);
}

void Internals::stopTrackingRepaints(Document* document, ExceptionCode& ec)
{
    if (!document || !document->view()) {
        ec = INVALID_ACCESS_ERR;
        return;
    }

    FrameView* frameView = document->view();
    frameView->setTracksRepaints(false);
}

static const char* cursorTypeToString(Cursor::Type cursorType)
{
    switch (cursorType) {
    case Cursor::Pointer: return "Pointer";
    case Cursor::Cross: return "Cross";
    case Cursor::Hand: return "Hand";
    case Cursor::IBeam: return "IBeam";
    case Cursor::Wait: return "Wait";
    case Cursor::Help: return "Help";
    case Cursor::EastResize: return "EastResize";
    case Cursor::NorthResize: return "NorthResize";
    case Cursor::NorthEastResize: return "NorthEastResize";
    case Cursor::NorthWestResize: return "NorthWestResize";
    case Cursor::SouthResize: return "SouthResize";
    case Cursor::SouthEastResize: return "SouthEastResize";
    case Cursor::SouthWestResize: return "SouthWestResize";
    case Cursor::WestResize: return "WestResize";
    case Cursor::NorthSouthResize: return "NorthSouthResize";
    case Cursor::EastWestResize: return "EastWestResize";
    case Cursor::NorthEastSouthWestResize: return "NorthEastSouthWestResize";
    case Cursor::NorthWestSouthEastResize: return "NorthWestSouthEastResize";
    case Cursor::ColumnResize: return "ColumnResize";
    case Cursor::RowResize: return "RowResize";
    case Cursor::MiddlePanning: return "MiddlePanning";
    case Cursor::EastPanning: return "EastPanning";
    case Cursor::NorthPanning: return "NorthPanning";
    case Cursor::NorthEastPanning: return "NorthEastPanning";
    case Cursor::NorthWestPanning: return "NorthWestPanning";
    case Cursor::SouthPanning: return "SouthPanning";
    case Cursor::SouthEastPanning: return "SouthEastPanning";
    case Cursor::SouthWestPanning: return "SouthWestPanning";
    case Cursor::WestPanning: return "WestPanning";
    case Cursor::Move: return "Move";
    case Cursor::VerticalText: return "VerticalText";
    case Cursor::Cell: return "Cell";
    case Cursor::ContextMenu: return "ContextMenu";
    case Cursor::Alias: return "Alias";
    case Cursor::Progress: return "Progress";
    case Cursor::NoDrop: return "NoDrop";
    case Cursor::Copy: return "Copy";
    case Cursor::None: return "None";
    case Cursor::NotAllowed: return "NotAllowed";
    case Cursor::ZoomIn: return "ZoomIn";
    case Cursor::ZoomOut: return "ZoomOut";
    case Cursor::Grab: return "Grab";
    case Cursor::Grabbing: return "Grabbing";
    case Cursor::Custom: return "Custom";
    }

    ASSERT_NOT_REACHED();
    return "UNKNOWN";
}

String Internals::getCurrentCursorInfo(Document* document, ExceptionCode& ec)
{
    if (!document || !document->frame()) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }

    Cursor cursor = document->frame()->eventHandler()->currentMouseCursor();

    StringBuilder result;
    result.append("type=");
    result.append(cursorTypeToString(cursor.type()));
    result.append(" hotSpot=");
    result.appendNumber(cursor.hotSpot().x());
    result.append(",");
    result.appendNumber(cursor.hotSpot().y());
    if (cursor.image()) {
        IntSize size = cursor.image()->size();
        result.append(" image=");
        result.appendNumber(size.width());
        result.append("x");
        result.appendNumber(size.height());
    }
    if (cursor.imageScaleFactor() != 1) {
        result.append(" scale=");
        NumberToStringBuffer buffer;
        result.append(numberToFixedPrecisionString(cursor.imageScaleFactor(), 8, buffer, true));
    }

    return result.toString();
}

PassRefPtr<ArrayBuffer> Internals::serializeObject(PassRefPtr<SerializedScriptValue> value) const
{
    String stringValue = value->toWireString();
    return ArrayBuffer::create(static_cast<const void*>(stringValue.impl()->characters()), stringValue.sizeInBytes());
}

PassRefPtr<SerializedScriptValue> Internals::deserializeBuffer(PassRefPtr<ArrayBuffer> buffer) const
{
    String value(static_cast<const UChar*>(buffer->data()), buffer->byteLength() / sizeof(UChar));
    return SerializedScriptValue::createFromWire(value);
}

void Internals::setUsesOverlayScrollbars(bool enabled)
{
    WebCore::Settings::setUsesOverlayScrollbars(enabled);
}

void Internals::forceReload(bool endToEnd)
{
    frame()->loader()->reload(endToEnd);
}

#if ENABLE(ENCRYPTED_MEDIA_V2)
void Internals::initializeMockCDM()
{
    CDM::registerCDMFactory(MockCDM::create, MockCDM::supportsKeySytem);
}
#endif

String Internals::markerTextForListItem(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }
    return WebCore::markerTextForListItem(element);
}

String Internals::getImageSourceURL(Element* element, ExceptionCode& ec)
{
    if (!element) {
        ec = INVALID_ACCESS_ERR;
        return String();
    }
    return element->imageSourceURL();
}

bool Internals::isSelectPopupVisible(Node* node)
{
    if (!isHTMLSelectElement(node))
        return false;

    HTMLSelectElement* select = toHTMLSelectElement(node);

    RenderObject* renderer = select->renderer();
    if (!renderer->isMenuList())
        return false;

    RenderMenuList* menuList = toRenderMenuList(renderer);
    return menuList->popupIsVisible();
}

}
