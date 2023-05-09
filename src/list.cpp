#include "list.hpp"
#include <iostream>


using namespace std;
using list::Node;


Node* list::from_string(const char* s) {
    return (*s=='\0') ? nullptr : new Node{*s, from_string(&s[1])};
} // I use (*k).next for learning purposes. The rest of the functions are written with arrows.


void list::free(Node* head) {
    Node* thisNode = head;
    Node* nextNode = head->next;
    for (; nextNode != nullptr; nextNode = nextNode->next) {
       delete[] thisNode;
       thisNode = nextNode;
    }
    delete[] thisNode;
}


void list::print(std::ostream& out, Node* head) {
    for (Node* k = head; k != nullptr; k = k->next)
        out << k->data;
    out << endl;
}


int list::length(Node* head) {
    int i = 1;
    for (Node* k = head; k->next != nullptr; k = k->next)
        ++i;
    return i;
}


Node* list::copy(Node* head) {
    Node* c = head->next;
    Node* n = new Node{head->data, nullptr};
    Node* newNode = n;
    for (; c != nullptr; n = n->next, c = c->next)
        n->next = new Node{c->data, nullptr};
    return newNode;
}


int list::compare(Node* lhs, Node* rhs) {
    Node* l = lhs;
    Node* r = rhs;
    for (; l != nullptr && r != nullptr; l = l->next, r = r->next)
        if (l->data != r->data)
            return (l->data - r->data);
    if (l==nullptr)
        return (r==nullptr) ? 0 : (-(r->data));
    return (l->data);
}

int list::compare(Node* lhs, Node* rhs, int n) {
    Node* l = lhs;
    Node* r = rhs;
    int i;
    for (i=0; l != nullptr && r != nullptr && i<n; l = l->next, r = r->next, ++i)
        if (l->data != r->data)
            return (l->data - r->data);
    if (i==n)
        return 0;
    if (l==nullptr)
        return (r==nullptr) ? 0 : (-(r->data));
    return (l->data);
}


Node* list::reverse(Node* head) {
    Node* prev;
    Node* newHead = new Node{head->data, nullptr};
    Node* iter = head->next;

    for (; iter != nullptr; iter = iter->next) {
        prev = newHead;
        newHead = new Node{iter->data, nullptr};
        newHead->next = prev;
    }
    return newHead;
}


Node* list::append(Node* lhs, Node* rhs) {
    Node* n = new Node{lhs->data, nullptr};
    Node* a = n;
    Node* iter = lhs->next;

    for (; iter != nullptr; iter = iter->next, n = n->next) {
        n->next = new Node{iter->data, nullptr};
    }
    iter = rhs;
    for (; iter != nullptr; iter = iter->next, n = n->next) {
        n->next = new Node{iter->data, nullptr};
    }
    return a;
}



