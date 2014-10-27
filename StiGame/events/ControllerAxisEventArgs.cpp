#include "ControllerAxisEventArgs.h"


namespace StiGame
{

ControllerAxisEventArgs::ControllerAxisEventArgs() : EventArgs() {}
ControllerAxisEventArgs::ControllerAxisEventArgs(SDL_Event *m_sdlEvent) : EventArgs(m_sdlEvent) {}
ControllerAxisEventArgs::~ControllerAxisEventArgs() {}

Uint32 ControllerAxisEventArgs::getTimestamp(void)
{
	return sdlEvent->caxis.timestamp;
}

SDL_JoystickID ControllerAxisEventArgs::getJoystickId(void)
{
	return sdlEvent->caxis.which;
}

SDL_GameControllerAxis ControllerAxisEventArgs::getAxis(void)
{
	return static_cast<SDL_GameControllerAxis>(sdlEvent->caxis.axis);
}

Sint16 ControllerAxisEventArgs::getValue(void)
{
	return sdlEvent->caxis.value;
}

SDL_ControllerAxisEvent* ControllerAxisEventArgs::getAxisEvent(void)
{
	return &(sdlEvent->caxis);
}

}