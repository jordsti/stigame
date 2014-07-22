#include "ControllerDeviceEventArgs.h"

namespace StiGame
{

ControllerDeviceEventArgs::ControllerDeviceEventArgs() : EventArgs() {}
ControllerDeviceEventArgs::ControllerDeviceEventArgs(SDL_Event *m_sdlEvent) : EventArgs(m_sdlEvent) {}
ControllerDeviceEventArgs::~ControllerDeviceEventArgs() {}

Uint32 ControllerDeviceEventArgs::getTimestamp(void)
{
	return sdlEvent->cdevice.timestamp;
}

SDL_JoystickID ControllerDeviceEventArgs::getJoystickId(void)
{
	return static_cast<SDL_JoystickID>(sdlEvent->cdevice.which);
}

DeviceEventType ControllerDeviceEventArgs::getType(void)
{
	if(sdlEvent->cdevice.type == SDL_CONTROLLERDEVICEADDED)
	{
		return DET_ADDED;
	}
	else if(sdlEvent->cdevice.type == SDL_CONTROLLERDEVICEREMOVED)
	{
		return DET_REMOVED;
	}
	else
	{
		return DET_REMAPPED;
	}
}

SDL_ControllerDeviceEvent* ControllerDeviceEventArgs::getDeviceEvent(void)
{
	return &(sdlEvent->cdevice);
}

}