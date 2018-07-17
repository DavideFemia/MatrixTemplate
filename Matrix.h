//
// Created by studu on 12/07/2018.
//

#ifndef PROJECT_MATRIX_H
#define PROJECT_MATRIX_H

#include <utility>
#include <vector>
#include <iostream>

#include "math_exception.h"
#include "index_exception.h"

template <typename T>
class Matrix {
private:
    unsigned int rows;
    unsigned int columns;
    T *ptr;

public:
    Matrix(unsigned int rows, unsigned int columns) throw(index_exception);
    explicit Matrix(unsigned int dim) throw(index_exception);
    Matrix(unsigned int rows, unsigned int columns, const std::vector<T>& v) throw(index_exception);
    Matrix(unsigned int dim, const std::vector<T>& v) throw(index_exception);
    Matrix(const Matrix<T>& M);
    virtual ~Matrix();

    Matrix<T>& transpose();

    unsigned int getRows() const;
    unsigned int getColumns() const;
    std::pair<unsigned int, unsigned int> size() const;

    Matrix<T> row(unsigned int row) const throw(index_exception);
    Matrix<T> column(unsigned int column) const throw(index_exception);

    void setValue(const T& value, unsigned int row, unsigned int column) throw(index_exception);
    T& getValue(unsigned int row, unsigned int column) const throw(index_exception);

    Matrix<T>& operator=(const Matrix<T>& rhs);

    Matrix<T> operator+(const Matrix<T>& rhs) const throw(math_exception);
    Matrix<T> operator-(const Matrix<T>& rhs) const throw(math_exception);
    Matrix<T> operator*(const Matrix<T>& rhs) const throw(math_exception);

    Matrix<T>& operator+=(const Matrix<T>& rhs) throw(math_exception);
    Matrix<T>& operator-=(const Matrix<T>& rhs) throw(math_exception);
    Matrix<T>& operator*=(const Matrix<T>& rhs) throw(math_exception);

    bool operator==(const Matrix<T>& rhs) const;
    bool operator!=(const Matrix<T>& rhs) const;

};


template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns) throw(index_exception)
        : rows(rows), columns(columns) {
    if (rows <= 0 || columns <= 0)
        throw index_exception("Invalid number of rows or columns");

    ptr = new T[rows * columns];

    for (int i = 0; i < rows * columns; i++)
        ptr[i] = 0;
}

template <typename T>
Matrix<T>::Matrix(unsigned int dim) throw(index_exception)
        : rows(dim), columns(dim) {
    if (rows <= 0 || columns <= 0)
        throw index_exception("Invalid number of rows or columns");

    ptr = new T[rows * columns];

    for (int i = 0; i < rows * columns; i++)
        ptr[i] = 0;
}

template <typename T>
Matrix<T>::Matrix(unsigned int rows, unsigned int columns, const std::vector<T>& v) throw(index_exception)
        : rows(rows), columns(columns) {
    if (rows <= 0 || columns <= 0)
        throw index_exception("Invalid number of rows or columns");

    ptr = new T[rows * columns];

    if (v.size() != rows * columns)
        throw index_exception("Matrix and vector sizes are not equal");

    for (int i = 0; i < rows * columns; i++)
        ptr[i] = v[i];
}

template <typename T>
Matrix<T>::Matrix(unsigned int dim, const std::vector<T>& v) throw(index_exception)
        : rows(dim), columns(dim) {
    if (rows <= 0 || columns <= 0)
        throw index_exception("Invalid number of rows or columns");

    ptr = new T[rows * columns];

    if (v.size() != rows * columns)
        throw index_exception("Matrix and vector sizes are not equal");

    for (int i = 0; i < rows * columns; i++)
        ptr[i] = v[i];
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& M)
        : rows(M.rows), columns(M.columns), ptr(new T[rows * columns]) {
    for (int i = 0; i < rows * columns; i++)
        ptr[i] = M.ptr[i];
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] ptr;
}

// transposes the matrix
template <typename T>
Matrix<T> &Matrix<T>::transpose() {
    T* t = new T[rows * columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++) {
            t[j*rows + i] = ptr[i*columns + j];
        }

    delete[] ptr;
    ptr = t;

    unsigned int app = rows;
    rows = columns;
    columns = app;
    return *this;
}

// returns the number of rows
template <typename T>
unsigned int Matrix<T>::getRows() const {
    return rows;
}

// returns the number of columns
template <typename T>
unsigned int Matrix<T>::getColumns() const {
    return columns;
}

// return the size of the matrix (rows and columns)
template <typename T>
std::pair<unsigned int, unsigned int> Matrix<T>::size() const {
    return std::pair<unsigned int, unsigned int>(rows, columns);
}



// returns a vector representing the specified row of the matrix
template <typename T>
Matrix<T> Matrix<T>::row(unsigned int row) const throw(index_exception){
    if (row < 0 || row >= rows)
        throw index_exception("Invalid row index");

    Matrix<T> r(1, columns);
    for (int i = 0; i < columns; i++)
        r.ptr[i] = ptr[row*columns + i];

    return r;
}

// returns a vector representing the specified column of the matrix
template <typename T>
Matrix<T> Matrix<T>::column(unsigned int column) const throw(index_exception) {
    if (column < 0 || column >= columns)
        throw index_exception("Invalid column index");

    Matrix<T> c(rows, 1);
    for (int i = 0; i < rows; i++)
        c.ptr[i] = ptr[i*rows];

    return c;
}

// sets the value at given indexes
template <typename T>
void Matrix<T>::setValue(const T &value, unsigned int row, unsigned int column) throw(index_exception){
    if (row < 0 || row >= rows || column < 0 || column >= columns)
        throw index_exception("Invalid index");
    ptr[row * columns + column] = value;
}

// returns the value at given indexes
template <typename T>
T &Matrix<T>::getValue(unsigned int row, unsigned int column) const throw(index_exception){
    if (row < 0 || row >= rows || column < 0 || column >= columns)
        throw index_exception("Invalid index");
    return ptr[row*columns + column];
}

//ARITHMETIC OPERATORS

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const throw(math_exception){
    if (this->rows != rhs.rows || this->columns != rhs.columns)
        throw math_exception("Invalid matrix size for operator +");

    Matrix<T> sum(rows, columns);

    for (int i = 0; i < rows * columns; i++)
        sum.ptr[i] = this->ptr[i] + rhs.ptr[i];

    return sum;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs) const throw(math_exception){
    if (this->rows != rhs.rows || this->columns != rhs.columns)
        throw math_exception("Invalid matrix size for operator -");

    Matrix<T> sub(rows, columns);

    for (int i = 0; i < rows * columns; i++)
        sub.ptr[i] = this->ptr[i] - rhs.ptr[i];

    return sub;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const throw(math_exception){
    if (columns != rhs.rows)
        throw math_exception("Invalid matrix sizes for operator *");

    Matrix<T> mul(rows, rhs.columns);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rhs.columns; j++)
            for (int k = 0; k < columns; ++k)
                mul.ptr[i * rhs.columns + j] += ptr[i * columns + k] * rhs.ptr[k * rhs.columns + j];

    return mul;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    this->rows = rhs.rows;
    this->columns = rhs.columns;

    delete[] ptr;
    ptr = new T[rows * columns];

    for (int i = 0; i < rows * columns; i++)
        ptr[i] = rhs.ptr[i];

    return *this;
}

//BINARY OPERATOR

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs) throw(math_exception){
    if (this->rows != rhs.rows || this->columns != rhs.columns)
        throw math_exception("Invalid matrix size for operator +=");

    for (int i = 0; i < rows * columns; i++)
        this->ptr[i] = this->ptr[i] + rhs.ptr[i];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs) throw(math_exception){
    if (this->rows != rhs.rows || this->columns != rhs.columns)
        throw math_exception("Invalid matrix size for operator -=");

    for (int i = 0; i < rows * columns; i++)
        this->ptr[i] = this->ptr[i] - rhs.ptr[i];

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs) throw(math_exception){
    if (columns != rhs.rows)
        throw math_exception("Invalid matrix sizes for operator *=");

    T* mul = new T[rows * rhs.columns];

    for (int i = 0; i < rows * rhs.columns; i++)
        mul[i] = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rhs.columns; j++)
            for (int k = 0; k < columns; ++k)
                mul[i * rhs.columns + j] += ptr[i * columns + k] * rhs.ptr[k * rhs.columns + j];

    columns = rhs.columns;

    delete[] ptr;
    ptr = mul;

    return *this;
}

//LOGICAL OPERATORS

template <typename T>
bool Matrix<T>::operator==(const Matrix<T> &rhs) const {
    if (this->rows != rhs.rows || this->columns != rhs.columns)
        return false;
    for (int i = 0; i < rows * columns; i++)
        if (this->ptr[i] != rhs.ptr[i])
            return false;
    return true;
}

template <typename T>
bool Matrix<T>::operator!=(const Matrix<T> &rhs) const {
    return !(*this == rhs);
}

#endif //PROJECT_MATRIX_H
