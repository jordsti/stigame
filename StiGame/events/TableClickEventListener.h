#ifndef TABLECLICKEVENTLISTENER_H
#define TABLECLICKEVENTLISTENER_H

#include "TableClickEventArgs.h"

namespace StiGame
{

namespace Gui
{

class TableClickEventThrower;

class TableClickEventListener
{
public:
    TableClickEventListener();
    virtual ~TableClickEventListener();

    virtual void handleEvent(TableClickEventThrower *src, TableClickEventArgs *args);
};

}

}
#endif // TABLECLICKEVENTLISTENER_H
