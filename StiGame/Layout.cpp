#include "Layout.h"
namespace StiGame
{

namespace Gui
{

Layout::Layout(std::string name)
    : Item(name)
{
    //ctor
    mouse = MPoint();
    handleKey = true;
}

Layout::~Layout()
{
    //dtor
}


void Layout::addChild(Item *item)
{
    childs.push_back(item);
    setChildsPosition();
}

void Layout::removeChild(Item *item)
{
    childs.remove(item);
    setChildsPosition();
}

Item* Layout::getChildAt(int index)
{

    if(index < childsCount())
    {
        int i=0;
        std::list<Item*>::iterator lit (childs.begin()), lend (childs.end());

        Item *item = nullptr;

        for(;lit!=lend;++lit)
        {
            if(i == index)
            {
                item = (*lit);
                break;
            }
            i++;
        }

        return item;
    }
    else
    {
        return nullptr;
    }
}

unsigned int Layout::childsCount()
{
    return childs.size();
}

void Layout::onClick(Point *relpt)
{
    mouse.setPoint(relpt);

    std::list<Item*>::iterator lit (childs.begin()), lend (childs.end());
    for(;lit!=lend;++lit)
    {
        MPoint pt = MPoint();
        if((*lit)->contains(relpt))
        {
            pt.setX(relpt->getX() - (*lit)->getX());
            pt.setY(relpt->getY() - (*lit)->getY());
            (*lit)->onClick(&pt);
        }
        else
        {
            (*lit)->setFocus(false);
            (*lit)->setMouseOver(false);
        }
    }
}

void Layout::onMouseMotion(Point *relpt)
{
    mouse.setPoint(relpt);


    std::list<Item*>::iterator lit (childs.begin()), lend (childs.end());
    for(;lit!=lend;++lit)
    {
        MPoint pt = MPoint();
        if((*lit)->contains(relpt))
        {
            pt.setX(relpt->getX() - (*lit)->getX());
            pt.setY(relpt->getY() - (*lit)->getY());
            (*lit)->onMouseMotion(&pt);
        }
        else
        {
            (*lit)->setMouseOver(false);
        }
    }
}

void Layout::resized()
{
    setChildsPosition();
}

void Layout::onKeyUp(SDL_KeyboardEvent *evt)
{
    std::list<Item*>::iterator lit(childs.begin()), lend(childs.end());
    for(;lit!=lend;++lit)
    {
        if((*lit)->contains(&mouse))
        {
            (*lit)->onKeyUp(evt);
        }
    }
}

Surface *Layout::render()
{
    //todo
    Surface *buffer = new Surface(width, height);
    buffer->fill(background);


    std::list<Item*>::iterator lit(childs.begin()), lend(childs.end());

    SDL_Rect *dst = new SDL_Rect();
    SDL_Rect *src = new SDL_Rect();

    for(;lit!=lend;++lit)
    {
        Surface *item = (*lit)->render();

        item->updateSDLRect(src);
        src->x = 0;
        src->y = 0;
        item->updateSDLRect(dst, (*lit)->getX(), (*lit)->getY());

        buffer->blit(item, src, dst);
    }

    delete src;
    delete dst;


    return buffer;
}

void Layout::onTextInput(char *text)
{
    std::list<Item*>::iterator lit(childs.begin()), lend(childs.end());
    for(;lit!=lend;++lit)
    {
        if((*lit)->isHandleKey() && (*lit)->isFocus())
        {
            (*lit)->onTextInput(text);
        }
    }
}

}

}

#ifdef C_WRAPPER
extern "C"
{
    void Layout_addChild(StiGame::Gui::Layout *layout, StiGame::Gui::Item *item)
    {
        layout->addChild(item);
    }

    void Layout_removeChild(StiGame::Gui::Layout *layout, StiGame::Gui::Item *item)
    {
        layout->removeChild(item);
    }

    StiGame::Gui::Item* Layout_getChildAt(StiGame::Gui::Layout *layout, int index)
    {
        return layout->getChildAt(index);
    }

    unsigned int Layout_childsCount(StiGame::Gui::Layout *layout)
    {
        return layout->childsCount();
    }

}
#endif // C_WRAPPER
