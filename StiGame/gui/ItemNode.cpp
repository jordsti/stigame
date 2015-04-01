#include "ItemNode.h"
#include "ItemIterator.h"

namespace StiGame {

namespace Gui {

namespace _future {

ItemNode::ItemNode(Item *m_item)
{
    _item = m_item;
    _next = nullptr;
}

ItemNode::~ItemNode()
{

}

Item* ItemNode::item(void)
{
    return _item;
}

ItemNode* ItemNode::next(void)
{
    return _next;
}

void ItemNode::setNext(ItemNode *m_node)
{
    _next = m_node;
}

bool ItemNode::hasNext(void)
{
    return _next != nullptr;
}

ItemIterator ItemNode::iterator(void)
{
    return ItemIterator(this);
}

}

}
}
