#ifndef CONTROLLERAXISEVENTTHROWER_H
#define CONTROLLERAXISEVENTTHROWER_H

#include "ControllerAxisEventListener.h"
#include <list>

namespace StiGame
{
/// \class ControllerAxisEventThrower
/// \brief Controller Axis Event Thrower
class ControllerAxisEventThrower
{
public:
    /// \brief Constructor
	ControllerAxisEventThrower();
    /// \brief Destructor
	virtual ~ControllerAxisEventThrower();
    /// \brief Subscribe a listener to this event thrower
    /// \param listener Listener to add
    virtual void subscribe(ControllerAxisEventListener *listener);
    /// \brief Remove a listener from this event thrower
    /// \param listener Listener to remove
	virtual void remove(ControllerAxisEventListener *listener);
protected:
    /// \brief Publish an event through the registered event listener
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void publish(ControllerAxisEventThrower *src, ControllerAxisEventArgs *args);
    /// \brief Registered Listeners
	std::list<ControllerAxisEventListener*> axisListeners;
	
};

}

#endif
