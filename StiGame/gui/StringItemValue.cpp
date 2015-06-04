#include "StringItemValue.h"

namespace StiGame
{

namespace Gui
{

StringItemValue::StringItemValue(Item *m_parent, std::string m_value) :
    ItemValue(m_parent)
{
    value = m_value;
}

StringItemValue::~StringItemValue()
{

}

ItemValueType StringItemValue::getType(void)
{
    return IVT_String;
}

std::string StringItemValue::getValue(void)
{
    return value;
}


}

}
