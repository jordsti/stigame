#ifndef STRINGITEMVALUE_H
#define STRINGITEMVALUE_H
#include "ItemValue.h"

namespace StiGame
{

namespace Gui
{

class StringItemValue :
        public ItemValue
{
public:
    StringItemValue(Item *m_parent, std::string m_value);
    virtual ~StringItemValue();

    ItemValueType getType(void);

    std::string getValue(void);

private:
    std::string value;
};

}

}

#endif // STRINGITEMVALUE_H
