#include "gtest/gtest.h"

#include "../Matrix.h"
#include "../math_exception.h"
#include "../index_exception.h"

class MatrixOperators : public ::testing::Test {
public:
    MatrixOperators()
            : A(3, 3, {1, 2, 3, 4, 5, 6, 7, 8, 9}),
              B(3, 3, {11, 12, 13, 14, 15, 16, 17, 18, 19}),
              col(3, 1, {1, 2, 3}) { }
protected:
    virtual void SetUp() { }

    Matrix<int> A;
    Matrix<int> B;

    Matrix<int> col;    // vettore colonna

};

TEST_F(MatrixOperators, Row) {
    Matrix<int> r(1, 3, {1, 2, 3});

    Matrix<int> row = A.row(0);

    ASSERT_EQ(row.getRows(), 1);
    ASSERT_EQ(row.getColumns(), 3);
    ASSERT_EQ(row, r);
}

TEST_F(MatrixOperators, column) {
    Matrix<int> r(3, 1, {1, 4, 7});

    Matrix<int> column = A.column(0);

    ASSERT_EQ(column.getRows(), 3);
    ASSERT_EQ(column.getColumns(), 1);
    ASSERT_EQ(column, r);
}

TEST_F(MatrixOperators, OperatorSum) {
    Matrix<int> sum(3, 3, {12, 14, 16, 18, 20, 22, 24, 26, 28});

    Matrix<int> somma = A + B;

    ASSERT_EQ(sum, somma);
}

TEST_F(MatrixOperators, OperatorSumInvalid) {
    Matrix<int> sum(4);
    ASSERT_THROW(A + sum, math_exception);
}

TEST_F(MatrixOperators, OperatorSub) {
    Matrix<int> sub(3, 3, {-10, -10, -10, -10, -10, -10, -10, -10, -10});

    ASSERT_EQ(sub, A - B);
}

TEST_F(MatrixOperators, OperatorSubInvalid) {
    Matrix<int> sub(4);
    ASSERT_THROW(A - sub, math_exception);
}

TEST_F(MatrixOperators, OperatorMul) {
    Matrix<int> mul(3, 3, {90, 96, 102, 216, 231, 246, 342, 366, 390});
    mul.setValue(90, 0, 0);

    Matrix<int> m = A * B;

    ASSERT_EQ(mul, m);
}

TEST_F(MatrixOperators, OperatorMulInvalid) {
    Matrix<int> mul(4);
    ASSERT_THROW((A * mul), math_exception);
}

TEST_F(MatrixOperators, OperatorBinarySum) {
    Matrix<int> sum(3, 3, {12, 14, 16, 18, 20, 22, 24, 26, 28});

    ASSERT_EQ(sum, A += B);
}

TEST_F(MatrixOperators, OperatorBinarySumInvalid) {
    Matrix<int> sum(4);
    ASSERT_THROW(A += sum, math_exception);
}

TEST_F(MatrixOperators, OperatorBinarySub) {
    Matrix<int> sub(3, 3, {-10, -10, -10, -10, -10, -10, -10, -10, -10});

    ASSERT_EQ(sub, A -= B);
}

TEST_F(MatrixOperators, OperatorBinarySubInvalid) {
    Matrix<int> sub(4);
    ASSERT_THROW(A -= sub, math_exception);
}

TEST_F(MatrixOperators, OperatorBinaryMul) {
    Matrix<int> mul(3, 3, {90, 96, 102, 216, 231, 246, 342, 366, 390});

    ASSERT_EQ(mul, A *= B);
}

TEST_F(MatrixOperators, OperatorBinaryMulInvalid) {
    Matrix<int> mul(4);
    ASSERT_THROW(A *= mul, math_exception);
}

TEST_F(MatrixOperators, Transpose) {
    Matrix<int> C(3, 3, {1, 4, 7, 2, 5, 8, 3, 6, 9});

    ASSERT_EQ(A.transpose(), C);
}

TEST_F(MatrixOperators, NotEqual) {
    ASSERT_TRUE(A != B);
    ASSERT_FALSE(A == B);
}

TEST_F(MatrixOperators, VectorProduct) {
    Matrix<int> mul(3, 1, {14, 32, 50});

    ASSERT_EQ(A * col, mul);
}

TEST_F(MatrixOperators, MatrixVectorSum) {
    ASSERT_THROW(A + col,math_exception);
}