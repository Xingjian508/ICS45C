#include "square.hpp"

#include <iostream>
#include <numbers>

using namespace std;

Square::Square(Point center, string name, int side): Rectangle(center, name, side, side) {
}

double Square::area() const {
    return Rectangle::area();
}

void Square::draw(ostream& out) const {
    Rectangle::draw(out);
}

Square* Square::clone() const {
    return new Square(*this);
}

