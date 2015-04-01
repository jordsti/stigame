#ifndef ITEMNODE_H
#define ITEMNODE_H
#include "Item.h"
namespace StiGame {

namespace Gui {

namespace _future {

class ItemIterator;

class ItemNode {
public:
    ItemNode(Item *m_item);
    virtual ~ItemNode();

    Item* item(void);
    ItemNode* next(void);
    ItemIterator iterator(void);

    void setNext(ItemNode *m_node);
    bool hasNext(void);
private:
    Item *_item;
    ItemNode *_next;
};

}

}

}

#endif // ITEMNODE_H
