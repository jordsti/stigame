#include "EffectEventThrower.h"

namespace StiGame
{

namespace Gui
{

namespace Effects
{

EffectEventThrower::EffectEventThrower()
{

}

EffectEventThrower::~EffectEventThrower()
{

}

void EffectEventThrower::subscribe(EffectListener *listener)
{
    listeners.push_back(listener);
}

void EffectEventThrower::remove(EffectListener *listener)
{
    listeners.remove(listener);
}

void EffectEventThrower::publish(EffectEventArgs *args)
{
    auto lit(listeners.begin()), lend(listeners.end());
    for(;lit!=lend;++lit)
    {
        EffectListener *listener = (*lit);
        listener->handleEvent(this, args);
    }
}

}

}

}
