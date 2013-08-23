// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "config.h"
#include "core/page/ImageBitmap.h"

#include "core/html/HTMLCanvasElement.h"
#include "core/html/HTMLImageElement.h"
#include "core/html/HTMLVideoElement.h"
#include "core/html/ImageData.h"
#include "core/html/canvas/CanvasRenderingContext.h"
#include "core/platform/graphics/BitmapImage.h"
#include "core/platform/graphics/GraphicsContext.h"
#include "core/platform/graphics/ImageBuffer.h"
#include "wtf/RefPtr.h"

using namespace std;

namespace WebCore {

static inline IntRect normalizeRect(const IntRect& rect)
{
    return IntRect(min(rect.x(), rect.maxX()),
        min(rect.y(), rect.maxY()),
        max(rect.width(), -rect.width()),
        max(rect.height(), -rect.height()));
}

static inline PassRefPtr<Image> cropImage(Image* image, const IntRect& cropRect)
{
    IntRect intersectRect = intersection(IntRect(IntPoint(), image->size()), cropRect);
    if (!intersectRect.width() || !intersectRect.height())
        return 0;

    SkBitmap cropped;
    image->nativeImageForCurrentFrame()->bitmap().extractSubset(&cropped, intersectRect);
    return BitmapImage::create(NativeImageSkia::create(cropped));
}

ImageBitmap::ImageBitmap(HTMLImageElement* image, const IntRect& cropRect)
    : m_cropRect(cropRect)
    , m_bitmap(0)
    , m_imageElement(image)
{
    IntRect srcRect = intersection(cropRect, IntRect(0, 0, image->width(), image->height()));
    m_bitmapRect = IntRect(IntPoint(max(0, -cropRect.x()), max(0, -cropRect.y())), srcRect.size());
    m_bitmapOffset = srcRect.location();

    if (!srcRect.width() || !srcRect.height())
        m_imageElement = 0;
    else
        m_imageElement->addClient(this);

    ScriptWrappable::init(this);
}

ImageBitmap::ImageBitmap(HTMLVideoElement* video, const IntRect& cropRect)
    : m_cropRect(cropRect)
    , m_imageElement(0)
    , m_bitmapOffset(IntPoint())
{
    IntRect videoRect = IntRect(IntPoint(), video->player()->naturalSize());
    IntRect srcRect = intersection(cropRect, videoRect);
    IntRect dstRect(IntPoint(), srcRect.size());

    OwnPtr<ImageBuffer> buf = ImageBuffer::create(videoRect.size(), 1, UnacceleratedNonPlatformBuffer);
    GraphicsContext* c = buf->context();
    c->clip(dstRect);
    c->translate(-srcRect.x(), -srcRect.y());
    video->paintCurrentFrameInContext(c, videoRect);
    m_bitmap = buf->copyImage(DontCopyBackingStore);
    m_bitmapRect = IntRect(IntPoint(max(0, -cropRect.x()), max(0, -cropRect.y())), srcRect.size());

    ScriptWrappable::init(this);
}

ImageBitmap::ImageBitmap(HTMLCanvasElement* canvas, const IntRect& cropRect)
    : m_cropRect(cropRect)
    , m_imageElement(0)
    , m_bitmapOffset(IntPoint())
{
    CanvasRenderingContext* sourceContext = canvas->renderingContext();
    if (sourceContext && sourceContext->is3d())
        sourceContext->paintRenderingResultsToCanvas();

    IntRect srcRect = intersection(cropRect, IntRect(IntPoint(), canvas->size()));
    m_bitmapRect = IntRect(IntPoint(max(0, -cropRect.x()), max(0, -cropRect.y())), srcRect.size());
    m_bitmap = cropImage(canvas->buffer()->copyImage(CopyBackingStore).get(), cropRect);

    ScriptWrappable::init(this);
}

ImageBitmap::ImageBitmap(ImageData* data, const IntRect& cropRect)
    : m_cropRect(cropRect)
    , m_imageElement(0)
    , m_bitmapOffset(IntPoint())
{
    IntRect srcRect = intersection(cropRect, IntRect(IntPoint(), data->size()));

    OwnPtr<ImageBuffer> buf = ImageBuffer::create(data->size(), 1, UnacceleratedNonPlatformBuffer);
    if (srcRect.width() > 0 && srcRect.height() > 0)
        buf->putByteArray(Premultiplied, data->data(), data->size(), srcRect, IntPoint(min(0, -cropRect.x()), min(0, -cropRect.y())));

    m_bitmap = buf->copyImage(DontCopyBackingStore);
    m_bitmapRect = IntRect(IntPoint(max(0, -cropRect.x()), max(0, -cropRect.y())),  srcRect.size());

    ScriptWrappable::init(this);
}

ImageBitmap::ImageBitmap(ImageBitmap* bitmap, const IntRect& cropRect)
    : m_cropRect(cropRect)
    , m_bitmap(0)
    , m_imageElement(bitmap->imageElement())
    , m_bitmapOffset(IntPoint())
{
    IntRect oldBitmapRect = bitmap->bitmapRect();
    IntRect srcRect = intersection(cropRect, oldBitmapRect);
    m_bitmapRect = IntRect(IntPoint(max(0, oldBitmapRect.x() - cropRect.x()), max(0, oldBitmapRect.y() - cropRect.y())), srcRect.size());

    if (m_imageElement) {
        m_imageElement->addClient(this);
        m_bitmapOffset = srcRect.location();
    } else if (bitmap->bitmapImage()) {
        IntRect adjustedCropRect(IntPoint(cropRect.x() -oldBitmapRect.x(), cropRect.y() - oldBitmapRect.y()), cropRect.size());
        m_bitmap = cropImage(bitmap->bitmapImage().get(), adjustedCropRect);
    }

    ScriptWrappable::init(this);
}

ImageBitmap::ImageBitmap(Image* image, const IntRect& cropRect)
    : m_cropRect(cropRect)
    , m_imageElement(0)
{
    IntRect srcRect = intersection(cropRect, IntRect(IntPoint(), image->size()));
    m_bitmap = cropImage(image, cropRect);
    m_bitmapRect = IntRect(IntPoint(max(0, -cropRect.x()), max(0, -cropRect.y())),  srcRect.size());

    ScriptWrappable::init(this);
}

ImageBitmap::~ImageBitmap()
{
    if (m_imageElement)
        m_imageElement->removeClient(this);
}

PassRefPtr<ImageBitmap> ImageBitmap::create(HTMLImageElement* image, const IntRect& cropRect)
{
    IntRect normalizedCropRect = normalizeRect(cropRect);
    return adoptRef(new ImageBitmap(image, normalizedCropRect));
}

PassRefPtr<ImageBitmap> ImageBitmap::create(HTMLVideoElement* video, const IntRect& cropRect)
{
    IntRect normalizedCropRect = normalizeRect(cropRect);
    return adoptRef(new ImageBitmap(video, normalizedCropRect));
}

PassRefPtr<ImageBitmap> ImageBitmap::create(HTMLCanvasElement* canvas, const IntRect& cropRect)
{
    IntRect normalizedCropRect = normalizeRect(cropRect);
    return adoptRef(new ImageBitmap(canvas, normalizedCropRect));
}

PassRefPtr<ImageBitmap> ImageBitmap::create(ImageData* data, const IntRect& cropRect)
{
    IntRect normalizedCropRect = normalizeRect(cropRect);
    return adoptRef(new ImageBitmap(data, normalizedCropRect));
}

PassRefPtr<ImageBitmap> ImageBitmap::create(ImageBitmap* bitmap, const IntRect& cropRect)
{
    IntRect normalizedCropRect = normalizeRect(cropRect);
    return adoptRef(new ImageBitmap(bitmap, normalizedCropRect));
}

PassRefPtr<ImageBitmap> ImageBitmap::create(Image* image, const IntRect& cropRect)
{
    IntRect normalizedCropRect = normalizeRect(cropRect);
    return adoptRef(new ImageBitmap(image, normalizedCropRect));
}

void ImageBitmap::notifyImageSourceChanged()
{
    m_bitmap = cropImage(m_imageElement->cachedImage()->image(), m_cropRect);
    m_bitmapOffset = IntPoint();
    m_imageElement = 0;
}

PassRefPtr<Image> ImageBitmap::bitmapImage() const
{
    ASSERT((m_imageElement || m_bitmap || !m_bitmapRect.width() || !m_bitmapRect.height()) && (!m_imageElement || !m_bitmap));
    if (m_imageElement)
        return m_imageElement->cachedImage()->image();
    return m_bitmap;
}

}
