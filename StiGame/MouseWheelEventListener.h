#ifndef MOUSEWHEELEVENTLISTENER_H
#define MOUSEWHEELEVENTLISTENER_H

#include "MouseWheelEventArgs.h"

namespace StiGame
{

class MouseWheelEventThrower;

class MouseWheelEventListener
{
public:
	MouseWheelEventListener();
	virtual ~MouseWheelEventListener();
	virtual void handleEvent(MouseWheelEventThrower *src, MouseWheelEventArgs *args);
};

}

#endif