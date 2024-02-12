//
// Created by skyne on 2023-12-30.
//

#include "DefaultStyle.h"
namespace DefaultStyle {
    const static std::unordered_map<JString, std::unordered_map<JString, JString>> styles = {
            {"div", { {"display", "block"} }},
            {"h1", { {"display", "block"}, {"font-size", "2em"}, {"margin-top", "0.67em"}, {"margin-bottom", "0.67em"}, {"font-weight", "bold"} }},
            {"h2", { {"display", "block"}, {"font-size", "1.5em"}, {"margin-top", "0.83em"}, {"margin-bottom", "0.83em"}, {"font-weight", "bold"} }},
            {"h3", { {"display", "block"}, {"font-size", "1.17em"}, {"margin-top", "1em"}, {"margin-bottom", "0.1em"}, {"font-weight", "bold"} }},
            {"h4", { {"display", "block"}, {"margin-top", "1.33em"}, {"margin-bottom", "1.33em"}, {"font-weight", "bold"} }},
            {"h5", { {"display", "block"}, {"font-size", "0.83em"}, {"margin-top", "1.67em"}, {"margin-bottom", "1.67em"}, {"font-weight", "bold"} }},
            {"h6", { {"display", "block"}, {"font-size", "0.67em"}, {"margin-top", "2.33em"}, {"margin-bottom", "2.33em"}, {"font-weight", "bold"} }},
            {"p", { {"display", "block"}, {"margin-top", "1em"}, {"margin-bottom", "1em"} }},
            {"pre", { {"display", "block"}, {"margin-top", "1em"}, {"margin-bottom", "1em"} }},
            {"b", { {"font-weight", "bold"} }},
            {"ul", { {"display", "block"} }},
            {"li", { {"display", "block"} }},
            {"i", { {"font-style", "italic"} }},
            {"a", { {"color", "#0000EE"} }},
    };

    const std::unordered_map<JString, JString>* getDefaultStyle(const JString& element) {
        auto it = styles.find(element);
        if(it != styles.end()) return &it->second;
        return nullptr;
    }
};