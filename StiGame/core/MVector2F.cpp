#include "MVector2F.h"
#include "MathTK.h"
#include <cmath>
namespace StiGame
{

namespace Math
{

MVector2F::MVector2F() :
    Vector2F()
{

}

MVector2F::MVector2F(double m_x, double m_y) :
    Vector2F(m_x, m_y)
{

}

MVector2F::MVector2F(PointF *start, PointF *end) :
    Vector2F(start, end)
{

}

MVector2F::MVector2F(double m_length, Angle *m_angle) :
    Vector2F(m_length, m_angle)
{

}

MVector2F::~MVector2F()
{

}

void MVector2F::setX(double m_x)
{
    x = m_x;
    double m_angle = atan2(y, x);
    angle.setAngle(AU_RADIAN, m_angle);
    length = TK::Pythagoras(x, y);
}

void MVector2F::setY(double m_y)
{
    y = m_y;
    double m_angle = atan2(y, x);
    angle.setAngle(AU_RADIAN, m_angle);
    length = TK::Pythagoras(x, y);
}

void MVector2F::setLength(double m_length)
{
    length = m_length;
    x = length*cos(angle.getAngle(AU_RADIAN));
    y = length*sin(angle.getAngle(AU_RADIAN));
}

void MVector2F::setAngle(Angle *m_angle)
{
    angle.setAngle(AU_RADIAN, m_angle->getAngle(AU_RADIAN));
    x = length*cos(angle.getAngle(AU_RADIAN));
    y = length*sin(angle.getAngle(AU_RADIAN));
}

}

}
