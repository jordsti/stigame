
#include "Viewport.h"
#include "Runtime.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Sprite.h"
#include <iostream>
#include <string>
#include <ctime>
#include "TimeTools.h"
#include "SDL_net.h"

namespace StiGame
{

bool Viewport::_sdlInitied = false;

void Viewport::initSDL(void)
{
    if(!_sdlInitied)
    {

        SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
        TTF_Init();
        SDLNet_Init();

        _sdlInitied = true;
    }

}

std::list<Dimension> Viewport::GetSupportedResolution(void)
{
    initSDL();
    std::list<Dimension> dimensions;
    int nb = SDL_GetNumDisplayModes(0);

    for(int i=0; i<nb; i++)
    {
        SDL_DisplayMode mode = SDL_DisplayMode();
        SDL_GetDisplayMode(0, i, &mode);

        Dimension dim (mode.w, mode.h);

        dimensions.push_back(dim);
    }

    return dimensions;

}

Dimension Viewport::GetHighestResolution(void)
{
    std::list<Dimension> dimensions = GetSupportedResolution();
    std::list<Dimension>::iterator lit(dimensions.begin()), lend(dimensions.end());

    int mw = 0;
    int mh = 0;

    if((*lit).getWidth() >= mw || (*lit).getHeight() >= mh)
    {
        mw = (*lit).getWidth();
        mh = (*lit).getHeight();
    }

    return Dimension (mw, mh);
}

Viewport::Viewport(void)
{
    msTreshold = DEFAULT_MS_TRESHOLD;
    centered = true;
	error = "";
	msWaitTime = 0;
	screen = 0;
	window = 0;
	sdlWindow = 0;
	width = 640;
	height = 480;
	fullscreen = false;
	title = "StiGame::Viewport";
	initialize();
}

Viewport::Viewport(int v_width, int v_height)
{
    msTreshold = DEFAULT_MS_TRESHOLD;
    centered = true;
	resizable = true;
	error = "";
	msWaitTime = 0;
	screen = 0;
	window = 0;
	sdlWindow = 0;
	width = v_width;
	height = v_height;
	fullscreen = false;
	title = "StiGame::Viewport";
	initialize();
}


Viewport::Viewport(int v_width, int v_height, bool v_fullscreen)
{
    msTreshold = DEFAULT_MS_TRESHOLD;
    centered = true;
	resizable = true;
	error = "";
	msWaitTime = 0;
	screen = 0;
	sdlWindow = 0;
	window = 0;
	width = v_width;
	height = v_height;
	fullscreen = v_fullscreen;
	title = "StiGame::Viewport";
	initialize();
}

bool Viewport::getResizable(void)
{
	return resizable;
}

void Viewport::setResizable(bool m_resizable)
{
	resizable = m_resizable;
}

void Viewport::resize(int m_width, int m_height)
{
	if(resizable && !fullscreen)
	{
		width = m_width;
		height = m_height;

        //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        //SDL_RenderSetLogicalSize(renderer, width, height);
        /** \brief
         *
         * \param width
         * \param height
         * \param 32
         * \param videoFlags
         * \return screen=
         *
         */
		//screen = SDL_SetVideoMode(width, height, 32, videoFlags);
        //area.setViewDimension(width, height);
		if(currentState != 0)
		{
			currentState->onResize(width, height);
		}
	}
}

void Viewport::handleWindowEvent(SDL_Event *evt)
{
    switch(evt->window.event)
    {
        case SDL_WINDOWEVENT_RESIZED:
            resize(evt->window.data1, evt->window.data2);
            break;
        case SDL_WINDOWEVENT_MOVED:
            updateWindowPosition();
            break;
    }

	WindowEventArgs wargs = WindowEventArgs(evt);
	publish(this, &wargs);

}

void Viewport::tick(void)
{
	//checking event
    Sprite::tickSprites();

	SDL_Event evt;

	while(SDL_PollEvent(&evt))
	{
        if(currentState->isRunning())
        {
            switch(evt.type)
            {
                //temporary need to let the state choose
                case SDL_QUIT:

                    if(currentState->isHandleQuit())
                    {
                        currentState->onEvent(&evt);
                    }
                    else
                    {
                        run = false;
                    }

                    break;
                case SDL_WINDOWEVENT:
                    handleWindowEvent(&evt);
                    break;

                default:
                    currentState->onEvent(&evt);
                    break;
            }
        }
	}

	if(!currentState->isRunning())
	{
		run = false;
	}
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

    //long long stamp = Time::GetMsTimestamp();
	currentState->onPaint(renderer);

    //std::cout << "paint time : " << Time::GetMsTimestamp() - stamp << std::endl;

	SDL_RenderPresent(renderer);
	//int rs = SDL_Flip(screen);
}

void Viewport::startLoop(void)
{
	if(currentState != 0)
	{
		run = true;
		while(run)
		{
			//starting tick
            if(lastTick == 0)
            {
                lastTick = Time::GetMsTimestamp();
                tick();
            }
            else
            {
                long long diff = Time::GetMsTimestamp() - lastTick;

                if(diff >= msWaitTime)
                {
                    long long over = diff - msWaitTime;

                    if(over > 0 && over > msTreshold)
                    {
                        std::cout << "missed frame by " << over << "ms !" << std::endl;
                        std::cout << "Treshold : " << msTreshold << "ms" << std::endl;
                    }
                    tick();
                    lastTick = Time::GetMsTimestamp();
                }
                if(diff > 0)
                {
                    current_fps = 1000 / diff;
                }
            }

			//ending time
			//SDL_Delay(diff);
            /*int delay = diff - 10;
            if(delay < 0)
                delay = 1;

            SDL_Delay(delay);*/

            //pending state verification

            if(stateWaiting)
            {
                currentState->unload();
                oldStates.push_back(currentState);

                currentState = pendingState;

                currentState->setViewport(this);
                currentState->onResize(width, height);
                currentState->onStart();

                stateWaiting = false;
                pendingState = nullptr;

            }
        }

		//quitting, unloading
        if(currentState != nullptr)
        {
            currentState->unload();
        }
		//quick hack
		Gui::Runtime::getInstance()->getStyle()->unload();
	}
}

void Viewport::push(BaseGameState* state)
{
    /*
     * Refactoring this method
     * Problems :
     *        - The state is unloaded while this method is called in this state
     *          SEGFAULT error are generated because of this
     * Solution :
     *        1 - Put the new state into pending mode
     *        2 - Finish the current state rendering
     *        3 - After the rendering, unload the last state and push the new one
     */
    if(state != nullptr)
	{
        if(currentState != nullptr)
        {
            //currentState->unload();
            /*Gui::OverlayMenu *omenu = currentState->getGameMenu();
            if(omenu != nullptr)
            {
                delete omenu;
            }*/
            //oldStates.push_back(currentState);

            pendingState = state;
            stateWaiting = true;
        }
        else
        {
            //first state pushed
            currentState = state;
            currentState->setViewport((Viewport*)this);
            currentState->onResize(width, height);
            currentState->onStart();

        }
	}
}

void Viewport::clearPreviousStates(void)
{
    auto lit(oldStates.begin()), lend(oldStates.end());

    for(;lit!=lend;++lit)
    {
        delete (*lit);
        //todo debug output
        std::cout << "Deleting state.." << std::endl;

    }

    oldStates.clear();
}

SDL_Rect* Viewport::getLowestMode(void)
{
	SDL_Rect* rect = new SDL_Rect();
	rect->h = 1080;
	rect->w = 1920;

	std::list<Dimension*>::iterator lit (modes.begin()), lend(modes.end());

	for(;lit!=lend;++lit)
	{
        if((*lit)->getHeight() < rect->h && (*lit)->getWidth() < rect->w)
        {
            rect->h = (*lit)->getHeight();
            rect->w = (*lit)->getWidth();
        }
	}

	return rect;
}

SDL_Rect* Viewport::getHighestMode(void)
{
	SDL_Rect* rect = new SDL_Rect();
	rect->h = 0;
	rect->w = 0;

	std::list<Dimension*>::iterator lit (modes.begin()), lend(modes.end());

	for(;lit!=lend;++lit)
	{
        if((*lit)->getHeight() > rect->h && (*lit)->getWidth() > rect->w)
        {
            rect->h = (*lit)->getHeight();
            rect->w = (*lit)->getWidth();
        }
	}

	return rect;
}

void Viewport::setFps(int fps)
{
	target_fps = fps;
	msWaitTime = 1000 / fps;
}

int Viewport::getFps(void)
{
    return current_fps;
}

void Viewport::initialize(void)
{
    window_x = SDL_WINDOWPOS_UNDEFINED;
    window_y = SDL_WINDOWPOS_UNDEFINED;

    //area = ViewportArea();

	lastTick = 0;
	run = false;
    currentState = nullptr;
    pendingState = nullptr;
    stateWaiting = false;

    initSDL();


	listDimensions();

	SDL_Rect* hsize = getHighestMode();

	if(hsize->w < width || hsize->h < height)
	{
		width = hsize->w;
		height = hsize->h;
		std::cout << "Overriding resolution to " << width << "x" << height;
	}

    videoFlags = 0;

	if(fullscreen)
	{
		resizable = false;
		videoFlags =  videoFlags | SDL_WINDOW_FULLSCREEN;
	}
	else if(resizable)
	{
		videoFlags =  videoFlags | SDL_WINDOW_RESIZABLE;
	}

    if(centered)
    {
        window_x = SDL_WINDOWPOS_CENTERED;
        window_y = SDL_WINDOWPOS_CENTERED;
    }

	sdlWindow = SDL_CreateWindow(title, window_x, window_y, width, height, videoFlags);
	window = new Window(sdlWindow);
    renderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
    cursor = new Cursor();
    SDL_SetWindowTitle(sdlWindow, title);

    updateWindowPosition();

    //area.setViewPoint(0,0);
    //area.setViewDimension(width, height);

    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderSetLogicalSize(renderer, width, height);

	error = SDL_GetError();
}

Cursor* Viewport::getCursor(void)
{
    return cursor;
}

void Viewport::showCursor(bool m_show)
{
    Cursor::Show(m_show);
}

void Viewport::setCursor(Cursor *m_cursor)
{
    if(!cursor->isDefault())
    {
        delete cursor;
    }

    cursor = m_cursor;
    SDL_SetCursor(cursor->getSDLCursor());
}

bool Viewport::isFullscreen(void)
{
	return fullscreen;
}


Viewport::~Viewport(void)
{
    if(sdlWindow != 0)
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(sdlWindow);
    }
}

int Viewport::getHeight(void)
{
    return height;
}
int Viewport::getWidth(void)
{
    return width;
}

void Viewport::setTitle(const char* m_title)
{
    title = m_title;
    if(sdlWindow != 0)
    {
        SDL_SetWindowTitle(sdlWindow, title);
    }
}

const char* Viewport::getTitle(void)
{
    return title;
}

void Viewport::listDimensions()
{
    //need to do some work here, multi-display mmokay
    int nb = SDL_GetNumDisplayModes(0);

    for(int i=0; i<nb; i++)
    {
        SDL_DisplayMode mode = SDL_DisplayMode();
        SDL_GetDisplayMode(0, i, &mode);

        Dimension *dim = new Dimension(mode.w, mode.h);

        if(!isModePresent(dim))
        {
            modes.push_back(dim);
        }
        else
        {
            delete dim;
        }
    }
}

bool Viewport::isModePresent(Dimension *dimension)
{
    std::list<Dimension*>::iterator lit(modes.begin()), lend(modes.end());

    for(;lit!=lend;++lit)
    {
        if((*lit)->getHeight() == dimension->getHeight() &&
           (*lit)->getWidth() == dimension->getWidth() )
        {
            return true;
        }
    }

    return false;
}

int Viewport::getWindowX(void)
{
    return window_x;
}

int Viewport::getWindowY(void)
{
    return window_y;
}

void Viewport::setWindowPosition(int m_window_x, int m_window_y)
{
    window_x = m_window_x;
    window_y = m_window_y;

    SDL_SetWindowPosition(sdlWindow, window_x, window_y);
}

void Viewport::updateWindowPosition(void)
{
    int m_window_x, m_window_y;

    SDL_GetWindowPosition(sdlWindow, &m_window_x, &m_window_y);

    window_x = m_window_x;
    window_y = m_window_y;
}

void Viewport::setGrab(bool grab)
{
    if(grab)
    {
        SDL_SetWindowGrab(sdlWindow, SDL_TRUE);
    }
    else
    {
        SDL_SetWindowGrab(sdlWindow, SDL_FALSE);
    }
}

bool Viewport::isGrabbed(void)
{
	SDL_bool grabbed = SDL_GetWindowGrab(sdlWindow);

	return (grabbed == SDL_TRUE);
}

SDL_Window* Viewport::getSDLWindow(void)
{
    return sdlWindow;
}

Window* Viewport::getWindow(void)
{
	return window;
}

SDL_Renderer* Viewport::getRenderer(void)
{
    return renderer;
}

void Viewport::show(void)
{
	if(sdlWindow != 0)
	{
		SDL_ShowWindow(sdlWindow);
	}
}

void Viewport::hide(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_HideWindow(sdlWindow);
	}*/
	window->hide();
}

void Viewport::restore(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_RestoreWindow(sdlWindow);
	}*/
	window->restore();
}

void Viewport::minimize(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_MinimizeWindow(sdlWindow);
	}*/
	window->minimize();
}

void Viewport::maximize(void)
{
	/*if(sdlWindow != 0)
	{
		SDL_MaximizeWindow(sdlWindow);
	}*/
	window->maximize();
}


OperatingSystem Viewport::GetCurrentOS()
{
    #ifdef OS_WIN32
    return OS_Win32;
    #endif // OS_WIN32

    #ifdef OS_LINUX
    return OS_Linux;
    #endif // OS_LINUX
}

}


#ifdef C_WRAPPER

extern "C" {
    void init_sdl()
    {
        SDL_Init(SDL_INIT_VIDEO);
    }
}

#endif // C_WRAPPER
