#ifndef CONTROLLERAXISEVENTLISTENER_H
#define CONTROLLERAXISEVENTLISTENER_H

#include "ControllerAxisEventArgs.h"

namespace StiGame
{

class ControllerAxisEventThrower;
/// \class ControllerAxisEventListener
/// \brief Controller Axis Event Listener
class ControllerAxisEventListener
{
public:
    /// \brief Constructor
	ControllerAxisEventListener();
    /// \brief Destructor
	virtual ~ControllerAxisEventListener();
    /// \brief Method thtat the inherited must override to handle the event
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void handleEvent(ControllerAxisEventThrower *src, ControllerAxisEventArgs *args);
};

}

#endif
