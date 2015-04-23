#ifndef CONTROLLERDEVICEEVENTARGS_H
#define CONTROLLERDEVICEEVENTARGS_H

#include "EventArgs.h"

namespace StiGame
{

enum DeviceEventType {
	DET_ADDED,
	DET_REMOVED,
	DET_REMAPPED
};

/// \class ControllerDeviceEventArgs
/// \brief Controller Device Event
class ControllerDeviceEventArgs
	: public EventArgs
{
public:
    /// \brief Empty Constructor
	ControllerDeviceEventArgs();
    /// \brief Create a new Controller Device Event with the underlying SDL Event
    /// \param m_sdlEvent Underlying SDL Event
	ControllerDeviceEventArgs(SDL_Event *m_sdlEvent);
    /// \brief Destructor
	virtual ~ControllerDeviceEventArgs();
    /// \brief Get the timestamp of the event
    /// \return Unix Timestamp
	Uint32 getTimestamp(void);
    /// \brief Get the Joystick ID
    /// \return SDL Joystick ID
	SDL_JoystickID getJoystickId(void);
    /// \brief Get Device Event Type
    /// \return Device Event Type
	DeviceEventType getType(void);
    /// \brief Get the underlying SDL Event
    /// \return Underlying SDL Controller Device Event
	SDL_ControllerDeviceEvent* getDeviceEvent(void);
};

}

#endif
