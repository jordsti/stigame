#ifndef SELECTIONEVENTTHROWER_H
#define SELECTIONEVENTTHROWER_H
#include "SelectionEventListener.h"
#include <list>

namespace StiGame
{

namespace Gui
{

/// \class SelectionEventThrower
/// \brief Selection Event thrower, when an item is selected by the user
class SelectionEventThrower
{
    public:
		/// \brief Create a new Selection Event Thrower
        SelectionEventThrower();
		/// \brief Destructor
        virtual ~SelectionEventThrower();
		/// \brief Subscribe to this thrower
		/// \param listener Selection Event Listener
        void subscribe(SelectionEventListener *listener); //major typo here...
		/// \brief Remove a listener
		/// \param listener Selection Event Listener
        void remove(SelectionEventListener *listener);
    protected:
		/// \brief Selection Event Listeners
        std::list<SelectionEventListener*> selectionListeners;
		/// \brief Publish event to the list
		/// \param source Thrower
		/// \param args Selection Event Args
        virtual void publish(SelectionEventThrower *source, SelectionEventArgs *args);

        bool containListeners(void);
    private:
};

}

}

#endif // SELECTIONEVENTTHROWER_H
