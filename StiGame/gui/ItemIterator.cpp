#include "ItemIterator.h"
namespace StiGame {

namespace Gui {

ItemIterator::ItemIterator(ItemNode *m_firstNode)
{
    _start = m_firstNode;
    _current = nullptr;
}

ItemIterator::~ItemIterator()
{

}

ItemNode *ItemIterator::node(void)
{
    return _current;
}

void ItemIterator::reset(void)
{
    _current = nullptr;
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

void ItemIterator::publishOnClick(Point *pt)
{
    publishOnClick(pt->getX(), pt->getY());
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

void ItemIterator::publishOnMouseMotion(int mouse_x, int mouse_y)
{
    Point mousePt (mouse_x, mouse_y);
    MPoint relpt (0, 0);
    for(;next();)
    {
        if(item()->contains(&mousePt))
        {
            relpt.setPoint(mouse_x - item()->getX(), mouse_y - item()->getY());
            item()->setMouseOver(true);
            item()->onMouseMotion(&relpt);
        }
        else
        {
            item()->setMouseOver(false);
        }
    }
}

void ItemIterator::publishOnMouseMotion(Point *pt)
{
    publishOnMouseMotion(pt->getX(), pt->getY());
}

}
}
