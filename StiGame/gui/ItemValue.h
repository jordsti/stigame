#ifndef ITEMVALUE_H
#define ITEMVALUE_H

#include "Item.h"

namespace StiGame
{

namespace Gui
{

enum ItemValueType {
    IVT_Integer,
    IVT_String,
    IVT_ValueObject
};

class ItemValue
{
public:
    ItemValue(Item *m_parent);
    virtual ~ItemValue();

    virtual ItemValueType getType(void) = 0;

    Item* getParent(void);
private:
    Item *parent;
};

}
}
#endif // ITEMVALUE_H
