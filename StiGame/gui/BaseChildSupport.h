#ifndef BASECHILDSUPPORT_H
#define BASECHILDSUPPORT_H

#include "ChildSupport.h"
#include "ItemContainer.h"
namespace StiGame
{

namespace Gui
{

class BaseChildSupport :
        public ChildSupport
{
public:
    BaseChildSupport();
    virtual ~BaseChildSupport();
    virtual Item* getChildAt(int index);
    virtual void addChild(Item *child);
    virtual void removeChild(Item *to_remove);
    virtual unsigned int childsCount();
protected:
    ItemContainer container;
};

}

}

#endif // BASECHILDSUPPORT_H
