#pragma once
#include "string"
#include "JString.h"
#include "unordered_map"

namespace utils {
    int newLineIndexOf(const char *str, int startIdx, int endIdx);

    int newLineIndexOf(const unsigned short *str, int startIdx, int endIdx);

    bool isWhiteSpace(char c);

    int skipWhiteSpace(const char *text, int startIdx, int endIdx);

    int skipWhiteSpace(const unsigned short *text, int startIdx, int endIdx);

    char lower(char c);

    unsigned short lower(unsigned short c);

    int indexOf(const char *text, char search, int startIdx, int end, bool ignoreCase);

    int indexOf(const char *text, char search, int startIdx, int end);

    int indexOf(const unsigned short *text, char search, int startIdx, int end);

    void ltrim(std::string &s);

    void rtrim(std::string &s);

    void trim(std::string &s);

    bool isspace(const unsigned short c);

    JString getParentPath(const JString &path);

    JString getPathCombine(const JString &base, const JString &path);

    JString getFileName(const JString &path);

    JString getFileNameWithoutExtension(const JString &path);

    int clamp(int value, int min, int max);

    template<typename K, typename V>
    const V& getOrDefault(const std::unordered_map<K, V>& map, const K& key, const V& _default) {
        auto it = map.find(key);
        return (it != map.end()) ? it->second : _default;
    }

    template<typename K, typename V>
    const V* getOrNull(const std::unordered_map<K, V>& map, const K& key) {
        auto it = map.find(key);
        return (it != map.end()) ? &it->second : nullptr;
    }

    template<typename K, typename V>
    V& putIfAbsent(std::unordered_map<K, V>& map, const K& key, const V& value) {
        auto it = map.find(key);
        if(it != map.end()) return it->second;
        return map.insert(key, value).first->second;
    }

    template<typename ... Args>
    std::string format(const char *format, Args ... args) {
        size_t size = snprintf(nullptr, 0, format, args ...) + 1;
        if (size <= 0) return "ERROR";
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format, args ...);
        return {buf.get(), buf.get() + size - 1};
    }

    template<typename ... Args>
    std::string format(const JString &format, Args ... args) {
        size_t size = snprintf(nullptr, 0, format.c_str_null().begin(), args ...) + 1;
        if (size <= 0) return "ERROR";
        std::unique_ptr<char[]> buf(new char[size]);
        snprintf(buf.get(), size, format.c_str_null().begin(), args ...);
        return {buf.get(), buf.get() + size - 1};
    }
}