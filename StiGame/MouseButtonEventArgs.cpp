#include "MouseButtonEventArgs.h"
namespace StiGame
{

MouseButtonEventArgs::MouseButtonEventArgs()
    : EventArgs()
{
    //ctor
}

MouseButtonEventArgs::MouseButtonEventArgs(SDL_Event *m_sdlEvent)
    : EventArgs(m_sdlEvent)
{

}

Uint8 MouseButtonEventArgs::GetSDLButton(MouseButton mbutton)
{
	if(mbutton == MB_LEFT)
	{
		return SDL_BUTTON_LEFT;
	}
	else if(mbutton == MB_MIDDLE)
	{
		return SDL_BUTTON_MIDDLE;
	}
	else if(mbutton == MB_RIGHT)
	{
		return SDL_BUTTON_RIGHT;
	}
	else if(mbutton == MB_X1)
	{
		return SDL_BUTTON_X1;
	}
	else if(mbutton == MB_X2)
	{
		return SDL_BUTTON_X2;
	}
	
	return SDL_BUTTON_LEFT;
}

MouseButton MouseButtonEventArgs::GetMouseButtonFromSDL(Uint8 mbutton)
{
	if(mbutton == SDL_BUTTON_LEFT)
	{
		return MB_LEFT;
	}
	else if(mbutton == SDL_BUTTON_MIDDLE)
	{
		return MB_MIDDLE;
	}
	else if(mbutton == SDL_BUTTON_RIGHT)
	{
		return MB_RIGHT;
	}
	else if(mbutton == SDL_BUTTON_X1)
	{
		return MB_X1;
	}
	else if(mbutton == SDL_BUTTON_X2)
	{
		return MB_X2;
	}
	
	return MB_LEFT;
}

Sint32 MouseButtonEventArgs::getX(void)
{
    return sdlEvent->button.x;
}

Sint32 MouseButtonEventArgs::getY(void)
{
    return sdlEvent->button.y;
}

Uint8 MouseButtonEventArgs::getButton(void)
{
    return sdlEvent->button.button;
}

MouseButton MouseButtonEventArgs::getMouseButton(void)
{
	Uint8 button = sdlEvent->button.button;
	
	if(button == SDL_BUTTON_LEFT)
	{
		return MB_LEFT;
	}
	else if(button == SDL_BUTTON_MIDDLE)
	{
		return MB_MIDDLE;
	}
	else if(button == SDL_BUTTON_RIGHT)
	{
		return MB_RIGHT;
	}
	else if(button == SDL_BUTTON_X1)
	{
		return MB_X1;
	}
	else if(button == SDL_BUTTON_X2)
	{
		return MB_X2;
	}
	
	return MB_LEFT;
}

Uint32 MouseButtonEventArgs::getWindowID(void)
{
    return sdlEvent->button.windowID;
}

bool MouseButtonEventArgs::isDown(void)
{
    return (sdlEvent->button.state == SDL_PRESSED);
}

MouseButtonEventArgs::~MouseButtonEventArgs()
{
    //dtor
}

}
