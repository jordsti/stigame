#include "Matrix.h"
namespace StiGame
{

namespace Math
{

Matrix::Matrix(int m_rows, int m_cols, float initValue)
{
    cols = m_cols;
    rows = m_rows;

    for(int c=0; c<cols; c++)
    {
        std::vector<float> col;
        for(int r=0; r<rows; r++)
        {
            col.push_back(initValue);
        }

        _values.push_back(col);
    }
}


Matrix Matrix::operator+(Matrix mat)
{
    Matrix rs (this->rows, this->cols);

    for(int c=0; c<this->cols; c++)
    {
        for(int r=0; r<this->rows; r++)
        {
            rs.set(c, r, this->get(c, r) + mat.get(c, r));
        }
    }

    return rs;
}

Matrix Matrix::operator-(Matrix mat)
{
    Matrix rs (this->rows, this->cols);

    for(int c=0; c<this->cols; c++)
    {
        for(int r=0; r<this->rows; r++)
        {
            rs.set(c, r, this->get(c, r) - mat.get(c, r));
        }
    }

    return rs;
}

float Matrix::get(int c, int r)
{
    return  _values[c][r];
}

void Matrix::set(int c, int r, float m_val)
{
    _values[c][r] = m_val;
}


int Matrix::getCols(void)
{
    return cols;
}

int Matrix::getRows(void)
{
    return rows;
}

Dimension Matrix::dimension(void)
{
    return Dimension(rows, cols);
}

Matrix Matrix::multiply(Matrix mat)
{
    //todo
    Matrix rs (rows, mat.getCols());

    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<mat.getCols(); c++)
        {
            float _elem = 0.0f;



        }
    }

    return rs;
}

Matrix::~Matrix()
{

}

}

}
