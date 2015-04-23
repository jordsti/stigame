#ifndef MOUSEMOTIONEVENTLISTENER_H
#define MOUSEMOTIONEVENTLISTENER_H

#include "MouseMotionEventArgs.h"

namespace StiGame
{

class MouseMotionEventThrower;
/// \class MouseMotionEventListener
/// \brief Mouse Motion Event Listener
class MouseMotionEventListener
{
public:
    /// \brief Constructor
	MouseMotionEventListener();
    /// \brief Destructor
	virtual ~MouseMotionEventListener();
    /// \brief Method that inherited class must override to handle these event
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void handleEvent(MouseMotionEventThrower *src, MouseMotionEventArgs *args);
};

}

#endif
