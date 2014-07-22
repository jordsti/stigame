#ifndef CHECKEVENTTHROWER_H
#define CHECKEVENTTHROWER_H
#include <list>
#include "CheckEventListener.h"
namespace StiGame
{


class CheckEventThrower
{
    public:
        CheckEventThrower();
        virtual ~CheckEventThrower();
        void subscribe(CheckEventListener *listener);
        void remove(CheckEventListener *listener);
    protected:
        void publish(CheckEventThrower *src, CheckEventArgs *args);
        std::list<CheckEventListener*> checkListeners;
    private:
};

}

#endif // CHECKEVENTTHROWER_H
