#include "HorizontalBoxLayout.h"

namespace StiGame
{
namespace Gui
{

HorizontalBoxLayout::HorizontalBoxLayout()
    : Layout("HorizontalBoxLayout")
{
    //ctor
}

HorizontalBoxLayout::~HorizontalBoxLayout()
{
    //dtor
}

void HorizontalBoxLayout::setChildsPosition()
{
    if(container.size() == 0)
    {
        return;
    }

    int cur_x = 0;
    for(ItemIterator it = container.iterator(); it.next();)
    {
        Item *item = it.item();
        int i_width = item->getMinimumSize()->getWidth();
        int i_height = item->getMinimumSize()->getHeight();
        int i_x = cur_x;
        int i_y = 0;

        item->setDimension(i_width, i_height);

        if(verticalAlign == LVA_Middle)
        {
            i_y = ( height - i_height ) / 2;
        }
        else if(horizontalAlign == LVA_Bottom)
        {
            i_y = height - i_height;
        }

        if(i_y < 0)
        {
            i_y = 0;
        }

        item->setPoint(i_x, i_y);

        cur_x += i_width;
    }

    if(cur_x < width)
    {
        //redisitribute free space
        int free_space = width - cur_x;
        int to_add = free_space / container.size();

        int i=0;
        for(ItemIterator it = container.iterator(); it.next();)
        {
            Item *item = it.item();
            int i_width = item->getWidth();
            i_width += to_add;

            item->setWidth(i_width);

            int i_x = item->getX();

            item->setX(i_x + i * to_add);

            i++;
        }
    }
}

}

}
