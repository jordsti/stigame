#ifndef MOTION_H
#define MOTION_H

#include "Vector.h"

namespace StiGame
{

namespace Math
{

class Motion :
	public Vector
{
public:
	Motion();
	Motion(int m_x, int m_y, double m_speed);
	Motion(int length, Angle *angle, double m_speed);
	virtual ~Motion();

	double getSpeed(void);
	void setSpeed(double m_speed);
	
	int getStartingX(void);
	int getStartingY(void);
	
	void tick(void);
	
	bool isEnded(void);
protected:
	bool ended;
	int startingX;
	int startingY;
	double speed;
	int _tick;
};

}

}

#endif