#include "Layout.h"
namespace StiGame
{

namespace Gui
{

Layout::Layout()
{
    //ctor
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
    return nullptr;
}

unsigned int Layout::childsCount()
{
    return childs.size();
}

void Layout::onClick(Point *relpt)
{

}

void Layout::onMouseMotion(Point *relpt)
{

}

void Layout::resized()
{
    setChildsPosition();
}

Surface *Layout::render()
{
    //todo
    return nullptr;
}

}

}
