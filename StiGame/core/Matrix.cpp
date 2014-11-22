#include "Matrix.h"

Matrix::Matrix(int cols, int rows, float initValue)
{
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

float Matrix::get(int c, int r)
{
    return  _values[c][r];
}

void Matrix::set(int c, int r, float m_val)
{
    _values[c][r] = m_val;
}

Matrix::~Matrix()
{

}
