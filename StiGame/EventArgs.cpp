
#include "EventArgs.h"

namespace StiGame
{

EventArgs::EventArgs(void)
{
	sdlEvent = 0;
}

EventArgs::EventArgs(SDL_Event *m_sdlEvent)
{
	sdlEvent = m_sdlEvent;
}

SDL_Event *EventArgs::getSDLEvent(void)
{
	return sdlEvent;
}

EventArgs::~EventArgs(void)
{
}

}
