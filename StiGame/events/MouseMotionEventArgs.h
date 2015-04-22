#ifndef MOUSEMOTIONEVENTARGS_H
#define MOUSEMOTIONEVENTARGS_H

#include "EventArgs.h"


namespace StiGame
{
/// \class MouseMotionEventArgs
/// \brief Mouse Motion Event
class MouseMotionEventArgs
	: public EventArgs
{
public:
    /// \brief Empty Constructor
	MouseMotionEventArgs();
    /// \brief Create a new Mouse Motion event with the underlying SDL Mouse Motion Event
    /// \param m_sdlEvent Underlying Mouse Motion Event
	MouseMotionEventArgs(SDL_Event *m_sdlEvent);
    /// \brief Destructor
	virtual ~MouseMotionEventArgs();
    /// \brief Timestamp of the event
    /// /return Unix Timestamp
	Uint32 getTimestamp(void);
    /// \brief Window ID of this event
    /// \return SDL Window ID
	Uint32 getWindowId(void);
    /// \brief Which
    /// \return which id
	Uint32 getWhich(void);
    /// \brief State of the event
    /// \return State ID
	Uint32 getState(void);
    /// \brief Mouse X Position
    /// \return X (px)
	Sint32 getX(void);
    /// \brief Mouse Y Position
    /// \return Y (px)
	Sint32 getY(void);
    /// \brief Get Relative X Position
    /// \return relative X (px)
    Sint32 getRelX(void);
    /// \brief Get Relative Y Position
    /// \return relative Y (px)
	Sint32 getRelY(void);
    /// \brief Get the underlying SDL Mouse Motion Event
    /// \return Underlying event
	SDL_MouseMotionEvent* getMotionEvent(void);
};

}

#endif
