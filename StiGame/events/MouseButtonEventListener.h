#ifndef MOUSEBUTTONEVENTLISTENER_H
#define MOUSEBUTTONEVENTLISTENER_H

#include "MouseButtonEventArgs.h"

namespace StiGame
{

class MouseButtonEventThrower;
/// \class MouseButtonEventListener
/// \brief Mouse Button Event Listener
class MouseButtonEventListener
{
public:
    /// \brief Constructor
	MouseButtonEventListener();
    /// \brief Destructor
	virtual ~MouseButtonEventListener();
    /// \brief Method to override by the inherited class
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void handleEvent(MouseButtonEventThrower *src, MouseButtonEventArgs *args);
};

}


#endif
