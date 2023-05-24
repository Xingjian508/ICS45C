#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

class Array {
public:
    // Construct zero-length array.
    Array() : len{0}, buf{nullptr} {
    }

    // Construct array of given length.
    explicit Array(int len) : len{len}, buf{new int[len]} {
    }

    // Copy & move constructors (TODO:test these).
    Array(const Array& other) : len{other.len}, buf{new int[other.len]} {
        for (int i=0; i<len; ++i)
            buf[i] = other.buf[i];
    }
    
    Array(Array&& other) noexcept {
        len = other.len;
        buf = other.buf;
        other.buf = nullptr;
    }

    // Swap two arrays (without allocations).
    // Note: now a friend function,
    // which is the more common way to do it.
    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    // Copy & move assignment (TODO: implement these.
    Array& operator=(const Array& other) {
        if (&other==this) return *this;
        delete[] buf;
        len = other.len;
        buf = new int[other.len];
        for (int i=0; i<len; ++i)
            buf[i] = other.buf[i];
        return *this;
    }

    Array& operator=(Array&& other) noexcept {
        delete[] buf;
        len = other.len;
        buf = other.buf;
        other.buf = nullptr;
        return *this;
    }

    // Destructor.
    ~Array() {
        // TODO: implement this.
        delete[] buf;
        buf = nullptr;
    }

    int length() const {
        return len;
    }

    // Get a particular element of the array.
    // TODO: add bounds check.
    int& operator[](int index) {
        if (in_bounds(index))
            return buf[index];
        else
            throw std::string("Exception operator[](" + std::to_string(index) + ") Out Of Range");
    }

    // Get a particular element of the array.
    // TODO: add bounds check.
    const int& operator[](int index) const {
        if (in_bounds(index))
            return buf[index];
        else
            throw std::string("Exception operator[](" + std::to_string(index) + ") Out Of Range");
    }

    // Set every element of the array to 'val'.
    // TODO: implement this.
    void fill(int val) {
        for (int i=0; i<len; ++i)
            buf[i] = val;
    }

private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

// Print array to 'out' in a single line.
inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    // We don't want to set formatting flags globally.
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i=0; i<array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

// Read array from 'in', entries should be separated by whitespace.
inline std::istream& operator>>(std::istream& in, Array& array) {
    for (int i=0; i<array.length(); ++i) {
        in >> array[i];
    }

    return in;
}

#endif
