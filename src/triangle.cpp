#include "triangle.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

Triangle::Triangle(Point center, string name, int base, int height): Shape(center, name) {
    this->base = base;
    this->height = height;
}

double Triangle::area() const {
    return (base*height/2);
}

void Triangle::draw(ostream& out) const {
    int offset = max(height, base);

    for (int i=0; i<height; i+=2) {
        for (int j=0; j<(offset-i)/2; ++j)
            out << ' ';
        for (int k=0; k<=i; ++k)
            out << '*';
        out << '\n';
    }
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}


