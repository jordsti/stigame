#ifndef VALUEOBJECTITEMVALUE_H
#define VALUEOBJECTITEMVALUE_H
#include "ItemValue.h"
#include "ValueObject.h"
namespace StiGame
{

namespace Gui
{

class ValueObjectItemValue :
        public ItemValue
{
public:
    ValueObjectItemValue(Item *m_parent, ValueObject *m_valueObject);
    virtual ~ValueObjectItemValue();

    ItemValueType getType(void);

    ValueObject* getValue(void);
private:
    ValueObject *valueObject;
};


}

}


#endif // VALUEOBJECTITEMVALUE_H
