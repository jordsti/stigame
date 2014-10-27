#include "MouseWheelEventThrower.h"


namespace StiGame
{

MouseWheelEventThrower::MouseWheelEventThrower() {}

MouseWheelEventThrower::~MouseWheelEventThrower() {}

void MouseWheelEventThrower::subscribe(MouseWheelEventListener *listener)
{
	wheelListeners.push_back(listener);
}

void MouseWheelEventThrower::remove(MouseWheelEventListener *listener)
{
	wheelListeners.remove(listener);
}

void MouseWheelEventThrower::publish(MouseWheelEventThrower *src, MouseWheelEventArgs *args)
{

	std::list<MouseWheelEventListener*>::iterator lit(wheelListeners.begin()), lend(wheelListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(src, args);
	}

}

}