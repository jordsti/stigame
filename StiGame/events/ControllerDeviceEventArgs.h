#ifndef CONTROLLERDEVICEEVENTARGS_H
#define CONTROLLERDEVICEEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum DeviceEventType {
	DET_ADDED,
	DET_REMOVED,
	DET_REMAPPED
};

class ControllerDeviceEventArgs
	: public EventArgs
{
public:
	ControllerDeviceEventArgs();
	ControllerDeviceEventArgs(SDL_Event *m_sdlEvent);
	virtual ~ControllerDeviceEventArgs();
	
	Uint32 getTimestamp(void);
	SDL_JoystickID getJoystickId(void);
	DeviceEventType getType(void);
	
	SDL_ControllerDeviceEvent* getDeviceEvent(void);
};

}

#endif