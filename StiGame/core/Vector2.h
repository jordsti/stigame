#ifndef VECTOR2_H
#define VECTOR2_H

#include "Angle.h"

namespace StiGame
{

namespace Math
{
//Vector rewrite
//WIP
class Vector2
{
public:
	Vector2();
	Vector2(int m_x, int m_y);
	Vector2(int m_length, Angle *m_angle);
	//Vector2(int m_length, double m_angle);
	virtual ~Vector2();
	
	Angle* getAngle(void);
	int getX(void);
	int getY(void);
	int getLength(void);
	
protected:
	int x;
	int y;
	int length;
	Angle *angle;

};


}

}

#endif