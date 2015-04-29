#ifndef VECTOR2_H
#define VECTOR2_H

#include "Angle.h"
#include "Point.h"
namespace StiGame
{

namespace Math
{
//Vector 2 Dimension

class Vector2F;

class Vector2
{
public:
	Vector2();
	Vector2(int m_x, int m_y);
    Vector2(Point *start, Point *end);
	Vector2(int m_length, Angle *m_angle);

	virtual ~Vector2();
	
    Vector2F toVector2F(void);

	Angle* getAngle(void);
	int getX(void);
	int getY(void);
	int getLength(void);
	

    Vector2 operator+(Vector2& vec);

    Vector2 operator-(Vector2& vec);

    Vector2 operator*(double scalar);

protected:
	int x;
	int y;
    int length;
    RadianAngle angle;

};


}

}

#endif
