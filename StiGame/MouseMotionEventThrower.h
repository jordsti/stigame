#ifndef MOUSEMOTIONEVENTTHROWER_H
#define MOUSEMOTIONEVENTTHROWER_H

#include "MouseMotionEventListener.h"
#include <list>


namespace StiGame
{

class MouseMotionEventThrower
{
public:
	MouseMotionEventThrower();
	virtual ~MouseMotionEventThrower();
	
	virtual void subscribe(MouseMotionEventListener *listener);
	virtual void remove(MouseMotionEventListener *listener);
protected:
	std::list<MouseMotionEventListener*> motionListeners;
	
	virtual void publish(MouseMotionEventThrower *src, MouseMotionEventArgs *args);
};

}

#endif