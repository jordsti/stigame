#ifndef ITEMVALUECHANGEDLISTENER_H
#define ITEMVALUECHANGEDLISTENER_H

#include "ItemValueChangedEventArgs.h"

namespace StiGame
{

namespace Gui
{
class ItemValueChangedEventThrower;

class ItemValueChangedEventListener
{
public:
    ItemValueChangedEventListener();
    virtual ~ItemValueChangedEventListener();

    virtual void handleEvent(ItemValueChangedEventThrower *src, ItemValueChangedEventArgs *args);
};

}

}

#endif // ITEMVALUECHANGEDLISTENER_H
