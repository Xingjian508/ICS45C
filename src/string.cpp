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
    for (i=0; src[i] != '\0' && i < n; ++i) {
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
    for (int i=0; src[i] != '\0' && i < n; ++i) {
        dest[l] = src[i];
        ++l;
    }
    dest[l] = '\0';
    return dest;
}



