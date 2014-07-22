#ifndef CONTROLLERAXISEVENTARGS_H
#define CONTROLLERAXISEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

class ControllerAxisEventArgs
	: public EventArgs
{
public:
	ControllerAxisEventArgs();
	ControllerAxisEventArgs(SDL_Event *m_sdlEvent);
	virtual ~ControllerAxisEventArgs();
	
	Uint32 getTimestamp(void);
	SDL_JoystickID getJoystickId(void);
	SDL_GameControllerAxis getAxis(void);
	Sint16 getValue(void);
	SDL_ControllerAxisEvent* getAxisEvent(void);
};

}

#endif