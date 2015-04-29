#ifndef MVECTOR2_H
#define MVECTOR2_H

#include "Vector2.h"

namespace StiGame
{

namespace Math
{

class MVector2 :
	public Vector2
{
public:
    MVector2();
    MVector2(int m_x, int m_y);
    MVector2(Point *start, Point *end);
    MVector2(int m_length, Angle *m_angle);
	virtual ~MVector2();
	
	void setX(int m_x);
	void setY(int m_y);
	void setLength(int m_length);
	void setAngle(double m_angle);
	void setAngle(Angle *m_angle);
	
};

}

}


#endif
