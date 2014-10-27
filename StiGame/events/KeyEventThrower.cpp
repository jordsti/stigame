#include "KeyEventThrower.h"

namespace StiGame
{


KeyEventThrower::KeyEventThrower()
{
    //ctor
}

KeyEventThrower::~KeyEventThrower()
{
    //dtor
}

void KeyEventThrower::subscribe(KeyEventListener *listener)
{
    keyListeners.push_back(listener);
}

void KeyEventThrower::remove(KeyEventListener *listener)
{
    keyListeners.remove(listener);
}

void KeyEventThrower::publish(KeyEventThrower *src, KeyEventArgs *args)
{
    std::list<KeyEventListener*>::iterator lit(keyListeners.begin()), lend(keyListeners.end());

    for(; lit!=lend; ++lit)
    {
        (*lit)->handleEvent(src, args);
    }
}

}
