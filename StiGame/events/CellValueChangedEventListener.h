#ifndef CELLVALUECHANGEDEVENTLISTENER_H
#define CELLVALUECHANGEDEVENTLISTENER_H

#include "CellValueChangedEventArgs.h"

namespace StiGame
{

namespace Gui
{

class CellValueChangedEventThrower;


class CellValueChangedEventListener
{
public:
    CellValueChangedEventListener();
    virtual ~CellValueChangedEventListener();

    virtual void handleEvent(CellValueChangedEventThrower *src, CellValueChangedEventArgs *args);
};

}

}

#endif // CELLVALUECHANGEDEVENTLISTENER_H
