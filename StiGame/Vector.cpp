#include "Vector.h"
#include "MathTK.h"
#include <cmath>

namespace StiGame
{

namespace Math
{


Vector::Vector()
{
    //ctor
    x = 0;
    y = 0;
}

Vector::Vector(int m_x, int m_y)
{
    x = m_x;
    y = m_y;
}

Vector::Vector(int m_length, Angle* angle)
{

    x = nearbyint((double)m_length * cos(angle->getAngle(AU_RADIAN)));
    y = nearbyint((double)m_length * sin(angle->getAngle(AU_RADIAN)));
}

int Vector::getX(void)
{
    return x;
}

int Vector::getY(void)
{
    return y;
}

int Vector::length(void)
{
    return (int)sqrt(pow(x,2) + pow(y,2));
}

Angle* Vector::getAngle(void)
{
    return TK::CreateAngle(AU_RADIAN, atan2(y,x));

}

void Vector::setX(int m_x)
{
    x = m_x;
}

void Vector::setY(int m_y)
{
    y = m_y;
}

Dimension* Vector::getDimension(void)
{
    Dimension *dim = new Dimension( std::abs(x), std::abs(y) );

    return dim;
}

Vector::~Vector()
{
    //dtor
}

}

}
