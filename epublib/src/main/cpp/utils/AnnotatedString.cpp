//
// Created by skyne on 2023-12-26.
//

#include "AnnotatedString.h"

template<typename T>
Array<Range<T>> filterRanges(const Array<Range<T>>& ranges, int start, int end) {
    std::vector<Range<T>>v;
    for(const Range<T>& value : ranges) {
        if(value.getStart() > end) break;
        if(value.getEnd() <= start) continue;
        v.emplace_back(value.getItem(), std::max(0, value.getStart() - start), std::min(end, value.getEnd()) - start);
    }
    return {v.data(), static_cast<int>(v.size())};
}

const AnnotatedString AnnotatedString::subSequence(int start, int end) const {
    return AnnotatedString(value.substring(start, end),
                           filterRanges<SpanStyle>(spanStyles, start, end),
                                   filterRanges<ParagraphStyle>(paragraphStyles, start, end));
}

AnnotatedStringBuilder::AnnotatedStringBuilder(const AnnotatedString& text) {
    builder.append(text.text());
    spanStyles.insert(spanStyles.end(), text.getSpanStyles().begin(), text.getSpanStyles().end());
    paragraphStyles.insert(paragraphStyles.end(), text.getParagraphStyles().begin(), text.getParagraphStyles().end());
}

AnnotatedStringBuilder &AnnotatedStringBuilder::append(const JString &text) {
    builder.append(text);
    return *this;
}

AnnotatedStringBuilder &AnnotatedStringBuilder::append(const AnnotatedString &text) {
    int start = builder.length();
    builder.append(text.text());
    for(const Range<SpanStyle>& spanStyle : text.getSpanStyles()) {
        addStyle(spanStyle.getItem(), start + spanStyle.getStart(), start + spanStyle.getEnd());
    }
    for(const Range<ParagraphStyle>& paragraph : text.getParagraphStyles()) {
        addStyle(paragraph.getItem(), start + paragraph.getStart(), start + paragraph.getEnd());
    }
    return *this;
}

AnnotatedStringBuilder &AnnotatedStringBuilder::addStyle(const Range<SpanStyle> &spanStyle) {
    spanStyles.emplace_back(spanStyle);
    return *this;
}

AnnotatedStringBuilder &
AnnotatedStringBuilder::addStyle(const Range<ParagraphStyle> &paragraphStyle) {
    paragraphStyles.emplace_back(paragraphStyle);
    return *this;
}

AnnotatedStringBuilder &
AnnotatedStringBuilder::addStyleAll(const Array<Range<SpanStyle>> &styles) {
    spanStyles.insert(spanStyles.end(), styles.begin(), styles.end());
    return *this;
}

AnnotatedStringBuilder &
AnnotatedStringBuilder::addStyleAll(const Array<Range<ParagraphStyle>> &styles) {
    paragraphStyles.insert(paragraphStyles.end(), styles.begin(), styles.end());
    return *this;
}

AnnotatedStringBuilder &
AnnotatedStringBuilder::addStyle(const SpanStyle &spanStyle, int start, int end) {
    spanStyles.emplace_back(spanStyle, start, end);
    return *this;
}

AnnotatedStringBuilder &
AnnotatedStringBuilder::addStyle(const ParagraphStyle &paragraphStyle, int start, int end) {
    paragraphStyles.emplace_back(paragraphStyle, start, end);
    return *this;
}

AnnotatedString AnnotatedStringBuilder::toAnnotatedString() {
    return AnnotatedString(builder.toString(), Array<Range<SpanStyle>>(spanStyles.data(), spanStyles.size()), Array<Range<ParagraphStyle>>(paragraphStyles.data(), paragraphStyles.size()));
}

void AnnotatedStringBuilder::clear() {
    builder.clear();
    spanStyles.clear();
    paragraphStyles.clear();
}