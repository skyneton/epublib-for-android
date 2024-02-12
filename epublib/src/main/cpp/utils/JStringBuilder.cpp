//
// Created by skyne on 2023-11-10.
//

#include "JStringBuilder.h"
#include "utils.h"

JStringBuilder::JStringBuilder(const char *str): vector() {
    this->append(str);
}

JStringBuilder::JStringBuilder(char c): vector() {
    this->append(c);
}

JStringBuilder::JStringBuilder(const unsigned short *str, int size): std::vector<unsigned short>(size) {
    for(int i = 0; i < size; i++) {
        (*this)[i] = str[i];
    }
}

JStringBuilder::JStringBuilder(const JString& str): std::vector<unsigned short>(str.size()) {
    for(int i = 0; i < length(); i++) {
        (*this)[i] = str[i];
    }
}

size_t JStringBuilder::length() const {
    return this->size();
}

JStringBuilder& JStringBuilder::append(const unsigned short *s, size_t n) {
    insert(end(), s, s + n);
    return *this;
}

JStringBuilder& JStringBuilder::append(const JString& s) {
    insert(end(), s.begin(), s.end());
    return *this;
}

JStringBuilder& JStringBuilder::append(const char* s) {
    while(*s) emplace_back(*(s++));
    return *this;
}

JStringBuilder& JStringBuilder::append(const unsigned short * s) {
    while(*s) emplace_back(*(s++));
    return *this;
}

JStringBuilder& JStringBuilder::append(const char c) {
    emplace_back(c);
    return *this;
}

JStringBuilder& JStringBuilder::append(const unsigned short c) {
    emplace_back(c);
    return *this;
}

JStringBuilder& JStringBuilder::append(const JStringBuilder& s, size_t n) {
    auto it = s.begin();
    while(n--) emplace_back(*(it++));
    return *this;
}

JStringBuilder& JStringBuilder::append(const JStringBuilder& s) {
    this->append(s, s.size());
    return *this;
}

int JStringBuilder::find(char value, int start) {
    while(start < size()) {
        if((*this)[start] == value) return start;
        start++;
    }
    return -1;
}

JStringBuilder JStringBuilder::substr(int pos, int len) const {
    return {this->begin() + pos, this->begin() + pos + static_cast<int>(len < 0 ? this->size() - pos : len)};
}

JStringBuilder& JStringBuilder::ltrim() {
    this->erase(this->begin(), std::find_if(this->begin(), this->end(), [](unsigned short ch) {
        return !utils::isspace(ch);
    }));
    return *this;
}

JStringBuilder& JStringBuilder::rtrim() {
    this->erase(std::find_if(this->rbegin(), this->rend(), [](unsigned short ch) {
        return !utils::isspace(ch);
    }).base(), this->end());
    return *this;
}

JStringBuilder& JStringBuilder::trim() {
    return ltrim().rtrim();
}

std::string JStringBuilder::to_str() const {
    std::string result;
    for(const unsigned short & it : *this) {
        result += (char)it;
    }
    return result;
}

bool JStringBuilder::startsWith(const unsigned short c) const {
    return !this->empty() && this->front() == c;
}

JStringBuilder JStringBuilder::lower() {
    JStringBuilder result = *this;
    for(auto it = result.begin(); it != result.end(); it++) {
        if(*it >= 'A' && *it <= 'Z') {
            *it = *it - 'A' + 'a';
        }
    }
    return result;
}

JStringBuilder JStringBuilder::upper() {
    JStringBuilder result = *this;
    for(auto it = result.begin(); it != result.end(); it++) {
        if(*it >= 'a' && *it <= 'z') {
            *it = *it - 'a' + 'A';
        }
    }
    return result;
}

JStringBuilder operator+(const char* a, const JStringBuilder& b) {
    JStringBuilder s;
    while(*a) s.emplace_back(*(a++));
    s.append(b);
    return s;
}

JStringBuilder operator+(const JStringBuilder& a, const char* b) {
    JStringBuilder s = a;
    while(*b) s.emplace_back(*(b++));
    return s;
}

JStringBuilder operator+(const JStringBuilder& a, const JStringBuilder& b) {
    JStringBuilder s = a;
    s.append(b);
    return s;
}

JStringBuilder operator+(const JStringBuilder& a, const char b) {
    JStringBuilder s = a;
    s.append(b);
    return s;
}

JStringBuilder operator+(const char a, const JStringBuilder& b) {
    JStringBuilder s = a;
    s.append(b);
    return s;
}

JStringBuilder& JStringBuilder::operator+=(const JStringBuilder& a) {
    append(a);
    return *this;
}

JStringBuilder& JStringBuilder::operator+=(unsigned short a) {
    emplace_back(a);
    return *this;
}

JStringBuilder& JStringBuilder::operator+=(const JString& a) {
    append(a);
    return *this;
}

bool JStringBuilder::operator==(const char *str) const {
    int size = static_cast<int>(this->size()), i = 0;
    for(; str[i] && i < size; i++) {
        if(str[i] != (*this)[i]) return false;
    }
    return i == size;
}

bool JStringBuilder::operator==(const JStringBuilder& str) const {
    if(size() != str.size()) return false;
    for(int i = 0; i < size(); i++) {
        if(str[i] != (*this)[i]) return false;
    }
    return true;
}

JStringBuilder& JStringBuilder::operator=(const char *a) {
    this->clear();
    this->append(a);
    return *this;
}
