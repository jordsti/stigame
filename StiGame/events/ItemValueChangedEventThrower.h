#ifndef ITEMVALUECHANGEDEVENTTHROWER_H
#define ITEMVALUECHANGEDEVENTTHROWER_H

#include <list>
#include "ItemValueChangedEventListener.h"

namespace StiGame
{

namespace Gui
{

class ItemValueChangedEventThrower
{
public:
    ItemValueChangedEventThrower();
    virtual ~ItemValueChangedEventThrower();

    void subscribe(ItemValueChangedEventListener *listener);
    void remove(ItemValueChangedEventListener *listener);

protected:
    virtual void publish(ItemValueChangedEventThrower *src, ItemValueChangedEventArgs *args);
    std::list<ItemValueChangedEventListener*> itemValueListeners;
};

}
}

#endif // ITEMVALUECHANGEDEVENTTHROWER_H
