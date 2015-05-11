#ifndef TABLECLICKEVENTTHROWER_H
#define TABLECLICKEVENTTHROWER_H

#include "TableClickEventListener.h"

#include <list>
namespace StiGame
{

namespace Gui
{

class TableClickEventThrower
{
public:
    TableClickEventThrower();
    virtual ~TableClickEventThrower();

    virtual void subscribe(TableClickEventListener *listener);
    virtual void remove(TableClickEventListener *listener);
protected:
    virtual void publish(TableClickEventThrower *src, TableClickEventArgs *args);

    std::list<TableClickEventListener*> listeners;
};

}

}

#endif // TABLECLICKEVENTTHROWER_H
