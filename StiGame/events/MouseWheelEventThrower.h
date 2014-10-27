#ifndef MOUSEWHEELEVENTTHROWER_H
#define MOUSEWHEELEVENTTHROWER_H

#include "MouseWheelEventListener.h"
#include <list>
namespace StiGame
{

class MouseWheelEventThrower
{
public:
	MouseWheelEventThrower();
	virtual ~MouseWheelEventThrower();
	virtual void subscribe(MouseWheelEventListener *listener);
	virtual void remove(MouseWheelEventListener *listener);
	
protected:
	std::list<MouseWheelEventListener*> wheelListeners;
	
	virtual void publish(MouseWheelEventThrower *src, MouseWheelEventArgs *args);
};

}

#endif