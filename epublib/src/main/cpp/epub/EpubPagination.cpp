//
// Created by skyne on 2024-01-03.
//
#include "EpubPagination.h"

class TextPaintData {
public:
    float textSize, letterSpacing;
    int typeface;
    float textScaleX, textSkewX;

    TextPaintData(float textSize, float letterSpacing, int typeface, float textScaleX,
                  float textSkewX) :
            textSize(textSize), letterSpacing(letterSpacing), typeface(typeface),
            textScaleX(textScaleX), textSkewX(textSkewX) {}

    float getScaleDiff(const TextPaintData &other) {
        return other.textSize * other.textScaleX * (1 - other.textSkewX) /
               (textSize * textScaleX * (1 - textSkewX));
    }

    float letterSpacingPx() { return letterSpacing * textSize; }
};

void applySpanStyle(TextPaintData& currentTextPaintData, TextPaintData& baseTextPaintData, float fontScale, float density, SpanStyle& item) {
    if(item.getFontSize().isSpecified())
        currentTextPaintData.textSize = item.getFontSize().toPx(baseTextPaintData.textSize, fontScale, density);

    if(item.getLetterSpacing().isSpecified()) {
        if(item.getLetterSpacing().isSpValue()) {
            int emWidth = baseTextPaintData.textSize * baseTextPaintData.textScaleX;
            if (emWidth)
                currentTextPaintData.letterSpacing = item.getLetterSpacing().toPx(baseTextPaintData.textSize, fontScale, density) / emWidth;
            else currentTextPaintData.letterSpacing = 0;
        }else
            currentTextPaintData.letterSpacing = item.getLetterSpacing().getValue();
    }
}

std::pair<Array<std::pair<int, int>>, int>
EpubPagination::
measureBreakAnnotatedText(JNIEnv *env, float density, float fontScale,
                          jobject paint,
                          jmethodID measureText,
                          const AnnotatedString &text, int viewportWidth,
                          float textSize, float letterSpacing, float textScaleX, float textSkewX,
                          float defaultLineHeight, bool wordBreak,
                          short* cacheArray, int defaultFontID,
                          jobject fontHandler, jmethodID fontMethodID, jobject fontByIdxHandler, jmethodID fontByIdxMethodID,
                          jclass integerClazz, jmethodID integerValueOf, jmethodID integerIntValue,
                          jclass booleanClazz, jmethodID booleanValueOf) {
    std::vector<std::pair<int, int>> list;
    const auto &spanStyles = text.getSpanStyles();
    const auto &paragraphStyles = text.getParagraphStyles();
    int spanIdx = 0, paraIdx = 0;
    TextPaintData baseTextPaintData = TextPaintData(textSize, letterSpacing, defaultFontID, textScaleX, textSkewX);
    TextPaintData currentTextPaintData = baseTextPaintData;

    jcharArray jCharArray = env->NewCharArray(text.length());
    env->SetCharArrayRegion(jCharArray, 0, text.length(), text.begin());

    int beforeTypeface = defaultFontID;

    if(defaultFontID != 0) {
        jobject idxObj = env->CallStaticObjectMethod(integerClazz, integerValueOf, defaultFontID);
        env->DeleteLocalRef(env->CallObjectMethod(fontByIdxHandler, fontByIdxMethodID, idxObj));
        env->DeleteLocalRef(idxObj);
    }

    std::pair<int, float> spaceData = {0, 0};

    defaultLineHeight = ceil(defaultLineHeight);
    int measureWidth = 0, currentHeight = defaultLineHeight, measureHeight = defaultLineHeight;
    int lineStartIdx = 0, idx = 0;
    float scaleDif = 1;
    float baseLetterSpacingPx = baseTextPaintData.letterSpacingPx();
    float currentLetterSpacingPx = baseLetterSpacingPx;

    while (idx < text.length()) {
        if (spanIdx < spanStyles.size() && spanStyles[spanIdx]->getEnd() == idx) {
            spanIdx++;
            currentTextPaintData = baseTextPaintData;
            if (beforeTypeface != currentTextPaintData.typeface) {
                jobject idxObj = env->CallStaticObjectMethod(integerClazz, integerValueOf, 0);
                env->DeleteLocalRef(env->CallObjectMethod(fontByIdxHandler, fontByIdxMethodID, idxObj));
                env->DeleteLocalRef(idxObj);
            }
        }
        if (paraIdx < paragraphStyles.size() && paragraphStyles[paraIdx]->getEnd() == idx) {
            paraIdx++;
            currentHeight = defaultLineHeight;
            scaleDif = 1;
            if (lineStartIdx == idx) measureHeight = currentHeight;
        }
        if (spanIdx < spanStyles.size() && spanStyles[spanIdx]->getStart() == idx) {
            const auto span = spanStyles[spanIdx];
            applySpanStyle(currentTextPaintData, baseTextPaintData, fontScale, density, span->getItem());
            scaleDif = baseTextPaintData.getScaleDiff(currentTextPaintData);
            currentLetterSpacingPx = currentTextPaintData.letterSpacingPx();

            jobject fontFamily = env->NewString(span->getItem().getFontFamily().begin(), span->getItem().getFontFamily().size());
            jobject fontWeight = env->CallStaticObjectMethod(integerClazz, integerValueOf, span->getItem().getFontWeight());
            jobject italicObj = env->CallStaticObjectMethod(booleanClazz, booleanValueOf, span->getItem().isItalic());
            jobject result = env->CallObjectMethod(fontHandler, fontMethodID, fontFamily, fontWeight, italicObj);
            int fontID = env->CallIntMethod(result, integerIntValue, result);
            env->DeleteLocalRef(fontFamily);
            env->DeleteLocalRef(fontWeight);
            env->DeleteLocalRef(italicObj);
            env->DeleteLocalRef(result);
            if(fontID >= 0) currentTextPaintData.typeface = fontID;

            measureHeight = measureHeight;
        }
        if (paraIdx < paragraphStyles.size() && paragraphStyles[paraIdx]->getStart() == idx) {
            currentHeight = ceil(paragraphStyles[paraIdx]->getItem().getLineHeight().toPx(textSize, fontScale, density));
            measureHeight = lineStartIdx == idx ? currentHeight : std::max(currentHeight, measureHeight);
        }

        if (currentTextPaintData.textSize == 0) {
            idx++;
            continue;
        }

        if (beforeTypeface != currentTextPaintData.typeface) {
            beforeTypeface = currentTextPaintData.typeface;
            if(cacheArray)
                memset(cacheArray, 0, (0x10FFFF + 1) * sizeof(short));
        }
        int c = text[idx];
        bool surrogate = 0;
        if (0xD800 <= c && c <= 0xD8FF && idx + 1 < text.length() && 0xDC00 <= text[idx + 1] && text[idx + 1] <= 0xDFFF) {
            c = (c - 0xD800) * 0x400 + (text[idx + 1] - 0xDC00) + 0x10000;
            surrogate = 1;
        }
        float charWidth;
        if (!cacheArray || !cacheArray[c]) {
            charWidth = env->CallFloatMethod(paint, measureText, jCharArray, idx, 1 + surrogate);
            if(cacheArray)
                cacheArray[c] = charWidth + 1;
        }else
            charWidth = cacheArray[c] - 1;

        charWidth -= baseLetterSpacingPx;
        measureWidth += ceil(charWidth * scaleDif + currentLetterSpacingPx);
        if (surrogate) idx++;

        if (wordBreak && c == ' ') spaceData = {idx, measureWidth};

        if (c == '\n' || measureWidth > viewportWidth && lineStartIdx != idx) {
//            float width = measureWidth;
            if (c == '\n') {
                measureWidth = 0;
                lineStartIdx = idx + 1;
            } else {
                if (spaceData.first > lineStartIdx && text[idx - surrogate - 1] != ' ') {
                    lineStartIdx = spaceData.first + 1;
                    measureWidth -= spaceData.second;
//                    width = spaceData.second;
                } else {
                    lineStartIdx = idx - surrogate;
                    measureWidth =
                            ceil(charWidth * scaleDif + currentLetterSpacingPx);
//                    width -= measureWidth;
                }
            }

            list.emplace_back(lineStartIdx, measureHeight);
            measureHeight = currentHeight;
        }
        idx++;
    }
    if (list.empty() || std::get<0>(list.back()) < text.length()) {
        list.emplace_back(text.length(), measureHeight);
    }
    env->DeleteLocalRef(jCharArray);

    jobject idxObj = env->CallStaticObjectMethod(integerClazz, integerValueOf, 0);
    env->DeleteLocalRef(env->CallObjectMethod(fontByIdxHandler, fontByIdxMethodID, idxObj));
    env->DeleteLocalRef(idxObj);
    return {{list.data(), static_cast<int>(list.size()), true}, currentTextPaintData.typeface};
}

Array<std::shared_ptr<EpubElement>>
pagination(JNIEnv *env, Array<std::shared_ptr<EpubElement>> elements,
           jobject paint,
           float density, float fontScale, int viewportWidth, int viewportHeight,
           float textSize, float letterSpacing, float textScaleX, float textSkewX,
           float defaultLineHeight, bool wordBreak,
           jmethodID measureText, int &height, int &pageStartKey, int &pageKey,
//           float& marginSubtractPx,
           short* cacheArray, int& defaultFontID,
           jobject fontHandler, jmethodID fontMethodID, jobject fontByIdxHandler, jmethodID fontByIdxMethodID,
           jclass integerClazz, jmethodID integerValueOf, jmethodID integerIntValue,
           jclass booleanClazz, jmethodID booleanValueOf,
           const EpubPagination::PageHandler &pageHandler) {
    std::vector<std::shared_ptr<EpubElement>> result;
    for (const auto &element: elements) {
        switch (element->getType()) {
            case EpubElementData::EpubElementText: {
                EpubElementText *item = static_cast<EpubElementText *>(element.get());
                auto [layout, latestTypeface] = EpubPagination::measureBreakAnnotatedText(env,
                                                                                          density, fontScale, paint,
                                                                                          measureText,
                                                                                          item->text(),
                                                                                          viewportWidth,
                                                                                          textSize, letterSpacing,
                                                                                          textScaleX, textSkewX,
                                                                                          defaultLineHeight, wordBreak,
                                                                                          cacheArray, defaultFontID,
                                                                                          fontHandler, fontMethodID, fontByIdxHandler, fontByIdxMethodID,
                                                                                          integerClazz, integerValueOf, integerIntValue,
                                                                                          booleanClazz, booleanValueOf);
                defaultFontID = latestTypeface;

                int startIdx = 0, currentIdx = 0;
                for (auto [lineEnd, lineHeight]: layout) {
                    if (height + lineHeight > viewportHeight) {
                        if (startIdx < currentIdx)
                            result.emplace_back(std::shared_ptr<EpubElementText>(new EpubElementText(item->text().subSequence(startIdx, currentIdx))));
                        pageHandler(result, pageStartKey);
                        result.clear();
                        startIdx = currentIdx;
                        pageStartKey = pageKey;
                        height = 0;
                    }
                    height += lineHeight;
                    pageKey += lineEnd - currentIdx;
                    currentIdx = lineEnd;
                }
                if (startIdx < currentIdx)
                    result.emplace_back(std::unique_ptr<EpubElementText>(
                            new EpubElementText(item->text().subSequence(startIdx, currentIdx))));
//                marginSubtractPx = 0;
                break;
            }
            case EpubElementData::EpubElementDivider: {
                int dividerHeight = ceil(textSize);
//                if(marginSubtractPx > 0) {
//                    dividerHeight -= std::min(marginSubtractPx, dividerHeight / 2);
//                }
                if (height + dividerHeight > viewportHeight) {
                    pageHandler(result, pageStartKey);
                    result.clear();
                    pageStartKey = pageKey;
                    height = 0;
                }
                result.emplace_back(element);
                height += dividerHeight;
                pageKey++;
//                marginSubtractPx = dividerHeight / 2;
                break;
            }
            case EpubElementData::EpubElementImage: {
                EpubElementImage *item = static_cast<EpubElementImage *>(element.get());
                int scaledHeight = ceil(std::min(static_cast<float>(viewportWidth) / item->getWidth(), static_cast<float>(viewportHeight) / item->getHeight()) * item->getHeight());
                if (height + scaledHeight > viewportHeight) {
                    pageHandler(result, pageStartKey);
                    result.clear();
                    pageStartKey = pageKey;
                    height = 0;
                }
                result.emplace_back(element);
                height += scaledHeight;
                pageKey++;
//                marginSubtractPx = 0;
                break;
            }
            case EpubElementData::EpubElementBox: {
                EpubElementBox *item = static_cast<EpubElementBox *>(element.get());
                TextUnit marginTop = item->getMargin().getTop();
                float marginTopPx = marginTop.toPx(textSize, fontScale, density, true);
//                if(marginTopPx > 0 && marginSubtractPx > 0) {
//                    marginTopPx = std::max(0.F, marginTopPx - marginSubtractPx);
//                    marginSubtractPx += marginTopPx;
//                    marginTop = TextUnit(marginTopPx / textSize / fontScale / (marginTop.isEmValue() ? textSize : 1), marginTop.isEmValue());
//                }
                TextUnit borderTop = item->getBorder().getTop();
//                float borderTopPx = borderTop.toPx(textSize, fontScale, density, true);
                TextUnit paddingTop = item->getPadding().getTop();
                float paddingTopPx = paddingTop.toPx(textSize, fontScale, density, true);
                TextUnit borderLeftTop = item->getBorderRadius().getTop();
                TextUnit borderRightTop = item->getBorderRadius().getRight();
                if (height + marginTopPx > viewportHeight) {
                    pageHandler(result, pageStartKey);
                    result.clear();
                    pageStartKey = pageKey;
                    marginTopPx = std::max(0.F, marginTopPx - viewportHeight + height);
                    height = 0;
                    marginTop = TextUnit(marginTopPx / density / fontScale /
                                         (marginTop.isEmValue() ? textSize : 1),
                                         marginTop.isEmValue());
                }
                height += ceil(marginTopPx)/* + ceil(borderTopPx)*/ + ceil(paddingTopPx);

//                if(borderTopPx > 0 || paddingTopPx > 0) marginSubtractPx = 0;

                auto remainData = pagination(env, item->getValue(), paint,
                                             density, fontScale,
                                             viewportWidth -
                                             item->getMargin().horizontalPx(textSize, fontScale, density, true)
//                                             - item->getBorder().horizontalPx(textSize, fontScale, density, true)
                                             - item->getPadding().horizontalPx(textSize, fontScale, density, true),
                                             viewportHeight,
                                             textSize, letterSpacing, textScaleX, textSkewX,
                                             defaultLineHeight, wordBreak,
                                             measureText, height, pageStartKey, pageKey,
//                                             marginSubtractPx,
                                             cacheArray, defaultFontID,
                                             fontHandler, fontMethodID, fontByIdxHandler, fontByIdxMethodID,
                                             integerClazz, integerValueOf, integerIntValue,
                                             booleanClazz, booleanValueOf,
                                             [&item, &result, &marginTop, &borderTop, &paddingTop, &borderLeftTop, &borderRightTop, &pageHandler](const std::vector<std::shared_ptr<EpubElement>>& page, int key) {
                    result.emplace_back(std::shared_ptr<EpubElementBox>(new EpubElementBox({page.data(), static_cast<int>(page.size())},
                                                                                        item->getMargin().copy(marginTop, DefaultTextUnit::Unspecified, DefaultTextUnit::Zero),
                                                                                        item->getPadding().copy(paddingTop, DefaultTextUnit::Unspecified, DefaultTextUnit::Zero),
                                                                                        item->getBorder().copy(borderTop, DefaultTextUnit::Unspecified, DefaultTextUnit::Zero),
                                                                                        item->getBorderRadius().copy(borderLeftTop, borderRightTop, DefaultTextUnit::Zero, DefaultTextUnit::Zero))));
                    pageHandler(result, key);
                    result.clear();
                    marginTop = DefaultTextUnit::Zero;
                    paddingTop = DefaultTextUnit::Zero;
                    borderTop = DefaultTextUnit::Zero;
                    borderLeftTop = DefaultTextUnit::Zero;
                    borderRightTop = DefaultTextUnit::Zero;
                });

//                TextUnit marginBottom = item->getMargin().getBottom();
//                float marginBottomPx = marginBottom.toPx(textSize, fontScale, density, true);
//                if(marginBottomPx > 0 && marginSubtractPx > 0) {
//                    marginBottomPx = std::max(0.F, marginBottomPx - marginSubtractPx);
//                    marginSubtractPx += marginBottomPx;
//                    marginBottom = TextUnit(marginBottomPx / textSize / fontScale / (marginBottom.isEmValue() ? textSize : 1), marginBottom.isEmValue());
//                }else marginSubtractPx = std::max(marginBottomPx, marginSubtractPx);
                height += ceil(item->getMargin().getBottom().toPx(textSize, fontScale, density, true))
                          + ceil(item->getBorder().getBottom().toPx(textSize, fontScale, density, true))
                          + ceil(item->getPadding().getBottom().toPx(textSize, fontScale, density, true));

                result.emplace_back(std::shared_ptr<EpubElementBox>(new EpubElementBox(remainData,
                                                                                    item->getMargin().copy(marginTop/*, DefaultTextUnit::Unspecified, marginBottom*/),
                                                                                    item->getPadding().copy(paddingTop),
                                                                                    item->getBorder().copy(borderTop),
                                                                                    item->getBorderRadius().copy(borderLeftTop, borderRightTop))));
                break;
            }
            default: break;
        }
    }
    return Array<std::shared_ptr<EpubElement>>(result.data(), static_cast<int>(result.size()));
}

std::pair<Array<std::shared_ptr<EpubElement>>, int>
EpubPagination::pagination(JNIEnv *env, const EpubPage &page, jobject paint,
                           float density, float fontScale,
                           int viewportWidth, int viewportHeight,
                           float textSize, float letterSpacing, float textScaleX,
                           float textSkewX, float defaultLineHeight, bool wordBreak,
                           jobject fontHandler, jobject fontByIdxHandler, const PageHandler &pageHandler) {
    jclass textPaintClazz = env->GetObjectClass(paint);
    jmethodID measureText = env->GetMethodID(textPaintClazz, "measureText", "([CII)F");

    jclass fontHandlerClazz = env->GetObjectClass(fontHandler);
    jmethodID fontMethodID = env->GetMethodID(fontHandlerClazz, "invoke", "(Ljava/lang/Object;Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");

    jclass fontByIdxHandlerClazz = env->GetObjectClass(fontByIdxHandler);
    jmethodID fontByIdxMethodID = env->GetMethodID(fontByIdxHandlerClazz, "invoke", "(Ljava/lang/Object;)Ljava/lang/Object;");

    jclass integerClazz = env->FindClass("java/lang/Integer");
    jmethodID integerValueOf = env->GetStaticMethodID(integerClazz, "valueOf", "(I)Ljava/lang/Integer;");
    jmethodID integerIntValue = env->GetMethodID(integerClazz, "intValue", "()I");

    jclass booleanClazz = env->FindClass("java/lang/Boolean");
    jmethodID booleanValueOf = env->GetStaticMethodID(booleanClazz, "valueOf", "(Z)Ljava/lang/Boolean;");

    std::shared_ptr<short> cacheArray = std::shared_ptr<short>(static_cast<short*>(calloc(0x10FFFF + 1, sizeof(short))), [](short* value){ free(value); });
    int defaultFontID = 0;

    int height = 0;
    int pageStartKey = 0, pageKey = 0;
    float marginSubtractPx = 0;
    auto remainData = pagination(env, page.getDocument(), paint,
                                 density, fontScale, viewportWidth, viewportHeight,
                                 textSize, letterSpacing, textScaleX, textSkewX, defaultLineHeight, wordBreak,
                                 measureText, height, pageStartKey, pageKey,
//                                 marginSubtractPx,
                                 cacheArray.get(), defaultFontID,
                                 fontHandler, fontMethodID, fontByIdxHandler, fontByIdxMethodID,
                                 integerClazz, integerValueOf, integerIntValue,
                                 booleanClazz, booleanValueOf,
                                 pageHandler);

    env->DeleteLocalRef(textPaintClazz);
    env->DeleteLocalRef(fontHandlerClazz);
    env->DeleteLocalRef(fontByIdxHandlerClazz);
    env->DeleteLocalRef(integerClazz);
    env->DeleteLocalRef(booleanClazz);

    return {remainData, pageStartKey};
}