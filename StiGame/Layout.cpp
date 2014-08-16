#include "Layout.h"
#include "PRect.h"

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
    verticalAlign = LVA_Middle;
    horizontalAlign = LHA_Center;
    childsChanged = false;
    drawBorder = true;
}

Layout::~Layout()
{
    //dtor
}

void Layout::setDrawBorder(bool m_drawBorder)
{
    drawBorder = m_drawBorder;
}


void Layout::addChild(Item *item)
{
    childs.push_back(item);
    childsChanged = true;

}

void Layout::removeChild(Item *item)
{
    childs.remove(item);
    childsChanged = true;
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
            (*lit)->setMouseOver(true);
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
        if((*lit)->isHandleKey())
        {
            (*lit)->onKeyUp(evt);
        }
    }
}

Surface *Layout::render()
{
    //todo
    if(childsChanged)
    {
        setChildsPosition();
        childsChanged = false;
    }

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

    if(drawBorder)
    {
        PRect border = PRect();
        border.setDimension(width, height);

        buffer->draw(&border, foreground);
    }


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

void Layout::setVerticalAlign(LayoutVerticalAlign m_verticalAlign)
{
    verticalAlign = m_verticalAlign;
}

void Layout::setHorizontalAlign(LayoutHorizontalAlign m_horizontalAlign)
{
    horizontalAlign = m_horizontalAlign;
}

LayoutVerticalAlign Layout::getVerticalAlign(void)
{
    return verticalAlign;
}

LayoutHorizontalAlign Layout::getHorizontalAlign(void)
{
    return horizontalAlign;
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

    int Layout_getVerticalAlign(StiGame::Gui::Layout *layout)
    {
        return layout->getVerticalAlign();
    }

    int Layout_getHorizontalAlign(StiGame::Gui::Layout *layout)
    {
        return layout->getHorizontalAlign();
    }

    void Layout_setVerticalAlign(StiGame::Gui::Layout *layout, int align)
    {
        layout->setVerticalAlign(static_cast<StiGame::Gui::LayoutVerticalAlign>(align));
    }

    void Layout_setHorizontalAlign(StiGame::Gui::Layout *layout, int align)
    {
        layout->setHorizontalAlign(static_cast<StiGame::Gui::LayoutHorizontalAlign>(align));
    }

}
#endif // C_WRAPPER
