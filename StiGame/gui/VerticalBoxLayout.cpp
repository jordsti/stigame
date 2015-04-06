#include "VerticalBoxLayout.h"

namespace StiGame
{

namespace Gui
{

VerticalBoxLayout::VerticalBoxLayout() : Layout("VerticalBoxLayout")
{
    //ctor
}

VerticalBoxLayout::~VerticalBoxLayout()
{
    //dtor
}

void VerticalBoxLayout::setChildsPosition()
{
    if(container.size() == 0)
    {
        return;
    }

    int cur_y = 0;
    for(ItemIterator it = container.iterator(); it.next();)
    {
        Item *item = it.item();
        int i_width = item->getMinimumSize()->getWidth();
        int i_height = item->getMinimumSize()->getHeight();
        int i_x = 0;
        int i_y = cur_y;

        item->setDimension(i_width, i_height);

        if(horizontalAlign == LHA_Center)
        {
            i_x = ( width - i_width ) / 2;
        }
        else if(horizontalAlign == LHA_Right)
        {
            i_x = width - i_width;
        }

        if(i_x < 0)
        {
            i_x = 0;
        }

        item->setPoint(i_x, i_y);

        cur_y += i_height;
    }

    if(cur_y < height)
    {
        //redisitribute free space
        int free_space = height - cur_y;
        int to_add = free_space / container.size();
        int i=0;
        for(ItemIterator it = container.iterator(); it.next();)
        {
            Item *item = it.item();
            int i_height = item->getHeight();
            i_height += to_add;

            item->setHeight(i_height);

            int i_y = item->getY();

            item->setY(i_y + i * to_add);

            i++;
        }
    }
}

}

}

#ifdef C_WRAPPER
extern "C"
{
    StiGame::Gui::VerticalBoxLayout* VerticalBoxLayout_new()
    {
        return new StiGame::Gui::VerticalBoxLayout();
    }

}
#endif // C_WRAPPER
