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
    //todo
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
