#include "ItemContainer.h"
namespace StiGame {

namespace Gui {

namespace _future {

ItemContainer::ItemContainer()
{
    _start = nullptr;
    clearItems = true;
}

ItemContainer::ItemContainer(bool m_clearItems)
{
    _start = nullptr;
    clearItems = m_clearItems;
}

ItemContainer::~ItemContainer()
{
    //clearing the node
    for(ItemIterator it = iterator(); it.nextWithClear();)
    {
        if(clearItems)
        {
            delete it.item();
        }
    }
}

void ItemContainer::clear(void)
{
    for(ItemIterator it = iterator(); it.nextWithClear();)
    {
        if(clearItems)
        {
            delete it.item();
        }
    }
}

void ItemContainer::setClearItems(bool m_clearItems)
{
    clearItems = m_clearItems;
}

bool ItemContainer::isClearItems(void)
{
    return clearItems;
}

ItemNode* ItemContainer::end(void)
{
    ItemNode *current = _start;

    if(current != nullptr)
    {
        while(current->next() != nullptr)
        {
            current = current->next();
        }
    }
    return current;
}

ItemNode* ItemContainer::begin(void)
{
    return _start;
}

void ItemContainer::addRange(ItemContainer *m_container)
{
    for(ItemIterator it = m_container->iterator(); it.next();)
    {
        add(it.item());
    }
}

void ItemContainer::addRange(ItemNode *m_node)
{
    ItemNode *current = m_node;
    while(current != nullptr)
    {
        add(current->item());
        current = current->next();
    }
}

void ItemContainer::add(Item *m_item)
{
    if(_start == nullptr)
    {
        //first item of the container, so creating the first node
        _start = new ItemNode(m_item);
    }
    else
    {
        ItemNode *last = end();
        last->setNext(new ItemNode(m_item));
    }
}

void ItemContainer::remove(Item *m_item)
{
    //remove only the first occurence of the pointer
    ItemNode *current = _start;
    ItemNode *previous = nullptr;

    while(current != nullptr)
    {
        if(current->item() == m_item)
        {
            //do the remove here
            if(previous == nullptr)
            {
                //first item is removed
                _start = current->next();
                delete current;
                break;
            }
            else
            {
                previous->setNext(current->next());
                delete current;
                break;
            }
        }

        //advance
        previous = current;
        current = current->next();
    }


}

void ItemContainer::removeAll(Item *m_item)
{
    //remove all occurences of the pointer
    ItemNode *current = _start;
    ItemNode *previous = nullptr;

    while(current != nullptr)
    {
        if(current->item() == m_item)
        {
            //do the remove here
            if(previous == nullptr)
            {
                //first item is removed
                _start = current->next();
                delete current;
            }
            else
            {
                previous->setNext(current->next());
                delete current;
            }
        }


        //advance
        previous = current;
        current = current->next();
    }
}

Item* ItemContainer::itemAt(unsigned int index)
{
    ItemNode *node = nodeAt(index);
    if(node != nullptr)
    {
        return node->item();
    }

    return nullptr;
}

ItemNode* ItemContainer::nodeAt(unsigned int index)
{
    ItemIterator it = iterator();
    unsigned int i=0;
    for(;it.next();i++)
    {
        if(i == index)
        {
            return it.node();
        }
    }

    return nullptr;
}

void ItemContainer::insert(Item *m_item, unsigned int index)
{
    //at the item after the index
    //if the index is higher than the number of item, it's added to the end
    ItemNode *current = _start;
    unsigned int i=0;
    while(current != nullptr)
    {
        if(i == index)
        {
            //adding the item in between those items
            ItemNode *next = current->next();
            ItemNode *newNode = new ItemNode(m_item);
            current->setNext(newNode);
            newNode->setNext(next);
            return;
        }

        //advance
        current = current->next();
        i++;
    }

    //loop endend, so add to the end
    add(m_item);

}

ItemIterator ItemContainer::iterator(void)
{
    return ItemIterator(_start);
}

unsigned int ItemContainer::size(void)
{
    ItemNode *current = _start;
    unsigned int count = 0;
    while(current != nullptr)
    {
        count++;
        current = current->next();
    }

    return count;
}

}

}

}
