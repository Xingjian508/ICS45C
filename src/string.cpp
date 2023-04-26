#include "string.hpp"
#include <iostream>


using namespace std;


int String::strlen(const char *s) {
    int i;
    for (i=0; s[i] != '\0'; ++i) {}
    return i;
}

char* String::strcpy(char *dest, const char *src) {
    int i;
    for (i=0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char* String::strncpy(char *dest, const char *src, int n) {
    int i;
    for (i=0; i<n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

char* String::strcat(char *dest, const char *src) {
    int i;
    for (i=0; dest[i] != '\0'; ++i) {}
    for (int j=0; src[j] != '\0'; ++j) {
        dest[i] = src[j];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char* String::strncat(char *dest, const char *src, int n) {
    int i;
    for (i=0; dest[i] != '\0'; ++i) {}
    for (int j=0; j<n && src[j] != '\0'; ++j) {
        dest[i] = src[j];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
    int i=0;
    for (i=0; left[i] != '\0' && right[i] != '\0'; ++i) {
        if (left[i] != right[i])
            return (left[i] - right[i]);
    }
    if (left[i] == right[i])
        return 0;
    else
        return (left[i] - right[i]);
}

int String::strncmp(const char *left, const char *right, int n) {
    int i=0;
    for (i=0; i<n && left[i] != '\0'; ++i) {
        if (left[i] != right[i])
            return (left[i] - right[i]);
    }
    if (i == n) return 0;
    else if (right[i] == '\0') return 0;
    else return (left[i]-right[i]);
}

void String::reverse_cpy(char* dest, const char* src) {
    int i = String::strlen(src)-1;
    int j;
    for (j=0; i>=0; --i) {
        dest[j] = src[i];
        ++j;
    }
    dest[j] = '\0';
}

const char* String::strchr(const char* str, char c) {
    const char* ptr = nullptr;
    int i;
    for (i=0; str[i] != '\0'; ++i) {
        if (str[i] == c) {
            ptr = &str[i];
            break;
        }
    }
    if (c == '\0') ptr = &str[i];
    return ptr;
}

const char* String::strstr(const char* haystack, const char* needle) {
    const char* ptr = nullptr;
    int needleLength = String::strlen(needle);
    if (needleLength == 0) {
        return haystack;
    }
    int cycle = String::strlen(haystack)-needleLength+1;
    for (int i=0; i<cycle; ++i) {
        int step = 0;
        for (; step<needleLength; ++step) {
            if (haystack[i+step] != needle[step])
                break;
        }
        if (step == needleLength) {
            ptr = &haystack[i];
            break;
        }
    }
    return ptr;
}

void String::print(std::ostream &out) const {
    for (int i=0; buf[i] != '\0'; ++i)
        out << buf[i];
}

std::ostream &operator<<(std::ostream &out, const String &s) {
    s.print(out);
    return out;
}

String::String(const char *s) {
    strncpy(buf, s, MAXLEN-1);
}

String::String(const String &s) {
    strcpy(buf, s.buf);
}

int String::size() {
    return strlen(buf);
}

String::~String() {
}

bool String::operator==(const String &s) const {
    if (String::strcmp(buf, s.buf) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool String::operator!=(const String &s) const {
    return (!(String::strcmp(buf, s.buf) == 0));
}

bool String::operator>(const String &s) const {
    return ((String::strcmp(buf, s.buf)) > 0);
}

bool String::operator<(const String &s) const {
    return ((String::strcmp(buf, s.buf)) < 0);
}

bool String::operator<=(const String &s) const {
    return ((String::strcmp(buf, s.buf)) <= 0);
}

bool String::operator>=(const String &s) const {
    return ((String::strcmp(buf, s.buf)) >= 0);
}

String& String::operator=(const String &s) {
    String::strcpy(buf, s.buf);
    return *this;
}

char& String::operator[](int index) {
    int n = String::strlen(buf);
    if (0<index && index<n)
        return buf[index];
    else {
        cout << "ERROR" << endl;
        return buf[0];
    }
}

String String::reverse() {
    String r;
    String::reverse_cpy(r.buf, buf);
    return r;
}

int String::indexOf(char c) {
    char* foundptr = (char*) String::strchr(buf, c);
    if (foundptr == nullptr) return -1;
    int index = foundptr-buf;
    return index;
}

int String::indexOf(const String &s) {
    char* otherbuf = (char*) s.buf;
    char* foundptr = (char*) String::strstr(buf, otherbuf);
    if (foundptr == nullptr) return -1;
    int index = foundptr-buf;
    return index;
}

String String::operator+(const String &s) {
    String r;
    int n = MAXLEN-String::strlen(r.buf);
    if (n<0 || (n==0 && strlen(s.buf) != 0)) {
        cout << "ERROR" << endl;
    }
    else {
        String::strcat(r.buf, buf);
        String::strncat(r.buf, s.buf, n);
    }
    return r;
}

String& String::operator+=(const String &s) {
    String r;
    int n = MAXLEN-String::strlen(r.buf);
    if (n<0 || (n==0 && strlen(s.buf) != 0)) {
        cout << "ERROR" << endl;
    }
    else {
        String::strcat(r.buf, buf);
        String::strncat(r.buf, s.buf, n);
        String::strcpy(buf, r.buf);
    }
    return *this;
}

void String::read(std::istream &in) {
    in >> buf;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}


