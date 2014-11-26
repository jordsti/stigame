#include "PointF.h"

namespace StiGame
{

PointF::PointF()
{
    x = 0.0f;
    y = 0.0f;
}

PointF::PointF(float m_x, float m_y)
{
    x = m_x;
    y = m_y;
}

PointF::~PointF()
{

}

float PointF::getX(void)
{
    return x;
}

float PointF::getY(void)
{
    return y;
}

bool PointF::equals(float m_x, float m_y)
{
    return (x == m_x && y == m_y);
}

bool PointF::equals(PointF *pt)
{
    return equals(pt->getX(), pt->getY());
}

Point PointF::toPoint(void)
{
    return Point((int)x, (int)y);
}

MPoint PointF::toMPoint(void)
{
    return MPoint((int)x, (int)y);
}

Math::Matrix PointF::homogenousMatrix(void)
{
    Math::Matrix matrix (1, 3, 1.0f);
    matrix.set(0, 0, x);
    matrix.set(0, 1, y);
    return matrix;
}

}
