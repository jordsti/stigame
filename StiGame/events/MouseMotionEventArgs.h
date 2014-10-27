#ifndef MOUSEMOTIONEVENTARGS_H
#define MOUSEMOTIONEVENTARGS_H

#include "EventArgs.h"


namespace StiGame
{

class MouseMotionEventArgs
	: public EventArgs
{
public:
	MouseMotionEventArgs();
	MouseMotionEventArgs(SDL_Event *m_sdlEvent);
	virtual ~MouseMotionEventArgs();
	
	Uint32 getTimestamp(void);
	Uint32 getWindowId(void);
	Uint32 getWhich(void);
	Uint32 getState(void);
	Sint32 getX(void);
	Sint32 getY(void);
	Sint32 getRelX(void);
	Sint32 getRelY(void);
	
	SDL_MouseMotionEvent* getMotionEvent(void);
};

}

#endif