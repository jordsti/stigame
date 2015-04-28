#ifndef CHILDSUPPORT_H
#define CHILDSUPPORT_H
#include "Item.h"
namespace StiGame
{

namespace Gui
{

class ChildSupport
{
public:
    ChildSupport();
    virtual ~ChildSupport();
    virtual Item* getChildAt(int index) = 0;
    virtual void addChild(Item *child) = 0;
    virtual void removeChild(Item *to_remove) = 0;
    virtual unsigned int childsCount() = 0;
protected:

};

}
}


#endif // CHILDSUPPORT_H
