#include "shape.hpp"
#include <iostream>
#include <string>

using namespace std;

Shape::Shape(Point center, string name) {
    this->center = center;
    this->name = name;
}

void Shape::print(std::ostream& out) const {
    out << name << " at " << '(' << center.x << ", "
    << center.y << ')' << " area = " << area() << endl;
}

