#include "PointF.h"
#include "MathTK.h"
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

PointF::PointF(PointF *pt)
{
    x = pt->getX();
    y = pt->getY();
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
    return Point(Math::TK::round(x), Math::TK::round(y));
}

MPoint PointF::toMPoint(void)
{
    return MPoint(Math::TK::round(x), Math::TK::round(y));
}

Math::Matrix PointF::homogenousMatrix(void)
{
    Math::Matrix matrix (1, 3, 1.0f);
    matrix.set(0, 0, x);
    matrix.set(0, 1, y);
    return matrix;
}

PointF PointF::operator+(PointF& pt)
{
    PointF _pt (this->x + pt.getX(), this->y + pt.getY());
    return _pt;
}

PointF PointF::operator-(PointF& pt)
{
    PointF _pt (this->x - pt.getX(), this->y - pt.getY());
    return _pt;
}

PointF PointF::operator*(double scalar)
{
    PointF _pt (this->x * scalar, this->y * scalar);
    return _pt;
}

}
