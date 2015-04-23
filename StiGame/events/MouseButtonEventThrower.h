#ifndef MOUEEBUTTONEVENTTHROWER_H
#define MOUSEBUTTONEVENTTHROWER_H

#include "MouseButtonEventListener.h"
#include <list>

namespace StiGame
{

/// \class MouseButtonEventThrower
/// \brief Mouse Button Event Thrower
class MouseButtonEventThrower
{
public:
    /// \brief Constructor
	MouseButtonEventThrower();
    /// \brief Destructor
	virtual ~MouseButtonEventThrower();
    /// \brief Subscribe a listener to this thrower
    /// \param listener Listener to add
	virtual void subscribe(MouseButtonEventListener *listener);
    /// \brief Remove a listener from this thrower
    /// \param listener Listener to remove
    virtual void remove(MouseButtonEventListener *listener);
protected:
    /// \brief Registered Listeners
	std::list<MouseButtonEventListener*> mouseListeners;
    /// \brief Publish an event through the registered listener
    /// \param source Event Thrower
    /// \param args Event Args
	virtual void publish(MouseButtonEventThrower *source, MouseButtonEventArgs *args);

};

}


#endif
