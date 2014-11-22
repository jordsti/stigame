#ifndef MATRIX_H
#define MATRIX_H
/*
 *
 * WIP
 *
 */

#include <vector>

class Matrix
{
public:
    Matrix(int cols, int rows, float initValue = 0.0f);

    float get(int c, int r);
    void set(int c, int r, float m_val);

    virtual ~Matrix();
private:
    std::vector< std::vector< float > > _values;
};

#endif // MATRIX_H
