//
// Created by skyne on 2023-11-13.
//

#ifndef TEXTREADER_CSSSELECTOR_H
#define TEXTREADER_CSSSELECTOR_H


#include "../utils/JString.h"

class CssSelector {
private:
    JString elementName, id, className;
public:
    CssSelector() {}
    CssSelector(const JString& elementName, const JString& id, const JString& className): elementName(elementName), id(id), className(className) {}

    const JString& getElementName() const { return elementName; }
    const JString& getId() const { return id; }
    const JString& getClassName() const { return className; }

    JString toString() const;

    size_t hashCode() const {
        size_t h = elementName.hashCode();
        h = h * 31 + id.hashCode();
        h = h * 31 + className.hashCode();
        return h;
    }

    bool operator<(const CssSelector& other) const {
        return this->hashCode() < other.hashCode();
    }
    bool operator>(const CssSelector& other) const {
        return this->hashCode() > other.hashCode();
    }
    bool operator==(const CssSelector& other) const {
        return elementName == other.elementName && other.id == id && other.className == className;
    }
    bool contains(const CssSelector& other) const {
        return (elementName == '*' || elementName == other.elementName)
               && (id == '*' || other.id == id)
               && (className == '*' || other.className == className);
    }
    bool contains(const JString& element, const JString& i, const JString& cls) const {
        return (this->elementName == '*' || this->elementName == element)
               && (this->id == '*' || this->id == i)
               && (this->className == '*' || this->className == cls);
    }
};

template<>
class std::hash<CssSelector> {
public:
    size_t operator()(const CssSelector& o) const {
        return o.hashCode();
    }
};

#endif //TEXTREADER_CSSSELECTOR_H
