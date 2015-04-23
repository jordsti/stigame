#ifndef CHECKEVENTLISTENER_H
#define CHECKEVENTLISTENER_H

#include "CheckEventArgs.h"

namespace StiGame
{
class CheckEventThrower;
/// \class CheckEventListener
/// \brief Check Event Listener
class CheckEventListener
{
    public:
        /// \brief Constructor
        CheckEventListener();
        /// \brief Destructor
        virtual ~CheckEventListener();
        /// \brief Method that inherited class must override to handle these event
        /// \param src Event Thrower
        /// \param args Event Args
        virtual void handleEvent(CheckEventThrower *src, CheckEventArgs *args);
    protected:
    private:
};
}
#endif // CHECKEVENTLISTENER_H

