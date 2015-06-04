#ifndef INTEGERITEMVALUE_H
#define INTEGERITEMVALUE_H

#include "ItemValue.h"

namespace StiGame
{

namespace Gui
{

class IntegerItemValue :
        public ItemValue
{
public:
    IntegerItemValue(Item *m_parent, int m_value);
    virtual ~IntegerItemValue();

    ItemValueType getType(void);

    int getValue(void);

private:
    int value;
};

}

}


#endif // INTEGERITEMVALUE_H
