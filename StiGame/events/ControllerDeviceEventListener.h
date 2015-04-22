#ifndef CONTROLLERDEVICEEVENTLISTENER_H
#define CONTROLLERDEVICEEVENTLISTENER_H

#include "ControllerDeviceEventArgs.h"

namespace StiGame
{

class ControllerDeviceEventThrower;

/// \class ControllerDeviceEventListener
/// \brief Handle Controller Device Event (Connect and disconnect a controller)
class ControllerDeviceEventListener
{
public:
    /// \brief Constructor
	ControllerDeviceEventListener();
    /// \brief Destructor
	virtual ~ControllerDeviceEventListener();
    /// \brief Method to override, to handle event
    /// \param src Thrower
    /// \param args Event Args
	virtual void handleEvent(ControllerDeviceEventThrower *src, ControllerDeviceEventArgs *args);
};

}

#endif
