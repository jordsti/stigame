#ifndef MOUSEWHEELEVENTARGS_H
#define MOUSEWHEELEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum WheelDirection {
	WD_NONE = 0,
	WD_UP = 1,
	WD_DOWN = 2,
	WD_LEFT = 4,
	WD_RIGHT = 8,
	//multi-direction
	WD_UP_LEFT = WD_UP + WD_LEFT,
	WD_UP_RIGHT = WD_UP + WD_RIGHT,
	WD_DOWN_LEFT = WD_DOWN + WD_LEFT,
	WD_DOWN_RIGHT = WD_DOWN + WD_RIGHT
};


class MouseWheelEventArgs
	: public EventArgs
{
public:
	MouseWheelEventArgs();
	MouseWheelEventArgs(SDL_Event *m_sdlEvent);
	virtual ~MouseWheelEventArgs();
	
	Uint32 getTimestamp(void);
	Uint32 getWindowId(void);
	Uint32 getWhich(void);
	Sint32 getX(void);
	Sint32 getY(void);
	WheelDirection getDirection(void);
	
	SDL_MouseWheelEvent* getWheelEvent(void);
};


}

#endif