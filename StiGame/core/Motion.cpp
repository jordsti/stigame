#include "Motion.h"

namespace StiGame
{

Motion::Motion() :
    Math::Vector2()
{
    _tick = 0;
    ended = false;
    speed = 0;
}

Motion::Motion(Point m_startPoint, int m_x, int m_y, double m_speed)
    : Math::Vector2(m_x, m_y)
{
    _tick = 0;
    ended = false;
    speed = m_speed;
    startPoint = m_startPoint;
    currentPoint.setPoint(&startPoint);
}

Motion::Motion(Point m_startPoint, int m_length, Math::Angle *m_angle, double m_speed) :
    Math::Vector2(m_length, m_angle)
{
    _tick = 0;
    ended = false;
    startPoint = m_startPoint;
    speed = m_speed;
    currentPoint.setPoint(&startPoint);
}

Motion::~Motion()
{

}

double Motion::getSpeed(void)
{
    return speed;
}

void Motion::setSpeed(double m_speed)
{
    speed = m_speed;
}

Point* Motion::getStartPoint(void)
{
    return &startPoint;
}

void Motion::tick(void)
{
    if(!ended)
    {
        _tick++;
        Point endPoint (startPoint.getX() + x, startPoint.getY() + y);
        if(currentPoint.equals(&endPoint))
        {
            ended = true;
        }
        else
        {
            int n_x = ((double)_tick*speed)*x;
            int n_y = ((double)_tick*speed)*y;

            if(n_x > endPoint.getX())
            {
                n_x = endPoint.getX();
            }

            if(n_y > endPoint.getY())
            {
                n_y = endPoint.getY();
            }

            currentPoint.setPoint(n_x, n_y);
        }
    }
}

bool Motion::isEnded(void)
{
    return ended;
}

Point* Motion::getCurrentPoint(void)
{
    return &currentPoint;
}

}
