#include "matrix.h"

// ctor
Matrix::Matrix(const ElemType *arr)
{
    int arr_ix = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            _matrix[i][j] = arr[arr_ix];
        }
    }
}
Matrix::Matrix(ElemType a00, ElemType a01, ElemType a02, ElemType a03,
           ElemType a10, ElemType a11, ElemType a12, ElemType a13,
           ElemType a20, ElemType a21, ElemType a22, ElemType a23,
           ElemType a30, ElemType a31, ElemType a32, ElemType a33)
{
    _matrix[0][0] = a00;
    _matrix[0][1] = a01;
    _matrix[0][2] = a02;
    _matrix[0][3] = a03;
    _matrix[1][0] = a10;
    _matrix[1][1] = a11;
    _matrix[1][2] = a12;
    _matrix[1][3] = a13;
    _matrix[2][0] = a20;
    _matrix[2][1] = a21;
    _matrix[2][2] = a22;
    _matrix[2][3] = a23;
    _matrix[3][0] = a30;
    _matrix[3][1] = a31;
    _matrix[3][2] = a32;
    _matrix[3][3] = a33;
}

ostream& Matrix::print(ostream &os) const
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            os << _matrix[i][j] << ' ';
        }
        os << '\n';
    }
    return os;
}

void Matrix::operator+=(const Matrix &rhs) {
    for (int i = 0; i < rhs.rows(); i++)
    {
        for (int j = 0; j < rhs.cols(); j++)
        {
            _matrix[i][j] += rhs._matrix[i][j];
        }
        
    }
}

ostream& operator<<(ostream &os, const Matrix &m)
{
    return m.print(os);
}

Matrix operator+(const Matrix &m1, const Matrix &m2)
{
    Matrix result(m1);
    result += m2;
    return result;
}

Matrix operator*(const Matrix &m1, const Matrix &m2) 
{
    Matrix result;
    for (int i = 0; i < m1.rows(); i++)
    {
        for (int j = 0; j < m1.cols(); j++)
        {
            result(i, j) = 0;
            for (int k = 0; k < m1.cols(); k++)
            {
                result(i, j) += m1(i, k) * m2(k, j);
            }
        }
        
    }
    return result;
}