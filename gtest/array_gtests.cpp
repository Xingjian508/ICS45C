#include <gtest/gtest.h>

#include <string>
#include "array.hpp"

using namespace std;

TEST(ArrayTests, BasicConstruction) {
    Array<int>{};
    Array<double> t{3};
}

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

TEST(ArrayTests, OutOfBounds) {
    Array<int> arr{10};
    EXPECT_ANY_THROW(arr[11]);
}




