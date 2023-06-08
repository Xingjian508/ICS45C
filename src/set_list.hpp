#ifndef SET_LIST_HPP
#define SET_LIST_HPP

#include <algorithm>
#include <functional>
#include <iterator>
#include <memory>
#include <ranges>

template<typename T>
class SetList {

public:
    struct ListNode {
        T data;
        std::shared_ptr<ListNode> next;
    };

    using value_type = T;

    class ListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = SetList::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ListIterator(std::shared_ptr<ListNode> ptr = nullptr) {
            this->ptr = ptr; // Copies the shared pointer.
        }

        ListIterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        
        ListIterator operator++(int) {
            ListIterator l(ptr);
            ptr = ptr->next;
            return l;
        }
        
        T& operator*() const {
            return ptr->data;
        }
        
        T* operator->() const {
            return &(ptr->data);
        }
        
        bool operator==(const ListIterator& other) const = default;

    private:
        std::shared_ptr<ListNode> ptr;
    };

    SetList() = default;

    template<std::ranges::input_range Rng>
    explicit SetList(Rng&& rng) {
        std::ranges::for_each(std::forward<Rng>(rng),
                              std::bind_front(&SetList::insert, this));
    }

    ListIterator begin() {
        return ListIterator(head);
    }

    ListIterator end() {
        auto k = head;
        for (; k != nullptr; k = k->next) {}
        return ListIterator(k);
    }
    
    bool contains(T const& value) {
        for (std::shared_ptr<ListNode> n = head; n != nullptr; n = n->next) {
            if (n->data == value) return true;
        }
        return false;
    }

    ListIterator insert(T value) {
        if (!contains(value)) {
            head = std::move(std::make_shared<ListNode>(ListNode{std::move(value), head}));
        }
        return ListIterator(head);
    }

private:
    using iterator = ListIterator;
    static_assert(std::forward_iterator<iterator>);
    std::shared_ptr<ListNode> head = nullptr;
};

#endif
