#include "ItemValueChangedEventArgs.h"
namespace StiGame
{

namespace Gui
{

ItemValueChangedEventArgs::ItemValueChangedEventArgs(ItemValue *m_oldValue, ItemValue *m_newValue)
{
    oldValue = m_oldValue;
    newValue = m_newValue;
}

ItemValueChangedEventArgs::~ItemValueChangedEventArgs()
{
    delete oldValue;
    delete newValue;
}

ItemValue* ItemValueChangedEventArgs::getOldValue(void)
{
    return oldValue;
}

ItemValue* ItemValueChangedEventArgs::getNewValue(void)
{
    return newValue;
}

}

}
