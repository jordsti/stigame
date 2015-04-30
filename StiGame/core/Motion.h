#ifndef MOTION_H
#define MOTION_H

#include "Vector2.h"
#include "MPoint.h"
namespace StiGame
{


class Motion :
    public Math::Vector2
{
public:
	Motion();
    Motion(Point m_startPoint, int m_x, int m_y, double m_speed);
    Motion(Point m_startPoint, int m_length, Math::Angle *m_angle, double m_speed);
	virtual ~Motion();

	double getSpeed(void);
	void setSpeed(double m_speed);
	
    Point* getStartPoint(void);

	void tick(void);
    Point* getCurrentPoint(void);
	
	bool isEnded(void);
protected:
    Point startPoint;
    MPoint currentPoint;
	bool ended;
	double speed;
	int _tick;
};


}

#endif
