#ifndef MVECTOR2F_H
#define MVECTOR2F_H
#include "Vector2F.h"
namespace StiGame
{

namespace Math
{

class MVector2F :
        public Vector2F
{
public:
    MVector2F();
    MVector2F(double m_x, double m_y);
    MVector2F(PointF *start, PointF *end);
    MVector2F(double m_length, Angle *m_angle);
    virtual ~MVector2F();

    void setX(double m_x);
    void setY(double m_y);
    void setLength(double m_length);
    void setAngle(Angle *m_angle);
};

}

}


#endif // MVECTOR2F_H
