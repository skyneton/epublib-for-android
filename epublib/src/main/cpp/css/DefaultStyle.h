//
// Created by skyne on 2023-12-30.
//
#include "../utils/JString.h"
#include "unordered_map"
namespace DefaultStyle {
    const std::unordered_map<JString, JString>* getDefaultStyle(const JString& element);
};