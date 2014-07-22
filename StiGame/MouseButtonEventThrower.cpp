#include "MouseButtonEventThrower.h"

namespace StiGame
{

MouseButtonEventThrower::MouseButtonEventThrower()
{

}

MouseButtonEventThrower::~MouseButtonEventThrower()
{

}
	
void MouseButtonEventThrower::subscribe(MouseButtonEventListener *listener)
{
	mouseListeners.push_back(listener);

}

void MouseButtonEventThrower::remove(MouseButtonEventListener *listener)
{
	mouseListeners.remove(listener);
}

//std::list<MouseEventListener*> mouseListeners;
	
void MouseButtonEventThrower::publish(MouseButtonEventThrower *source, MouseButtonEventArgs *args)
{
	std::list<MouseButtonEventListener*>::iterator lit(mouseListeners.begin()), lend(mouseListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(source, args);
	}
}

}