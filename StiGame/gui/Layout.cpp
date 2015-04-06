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
    container.add(item);

    childsChanged = true;
}

void Layout::removeChild(Item *item)
{
    container.remove(item);
    childsChanged = true;
}

Item* Layout::getChildAt(int index)
{
    return container.itemAt(index);
}

unsigned int Layout::childsCount()
{
    return container.size();
}

void Layout::onClick(Point *relpt)
{
    mouse.setPoint(relpt);
    ItemIterator it = container.iterator();
    it.publishOnClick(relpt->getX(), relpt->getY());
}

void Layout::onMouseMotion(Point *relpt)
{
    mouse.setPoint(relpt);
    ItemIterator it = container.iterator();
    it.publishOnMouseMotion(relpt->getX(), relpt->getY());
}

void Layout::resized()
{
    setChildsPosition();
}

void Layout::onKeyUp(SDL_KeyboardEvent *evt)
{
    ItemIterator it = container.iterator();
    it.publishOnKeyUp(evt);
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

    for(ItemIterator it = container.iterator(); it.next();)
    {
        Surface *itemBuffer = it.item()->render();
        buffer->blit(itemBuffer, it.item());
        delete itemBuffer;
    }

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
    container.iterator().publishTextInput(text);
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
