#ifndef CONTROLLERBUTTONEVENTTHROWER_H
#define CONTROLLERBUTTONEVENTTHROWER_H

#include "ControllerButtonEventListener.h"
#include <list>

namespace StiGame
{
/// \class ControllerButtonEventThrower
/// \brief Controller Button Event Thrower
class ControllerButtonEventThrower
{
public:
    /// \brief Constructor
	ControllerButtonEventThrower();
    /// \brief Destructor
	virtual ~ControllerButtonEventThrower();
    /// \brief Subscribe a listener to this thrower
    /// \param listener Listener to add
	virtual void subscribe(ControllerButtonEventListener *listener);
    /// \brief Remove a listener from this thrower
    /// \param listener Remove a listener from this thrower
	virtual void remove(ControllerButtonEventListener *listener);
protected:
    /// \brief Publish an event through the registered listener
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void publish(ControllerButtonEventThrower *src, ControllerButtonEventArgs *args);
    /// \brief Registered listeners
	std::list<ControllerButtonEventListener*> cbuttonListeners;
};

}


#endif
