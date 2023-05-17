#include "rectangle.hpp"

#include <iostream>
#include <numbers>

using namespace std;

Rectangle::Rectangle(Point center, string name, int width, int height): Shape(center, name) {
    this->width = width;
    this->height = height;
}

double Rectangle::area() const {
    return (width*height);
}

void Rectangle::draw(ostream& out) const {
    for (int i=0; i<height; i+=2) {
        for (int j=0; j<width; ++j)
            out << '*';
        out << '\n';
    }
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}


