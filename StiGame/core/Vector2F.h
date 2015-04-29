#ifndef VECTOR2F_H
#define VECTOR2F_H

#include "Angle.h"
#include "PointF.h"

namespace StiGame
{

namespace Math
{
//Vector 2 Dimension, with Floating number (double)

class Vector2;
class MVector2F;

class Vector2F
{
public:
    Vector2F();
    Vector2F(double m_x, double m_y);
    Vector2F(PointF *start, PointF *end);
    Vector2F(double m_length, Angle *m_angle);

    virtual ~Vector2F();

    Vector2 toVector2();
    MVector2F toMVector2F();


    Angle* getAngle(void);
    double getX(void);
    double getY(void);
    double getLength(void);


    Vector2F operator+(Vector2F& vec);

    Vector2F operator-(Vector2F& vec);

    Vector2F operator*(double scalar);

protected:
    double x;
    double y;
    double length;
    RadianAngle angle;

};


}

}
#endif // VECTOR2F_H
