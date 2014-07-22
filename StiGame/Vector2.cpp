#include "Vector2.h"
#include <cmath>
#include "MathTK.h"

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
	
	angle = TK::CreateAngle(AU_RADIAN, m_angle);
}

Vector2::Vector2(int m_length, Angle *m_angle)
{
	length = m_length;
	angle = m_angle;

	x = length*cos(angle->getAngle(AU_RADIAN));
	y = length*sin(angle->getAngle(AU_RADIAN));
}

/*Vector2::Vector2(int m_length, double m_angle)
{
	angle = MathTK::CreateAngle(AU_RADIAN, m_angle);
	length = m_length;
	
	x = length*cos(m_angle);
	y = length*sin(m_angle);
}*/

Vector2::~Vector2()
{
	if(angle != 0)
	{
		delete angle;
	}
}

Angle* Vector2::getAngle(void)
{
	return angle;
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

}

}