#include "ValueObjectItemValue.h"

namespace StiGame
{

namespace Gui
{
ValueObjectItemValue::ValueObjectItemValue(Item *m_parent, ValueObject *m_valueObject) :
    ItemValue(m_parent)
{
    valueObject = m_valueObject;
}

ValueObjectItemValue::~ValueObjectItemValue()
{

}

ItemValueType ValueObjectItemValue::getType(void)
{
    return IVT_ValueObject;
}

ValueObject* ValueObjectItemValue::getValue(void)
{
    return valueObject;
}

}

}
