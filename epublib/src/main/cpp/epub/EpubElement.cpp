//
// Created by skyne on 2023-12-26.
//

#include "EpubElement.h"

EpubElementData EpubPageParseElementBlock::getType() const { return EpubElementData::EpubElementBox; }

EpubElementData EpubPageParseElementImage::getType() const { return EpubElementData::EpubElementImage; }

EpubElementData EpubPageParseElementDivider::getType() const { return EpubElementData::EpubElementDivider; }

EpubElementData EpubPageParseElementText::getType() const { return EpubElementData::EpubElementText; }

EpubElementData EpubElementBox::getType() const { return EpubElementData::EpubElementBox; }

EpubElementData EpubElementImage::getType() const { return EpubElementData::EpubElementImage; }

EpubElementData EpubElementDivider::getType() const { return EpubElementData::EpubElementDivider; }

EpubElementData EpubElementText::getType() const { return EpubElementData::EpubElementText; }

void RectTextUnit::save(ByteBuf &buf) const {
    top.save(buf);
    right.save(buf);
    bottom.save(buf);
    left.save(buf);
}

RectTextUnit* RectTextUnit::load(ByteBuf &buf) {
    top.load(buf);
    right.load(buf);
    bottom.load(buf);
    left.load(buf);

    return this;
}

const RectTextUnit
RectTextUnit::copy(const TextUnit &newTop, const TextUnit &newRight, const TextUnit &newBottom,
                   const TextUnit &newLeft) const {
    return RectTextUnit(newTop.isUnSpecified() ? top : newTop,
                        newRight.isUnSpecified() ? right : newRight,
                        newBottom.isUnSpecified() ? bottom : newBottom,
                        newLeft.isUnSpecified() ? left : newLeft);
}

void EpubElementDivider::save(ByteBuf &buf) const {
    buf.writeVarInt(static_cast<int>(EpubElementData::EpubElementDivider));
}

void EpubElementImage::save(ByteBuf &buf) const {
    buf.writeVarInt(static_cast<int>(EpubElementData::EpubElementImage))
    .writeString(src).writeVarInt(width).writeVarInt(height);
}

EpubElementImage* EpubElementImage::load(ByteBuf &buf) {
    src = buf.readString();
    width = buf.readVarInt();
    height = buf.readVarInt();

    return this;
}

void EpubElementText::save(ByteBuf &buf) const {
    buf.writeVarInt(static_cast<int>(EpubElementData::EpubElementText)).writeString(value.text());
    buf.writeVarInt(value.getParagraphStyles().size());
    for(const Range<ParagraphStyle>& para : value.getParagraphStyles()) {
        buf.writeVarInt(para.getStart()).writeVarInt(para.getEnd());
        para.getItem().getLineHeight().save(buf);
    }
    buf.writeVarInt(value.getSpanStyles().size());
    for(const Range<SpanStyle>& span : value.getSpanStyles()) {
        buf.writeVarInt(span.getStart()).writeVarInt(span.getEnd())
        .writeString(span.getItem().getFontFamily());
        span.getItem().getColor().save(buf);
        span.getItem().getFontSize().save(buf);
        buf.writeVarInt(span.getItem().getFontWeight().getWeight());
        span.getItem().getLetterSpacing().save(buf);
        span.getItem().getTextDecoration().save(buf);
        buf.writeBool(span.getItem().isItalic());
    }
}

EpubElementText* EpubElementText::load(ByteBuf &buf) {
    JString text = buf.readString();
    auto para = Array<Range<ParagraphStyle>>(buf.readVarInt());
    for(int i = 0; i < para.size(); i++) {
        int start = buf.readVarInt();
        int end = buf.readVarInt();
        *para[i] = Range<ParagraphStyle>(ParagraphStyle(TextUnit().load(buf)), start, end);
    }
    auto span = Array<Range<SpanStyle>>(buf.readVarInt());
    for(int i = 0; i < span.size(); i++) {
        int start = buf.readVarInt();
        int end = buf.readVarInt();
        JString fontFamily = buf.readString();
        Color color = Color().load(buf);
        TextUnit fontSize = TextUnit().load(buf);
        int fontWeight = buf.readVarInt();
        TextUnit letterSpacing = TextUnit().load(buf);
        TextDecoration textDecoration = TextDecoration().load(buf);
        bool isItalic = buf.readBool();
        *span[i] = Range<SpanStyle>(SpanStyle(fontFamily, color, fontSize, FontWeight(fontWeight), letterSpacing, textDecoration, isItalic), start, end);
    }
    value = AnnotatedString(text, span, para);

    return this;
}

void EpubElementBox::save(ByteBuf &buf) const {
    buf.writeVarInt(static_cast<int>(EpubElementData::EpubElementBox));
    margin.save(buf);
    padding.save(buf);
    border.save(buf);
    borderRadius.save(buf);
    buf.writeVarInt(value.size());
    for(const std::shared_ptr<EpubElement>& element : value) {
        element.get()->save(buf);
    }
}

EpubElementBox* EpubElementBox::load(ByteBuf &buf) {
    margin.load(buf);
    padding.load(buf);
    border.load(buf);
    borderRadius.load(buf);
    value = Array<std::shared_ptr<EpubElement>>(buf.readVarInt());
    for(int i = 0; i < value.size(); i++) {
        *value[i] = loadEpubElement(buf, buf.readVarInt());
    }

    return this;
}

std::shared_ptr<EpubElement> loadEpubElement(ByteBuf& buf, int id) {
    switch(id) {
        case static_cast<int>(EpubElementData::EpubElementDivider): return std::shared_ptr<EpubElementDivider>((new EpubElementDivider())->load(buf));
        case static_cast<int>(EpubElementData::EpubElementImage): return std::shared_ptr<EpubElementImage>((new EpubElementImage())->load(buf));
        case static_cast<int>(EpubElementData::EpubElementText): return std::shared_ptr<EpubElementText>((new EpubElementText())->load(buf));
        case static_cast<int>(EpubElementData::EpubElementBox): return std::shared_ptr<EpubElementBox>((new EpubElementBox())->load(buf));
    }
    return std::shared_ptr<EpubElement>(new EpubElement());
}