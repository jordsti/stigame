#ifndef CELLVALUECHANGEDEVENTTHROWER_H
#define CELLVALUECHANGEDEVENTTHROWER_H

#include <list>
#include "CellValueChangedEventArgs.h"

namespace StiGame
{

namespace Gui
{

class CellValueChangedEventListener;

class CellValueChangedEventThrower
{
public:
    CellValueChangedEventThrower();
    virtual ~CellValueChangedEventThrower();

    void subscribe(CellValueChangedEventListener *listener);
    void remove(CellValueChangedEventListener *listener);
protected:
    virtual void publish(CellValueChangedEventThrower *src, CellValueChangedEventArgs *args);
    std::list<CellValueChangedEventListener*> listeners;
};

}

}

#endif // CELLVALUECHANGEDEVENTTHROWER_H
