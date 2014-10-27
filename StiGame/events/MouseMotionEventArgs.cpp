#include "MouseMotionEventArgs.h"

namespace StiGame
{

MouseMotionEventArgs::MouseMotionEventArgs() 
	: EventArgs()
{

}

MouseMotionEventArgs::MouseMotionEventArgs(SDL_Event *m_sdlEvent)
	: EventArgs(m_sdlEvent)
{

}

MouseMotionEventArgs::~MouseMotionEventArgs()
{

}

Uint32 MouseMotionEventArgs::getTimestamp(void)
{
	return sdlEvent->motion.timestamp;
}

Uint32 MouseMotionEventArgs::getWindowId(void)
{
	return sdlEvent->motion.windowID;
}

Uint32 MouseMotionEventArgs::getWhich(void)
{
	return sdlEvent->motion.which;
}

Uint32 MouseMotionEventArgs::getState(void)
{
	return sdlEvent->motion.state;
}

Sint32 MouseMotionEventArgs::getX(void)
{
	return sdlEvent->motion.x;
}

Sint32 MouseMotionEventArgs::getY(void)
{
	return sdlEvent->motion.y;
}

Sint32 MouseMotionEventArgs::getRelX(void)
{
	return sdlEvent->motion.xrel;
}

Sint32 MouseMotionEventArgs::getRelY(void)
{
	return sdlEvent->motion.yrel;
}

SDL_MouseMotionEvent* MouseMotionEventArgs::getMotionEvent(void)
{
	return &(sdlEvent->motion);
}


}