#ifndef MOUSEWHEELEVENTTHROWER_H
#define MOUSEWHEELEVENTTHROWER_H

#include "MouseWheelEventListener.h"
#include <list>
namespace StiGame
{
/// \class MouseWheelEventThrower
/// \brief Mouse Wheel Event Thrower
class MouseWheelEventThrower
{
public:
    /// \brief Constructor
	MouseWheelEventThrower();
    /// \brief Destructor
	virtual ~MouseWheelEventThrower();
    /// \brief Subscribe a listener to this event thrower
    /// \param listener Listener to add
	virtual void subscribe(MouseWheelEventListener *listener);
    /// \brief Remove a listener from this event thrower
    /// \param listener Listener to remove
    virtual void remove(MouseWheelEventListener *listener);
	
protected:
    /// \brief Registered Event Listener
	std::list<MouseWheelEventListener*> wheelListeners;
    /// \brief Publish an event through the registered event listener
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void publish(MouseWheelEventThrower *src, MouseWheelEventArgs *args);
};

}

#endif
