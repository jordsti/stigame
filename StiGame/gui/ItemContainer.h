#ifndef ITEMCONTAINER_H
#define ITEMCONTAINER_H
#include "ItemIterator.h"
namespace StiGame {

namespace Gui {

/// \class ItemContainer
/// \brief List Data Structure for the Gui Item (Will be replace list<Item*>)
class ItemContainer
{
public:
    /// \brief Item Not Found Consant
    static const int ITEM_NOT_FOUND;
    /// \brief Create a new Item Container, with clear items as false
    ItemContainer();
    /// \brief Create a new Item Container with custom clear items value
    /// \param m_clearItems Delete the item at destruction
    ItemContainer(bool m_clearItems);
    /// \brief Destructor
    virtual ~ItemContainer();
    /// \brief Append a new item to the container
    void add(Item *m_item);
    /// \brief Append a list of items to the container
    /// \param m_container Container of items to add
    void addRange(ItemContainer *m_container);
    /// \brief Add a list of items to the container, from that node
    /// \param m_node The Starting node of the range
    void addRange(ItemNode *m_node);
    /// \brief Remove the first occurence of an item
    /// \param m_item Item to delete
    void remove(Item *m_item);
    /// \brief Remove all occurences of that item
    /// \param m_item Item to delete
    void removeAll(Item *m_item);
    /// \brief Get the item located at this index
    /// \param index Index
    /// \return Item Pointer or nullptr if the index is bigger than the list
    Item* itemAt(unsigned int index);
    /// \brief Get the node located at this index
    /// \param index Index
    /// \return Node Pointer or nullptr if the index is bigger than the list
    ItemNode* nodeAt(unsigned int index);
    /// \brief Insert an item at the specified index
    /// \param m_item Item to insert
    /// \param index The index to place it
    void insert(Item *m_item, unsigned int index);
    /// \brief Get the index of item
    /// \param m_item Item to found
    /// \return Item index or ITEM_NOT_FOUND constant
    int indexOf(Item *m_item);
    /// \brief Replace an item in the container
    /// \param old_item The item to overwrite
    /// \param new_item The item that will be placed instead
    /// \return If the old_item is found or not
    bool replace(Item *old_item, Item *new_item);
    /// \brief Replace an item in the container
    /// \param old_item The item to overwrite
    /// \param new_item The item that will be placed instead
    /// \param clearItem Do the container need to free the memory of the item
    /// \return If the old_item is found or not
    bool replace(Item *old_item, Item *new_item, bool clearItem);
    /// \brief Get an Iterator for the current container
    /// \return Container Iterator
    ItemIterator iterator(void);
    /// \brief The number of elements in the container
    /// \return Items count
    unsigned int size(void);
    /// \brief Get the last Node
    /// \return Last Node Pointer
    ItemNode* end(void);
    /// \brief Get the first Node
    /// \return First Node Pointer
    ItemNode* begin(void);
    /// \brief Clear all the elements in the container
    void clear(void);
    /// \brief Set the Clear Items Value
    /// \param m_clearIteams Clear the Item at destruction and/or replacement
    void setClearItems(bool m_clearItems);
    /// \brief Is Items get cleared by the container
    /// \return Cleared or not by the container
    bool isClearItems(void);
    /// \brief Get Item with specified Id
    /// \param item_id Item Id
    /// \return Item pointer or nullptr if not found
    Item* id(int item_id);

    bool contains(Item *m_item);

private:
    /// \brief Starting Node
    ItemNode *_start;
    /// \brief Clear the items
    bool clearItems;

};


}
}

#endif // ITEMCONTAINER_H
