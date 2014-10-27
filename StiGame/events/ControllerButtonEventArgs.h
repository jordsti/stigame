#ifndef CONTROLLERBUTTONEVENTARGS_H
#define CONTROLLERBUTTONEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

class ControllerButtonEventArgs
	: public EventArgs
{
public:
	ControllerButtonEventArgs();
	ControllerButtonEventArgs(SDL_Event *m_sdlEvent);
	virtual ~ControllerButtonEventArgs();
	
	Uint32 getTimestamp(void);
	SDL_JoystickID getJoystickId(void);
	bool isDown(void);
	SDL_GameControllerButton getButton(void);
	Uint8 getState(void);
	SDL_ControllerButtonEvent* getButtonEvent(void);
};

}

#endif