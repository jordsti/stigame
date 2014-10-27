#include "WindowEventThrower.h"

namespace StiGame
{

WindowEventThrower::WindowEventThrower() {}
WindowEventThrower::~WindowEventThrower() {}

void WindowEventThrower::subscribe(WindowEventListener *listener)
{
	windowListeners.push_back(listener);
}

void WindowEventThrower::remove(WindowEventListener *listener)
{
	windowListeners.remove(listener);
}

void WindowEventThrower::publish(WindowEventThrower *src, WindowEventArgs *args)
{
	std::list<WindowEventListener*>::iterator lit(windowListeners.begin()), lend(windowListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(src, args);
	}
}
//std::list<WindowEventListener*> windowListeners;

}