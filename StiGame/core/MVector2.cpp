#include "MVector2.h"
#include <cmath>
#include "MathTK.h"
namespace StiGame
{

namespace Math
{

MVector2::MVector2() : Vector2()
{

}

MVector2::MVector2(int m_x, int m_y) :
    Vector2(m_x, m_y)
{

}

MVector2::MVector2(Point *start, Point *end) :
    Vector2(start, end)
{

}

MVector2::MVector2(int m_length, Angle *m_angle) :
    Vector2(m_length, m_angle)
{

}

MVector2::~MVector2()
{

}

void MVector2::setX(int m_x)
{
	x = m_x;
	double m_angle = atan2(y, x);
    angle.setAngle(AU_RADIAN, m_angle);
	length = TK::Pythagoras(x, y);
}

void MVector2::setY(int m_y)
{
	y = m_y;
	double m_angle = atan2(y, x);
    angle.setAngle(AU_RADIAN, m_angle);
	length = TK::Pythagoras(x, y);
}

void MVector2::setLength(int m_length)
{
	length = m_length;
    x = length*cos(angle.getAngle(AU_RADIAN));
    y = length*sin(angle.getAngle(AU_RADIAN));
}

void MVector2::setAngle(Angle *m_angle)
{
    angle.setAngle(AU_RADIAN, m_angle->getAngle(AU_RADIAN));
    x = length*cos(angle.getAngle(AU_RADIAN));
    y = length*sin(angle.getAngle(AU_RADIAN));
}

}

}
