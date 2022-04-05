#include "Matrix.hpp"
using zich::Matrix;

Matrix::Matrix(vector<double>& mat, int row, int col)
{
    if (row <= 0 || col <= 0)
    {
        throw MessageException("rows and columns must be positive numbers");
    }
    if (row * col != mat.size())
    {
        throw MessageException("the matrix must be at the same size of: row * col");
    }
    _row = row;
    _col = col;
    arrToMat(mat, row, col);
    
}

void Matrix::arrToMat(vector<double>& matArr, int row, int col)
{
    _mat = vector<vector<double>>();
    unsigned int ind = 0;
    int len = matArr.size();
    for (unsigned int i = 0; i < row && ind < len; i++)
    {
        _mat.push_back(vector<double>());
        for (unsigned int j = 0; j < col && ind < len; j++)
        {
            _mat[i][j] = matArr[ind++];
        }
        
    }
}

Matrix::~Matrix()
{
}

void Matrix::throwIfNotSameSize(const Matrix& a, const Matrix& b)
{
    if (a._row != b._row || a._col != b._col)
    {
        throw MessageException("the matrixes must have same number of row and same number column");
    }
}

void Matrix::throwIfMulWrong(const Matrix& a, const Matrix& b)
{
    if (a._col != b._row)
    {
        throw MessageException("the number of column of the left matrix must be equal to the number of rows of the right matrix");
    }
}

Matrix Matrix::operator+() const
{
    return (*this);
}

Matrix Matrix::operator+(const Matrix& other) const
{
    throwIfNotSameSize(*this, other);

    return (*this);
}

Matrix Matrix::operator-() const
{
    return (*this);
}
Matrix Matrix::operator-(const Matrix& other) const
{
    throwIfNotSameSize(*this, other);
    return (*this);
}

// * operator
Matrix Matrix::operator*(const Matrix& other) const
{
    throwIfMulWrong(*this, other);
    return (*this);
}

Matrix Matrix::operator*(double skalar) const
{
    return (*this);
}

Matrix operator*(double skalar, const Matrix& m)
{
    return (m);
}



Matrix& Matrix::operator+=(const Matrix& other)
{
    throwIfNotSameSize(*this, other);
    return (*this);
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    throwIfNotSameSize(*this, other);
    return (*this);
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    throwIfMulWrong(*this, other);
    return (*this);
}

Matrix& Matrix::operator*=(double skalar)
{
    return (*this);
}