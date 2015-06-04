#include "IntegerItemValue.h"

namespace StiGame
{

namespace Gui
{

IntegerItemValue::IntegerItemValue(Item *m_parent, int m_value) :
    ItemValue(m_parent)
{
    value = m_value;
}

IntegerItemValue::~IntegerItemValue()
{

}

ItemValueType IntegerItemValue::getType(void)
{
    return IVT_Integer;
}

int IntegerItemValue::getValue(void)
{
    return value;
}

}

}
