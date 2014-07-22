#ifndef KEYEVENTTHROWER_H
#define KEYEVENTTHROWER_H
#include <list>
#include "KeyEventArgs.h"
#include "KeyEventListener.h"

namespace StiGame
{

class KeyEventThrower
{
	/// \class KeyEventThrower
	/// \brief Key Event Thrower
    public:
		/// \brief Create a new Key Event Thrower
        KeyEventThrower();
		/// \brief Destructor
        virtual ~KeyEventThrower();
		/// \brief Subscribe to this thrower
		/// \param listener Key Event Listener
        void subscribe(KeyEventListener *listener);
		/// \brief Remove a listener
		/// \param listener Key Event Listener
        void remove(KeyEventListener *listener);
    protected:
		/// \brief Remove a listener
		/// \param src Key Event Thrower
		/// \param args Key Event Args
        void publish(KeyEventThrower *src, KeyEventArgs *args);
		/// \brief Subscribed listeners
        std::list<KeyEventListener*> keyListeners;
    private:
};

}
#endif // KEYEVENTTHROWER_H
