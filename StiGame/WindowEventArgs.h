#ifndef WINDOWEVENTARGS_H
#define WINDOWEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum WindowEventType {
	WET_SHOWN = SDL_WINDOWEVENT_SHOWN,
	WET_HIDDEN = SDL_WINDOWEVENT_HIDDEN,
	WET_EXPOSED = SDL_WINDOWEVENT_EXPOSED,
	WET_MOVED = SDL_WINDOWEVENT_MOVED,
	WET_RESIZED = SDL_WINDOWEVENT_RESIZED,
	WET_RESTORED = SDL_WINDOWEVENT_RESTORED,
	WET_ENTER = SDL_WINDOWEVENT_ENTER,
	WET_LEAVE = SDL_WINDOWEVENT_LEAVE,
	WET_FOCUS_GAINED = SDL_WINDOWEVENT_FOCUS_GAINED,
	WET_FOCUS_LOST = SDL_WINDOWEVENT_FOCUS_LOST,
	WET_CLOSE = SDL_WINDOWEVENT_CLOSE
};

class WindowEventArgs :
	public EventArgs
{
public:
	WindowEventArgs();
	WindowEventArgs(SDL_Event *m_sdlEvent);
	virtual ~WindowEventArgs();
	
	Uint32 getWindowId(void);
	Uint32 getTimestamp(void);
	
	SDL_WindowEvent* getWindowEvent(void);
	WindowEventType getType(void);
	
	Sint32 getData1(void);
	Sint32 getData2(void);
};

}

#endif