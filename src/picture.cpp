#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() {
    head = nullptr;
    tail = nullptr;
}

void Picture::add(const Shape& shape) {
    Shape* dup_shape = shape.clone();
    if (!head) {
        head = new Picture::ListNode(dup_shape, nullptr, nullptr); // Add new.
        tail = head; // Both points to it.
    }
    else {
        tail->next = new Picture::ListNode(dup_shape, tail, nullptr); // Add new.
        tail = tail->next; // Shifts.
    }
}

void Picture::print_all(std::ostream& out) const {
    for (ListNode* n=head; n!=nullptr; n=n->next)
        (n->shape)->print(out);
}

void Picture::draw_all(std::ostream& out) const {
    for (ListNode* n = head; n != nullptr; n = n->next)
        (n->shape)->draw(out);
}

double Picture::total_area() const {
    double k = 0;
    for (ListNode* n = head; n != nullptr; n = n->next)
        k += (n->shape)->area();
    return k;
}

Picture::~Picture() {
    ListNode* temp;
    for (ListNode* n = head; n != nullptr; n = temp) {
        temp = n->next;
        delete (n->shape);
        delete n;
    }
}
