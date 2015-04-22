#ifndef CHECKEVENTTHROWER_H
#define CHECKEVENTTHROWER_H
#include <list>
#include "CheckEventListener.h"
namespace StiGame
{

/// \class CheckEventThrower
/// \brief Check event source
class CheckEventThrower
{
    public:
        /// \brief Constructor
        CheckEventThrower();
        /// \brief Destructor
        virtual ~CheckEventThrower();
        /// \brief Subscribe a listener to this thrower
        /// \param listener Check Event Listener
        void subscribe(CheckEventListener *listener);
        /// \brief Remove a listener from this thrower
        /// \param listener Listener to remove
        void remove(CheckEventListener *listener);
    protected:
        /// \brief Publish an event through the listeners
        /// \param src Thrower
        /// \param args Event Args
        void publish(CheckEventThrower *src, CheckEventArgs *args);
        /// \brief Registered Listeners
        std::list<CheckEventListener*> checkListeners;
    private:
};

}

#endif // CHECKEVENTTHROWER_H
