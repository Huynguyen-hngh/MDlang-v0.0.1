#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <iomanip>
#include "iostd.h"

set iostd standard; // = using namespace std;

// Alias Mdlang-style
#define str string

// ================================
// Mdlang String Utilities v0.0.2
// ================================

// Chuyển chuỗi thành chữ hoa
str to_upper(const str& s) {
    str res = s;
    transform(res.begin(), res.end(), res.begin(), ::toupper);
    return res;
}

// Chuyển chuỗi thành chữ thường
str to_lower(const str& s) {
    str res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

// Xóa khoảng trắng 2 đầu (strip)
str del_space(const str& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == str::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

// Trim khoảng trắng 2 đầu (alias del_space)
str trim(const str& s) {
    return del_space(s);
}

// Kiểm tra prefix
bool starts_with(const str& s, const str& prefix) {
    return s.rfind(prefix, 0) == 0;
}

// Kiểm tra suffix
bool ends_with(const str& s, const str& suffix) {
    if (suffix.size() > s.size()) return false;
    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

// Split chuỗi theo ký tự (giống Python str.split)
vector<str> split_str(const str& s, char delim=' ') {
    vector<str> tokens;
    stringstream ss(s);
    str item;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

// Split (alias cho split_str)
vector<str> split(const str& s, char delim=' ') {
    return split_str(s, delim);
}

// Join vector thành chuỗi
str join(const vector<str>& vec, const str& sep="") {
    str res;
    for (size_t i = 0; i < vec.size(); i++) {
        res += vec[i];
        if (i != vec.size() - 1) res += sep;
    }
    return res;
}

// Kiểm tra tất cả ký tự là chữ số
bool is_digit(const str& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

// Kiểm tra tất cả ký tự là chữ cái
bool is_alpha(const str& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isalpha);
}

// Lặp chuỗi n lần
str repeat(const str& s, int n) {
    str res;
    for (int i = 0; i < n; i++) res += s;
    return res;
}

// Đảo ngược chuỗi
str reverse(const str& s) {
    str res = s;
    reverse(res.begin(), res.end());
    return res;
}

#endif // STRING_H

