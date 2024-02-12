//
// Created by skyne on 2023-11-13.
//

#include "CssSelector.h"
#include "../utils/JStringBuilder.h"

JString CssSelector::toString() const {
    JStringBuilder result = elementName;
    result += '#'; result += id;
    result += '.'; result += className;
    return result.toString();
}
