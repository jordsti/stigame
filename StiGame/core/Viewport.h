#pragma once
#include "SDL.h"
#include <string>
#include "BaseGameState.h"
#include "Dimension.h"
#include "Cursor.h"
#include "WindowEventThrower.h"
#include "Window.h"

namespace StiGame
{

enum OperatingSystem { OS_Win32, OS_Linux };

/// \class Viewport
/// \brief Engine Screen Viewport, handling the screen output
class Viewport :
	public WindowEventThrower
{
private:
	/// \brief List availabe video resolution
    void listDimensions(void);

    static bool _sdlInitied;

protected:
    std::list<BaseGameState*> oldStates;

    static void initSDL(void);

	/// \brief Window title
    const char* title;

	/// \brief milliseconds before the next tick
	unsigned int msWaitTime;
	/// \brief last tick time
	unsigned long long lastTick;
	/// \brief fullscreen or windowed
	bool fullscreen;
	/// \brief window can be resized
	bool resizable;
	/// \brief center the window
	bool centered;
	/// brief Window X position
    int window_x;
	/// brief Window Y position
    int window_y;

	/// \brief width (px)
	int width;
	/// \brief height (px)
	int height;
	/// \brief targeted fps
	int target_fps;

    int current_fps;

	int msTreshold;

	/// \brief is running
	bool run;
	/// \brief initilization
	void initialize(void);
	/// \brief SDL_Window Structure
	SDL_Window *sdlWindow;
	Window *window;

	/// \brief SDL_Renderer
	SDL_Renderer *renderer;
	/// \brief SDL_Surface pointer to the screen surface
	SDL_Surface *screen;
	/// \brief Current state running
	BaseGameState *currentState;

    BaseGameState *pendingState;
    bool stateWaiting;

	/// \brief SDL Error
	std::string error;
	/// \brief SDL Video Flags
	Uint32 videoFlags;
	/// \brief Tick method
	void tick(void);
	/// \brief Viewport resize method
	/// \param m_width new width (px)
	/// \param m_height new height (px)
	void resize(int m_width,int m_height);
	/// \brief Supported video resolution
	std::list<Dimension*> modes;
	/// \brief Is the video resolution is supported
	/// \param dimension Video Resolution
	bool isModePresent(Dimension *dimension);
	/// \brief Handle window event
	/// \param evt SDL_WindowEvent
	void handleWindowEvent(SDL_Event *evt);

    Cursor* cursor;
public:
    const int DEFAULT_MS_TRESHOLD = 4;

    //static method
    static std::list<Dimension> GetSupportedResolution(void);
    static Dimension GetHighestResolution(void);

	/// \brief Create a new viewport
	Viewport(void);
	/// \brief Create a new viewport with the specified size
	/// \param m_width width (px)
	/// \param m_height height (px)
	Viewport(int m_width,int m_height);
	/// \brief Create a new viewport with the specified size
	/// \param m_width width (px)
	/// \param m_height height (px)
	/// \param m_fullscreen fullscreen or window
	Viewport(int m_width,int m_height,bool m_fullscreen);
	/// \brief Destructor
	~Viewport(void);
	/// \brief Get fullscreen value
	/// \return fullscreen or window
	bool isFullscreen(void);
	/// \brief Get the highest video mode available
	/// \return SDL_Rect pointer
	SDL_Rect* getHighestMode(void);
	/// \brief Get the lowest video mode available
	/// \return SDL_Rect pointer
	SDL_Rect* getLowestMode(void);

	/// \brief Get target fps
	/// \return fps
	int getFps(void);
	/// \brief Set target fps
	/// \param m_targetFps Target FPS
	void setFps(int m_targetFps);
	/// \brief Push a GameState to the viewport
	/// \param state State to be pushed
	void push(BaseGameState *state);
	/// \brief Start the viewport mainloop
	void startLoop(void);
	/// \brief Get resizable value
	/// \return resizable or not
	bool getResizable(void);
	/// \brief Set the resizable value
	/// \param m_resizable resizable or not
	void setResizable(bool m_resizable);

	/// \brief Set the window title
	/// \param m_title Window title
    void setTitle(const char* m_title);
	/// \brief Get the current window title
	/// \return Window title
    const char* getTitle(void);
	/// \brief Get viewport height
	/// \return Viewport height
	int getHeight(void);
	/// \brief Get viewport width
	/// \return Viewport width
	int getWidth(void);
	/// \brief Get current window x position
	/// \return Window X
	int getWindowX(void);
	/// \brief Get current window y position
	/// \return Window Y
	int getWindowY(void);
	/// \brief Set window position
	/// \param m_window_x New window x position
	/// \param m_window_y New window y position
	void setWindowPosition(int m_window_x, int m_window_y);
	/// \brief Update the current window position
	void updateWindowPosition(void);
	/// \brief Set window grab input
	/// \param grab Grab or not
	void setGrab(bool grab);

	bool isGrabbed(void);

    void clearPreviousStates(void);

	/// \brief Get SDL_Window pointer
	/// \return SDL_Window pointer
	SDL_Window* getSDLWindow(void);
	/// \brief Get SDL_Renderer pointer
	/// \return SDL_Renderer pointer
	SDL_Renderer* getRenderer(void);

	void hide(void);
	void show(void);

	void minimize(void);
	void maximize(void);
	void restore(void);

    Cursor* getCursor(void);
    void setCursor(Cursor *m_cursor);
    void showCursor(bool m_show);

	Window* getWindow(void);

	static OperatingSystem GetCurrentOS();
};

}

