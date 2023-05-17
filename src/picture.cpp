#include "picture.hpp"
#include <iostream>
#include <utility>

Picture::Picture() {
    head = nullptr;
    tail = nullptr;
}

Picture::Picture(const Picture& other) {
    ListNode* h = head;
    ListNode* prev = nullptr;
    for (ListNode* n = other.head; n != nullptr; prev = h, n = n->next) {
        h = new ListNode((n->shape)->clone(), prev, nullptr);
        if (prev) prev->next = h;
    }
    tail = prev;
}

Picture::Picture(Picture&& other) {
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
}

void Picture::swap(Picture& other) {
    ListNode* t1 = head;
    ListNode* t2 = tail;
    head = other.head;
    tail = other.tail;
    other.head = t1;
    other.tail = t2;
}

Picture& Picture::operator=(const Picture& other) {
    Picture::free_nodes();
    ListNode* h = head;
    ListNode* prev = nullptr;
    for (ListNode* n = other.head; n != nullptr; prev = h, n = n->next) {
        h = new ListNode((n->shape)->clone(), prev, nullptr);
        if (prev) prev->next = h;
    }
    tail = prev;
    return *this;
}

Picture& Picture::operator=(Picture&& other) {
    Picture::swap(other);
    return *this;
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
    for (ListNode* n=head; n!=nullptr; n=n->next) {
        (n->shape)->print(out);
        (n->shape)->draw(out);
    }
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

void Picture::free_nodes() {
    ListNode* temp;
    for (ListNode* n = head; n != nullptr; n = temp) {
        temp = n->next;
        delete (n->shape);
        delete n;
    }
    head = nullptr;
    tail = nullptr;
} 

Picture::~Picture() {
    Picture::free_nodes();
}
