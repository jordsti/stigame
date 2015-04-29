#include "Vector2F.h"
#include "Vector2.h"
#include "MathTK.h"
#include "MVector2F.h"
namespace StiGame
{

namespace Math
{

Vector2F::Vector2F()
{
    x = 0;
    y = 0;
    length = 0;
    angle = RadianAngle(0);
}

Vector2F::Vector2F(double m_x, double m_y)
{
    x = m_x;
    y = m_y;

    double m_angle = atan2(m_y, m_x);

    length = TK::Pythagoras(x, y);

    angle = RadianAngle(m_angle);
}

Vector2F::Vector2F(PointF *start, PointF *end)
{
    x = end->getX() - start->getX();
    y = end->getY() - start->getY();
    length = TK::Pythagoras(x, y);

    double m_angle = atan2(x, y);
    angle = RadianAngle(m_angle);

}

Vector2F::Vector2F(double m_length, Angle *m_angle)
{

    length = m_length;
    angle = RadianAngle(m_angle->getAngle(AU_RADIAN));
    x = length*cos(angle.getAngle(AU_RADIAN));
    y = length*sin(angle.getAngle(AU_RADIAN));
}

Vector2F::~Vector2F()
{

}

Vector2 Vector2F::toVector2()
{
    Vector2 v (x, y);
    return v;
}

MVector2F Vector2F::toMVector2F()
{
    MVector2F v (x, y);
    return v;
}


Angle* Vector2F::getAngle(void)
{
    return &angle;
}

double Vector2F::getX(void)
{
    return x;
}

double Vector2F::getY(void)
{
    return y;
}

double Vector2F::getLength(void)
{
    return length;
}


Vector2F Vector2F::operator+(Vector2F& vec)
{
    Vector2F v (this->x + vec.getX(), this->y + vec.getY());
    return v;
}

Vector2F Vector2F::operator-(Vector2F& vec)
{
    Vector2F v (this->x - vec.getX(), this->y - vec.getY());
    return v;
}

Vector2F Vector2F::operator*(double scalar)
{
    Vector2F v (this->x * scalar, this->y * scalar);
    return v;
}

}

}
