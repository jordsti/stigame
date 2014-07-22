#include "MouseWheelEventArgs.h"

namespace StiGame
{

MouseWheelEventArgs::MouseWheelEventArgs()
	: EventArgs()
{

}
MouseWheelEventArgs::MouseWheelEventArgs(SDL_Event *m_sdlEvent)
	: EventArgs(m_sdlEvent)
{

}

MouseWheelEventArgs::~MouseWheelEventArgs()
{

}

Uint32 MouseWheelEventArgs::getTimestamp(void)
{
	return sdlEvent->wheel.timestamp;
}

Uint32 MouseWheelEventArgs::getWindowId(void)
{
	return sdlEvent->wheel.windowID;
}

Uint32 MouseWheelEventArgs::getWhich(void)
{
	return sdlEvent->wheel.which;
}

Sint32 MouseWheelEventArgs::getX(void)
{
	return sdlEvent->wheel.x;
}

Sint32 MouseWheelEventArgs::getY(void)
{
	return sdlEvent->wheel.y;
}

WheelDirection MouseWheelEventArgs::getDirection(void)
{
	Sint32 x = getX();
	Sint32 y = getY();
	
	int direction = WD_NONE;
	
	// x = 1 -> right
	// x = 0 -> nothing todo
	// x = -1 -> left
	
	if(x == 1)
	{
		direction += WD_RIGHT;
	}
	else if(x == -1)
	{
		direction += WD_LEFT;
	}
	
	// y = 1 -> up
	// y = 0 -> nothing todo
	// y = -1 -> down
	if(y == 1)
	{
		direction += WD_UP;
	}
	else if(y == -1)
	{
		direction += WD_DOWN;
	}
	
	WheelDirection wd = static_cast<WheelDirection>(direction);
	return wd;
}

SDL_MouseWheelEvent* MouseWheelEventArgs::getWheelEvent(void)
{
	return &(sdlEvent->wheel);
}

}