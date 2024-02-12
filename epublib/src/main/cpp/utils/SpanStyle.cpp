//
// Created by skyne on 2023-12-26.
//

#include "SpanStyle.h"

bool SpanStyle::operator==(const SpanStyle &other) const {
    if(this == &other) return 1;
    return !(fontFamily != other.fontFamily || color != other.color || fontSize != other.fontSize || fontWeight != other.fontWeight || italic != other.italic);
}