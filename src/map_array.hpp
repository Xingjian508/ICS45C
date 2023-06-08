#ifndef MAP_ARRAY_HPP
#define MAP_ARRAY_HPP

#include <algorithm>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>

template <typename Key, typename Value>
class MapArray {
public:
    using value_type = std::pair<Key, Value>;

    class ArrayIterator {
    public:
        // Iterator traits.
        using iterator_category = std::random_access_iterator_tag;
        using value_type = MapArray::value_type;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        explicit ArrayIterator(std::pair<Key, Value>* ptr = nullptr) {
            this->ptr = ptr;
        }

        ArrayIterator& operator++() {
            ++ptr;
            return *this;
        }
        
        ArrayIterator& operator--() {
            --ptr;
            return *this;
        }
        
        ArrayIterator operator++(int) {
            ArrayIterator k(ptr);
            ++ptr;
            return k;
        }
        
        ArrayIterator operator--(int) {
            ArrayIterator k(ptr);
            --ptr;
            return k;
        }
        
        ArrayIterator& operator+=(difference_type d) {
            for (; d; --d) ++ptr;
            return *this;
        }

        ArrayIterator& operator-=(difference_type d) {
            for (; d; --d) --ptr;
            return *this;
        }

        friend ArrayIterator operator+(ArrayIterator it, difference_type d) {
            return it += d;
        }

        friend ArrayIterator operator+(difference_type d, ArrayIterator it) {
            return it += d;
        }

        friend ArrayIterator operator-(ArrayIterator it, difference_type d) {
            return it -= d;
        }

        friend difference_type operator-(ArrayIterator lhs, ArrayIterator rhs) {
            auto k = lhs.ptr - rhs.ptr; // Tries to examine the type. Is it minus-able?
            return k;
        }

        auto operator<=>(const ArrayIterator& other) const = default;

        std::pair<Key, Value>& operator*() const {
            return *ptr;
        }

        std::pair<Key, Value>* operator->() const {
            return ptr;
        }

        std::pair<Key, Value>& operator[] (difference_type d) const {
            std::pair<Key, Value>* dup = ptr;
            for (; d; d--) ++dup;
            return *dup;
        }

    private:
        // Only one pointer to a "pair" object.
        std::pair<Key, Value>* ptr;
    };

    using iterator = ArrayIterator;

    ArrayIterator begin() {
        if (data.size()==0) return ArrayIterator();
        return ArrayIterator(&data[0]);
    }
    
    ArrayIterator end() {
        if (data.size()==0) return ArrayIterator();
        return ArrayIterator(&data[data.size()]);
    }

    Value& operator[](const Key& key) {
        for (int i=0; i<int(data.size()); ++i) {
            auto k = data[i];
            if (k.first==key) return data[i].second;
        }
        std::pair<Key, Value> temp = std::make_pair(key, Value{});
        if (int(data.size()) == 0) {
            data.push_back(temp);
            return data[0].second;
        }
        auto I_FIGURED_IT_OUT = std::upper_bound(data.begin(), data.end(), temp);
        auto pos = data.insert(I_FIGURED_IT_OUT, temp);
        return pos->second;
    }

private:
    std::vector<std::pair<Key, Value>> data;
    static_assert(std::random_access_iterator<iterator>);
};

#endif
