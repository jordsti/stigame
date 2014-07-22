#ifndef SELECTIONEVENTLISTENER_H
#define SELECTIONEVENTLISTENER_H

#include "SelectionEventArgs.h"

namespace StiGame
{

namespace Gui
{

class SelectionEventThrower;

/// \class SelectionEventListener
/// \brief Listener for a Selection Event
class SelectionEventListener
{
    public:
		/// \brief Create a new Selection event listener
        SelectionEventListener();
		/// \brief Destructor
        virtual ~SelectionEventListener();
		/// \brief Handle throwed event
		/// \param src Thrower
		/// \param ags Event args
        virtual void handleEvent(SelectionEventThrower *src, SelectionEventArgs *args);
    protected:
    private:
};

}

}
#endif // SELECTIONEVENTLISTENER_H
