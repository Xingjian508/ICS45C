#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <string>

struct Point {
    int x;
    int y;
};

class Shape {
public:

    // Constructs this Shape with given center and name.
    Shape(Point center, std::string name);

    // Prints this Shape's name and coordinates,
    // in this specific format followed by a new line:
    // name(center.x, center.), e.g., Circle_2(1.0, 2.3).
    void print(std::ostream& out) const;

    // Deletes assignment to prevent accidental slicing.
    Shape& operator=(const Shape& other) = delete;

    // Computes and returns the area of this Shape.
    virtual double area() const = 0;

    // Draws this Shape using character graphics,
    // using the algorithms given in the write-up.
    virtual void draw(std::ostream& out) const = 0;

    // Creates a new duplicate of this Shape,
    // allocated from the free store.
    // Must be over-ridden by each concrete class,
    // to return a copy of itself.
    virtual Shape* clone() const = 0;

    // Cleans up any sub-storage owned by this Shape object.
    virtual ~Shape() = default;

protected:

    // Protects the copy constructor to be used only by clone().
    Shape(const Shape& other) = default;

private:
    
    // Position coordinates, used to illustrate inheritance.
    Point center;
    
    // The name of this Shape, supplied to the constructor.
    std::string name;
};

#endif
