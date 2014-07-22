#include "CheckEventThrower.h"
#include "CheckEventListener.h"

namespace StiGame
{

CheckEventThrower::CheckEventThrower()
{
    //ctor
}

CheckEventThrower::~CheckEventThrower()
{
    //dtor
}

void CheckEventThrower::subscribe(CheckEventListener *listener)
{
    checkListeners.push_back(listener);
}

void CheckEventThrower::remove(CheckEventListener *listener)
{
    checkListeners.remove(listener);
}

void CheckEventThrower::publish(CheckEventThrower *src, CheckEventArgs *args)
{
    std::list<CheckEventListener*>::iterator lit(checkListeners.begin()), lend(checkListeners.end());
    for(; lit!=lend; ++lit)
    {
        (*lit)->handleEvent(src, args);
    }
}

}
