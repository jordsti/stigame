#ifndef CONTROLLERDEVICEEVENTTHROWER_H
#define CONTROLLERDEVICEEVENTTHROWER_H

#include "ControllerDeviceEventListener.h"
#include <list>

namespace StiGame
{
/// \class ControllerDeviceEventThrower
/// \brief Controller Device Event Thrower
class ControllerDeviceEventThrower
{
public:
    /// \brief Constructor
	ControllerDeviceEventThrower();
    /// \brief Destructor
	virtual ~ControllerDeviceEventThrower();
    /// \brief Subscribe a listener to this event thrower
    /// \param listener Listener to add
	virtual void subscribe(ControllerDeviceEventListener *listener);
    /// \brief Remove a listener from this event thrower
    /// \param listener Listener to remove
	virtual void remove(ControllerDeviceEventListener *listener);
protected:
    /// \brief Publish an event through the registered listener
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void publish(ControllerDeviceEventThrower *src, ControllerDeviceEventArgs *args);
    /// \brief Registered Listeners
	std::list<ControllerDeviceEventListener*> cdeviceListeners;
};

}

#endif
