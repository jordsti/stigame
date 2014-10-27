#include "ControllerButtonEventArgs.h"

namespace StiGame
{

ControllerButtonEventArgs::ControllerButtonEventArgs() : EventArgs() {}
ControllerButtonEventArgs::ControllerButtonEventArgs(SDL_Event *m_sdlEvent) : EventArgs(m_sdlEvent) {}
ControllerButtonEventArgs::~ControllerButtonEventArgs() {}

Uint32 ControllerButtonEventArgs::getTimestamp(void)
{
	return sdlEvent->cbutton.timestamp;
}

SDL_JoystickID ControllerButtonEventArgs::getJoystickId(void)
{
	return sdlEvent->cbutton.which;
}

bool ControllerButtonEventArgs::isDown(void)
{
	return (sdlEvent->cbutton.type == SDL_CONTROLLERBUTTONDOWN);
}

SDL_GameControllerButton ControllerButtonEventArgs::getButton(void)
{
	return static_cast<SDL_GameControllerButton>(sdlEvent->cbutton.button);
}

Uint8 ControllerButtonEventArgs::getState(void)
{
	return sdlEvent->cbutton.state;
}

SDL_ControllerButtonEvent* ControllerButtonEventArgs::getButtonEvent(void)
{
	return &(sdlEvent->cbutton);
}

}