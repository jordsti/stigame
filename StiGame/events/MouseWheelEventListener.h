#ifndef MOUSEWHEELEVENTLISTENER_H
#define MOUSEWHEELEVENTLISTENER_H

#include "MouseWheelEventArgs.h"

namespace StiGame
{

class MouseWheelEventThrower;
/// \class MouseWheelEventListener
/// \brief Mouse Wheel Event Listener
class MouseWheelEventListener
{
public:
    /// \brief Constructor
	MouseWheelEventListener();
    /// \brief Destructor
	virtual ~MouseWheelEventListener();
    /// \brief Method that inherited class must override to handle these event
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void handleEvent(MouseWheelEventThrower *src, MouseWheelEventArgs *args);
};

}

#endif
