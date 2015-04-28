#include "ExpandItem.h"

namespace StiGame
{

namespace Gui
{

namespace Effects
{

ExpandItem::ExpandItem(Item *m_item, BaseGameState *m_state, float percentPerFrame, Dimension startingSize) :
    ItemEffect(m_item, m_state)
{
    speed = percentPerFrame;
    currentSize.setDimension(&startingSize);
}

ExpandItem::~ExpandItem()
{

}

Dimension* ExpandItem::getCurrentSize(void)
{
    return &currentSize;
}

int ExpandItem::getSpeed(void)
{
    return speed;
}

Surface* ExpandItem::renderWithEffect(void)
{
    int ratio_x = item->getWidth() / width;
    int ratio_y = item->getHeight() / height;
    return effectBuffer->shrink(ratio_x, ratio_y);
}

void ExpandItem::tickEffect(void)
{
    if(currentSize.getWidth() < item->getWidth())
    {
        currentSize.setWidth(currentSize.getWidth() + speed*((float)item->getWidth()));
    }

    if(currentSize.getHeight() < item->getHeight())
    {
        currentSize.setHeight(currentSize.getHeight() + speed*((float)item->getHeight()));
    }

    if(currentSize.getWidth() > item->getWidth())
    {
        currentSize.setWidth(item->getWidth());
    }

    if(currentSize.getHeight() > item->getHeight())
    {
        currentSize.setHeight(item->getHeight());
    }

    //computing point
    x = item->getX() + (item->getWidth() - currentSize.getWidth())/2;
    y = item->getY() + (item->getHeight() - currentSize.getHeight())/2;
    width = currentSize.getWidth();
    height = currentSize.getHeight();
}

}

}

}
