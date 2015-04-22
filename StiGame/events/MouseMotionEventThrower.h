#ifndef MOUSEMOTIONEVENTTHROWER_H
#define MOUSEMOTIONEVENTTHROWER_H

#include "MouseMotionEventListener.h"
#include <list>


namespace StiGame
{
/// \class MouseMotionEventThrower
/// \brief Mouse Motion Event Thrower
class MouseMotionEventThrower
{
public:
    /// \brief Constructor
	MouseMotionEventThrower();
    /// \brief Destructor
	virtual ~MouseMotionEventThrower();
    /// \brief Subscribe a listener to this thrower
    /// \param listener Listener to add
	virtual void subscribe(MouseMotionEventListener *listener);
    /// \brief Remove a listener from this thrower
    /// \param listener Listener to remove
	virtual void remove(MouseMotionEventListener *listener);
protected:
    /// \brief Motion Listeners registered
	std::list<MouseMotionEventListener*> motionListeners;
    /// \brief Publish an event through the registered listeners
    /// \param src Event Source
    /// \param args Event Args
	virtual void publish(MouseMotionEventThrower *src, MouseMotionEventArgs *args);
};

}

#endif
