#ifndef WINDOW_H
#define WINDOW_H

#include "Surface.h"

namespace StiGame
{

class Window
{
public:
	Window();
	Window(SDL_Window *m_sdlWindow);
	virtual ~Window();
	
	void setBordered(bool m_border);

	void setBrightness(float brightness);
	float getBrightness(void);
	
	void setDisplayMode(const SDL_DisplayMode *mode);
	void getDisplayMode(SDL_DisplayMode *mode);
	
	void setGrab(bool grabbed);
	bool getGrab(void);
	
	void setIcon(SDL_Surface *icon);
	void setIcon(Surface *icon);
	
	void setMaximumSize(int max_width, int max_height);
	Dimension* getMaximumSize(void);
	
	void setMinimumSize(int min_width, int min_height);
	Dimension* getMinimumSize(void);
	
	void setPosition(int x, int y);
	Point* getPosition(void);
	
	void setSize(int width, int height);
	Dimension* getSize(void);
	
	void setTitle(const char* title);
	const char* getTitle(void);
	
	
	Uint32 getId(void);
	
	SDL_Window* getSDLWindow(void);
	
	void maximize(void);
	void minimize(void);
	void restore(void);
	void hide(void);
	
protected:
	static bool FromSDLBool(SDL_bool sdl_bool);
	static SDL_bool GetSDLBool(bool cond);

	SDL_Window *sdlWindow;
};

}

#endif