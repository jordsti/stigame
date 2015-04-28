#include "ItemCreatorChain.h"

namespace StiGame
{

namespace Gui
{

ItemCreatorChain::ItemCreatorChain()
{
    _next = nullptr;
}

ItemCreatorChain::~ItemCreatorChain()
{

}

ItemCreatorChain* ItemCreatorChain::next(void)
{
    return _next;
}

Item* ItemCreatorChain::create(std::string type, std::map<std::string, int> variables)
{
    Item *item = createItem(type, variables);

    if(item == nullptr && hasNext())
    {
        item = next()->createItem(type, variables);
    }

    return item;
}

bool ItemCreatorChain::hasNext(void)
{
    return _next != nullptr;
}

void ItemCreatorChain::setNext(ItemCreatorChain *m_next)
{
    _next = m_next;
}


}

}
