#include "Vector2.h"
#include <cmath>
#include "MathTK.h"
#include "Vector2F.h"
#include "MVector2.h"
namespace StiGame
{

namespace Math
{

Vector2::Vector2()
{
	x = 0;
	y = 0;
	length = 0;
	angle = 0;
}

Vector2::Vector2(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
	
	double m_angle = atan2(m_y, m_x);
	
	length = TK::Pythagoras(x, y);
	
    angle = RadianAngle(m_angle);
}

Vector2::Vector2(int m_length, Angle *m_angle)
{
	length = m_length;
    angle = RadianAngle(m_angle->getAngle(AU_RADIAN));
    x = length*cos(angle.getAngle(AU_RADIAN));
    y = length*sin(angle.getAngle(AU_RADIAN));
}

Vector2::Vector2(Point *start, Point *end)
{
    x = end->getX() - start->getX();
    y = end->getY() - start->getY();
    length = TK::Pythagoras(x, y);

    double m_angle = atan2(x, y);
    angle = RadianAngle(m_angle);
}


Vector2F Vector2::toVector2F(void)
{
    Vector2F v (x, y);
    return v;
}

MVector2 Vector2::toMVector2(void)
{
    MVector2 v (x, y);
    return v;
}

Vector2::~Vector2()
{

}

Angle* Vector2::getAngle(void)
{
    return &angle;
}

int Vector2::getX(void)
{
	return x;
}

int Vector2::getY(void)
{
	return y;
}

int Vector2::getLength(void)
{
	return length;
}

Vector2 Vector2::operator+(Vector2& vec)
{
    Vector2 v (this->x + vec.getX(), this->y + vec.getY());
    return v;
}

Vector2 Vector2::operator-(Vector2& vec)
{
    Vector2 v (this->x - vec.getX(), this->y - vec.getY());
    return v;
}

Vector2 Vector2::operator*(double scalar)
{
    Vector2 v (this->x * scalar, this->y * scalar);
    return v;
}

}

}
