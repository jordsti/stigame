#ifndef SELECTIONEVENTARGS_H
#define SELECTIONEVENTARGS_H
#include "EventArgs.h"
#include "ValueObject.h"

namespace StiGame
{

namespace Gui
{
/// \class SelectionEventArgs
/// \brief Event Args for a selection event
class SelectionEventArgs :
    public EventArgs
{
    public:
		/// \brief Create a new SelectionEventArgs
		/// \param m_selection Selection Item
        SelectionEventArgs(ValueObject* m_selection);
		/// \brief Destructor
        virtual ~SelectionEventArgs();
		/// \brief Get the selection item
		/// \return Selected Value Object
        ValueObject *getSelection(void);
    protected:
		/// \brief Selected Value Object
        ValueObject *selection;
    private:
};


}
}

#endif // SELECTIONEVENTARGS_H
