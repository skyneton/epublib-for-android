//
// Created by skyne on 2024-01-03.
//

#ifndef TEXTREADER_EPUBPAGINATION_H
#define TEXTREADER_EPUBPAGINATION_H
#pragma once
#include <jni.h>
#include "Epub.h"
namespace EpubPagination {
    typedef std::function<void (const std::vector<std::shared_ptr<EpubElement>>&, int)> PageHandler;

    std::pair<Array<std::pair<int, int>>, int>
            measureBreakAnnotatedText(JNIEnv *env, float density, float fontScale,
                                      jobject paint, jmethodID measureText,
                                      const AnnotatedString &text,
                                      int viewportWidth, float textSize, float letterSpacing, float textScaleX, float textSkewX,
                                      float defaultLineHeight, bool wordBreak,
                                      short* cacheArray, int defaultFontID,
                                      jobject fontHandler, jmethodID fontMethodID, jobject fontByIdxHandler, jmethodID fontByIdxMethodID,
                                      jclass integerClazz, jmethodID integerValueOf, jmethodID integerIntValue,
                                      jclass booleanClazz, jmethodID booleanValueOf);

    std::pair<Array<std::shared_ptr<EpubElement>>, int>
            pagination(JNIEnv* env, const EpubPage& page, jobject paint,
                       float density, float fontScale, int viewportWidth, int viewportHeight,
                       float textSize, float letterSpacing, float textScaleX, float textSkewX, float defaultLineHeight, bool wordBreak,
                       jobject fontHandler, jobject fontByIdxHandler, const PageHandler&);
}
#endif //TEXTREADER_EPUBPAGINATION_H
