#ifndef WINDOWEVENTARGS_H
#define WINDOWEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum WindowEventType {
	WET_SHOWN = SDL_WINDOWEVENT_SHOWN,
	WET_HIDDEN = SDL_WINDOWEVENT_HIDDEN,
	WET_EXPOSED = SDL_WINDOWEVENT_EXPOSED,
	WET_MOVED = SDL_WINDOWEVENT_MOVED,
	WET_RESIZED = SDL_WINDOWEVENT_RESIZED,
	WET_RESTORED = SDL_WINDOWEVENT_RESTORED,
	WET_ENTER = SDL_WINDOWEVENT_ENTER,
	WET_LEAVE = SDL_WINDOWEVENT_LEAVE,
	WET_FOCUS_GAINED = SDL_WINDOWEVENT_FOCUS_GAINED,
	WET_FOCUS_LOST = SDL_WINDOWEVENT_FOCUS_LOST,
	WET_CLOSE = SDL_WINDOWEVENT_CLOSE
};

/// \class WindowEventArgs
/// \brief Window Event
class WindowEventArgs :
	public EventArgs
{
public:
    /// \brief Empty Constructor
	WindowEventArgs();
    /// \brief Create a new Window Event with the underlying SDL Event
    /// \param m_sdlEvent SDL Window Event
	WindowEventArgs(SDL_Event *m_sdlEvent);
    /// \brief Destructor
	virtual ~WindowEventArgs();
    /// \brief Affected Window ID
    /// \return SDL Window ID
	Uint32 getWindowId(void);
    /// \brief Timestamp of the event
    /// \return Unix Timestamp when the event was thrown
	Uint32 getTimestamp(void);
    /// \brief Get the underlying SDL Window Event
    /// \return SDL Window Event
	SDL_WindowEvent* getWindowEvent(void);
    /// \brief Get Window Event Type
    /// \return Event Type
	WindowEventType getType(void);
    /// \brief Get the value of the first field
    /// \return Signed 32 bit integer
	Sint32 getData1(void);
    /// \brief Get the value of the second field
    /// \return Signed 32 bit integer
	Sint32 getData2(void);
};

}

#endif
