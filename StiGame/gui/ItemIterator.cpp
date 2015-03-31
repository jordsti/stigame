#include "ItemIterator.h"
namespace StiGame {

namespace Gui {

namespace _future {
ItemIterator::ItemIterator(ItemNode *m_firstItem)
{
    _start = m_firstItem;
    _current = nullptr;
}

ItemIterator::~ItemIterator()
{

}

ItemNode *ItemIterator::node(void)
{
    return _current;
}


Item *ItemIterator::item(void)
{
    if(_current != nullptr)
    {
        return _current->item();
    }
    else
    {
        return nullptr;
    }
}

bool ItemIterator::nextWithClear(void)
{
    if(_current == nullptr && _start != nullptr)
    {
        _current = _start;
        return true;
    }
    else if(_current != nullptr)
    {
        if(_current->hasNext())
        {
            ItemNode *prev = _current;
            _current = _current->next();
            delete prev;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool ItemIterator::next(void)
{
    if(_current == nullptr && _start != nullptr)
    {
        _current = _start;
        return true;
    }
    else if(_current != nullptr)
    {
        if(_current->hasNext())
        {
            _current = _current->next();
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void ItemIterator::publishOnClick(int mouse_x, int mouse_y)
{
    for(;next();)
    {
        if(item()->contains(mouse_x, mouse_y))
        {
            Point relp (mouse_x - item()->getX(), mouse_y - item()->getY());
            item()->onClick(&relp);
        }
    }
    //reset the iterator
    _current = nullptr;
}

void ItemIterator::publishTextInput(char *text)
{
    for(;next();)
    {
        if(item()->isHandleKey())
        {
            item()->onTextInput(text);
        }
    }

    _current = nullptr;
}

void ItemIterator::publishOnKeyUp(SDL_KeyboardEvent *evt)
{
    for(;next();)
    {
        if(item()->isHandleKey())
        {
            item()->onKeyUp(evt);
        }
    }

    _current = nullptr;
}

}
}
}
