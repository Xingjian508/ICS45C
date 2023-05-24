#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class Array {
public:
    Array() : len{0}, buf{nullptr} {
    }

    explicit Array(int len) : len{len}, buf{new T[len]} {
    }

    Array(const Array& other) : len{other.len}, buf{new T[other.len]} {
        for (int i=0; i<len; ++i)
            buf[i] = other.buf[i];
    }

    ~Array() {
        delete[] buf;
        buf = nullptr;
    }

    int length() const {
        return len;
    }


    Array(Array&& other) noexcept {
        len = other.len;
        buf = other.buf;
        other.buf = nullptr;
    }

    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }

    Array& operator=(const Array& other) {
        if (&other==this) return *this;
        delete[] buf;
        len = other.len;
        buf = new T[len];
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

    T& operator[](int index) {
        if (in_bounds(index))
            return buf[index];
        else
            throw std::string("Exception operator[](" + std::to_string(index) + ") Out Of Range");
    }

    const T& operator[](int index) const {
        if (in_bounds(index))
            return buf[index];
        else
            throw std::string("Exception operator[](" + std::to_string(index) + ") Out Of Range");
    }


    template <typename Fn>
    void fill_with_fn(Fn fn) {
        for (int i=0; i<len; ++i)
            buf[i] = fn(i);
    }

private:
    int len;
    T* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};


// Print array to 'out' in a single line.
std::ostream& operator<<(std::ostream& out, const Array<auto>& array) {
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
std::istream& operator>>(std::istream& in, Array<auto>& array) {
    for (int i=0; i<array.length(); ++i) {
        in >> array[i];
    }

    return in;
}

#endif

