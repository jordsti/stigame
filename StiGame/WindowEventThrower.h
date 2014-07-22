#ifndef WINDOWEVENTTHROWER_H
#define WINDOWEVENTTHROWER_H

#include "WindowEventListener.h"
#include <list>

namespace StiGame
{

class WindowEventThrower
{
public:
	WindowEventThrower();
	virtual ~WindowEventThrower();
	virtual void subscribe(WindowEventListener *listener);
	virtual void remove(WindowEventListener *listener);
protected:
	virtual void publish(WindowEventThrower *src, WindowEventArgs *args);
	std::list<WindowEventListener*> windowListeners;
};

}

#endif