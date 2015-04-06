#ifndef ITEMNODE_H
#define ITEMNODE_H
#include "Item.h"
namespace StiGame {

namespace Gui {

class ItemIterator;
/// \class ItemNode
/// \brief Forward Item Node
class ItemNode {
public:
    /// \brief Create a new Node
    /// \param m_item Item to put in the node
    ItemNode(Item *m_item);
    /// \brief Destructor
    virtual ~ItemNode();
    /// \brief Get the Item Pointer
    /// \return Item Pointer
    Item* item(void);
    /// \brief Get the next node pointer
    /// \return Item Node Pointer
    ItemNode* next(void);
    /// \brief Create a new Iterator with this node as starting node
    /// \return New Iterator
    ItemIterator iterator(void);
    /// \brief Set the next node
    /// \param m_node Next Node
    void setNext(ItemNode *m_node);
    /// \brief Is the Node contain a next element
    /// \return Has Next element or not
    bool hasNext(void);
private:
    /// \brief Item Pointer
    Item *_item;
    /// \brief Next Node
    ItemNode *_next;
};

}

}


#endif // ITEMNODE_H
