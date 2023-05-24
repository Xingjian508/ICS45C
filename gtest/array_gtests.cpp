#include <gtest/gtest.h>

#include <string>

#include "alloc.hpp"
#include "array.hpp"

using namespace std;

TEST(ArrayTests, Length) {
    Array<int> arr{3};
    EXPECT_EQ(arr.length(), 3);

    Array<string> arr2{10};
    EXPECT_EQ(arr2.length(), 10);

    EXPECT_EQ(Array<double>{}.length(), 0);
}


TEST(ArrayTests, Subscript) {
    Array<double> arr{10};
    arr[0] = 3.0;
    arr[3] = 5.0;
    EXPECT_EQ(arr[0], 3.0);
    EXPECT_EQ(arr[3], 5.0);
}

TEST(ArrayTests, Print) {
    stringstream out;

    Array<string> arr{3};
    arr[0] = "0";
    arr[1] = "1";
    arr[2] = "2";

    out << arr;

    EXPECT_EQ(out.str(), "       0       1       2");
}

TEST(ArrayTests, Fill) {
    Array<int> arr{10};
    arr.fill(20);
    EXPECT_EQ(arr[0], 20);
    arr.fill(5);
    EXPECT_EQ(arr[9], 5);
}

TEST(ArrayTests, OutOfBounds) {
    Array<int> arr{10};
    EXPECT_ANY_THROW(arr[11]);
}

TEST(ArrayTests, CopyConstructor) {
    Array<int> arr{10};
    arr.fill(20);
    Array<int> arr2{arr};
    EXPECT_EQ(arr2.length(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    Array<int> empty;
    Array<int> arr3{empty};
    EXPECT_EQ(arr3.length(), 0);
}

TEST(ArrayTests, MoveConstructor) {
    AllocationTracker tracker;

    Array<int> arr{10};
    arr.fill(20);

    std::size_t allocs_before_move = tracker.get_num_allocations();
    Array<int> arr2{std::move(arr)};
    std::size_t allocs_after_move = tracker.get_num_allocations();

    EXPECT_EQ(allocs_before_move, allocs_after_move);

    EXPECT_EQ(arr2.length(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    Array<int> empty;
    Array<int> arr3{std::move(empty)};
    EXPECT_EQ(arr3.length(), 0);
}

TEST(ArrayTests, Swap) {
    AllocationTracker tracker;

    Array<int> arr{10};
    arr.fill(20);
    Array<int> arr2{2};
    arr2.fill(5);

    std::size_t allocs_before_swap = tracker.get_num_allocations();
    swap(arr, arr2);
    std::size_t allocs_after_swap = tracker.get_num_allocations();

    EXPECT_EQ(allocs_before_swap, allocs_after_swap);

    EXPECT_EQ(arr2.length(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
}

TEST(ArrayTests, CopyAssignment) {
    Array<int> arr{10};
    arr.fill(20);

    Array<int> arr2{2};
    arr2.fill(5);

    arr = arr2;

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);

    EXPECT_EQ(arr2.length(), 2);
    EXPECT_EQ(arr2[0], 5);
    EXPECT_EQ(arr2[1], 5);

    arr = arr;

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);
}

TEST(ArrayTests, MoveAssignment) {
    AllocationTracker tracker;

    Array<int> arr{10};
    arr.fill(20);

    Array<int> arr2{2};
    arr2.fill(5);

    std::size_t allocs_before_move = tracker.get_num_allocations();
    arr = std::move(arr2);
    std::size_t allocs_after_move = tracker.get_num_allocations();
    EXPECT_EQ(allocs_before_move, allocs_after_move);

    EXPECT_EQ(arr.length(), 2);
    EXPECT_EQ(arr[0], 5);
    EXPECT_EQ(arr[1], 5);


    arr2 = Array<int>{5};
    EXPECT_EQ(arr2.length(), 5);
    arr2 = std::move(arr2);
    arr2 = Array<int>{7};
    EXPECT_EQ(arr2.length(), 7);
}
