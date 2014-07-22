#ifndef KEYEVENTLISTENER_H
#define KEYEVENTLISTENER_H

#include "KeyEventArgs.h"

namespace StiGame
{

class KeyEventThrower;

/// \class KeyEventListener
/// \brief Key Event Listener
class KeyEventListener
{
    public:
		/// \brief Create a new Key Event Listener
        KeyEventListener();
		/// \brief Destructor
        virtual ~KeyEventListener();
		/// \brief Handle Key Event
		/// \param src Thrower
		/// \param args Key Event Args
        virtual void handleEvent(KeyEventThrower *src, KeyEventArgs *args);
    protected:
    private:
};

}

#endif // KEYEVENTLISTENER_H
