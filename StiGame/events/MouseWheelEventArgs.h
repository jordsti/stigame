#ifndef MOUSEWHEELEVENTARGS_H
#define MOUSEWHEELEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum WheelDirection {
	WD_NONE = 0,
	WD_UP = 1,
	WD_DOWN = 2,
	WD_LEFT = 4,
	WD_RIGHT = 8,
	//multi-direction
	WD_UP_LEFT = WD_UP + WD_LEFT,
	WD_UP_RIGHT = WD_UP + WD_RIGHT,
	WD_DOWN_LEFT = WD_DOWN + WD_LEFT,
	WD_DOWN_RIGHT = WD_DOWN + WD_RIGHT
};

/// \class MouseWheelEventArgs
/// \brief Mouse Wheel Event
class MouseWheelEventArgs
	: public EventArgs
{
public:
    /// \brief Empty Constructor
	MouseWheelEventArgs();
    /// \brief Create a new Mouse Wheel Event with the underlying SDL Event
    /// \param m_sdlEvent Underlying SDL Event
	MouseWheelEventArgs(SDL_Event *m_sdlEvent);
    /// \brief Destructor
	virtual ~MouseWheelEventArgs();
    /// \brief Get event timestamp
    /// \return Unix timestamp
	Uint32 getTimestamp(void);
    /// \brief Get Window Id
    /// \return SDL Window Id
	Uint32 getWindowId(void);
    /// \brief Get Which
    /// \return Which ID
	Uint32 getWhich(void);
    /// \brief Get Mouse X
    /// \return X (px)
	Sint32 getX(void);
    /// \brief Get Mouse Y
    /// \return Y (px)
	Sint32 getY(void);
    /// \brief Get Wheel Direction
    /// \return Wheel Direction
	WheelDirection getDirection(void);
    /// \brief Get the underlying Wheel Event
    /// \return Underlying Mouse Wheel Event
	SDL_MouseWheelEvent* getWheelEvent(void);
};


}

#endif
