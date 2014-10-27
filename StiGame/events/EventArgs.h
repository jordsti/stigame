#ifndef EVENTARGS_H
#define EVENTARGS_H
#include "SDL.h"
namespace StiGame
{
/// \class SEventArgs
/// \brief Basic Event wrapper
class EventArgs
{
public:
	/// \brief Create an empty event
	EventArgs(void);
	/// \brief Create an event
	/// \param m_sdlEvent SDL_Event
	EventArgs(SDL_Event *m_sdlEvent);
	/// \brief SEventArgs destructor
	virtual ~EventArgs(void);
	/// \brief Get SDL_Event
	/// \return SDL_Event pointer
	SDL_Event *getSDLEvent(void);
protected:
	/// \brief SDL_Event
	SDL_Event *sdlEvent;
};

}

#endif