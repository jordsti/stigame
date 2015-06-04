#include "ItemValue.h"

namespace StiGame
{

namespace Gui
{

ItemValue::ItemValue(Item *m_parent)
{
    parent = m_parent;
}

ItemValue::~ItemValue()
{

}

Item* ItemValue::getParent(void)
{
    return parent;
}

}

}
