#ifndef WINDOWEVENTLISTENER
#define WINDOWEVENTLISTENER

#include "WindowEventArgs.h"

namespace StiGame
{

class WindowEventThrower;

class WindowEventListener
{
public:
	WindowEventListener();
	virtual ~WindowEventListener();
	virtual void handleEvent(WindowEventThrower *src, WindowEventArgs *args);
};

}

#endif