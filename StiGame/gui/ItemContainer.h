#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H
#include "ItemIterator.h"
namespace StiGame {

namespace Gui {

namespace _future {

class ItemContainer
{
public:
    ItemContainer();
    ItemContainer(bool m_clearItems);
    virtual ~ItemContainer();

    void add(Item *m_item);

    void addRange(ItemContainer *m_container);
    void addRange(ItemNode *m_node);

    void remove(Item *m_item);
    void removeAll(Item *m_item);
    Item* itemAt(unsigned int index);
    ItemNode* nodeAt(unsigned int index);
    void insert(Item *m_item, unsigned int index);
    ItemIterator iterator(void);
    unsigned int size(void);
    ItemNode* end(void);
    ItemNode* begin(void);
    void clear(void);
    void setClearItems(bool m_clearItems);
    bool isClearItems(void);
private:
    ItemNode *_start;
    bool clearItems;

};


}
}
}

#endif // ITEMCONTAINER_H
