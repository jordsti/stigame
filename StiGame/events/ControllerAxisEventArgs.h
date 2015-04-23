#ifndef CONTROLLERAXISEVENTARGS_H
#define CONTROLLERAXISEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{
/// \class ControllerAxisEventArgs
/// \brief Controller Axis Event
class ControllerAxisEventArgs
	: public EventArgs
{
public:
    /// \brief Empty Constructor
	ControllerAxisEventArgs();
    /// \brief Create a new Controller Axis Event with the SDL underlying event
    /// \param m_sdlEvent Underlying SDL Event
	ControllerAxisEventArgs(SDL_Event *m_sdlEvent);
    /// \brief Destructor
	virtual ~ControllerAxisEventArgs();
    /// \brief Get event timestamp
    /// \return Unix timestamp
	Uint32 getTimestamp(void);
    /// \brief Get the Joystick ID
    /// \return SDL Joystick ID
	SDL_JoystickID getJoystickId(void);
    /// \brief Get the axis Id
    /// \return SDL Game Controller Axis Id
	SDL_GameControllerAxis getAxis(void);
    /// \brief Get the value
    /// \return Get the axis value
	Sint16 getValue(void);
    /// \brief Get the underlying SDL Controller Axis Event
    /// \return Underlying SDL Event
	SDL_ControllerAxisEvent* getAxisEvent(void);
};

}

#endif
