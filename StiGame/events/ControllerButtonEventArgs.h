#ifndef CONTROLLERBUTTONEVENTARGS_H
#define CONTROLLERBUTTONEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{
/// \class ControllerButtonEventArgs
/// \brief Controller Button Event
class ControllerButtonEventArgs
	: public EventArgs
{
public:
    /// \brief Empty Constructor
	ControllerButtonEventArgs();
    /// \brief Create a new Controller Button Event with an underlying SDL Controller Button Event
    /// \param m_sdlEvent Underlying SDL Event
	ControllerButtonEventArgs(SDL_Event *m_sdlEvent);
    /// \brief Destructor
	virtual ~ControllerButtonEventArgs();
    /// \brief Timestamp of the Event
    /// \return Unix Timestamp
	Uint32 getTimestamp(void);
    /// \brief Get the joystick Id
    /// \return SDL Joystick ID
	SDL_JoystickID getJoystickId(void);
    /// \brief Is Button Down
    /// \return Down or not
	bool isDown(void);
    /// \brief Get the Game Controller Button Id
    /// \return SDL Game Controller Button Id
	SDL_GameControllerButton getButton(void);
    /// \brief Get Event State
    /// \return State ID
	Uint8 getState(void);
    /// \brief Get the underlying SDL Event
    /// \return Underlying Event
	SDL_ControllerButtonEvent* getButtonEvent(void);
};

}

#endif
