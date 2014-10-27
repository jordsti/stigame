#include "WindowEventArgs.h"

namespace StiGame
{

WindowEventArgs::WindowEventArgs() : EventArgs() {}
WindowEventArgs::WindowEventArgs(SDL_Event *m_sdlEvent) : EventArgs(m_sdlEvent) {}
WindowEventArgs::~WindowEventArgs() {}
	
Uint32 WindowEventArgs::getWindowId(void)
{
	return sdlEvent->window.windowID;
}

Uint32 WindowEventArgs::getTimestamp(void)
{
	return sdlEvent->window.timestamp;
}
	
SDL_WindowEvent* WindowEventArgs::getWindowEvent(void)
{
	return &(sdlEvent->window);
}

WindowEventType WindowEventArgs::getType(void)
{
	return static_cast<WindowEventType>(sdlEvent->window.type);
}
	
Sint32 WindowEventArgs::getData1(void)
{
	return sdlEvent->window.data1;
}

Sint32 WindowEventArgs::getData2(void)
{
	return sdlEvent->window.data2;
}

}