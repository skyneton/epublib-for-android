//
// Created by skyne on 2023-12-26.
//

#ifndef TEXTREADER_ANNOTATEDSTRING_H
#define TEXTREADER_ANNOTATEDSTRING_H
#pragma once
#include "JString.h"
#include "JStringBuilder.h"
#include "Range.h"
#include "SpanStyle.h"
#include "ParagraphStyle.h"
#include "vector"

class AnnotatedString {
private:
    Array<Range<SpanStyle>> spanStyles;
    Array<Range<ParagraphStyle>> paragraphStyles;
    JString value;
public:
    AnnotatedString() {}
    AnnotatedString(const JString& text, const Array<Range<SpanStyle>>& spanStyles, const Array<Range<ParagraphStyle>>& paragraphStyles): value(text), spanStyles(spanStyles), paragraphStyles(paragraphStyles) {}
    const Array<Range<SpanStyle>>& getSpanStyles() const { return spanStyles; }
    const Array<Range<ParagraphStyle>>& getParagraphStyles() const { return paragraphStyles; }
    const JString& text() const { return value; }
    int length() const { return value.size(); }
    unsigned short operator[](int i) { return value[i]; }
    unsigned short operator[](int i) const { return value[i]; }
    const unsigned short* begin() const { return value.begin(); }
    const unsigned short* end() const { return value.end(); }
    const AnnotatedString subSequence(int start, int end) const;
};

class AnnotatedStringBuilder {
private:
    std::vector<Range<SpanStyle>> spanStyles;
    std::vector<Range<ParagraphStyle>> paragraphStyles;
    JStringBuilder builder;
public:
    AnnotatedStringBuilder() {}
    AnnotatedStringBuilder(const JString& text): builder(text) {}
    AnnotatedStringBuilder(const AnnotatedString& text);

    int length() { return builder.length(); }
    bool empty() { return builder.empty(); }

    AnnotatedStringBuilder& append(const JString& text);
    AnnotatedStringBuilder& append(const AnnotatedString& text);
    AnnotatedStringBuilder& addStyle(const SpanStyle& spanStyle, int start, int end);
    AnnotatedStringBuilder& addStyle(const ParagraphStyle& paragraphStyle, int start, int end);
    AnnotatedStringBuilder& addStyle(const Range<SpanStyle>& spanStyle);
    AnnotatedStringBuilder& addStyle(const Range<ParagraphStyle>& paragraphStyle);
    AnnotatedStringBuilder& addStyleAll(const Array<Range<SpanStyle>>& styles);
    AnnotatedStringBuilder& addStyleAll(const Array<Range<ParagraphStyle>>& styles);

    const std::vector<Range<SpanStyle>>& getSpanStyles() const { return spanStyles; }
    const std::vector<Range<ParagraphStyle>>& getParagraphStyles() const { return paragraphStyles; }

    void clear();

    AnnotatedString toAnnotatedString();
};

#endif //TEXTREADER_ANNOTATEDSTRING_H
