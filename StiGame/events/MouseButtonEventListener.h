#ifndef MOUSEBUTTONEVENTLISTENER_H
#define MOUSEBUTTONEVENTLISTENER_H

#include "MouseButtonEventArgs.h"

namespace StiGame
{

class MouseButtonEventThrower;

class MouseButtonEventListener
{
public:
	MouseButtonEventListener();
	virtual ~MouseButtonEventListener();
	virtual void handleEvent(MouseButtonEventThrower *src, MouseButtonEventArgs *args);
};

}


#endif