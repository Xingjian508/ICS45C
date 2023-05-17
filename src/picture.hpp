#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iosfwd>

#include "shape.hpp"

class Picture {
public:
    
    // Initializing constructor creates this as an empty picture.
    Picture();

    // Copy and move constructors for Picture (GOOD C++ PRACTICE).
    Picture(const Picture& other);
    Picture(Picture&& other);

    // Swaps this Picture's list with other Picture's list.
    void swap(Picture& other);

    // Copy and move assignment for Picture (GOOD C++ PRACTICE).
    Picture& operator=(const Picture& other);
    Picture& operator=(Picture&& other);

    // Adds clone of Shape to end of this Picture's linked list.
    // Cloning allows us to create any number of Shape objects,
    // during runtime while Picture can own them. They will,
    // in a sense, encapsulate the newly created Shape objects.
    // Note that this means Picture is responsible for deleting,
    // in full, these clones when this Picture object dies.
    void add(const Shape& shape);

    // Calls method print() on each Shape,
    // in the order they were added.
    void print_all(std::ostream& out) const;

    // Draws the Shapes in this Picture in the order they were added.
    void draw_all(std::ostream& out) const;

    // Returns the sum of areas of all the Shapes in this Picture.
    double total_area() const;

    // Frees up all storage owned by this Picture when it dies.
    ~Picture();

private:

    struct ListNode {
        Shape* shape;
        ListNode* prev;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;

};

#endif
