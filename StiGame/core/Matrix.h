#ifndef MATRIX_H
#define MATRIX_H
/*
 *
 * WIP
 *
 */

#include <vector>
#include "Dimension.h"

namespace StiGame
{

namespace Math
{

class Matrix
{
public:
    Matrix(int m_rows, int m_cols, float initValue = 0.0f);

    float get(int c, int r);
    void set(int c, int r, float m_val);

    Matrix operator+(Matrix mat);

    Matrix operator-(Matrix mat);

    Matrix multiply(Matrix mat);

    int getCols(void);
    int getRows(void);
    Dimension dimension(void);

    virtual ~Matrix();
private:
    int cols;
    int rows;
    std::vector< std::vector< float > > _values;
};

}

}

#endif // MATRIX_H
