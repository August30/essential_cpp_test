#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
using namespace std;


typedef float ElemType;
class Matrix
{
    friend ostream& operator<<(ostream &os, const Matrix &m);
    friend Matrix operator+(const Matrix &m1, const Matrix &m2);
    friend Matrix operator*(const Matrix &m1, const Matrix &m2);

public:
    // ctor
    Matrix(const ElemType *array);
    Matrix(ElemType a00 = 0, ElemType a01 = 0, ElemType a02 = 0, ElemType a03 = 0,
           ElemType a10 = 0, ElemType a11 = 0, ElemType a12 = 0, ElemType a13 = 0,
           ElemType a20 = 0, ElemType a21 = 0, ElemType a22 = 0, ElemType a23 = 0,
           ElemType a30 = 0, ElemType a31 = 0, ElemType a32 = 0, ElemType a33 = 0);
    // rows cols
    int rows() const { return 4; }
    int cols() const { return 4; }

    ElemType operator()(int row, int col) const
    {
        return _matrix[row][col];
    }
    ElemType& operator()(int row, int col)
    {
        return _matrix[row][col];
    }

    // show
    ostream& print(ostream &os) const;
    void operator+=(const Matrix &rhs);

private:
    ElemType _matrix[4][4];
};



#endif // __MATRIX_H__