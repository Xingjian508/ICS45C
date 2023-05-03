#include "string.hpp"
#include <iostream>


using namespace std;


int String::strlen(const char* s) {
    int i;
    for (i=0; s[i] != '\0'; ++i) {}
    return i;
}


char* String::strcpy(char* dest, const char* src) {
    int i;
    for (i=0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}


char* String::strncpy(char* dest, const char* src, int n) {
    int i;
    for (i=0; src[i] != '\0' && i<n; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}


char* String::strdup(const char* src) {
    int l = String::strlen(src)+1; // Finds the allocation length needed.
    char* heapstr{new char[l]}; // Creates new via heap.
    String::strcpy(heapstr, src); // Copy the src over.
    return heapstr;
}


char* String::strcat(char* dest, const char* src) {
    int l = String::strlen(dest);
    for (int i=0; src[i] != '\0'; ++i) {
        dest[l] = src[i];
        ++l;
    }
    dest[l] = '\0';
    return dest;
}


char* String::strncat(char* dest, const char* src, int n) {
    int l = String::strlen(dest);
    for (int i=0; src[i] != '\0' && i<n; ++i) {
        dest[l] = src[i];
        ++l;
    }
    dest[l] = '\0';
    return dest;
}


int String::strcmp(const char* left, const char* right) {
    int i;
    for (i=0; left[i] != '\0'; ++i)
        if (left[i] != right[i])
            return (left[i] - right[i]);
    return (left[i] - right[i]);
}

int String::strncmp(const char* left, const char* right, int n) {
    int i;
    for (i=0; left[i] != '\0' && i<n; ++i)
        if (left[i] != right[i])
            return (left[i] - right[i]);
    if (i==n)
        return 0;
    return (left[i] - right[i]);
}


void String::reverse_cpy(char* dest, const char* src) {
    int end = String::strlen(src)-1;
    for (int i=0; i<=end; ++i)
        dest[i] = src[end-i];
    dest[end+1] = '\0';
}


const char* String::strchr(const char* str, char c) {
    const char* ptr = nullptr;
    int i;
    for (i=0; str[i] != '\0'; ++i)
        if (str[i] == c) {
            ptr = &str[i];
            break;
        }
    if (c == '\0')
        ptr = &str[i];
    return ptr;
}


const char* String::strstr(const char* haystack, const char* needle) {
    const char* ptr = nullptr;
    int needleLength = String::strlen(needle);

    if (needleLength == 0)
        return haystack; // Returns the haystack pointer if needle is "".

    int cycle = String::strlen(haystack)-needleLength+1;
    for (int i=0; i<cycle; ++i) {
        int step = 0;
        for (; step<needleLength; ++step)
            if (haystack[i+step] != needle[step])
                break; // Break out of the loop at a non-equal comparison.
        if (step == needleLength) { // If that iteration was successful, i.e. str exist.
            ptr = &haystack[i];
            break;
        }
    }
    return ptr;
}

