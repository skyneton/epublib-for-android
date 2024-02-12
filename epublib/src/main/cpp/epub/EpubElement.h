//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_EPUBELEMENT_H
#define TEXTREADER_EPUBELEMENT_H

#pragma once
#include "../utils/JString.h"
#include "vector"
#include "../utils/ByteBuf.h"
#include "../utils/AnnotatedString.h"

enum class EpubElementData {
    EpubElementDivider,
    EpubElementImage,
    EpubElementText,
    EpubElementBox,
    None = -1
};

class RectTextUnit {
private:
    TextUnit top, right, bottom, left;
public:
    RectTextUnit() {}
    RectTextUnit(TextUnit top, TextUnit right, TextUnit bottom, TextUnit left): top(top), right(right), bottom(bottom), left(left) {}
    RectTextUnit(const Array<JString>& values):
    RectTextUnit(TextUnit::toTextUnit(values[0]), TextUnit::toTextUnit(values[1]), TextUnit::toTextUnit(values[2]), TextUnit::toTextUnit(values[3])) {}
    void save(ByteBuf &buf) const;
    RectTextUnit* load(ByteBuf &buf);

    const TextUnit& getTop() const { return top; }
    const TextUnit& getRight() const { return right; }
    const TextUnit& getBottom() const { return bottom; }
    const TextUnit& getLeft() const { return left; }
    const float horizontalPx(float textSize, float fontScale, float density, bool unspecifiedZero = false) const { return ceil(left.toPx(textSize, fontScale, density, unspecifiedZero)) + ceil(right.toPx(textSize, fontScale, density, unspecifiedZero)); }
    const RectTextUnit copy(const TextUnit& newTop = DefaultTextUnit::Unspecified,
                            const TextUnit& newRight = DefaultTextUnit::Unspecified,
                            const TextUnit& newBottom = DefaultTextUnit::Unspecified,
                            const TextUnit& newLeft = DefaultTextUnit::Unspecified) const;
};

class EpubPageParseElement {
private:
    JString element, id, className;
public:
    virtual EpubElementData getType() const { return EpubElementData::None; }
    EpubPageParseElement(const JString& element, const JString& id, const JString& className): element(element), id(id), className(className) {}
    const JString& getElementName() const { return element; }
    const JString& getIdName() const { return id; }
    const JString& getClassName() const { return className; }
};

class EpubPageParseElementBlock: public EpubPageParseElement {
private:
    std::vector<std::shared_ptr<EpubPageParseElement>>value;
public:
    EpubElementData getType() const override;
    EpubPageParseElementBlock(const JString& element, const JString& id, const JString& className): EpubPageParseElement(element, id, className) { }
    const std::vector<std::shared_ptr<EpubPageParseElement>>& getValue() const { return value; }
    std::vector<std::shared_ptr<EpubPageParseElement>>& getValue() { return value; }
};

class EpubPageParseElementDivider: public EpubPageParseElement {
public:
    EpubElementData getType() const override;
    EpubPageParseElementDivider(const JString& element, const JString& id, const JString& className): EpubPageParseElement(element, id, className) { }
};

class EpubPageParseElementImage: public EpubPageParseElement {
private:
    JString src;
    int width, height;
public:
    EpubElementData getType() const override;
    EpubPageParseElementImage(const JString& element, const JString& id, const JString& className, const JString& src, int width, int height): EpubPageParseElement(element, id, className), src(src), width(width), height(height) { }
    const JString& getSrc() const { return src; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

class EpubPageParseElementText: public EpubPageParseElement {
private:
    JString value;
public:
    EpubElementData getType() const override;
    EpubPageParseElementText(const JString& text): EpubPageParseElement("", "", ""), value(text) {}
    const JString& text() const { return value; }
};

class EpubElement {
public:
    virtual EpubElementData getType() const { return EpubElementData::None; }
    virtual void save(ByteBuf& buf) const {}
    virtual EpubElement* load(ByteBuf& buf) { return this; }
};

class EpubElementDivider: public EpubElement {
public:
    EpubElementData getType() const override;
    void save(ByteBuf &buf) const override;
    EpubElementDivider* load(ByteBuf &buf) override { return this; }
};

class EpubElementImage: public EpubElement {
private:
    JString src;
    int width, height;
public:
    EpubElementData getType() const override;
    EpubElementImage(const JString& src, int width, int height): src(src), width(width), height(height) {}
    EpubElementImage(): EpubElementImage("", 0, 0) {}
    void save(ByteBuf &buf) const override;
    EpubElementImage* load(ByteBuf &buf) override;
    const JString& getSrc() const { return src; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

class EpubElementText: public EpubElement {
private:
    AnnotatedString value;
public:
    EpubElementData getType() const override;
    EpubElementText() {}
    EpubElementText(const AnnotatedString& value): value(value) {}
    const AnnotatedString& text() const { return value; }
    void save(ByteBuf &buf) const override;
    EpubElementText* load(ByteBuf &buf) override;
};

class EpubElementBox: public EpubElement {
private:
    Array<std::shared_ptr<EpubElement>> value;
    RectTextUnit margin, padding, border, borderRadius;
public:
    EpubElementData getType() const override;
    EpubElementBox() {}
    EpubElementBox(const Array<std::shared_ptr<EpubElement>>& value, const RectTextUnit& margin, const RectTextUnit& padding, const RectTextUnit& border, const RectTextUnit& borderRadius):
    value(value), margin(margin), padding(padding), border(border), borderRadius(borderRadius) {}
    void save(ByteBuf &buf) const override;
    EpubElementBox* load(ByteBuf &buf) override;

    const RectTextUnit& getMargin() { return margin; }
    const RectTextUnit& getPadding() { return padding; }
    const RectTextUnit& getBorder() { return border; }
    const RectTextUnit& getBorderRadius() { return borderRadius; }
    const Array<std::shared_ptr<EpubElement>>& getValue() const { return value; }
};

std::shared_ptr<EpubElement> loadEpubElement(ByteBuf& buf, int id);
#endif //TEXTREADER_EPUBELEMENT_H
