#include <gtest/gtest.h>

#include <string>

#include "matrix.hpp"

using namespace std;

TEST(MatrixTests, RowsAndCols) {
    Matrix<int> mat{3, 2};
    EXPECT_EQ(mat.num_rows(), 3);
    EXPECT_EQ(mat.num_cols(), 2);

    Matrix<double> mat2{5, 1};
    EXPECT_EQ(mat2.num_rows(), 5);
    EXPECT_EQ(mat2.num_cols(), 1);

    Matrix<string> mat3;
    EXPECT_EQ(mat3.num_rows(), 0);
    EXPECT_EQ(mat3.num_cols(), 0);
}

TEST(MatrixTests, FillingwithLambda) {
    Matrix<int> mat{3, 4};
    EXPECT_EQ(mat.num_rows(), mat.num_cols()-1);

    mat.fill_with_fn([](int i, int j){return i+j;});

    EXPECT_EQ(mat[2][3], 5);
}

TEST(MatrixTests, Fill) {
    Matrix<string> mat{5, 5};
    mat.fill("JOHN CENA");
    EXPECT_EQ(mat[3][4], mat[3][2]);
    EXPECT_EQ(mat[2][3], "JOHN CENA");
    cout << mat << endl;
}

