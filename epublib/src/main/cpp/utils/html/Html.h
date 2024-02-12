//
// Created by skyne on 2024-02-02.
//

#ifndef TEXTREADER_HTML_H
#define TEXTREADER_HTML_H

#endif //TEXTREADER_HTML_H
#pragma once
#include "../JString.h"
#include "utility"

namespace Html {
    JString decodeHtml(const JString& str, int start = 0, int end = -1);
}
