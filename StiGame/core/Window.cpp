#include "Window.h"

namespace StiGame
{

Window::Window()
{
	sdlWindow = 0;
}

Window::Window(SDL_Window *m_sdlWindow)
{
	sdlWindow = m_sdlWindow;
}

Window::~Window()
{
	
}

void Window::setBordered(bool m_border)
{
	SDL_SetWindowBordered(sdlWindow, GetSDLBool(m_border));
}

void Window::setBrightness(float brightness)
{
	SDL_SetWindowBrightness(sdlWindow, brightness);
}

float Window::getBrightness(void)
{
	return SDL_GetWindowBrightness(sdlWindow);
}

void Window::setDisplayMode(const SDL_DisplayMode *mode)
{
	SDL_SetWindowDisplayMode(sdlWindow, mode);
}

void Window::getDisplayMode(SDL_DisplayMode *mode)
{
	SDL_GetWindowDisplayMode(sdlWindow, mode);
}

void Window::setGrab(bool grabbed)
{
	SDL_SetWindowGrab(sdlWindow, GetSDLBool(grabbed));
}

bool Window::getGrab(void)
{
	return FromSDLBool(SDL_GetWindowGrab(sdlWindow));
}

void Window::setIcon(SDL_Surface *icon)
{
	SDL_SetWindowIcon(sdlWindow, icon);
}

void Window::setIcon(Surface *icon)
{
	SDL_SetWindowIcon(sdlWindow, icon->getSDLSurface());
}

void Window::setMaximumSize(int max_width, int max_height)
{
	SDL_SetWindowMaximumSize(sdlWindow, max_width, max_height);
}

Dimension* Window::getMaximumSize(void)
{
	MDimension *dim = new MDimension();
	
	int w,h;
	
	SDL_GetWindowMaximumSize(sdlWindow, &w, &h);
	dim->setWidth(w);
	dim->setHeight(h);
	
	return dim;
}

void Window::setMinimumSize(int min_width, int min_height)
{
	SDL_SetWindowMinimumSize(sdlWindow, min_width, min_height);
}

Dimension* Window::getMinimumSize(void)
{
	MDimension *dim = new MDimension();
	
	int w,h;
	
	SDL_GetWindowMinimumSize(sdlWindow, &w, &h);
	dim->setWidth(w);
	dim->setHeight(h);
	
	return dim;
}


void Window::setPosition(int x, int y)
{
	SDL_SetWindowPosition(sdlWindow, x, y);
}

Point* Window::getPosition(void)
{
	MPoint *pt = new MPoint();
	int x,y;
	
	SDL_GetWindowPosition(sdlWindow, &x, &y);
	
	pt->setX(x);
	pt->setY(y);
	
	return pt;
}

void Window::setSize(int width, int height)
{
	SDL_SetWindowSize(sdlWindow, width, height);
}

Dimension* Window::getSize(void)
{
	MDimension *dim = new MDimension();
	
	int w,h;
	
	SDL_GetWindowSize(sdlWindow, &w, &h);
	
	dim->setWidth(w);
	dim->setHeight(h);
	
	return dim;
}

void Window::setTitle(const char* title)
{
	SDL_SetWindowTitle(sdlWindow, title);
}

const char* Window::getTitle(void)
{
	return SDL_GetWindowTitle(sdlWindow);
}


Uint32 Window::getId(void)
{
	return SDL_GetWindowID(sdlWindow);
}

SDL_Window* Window::getSDLWindow(void)
{
	return sdlWindow;
}

void Window::maximize(void)
{
	SDL_MaximizeWindow(sdlWindow);
}

void Window::minimize(void)
{
	SDL_MinimizeWindow(sdlWindow);
}

void Window::restore(void)
{
	SDL_RestoreWindow(sdlWindow);
}

void Window::hide(void)
{
	SDL_HideWindow(sdlWindow);
}

bool Window::FromSDLBool(SDL_bool sdl_bool)
{
	return (sdl_bool == SDL_TRUE);
}

SDL_bool Window::GetSDLBool(bool cond)
{
	if(cond)
	{
		return SDL_TRUE;
	}
	else
	{
		return SDL_FALSE;
	}
}



}