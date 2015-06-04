#include "ItemValueChangedEventThrower.h"

namespace StiGame
{

namespace Gui
{

ItemValueChangedEventThrower::ItemValueChangedEventThrower()
{

}

ItemValueChangedEventThrower::~ItemValueChangedEventThrower()
{

}

void ItemValueChangedEventThrower::subscribe(ItemValueChangedEventListener *listener)
{
    itemValueListeners.push_back(listener);
}

void ItemValueChangedEventThrower::remove(ItemValueChangedEventListener *listener)
{
    itemValueListeners.remove(listener);
}


void ItemValueChangedEventThrower::publish(ItemValueChangedEventThrower *src, ItemValueChangedEventArgs *args)
{
    auto lit(itemValueListeners.begin()), lend(itemValueListeners.end());
    for(;lit!=lend;++lit)
    {
        ItemValueChangedEventListener *listener = (*lit);
        listener->handleEvent(src, args);
    }
}

}


}
