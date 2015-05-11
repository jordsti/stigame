#include "CellValueChangedEventThrower.h"
#include "CellValueChangedEventListener.h"
namespace StiGame
{

namespace Gui
{

CellValueChangedEventThrower::CellValueChangedEventThrower()
{

}

CellValueChangedEventThrower::~CellValueChangedEventThrower()
{

}

void CellValueChangedEventThrower::subscribe(CellValueChangedEventListener *listener)
{
    listeners.push_back(listener);
}

void CellValueChangedEventThrower::remove(CellValueChangedEventListener *listener)
{
    listeners.remove(listener);
}

void CellValueChangedEventThrower::publish(CellValueChangedEventThrower *src, CellValueChangedEventArgs *args)
{
    auto lit(listeners.begin()), lend(listeners.end());
    for(;lit!=lend;++lit)
    {
        (*lit)->handleEvent(src, args);
    }
}

}

}
