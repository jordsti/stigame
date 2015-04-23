#ifndef WINDOWEVENTLISTENER
#define WINDOWEVENTLISTENER

#include "WindowEventArgs.h"

namespace StiGame
{

class WindowEventThrower;
/// \class WindowEventListener
/// \brief Window Event Listener
class WindowEventListener
{
public:
    /// \brief Constructor
	WindowEventListener();
    /// \brief Destructor
	virtual ~WindowEventListener();
    /// \brief Method that inherited class must override to handle these event
    /// \param src Event Thrower
    /// \param args Event Args
	virtual void handleEvent(WindowEventThrower *src, WindowEventArgs *args);
};

}

#endif
