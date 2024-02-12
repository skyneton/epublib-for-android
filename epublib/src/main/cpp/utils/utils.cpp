//
// Created by skyne on 2023-11-10.
//
#include "utils.h"
#include "string"
#include <jni.h>

namespace utils {
    int newLineIndexOf(const char *str, int startIdx, int endIdx) {
        int idx = startIdx;
        while (idx < endIdx) {
            switch (str[idx++]) {
                case '\n':
                    return idx - 1;
                case '\r':
                    return !(idx <= endIdx && str[idx] == '\n') ? idx - 1 : idx;
            }
        }
        return endIdx;
    }

    int newLineIndexOf(const unsigned short *str, int startIdx, int endIdx) {
        int idx = startIdx;
        while (idx < endIdx) {
            switch (str[idx++]) {
                case '\n':
                    return idx - 1;
                case '\r':
                    return !(idx <= endIdx && str[idx] == '\n') ? idx - 1 : idx;
            }
        }
        return endIdx;
    }

    bool isWhiteSpace(char c) {
        switch (c) {
            case '\n':
            case '\t':
            case ' ':
            case '\r':
                return true;
        }
        return false;
    }

    int skipWhiteSpace(const char *text, int startIdx, int endIdx) {
        while (startIdx + 1 < endIdx && isWhiteSpace(text[startIdx])) startIdx++;
        return startIdx;
    }

    int skipWhiteSpace(const unsigned short *text, int startIdx, int endIdx) {
        while (startIdx + 1 < endIdx && isWhiteSpace(text[startIdx])) startIdx++;
        return startIdx;
    }

    char lower(char c) {
        return c >= 'A' && c <= 'Z' ? (char) (c - 'A' + 'a') : c;
    }

    unsigned short lower(unsigned short c) {
        return c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c;
    }

    int indexOf(const char *text, char search, int startIdx, int end, bool ignoreCase) {
        if (ignoreCase) search = lower(search);
        while (startIdx < end) {
            if ((ignoreCase ? lower(text[startIdx]) : text[startIdx]) == search) return startIdx;
            startIdx++;
        }
        return -1;
    }

    int indexOf(const char *text, char search, int startIdx, int end) {
        while (startIdx < end) {
            if (text[startIdx] == search) return startIdx;
            startIdx++;
        }
        return -1;
    }

    int indexOf(const unsigned short *text, char search, int startIdx, int end) {
        while (startIdx < end) {
            if (text[startIdx] == search) return startIdx;
            startIdx++;
        }
        return -1;
    }

    void ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    }

    void rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), s.end());
    }

    void trim(std::string &s) {
        rtrim(s);
        ltrim(s);
    }

    bool isspace(const unsigned short c) {
        return c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v';
    }

    JString getParentPath(const JString &path) {
        return path.substring(0, std::max(0, path.lastIndexOf('/',
                                                              path.endsWith('/') ? path.size() - 2 :
                                                              path.size() - 1)));
    }

    JString getPathCombine(const JString &base, const JString &path) {
        if (path.startsWith('/') || base.empty()) return path;
        JString result = base;
        int start = 0, end;
        while ((end = path.indexOf('/', start, false)) >= 0) {
            JString sub = path.substring(start, end);
            start = end + 1;

            if (sub == '.') continue;
            if (sub == "..") {
                result = getParentPath(result);
                continue;
            }
            if (!result.empty() && !result.endsWith('/'))
                result += '/' + sub;
            else
                result += sub;
        }
        if (start < path.size()) {
            JString sub = path.substring(start, path.size());
            if (sub != '.') {
                if (sub == "..") {
                    result = getParentPath(result);
                } else {
                    if (!result.empty() && !result.endsWith('/'))
                        result += '/' + sub;
                    else
                        result += sub;
                }
            }
        }
        return result;
    }

    int clamp(int value, int min, int max) { return std::max(min, std::min(max, value)); }

    JString getFileName(const JString &path) {
        return path.substring(path.lastIndexOf('/', path.size() - 1 - path.endsWith('/')) + 1,
                              path.size() - path.endsWith('/'));
    }

    JString getFileNameWithoutExtension(const JString &path) {
        JString filename = getFileName(path);
        int extension = filename.lastIndexOf('.');
        return filename.substring(0, extension < 0 ? filename.size() : extension);
    }
}

extern "C"
JNIEXPORT void JNICALL
Java_net_mpoisv_textreader_native_NativeManager_nShortMemset(JNIEnv *env, jclass clazz,
                                                             jshortArray array, jshort fill) {
    int len = env->GetArrayLength(array);
    short* target = (short*) env->GetPrimitiveArrayCritical(array, nullptr);
    memset(target, fill, len * sizeof(short));
    env->ReleasePrimitiveArrayCritical(array, target, 0);
}