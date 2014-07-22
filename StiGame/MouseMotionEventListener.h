#ifndef MOUSEMOTIONEVENTLISTENER_H
#define MOUSEMOTIONEVENTLISTENER_H

#include "MouseMotionEventArgs.h"

namespace StiGame
{

class MouseMotionEventThrower;

class MouseMotionEventListener
{
public:
	MouseMotionEventListener();
	virtual ~MouseMotionEventListener();
	virtual void handleEvent(MouseMotionEventThrower *src, MouseMotionEventArgs *args);
};

}

#endif