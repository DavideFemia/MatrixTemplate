#include "gtest/gtest.h"

#include "../Matrix.h"

TEST(MatrixConstructors, ConstructorRowColumns) {
    Matrix<int> m(3, 4);

    ASSERT_EQ(3, m.getRows());
    ASSERT_EQ(4, m.getColumns());
}

// TEST SQUARE CONSTRUCTOR AND SIZE FUNCTION
TEST(MatrixConstructors, ConstructorSquare) {
    Matrix<int> m(3);

    ASSERT_EQ(3, m.size().first);
    ASSERT_EQ(3, m.size().second);
}

TEST(MatrixConstructors, ConstructorVector) {
    Matrix<int> m(3, {1, 2, 3, 4, 5, 6, 7, 8, 9});

    ASSERT_EQ(m.getValue(0, 0), 1);
    ASSERT_EQ(m.getValue(0, 1), 2);
    ASSERT_EQ(m.getValue(0, 2), 3);
    ASSERT_EQ(m.getValue(1, 0), 4);
    ASSERT_EQ(m.getValue(1, 1), 5);
    ASSERT_EQ(m.getValue(1, 2), 6);
    ASSERT_EQ(m.getValue(2, 0), 7);
    ASSERT_EQ(m.getValue(2, 1), 8);
    ASSERT_EQ(m.getValue(2, 2), 9);
}

TEST(MatrixConstructors, ConstructorVectorException) {
    ASSERT_THROW(Matrix<int>(8, 8, {1, 2}), index_exception);
}