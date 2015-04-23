#ifndef CONTROLLERBUTTONEVENTLISTENER_H
#define CONTROLLERBUTTONEVENTLISTENER_H

#include "ControllerButtonEventArgs.h"

namespace StiGame
{

class ControllerButtonEventThrower;
/// \class ControllerButtonEventListener
/// \brief Controller Button Event Listener
class ControllerButtonEventListener
{
public:
    /// \brief Constructor
	ControllerButtonEventListener();
    /// \brief Destructor
	virtual ~ControllerButtonEventListener();
    /// \brief Method that inherited class must override to handle these event
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void handleEvent(ControllerButtonEventThrower *src, ControllerButtonEventArgs *args);
};

}

#endif
