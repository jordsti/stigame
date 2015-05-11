#include "TableClickEventThrower.h"

namespace StiGame
{

namespace Gui
{

TableClickEventThrower::TableClickEventThrower()
{
}

TableClickEventThrower::~TableClickEventThrower()
{
}



void TableClickEventThrower::subscribe(TableClickEventListener *listener)
{
    listeners.push_back(listener);
}

void TableClickEventThrower::remove(TableClickEventListener *listener)
{
    listeners.remove(listener);
}

void TableClickEventThrower::publish(TableClickEventThrower *src, TableClickEventArgs *args)
{
    auto lit(listeners.begin()), lend(listeners.end());
    for(;lit!=lend;++lit)
    {
        (*lit)->handleEvent(src, args);
    }
}

}

}
