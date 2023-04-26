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
    int i;
    for (i=0; left[i] != '\0' && right[i] != '\0'; ++i) {
        if (left[i] != right[i])
            return (left[i] - right[i]);
    }
    return 0;
}

int String::strncmp(const char *left, const char *right, int n) {
    int i;
    for (i=0; i<n && left[i] != '\0' && right[i] != '\0'; ++i) {
        if (left[i] != right[i])
            return (left[i] - right[i]);
    }
    return 0;
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

void String::print(std::ostream &out) const {
    for (int i=0; buf[i] != '\0'; ++i)
        out << buf[i];
    out << endl;
}

String::String(const char *s) {
    strncpy(buf, s, MAXLEN-1);
}

String::String(const String &s) {
    strcpy(buf, s.buf);
}

int String::size() {
    int i;
    for (i=0; buf[i] != '\0'; ++i) {
    }
    return i;
}

