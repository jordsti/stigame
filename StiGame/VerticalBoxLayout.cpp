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
    if(childs.size() == 0)
    {
        return;
    }

    std::list<Item*>::iterator lit(childs.begin()), lend(childs.end());
    int cur_y = 0;
    for(;lit!=lend;++lit)
    {
        int i_width = (*lit)->getMinimumSize()->getWidth();
        int i_height = (*lit)->getMinimumSize()->getHeight();
        int i_x = 0;
        int i_y = cur_y;

        (*lit)->setDimension(i_width, i_height);

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

        (*lit)->setPoint(i_x, i_y);

        cur_y += i_height;
    }

    if(cur_y < height)
    {
        //redisitribute free space
        int free_space = height - cur_y;
        int to_add = free_space / childs.size();

        lit = childs.begin();
        lend = childs.end();
        int i=0;
        for(;lit!=lend;++lit)
        {
            int i_height = (*lit)->getHeight();
            i_height += to_add;

            (*lit)->setHeight(i_height);

            int i_y = (*lit)->getY();

            (*lit)->setY(i_y + i * to_add);

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
