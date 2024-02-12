//
// Created by skyne on 2023-11-10.
//

#ifndef TEXTREADER_JSTRINGBUILDER_H
#define TEXTREADER_JSTRINGBUILDER_H
#pragma once

#include "vector"
#include "JString.h"

class JStringBuilder: public std::vector<unsigned short> {
private:
public:
    JStringBuilder(const std::__wrap_iter<unsigned short *> first, const std::__wrap_iter<unsigned short *> last): vector(first, last) {}
    JStringBuilder(std::vector<unsigned short>::const_iterator first, std::vector<unsigned short>::const_iterator last): vector(first, last) {}
    JStringBuilder(const unsigned short* str, int size);
    JStringBuilder(const JString& str);
    JStringBuilder(): vector() {}
    JStringBuilder(const char* str);
    JStringBuilder(char c);

    size_t length() const;
    JStringBuilder& append(const unsigned short* s, size_t n);
    JStringBuilder& append(const JString& s);
    JStringBuilder& append(const JStringBuilder& s, size_t n);
    JStringBuilder& append(const JStringBuilder& s);
    JStringBuilder& append(const char* s);
    JStringBuilder& append(const unsigned short* s);
    JStringBuilder& append(const unsigned short c);
    JStringBuilder& append(const char c);
    int find(char value, int start);
    JStringBuilder substr(int pos = 0, int len = -1) const;
    JStringBuilder& ltrim();
    JStringBuilder& rtrim();
    JStringBuilder& trim();
    std::string to_str() const;
    JString toString() const { return JString(data(), size()); };

    bool startsWith(const unsigned short c) const;

    JStringBuilder lower();
    JStringBuilder upper();

    size_t hashCode() const {
//        size_t h = 0;
//        for(const unsigned short c : *this) {
//            h = h * 31 + c;
//        }
//        return h;
        size_t hash = (size_t) this->size() << 24;
        for(int i = 0; i < 2 && i < this->size(); i++) {
            hash |= (((*this)[i] >> 8) ^ ((*this)[i] & 0xFF)) << (8 << (1 - i));
        }
        if(!this->empty()) {
            hash |= (this->back() >> 8) ^ (this->back() & 0xFF);
        }
        return hash;
    }

    JStringBuilder& operator+=(const JStringBuilder& a);
    JStringBuilder& operator+=(unsigned short a);
    JStringBuilder& operator+=(const JString& str);
    bool operator==(const char* str) const;
    bool operator==(const JStringBuilder& str) const;
    bool operator!=(const char* str) const { return !(*this==str); }
    bool operator!=(const JStringBuilder& str) const { return !(*this == str); }
    JStringBuilder& operator=(const char* a);
};

JStringBuilder operator+(const char* a, const JStringBuilder& b);
JStringBuilder operator+(const JStringBuilder& a, const char* b);
JStringBuilder operator+(const JStringBuilder& a, const JStringBuilder& b);

template<>
class std::hash<JStringBuilder> {
public:
    size_t operator()(const JStringBuilder& o) const {
        return o.hashCode();
    }
};

#endif //TEXTREADER_JSTRINGBUILDER_H

