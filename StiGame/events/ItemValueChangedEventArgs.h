#ifndef ITEMVALUECHANGEDEVENTARGS_H
#define ITEMVALUECHANGEDEVENTARGS_H
#include "ItemValue.h"
namespace StiGame
{

namespace Gui
{

class ItemValueChangedEventArgs
{
public:
    ItemValueChangedEventArgs(ItemValue *m_oldValue, ItemValue *m_newValue);
    virtual ~ItemValueChangedEventArgs();

    ItemValue* getOldValue(void);
    ItemValue* getNewValue(void);

    template <class T>
    T* getNewValue(void)
    {
        return dynamic_cast<T*>(newValue);
    }

    template <class T>
    T* getOldValue(void)
    {
        return dynamic_cast<T*>(oldValue);
    }

private:
    ItemValue *oldValue;
    ItemValue *newValue;
};

}

}

#endif // ITEMVALUECHANGEDEVENTARGS_H
