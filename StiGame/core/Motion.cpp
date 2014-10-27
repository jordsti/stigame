#include "Motion.h"

namespace StiGame
{

namespace Math
{

Motion::Motion()
	: Vector()
{
	startingX = x;
	startingY = y;
	speed = 0;
	ended = true;
}

Motion::Motion(int m_x, int m_y, double m_speed)
	: Vector(m_x, m_y)
{
	speed = m_speed;
	startingX = m_x;
	startingY = m_y;
	ended = false;
}

Motion::Motion(int length, Angle *angle, double m_speed)
	: Vector(length, angle)
{
	speed = m_speed;
	startingX = x;
	startingY = y;
	ended = false;
}

Motion::~Motion()
{

}

void Motion::tick(void)
{

}

bool Motion::isEnded(void)
{
	return ended;
}

int Motion::getStartingX(void)
{
	return startingX;
}
int Motion::getStartingY(void)
{
	return startingY;
}

double Motion::getSpeed(void)
{
	return speed;
}

void Motion::setSpeed(double m_speed)
{
	speed = m_speed;
}

}

}