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
    if(childs.size() == 0)
    {
        return;
    }

    std::list<Item*>::iterator lit(childs.begin()), lend(childs.end());
    int cur_x = 0;
    for(;lit!=lend;++lit)
    {
        int i_width = (*lit)->getMinimumSize()->getWidth();
        int i_height = (*lit)->getMinimumSize()->getHeight();
        int i_x = cur_x;
        int i_y = 0;

        (*lit)->setDimension(i_width, i_height);

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

        (*lit)->setPoint(i_x, i_y);

        cur_x += i_width;
    }

    if(cur_x < width)
    {
        //redisitribute free space
        int free_space = width - cur_x;
        int to_add = free_space / childs.size();

        lit = childs.begin();
        lend = childs.end();
        int i=0;
        for(;lit!=lend;++lit)
        {
            int i_width = (*lit)->getWidth();
            i_width += to_add;

            (*lit)->setWidth(i_width);

            int i_x = (*lit)->getX();

            (*lit)->setX(i_x + i * to_add);

            i++;
        }
    }
}

}

}
