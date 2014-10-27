#include "HighlightItem.h"

namespace StiGame {

namespace Gui
{

HighlightItem::HighlightItem() : Item()
{
    //ctor
    highlightForeground = style->getHighlightForeground();
    highlightBackground = style->getHighlightBackground();
}

HighlightItem::HighlightItem(std::string i_name) : Item(i_name)
{
    highlightForeground = style->getHighlightForeground();
    highlightBackground = style->getHighlightBackground();
}


void HighlightItem::setHighlightBackground(Color *color)
{
    highlightBackground = color;
}

void HighlightItem::setHighlightForeground(Color *color)
{
    highlightForeground = color;
}

Color *HighlightItem::getHighlightBackground(void)
{
    return highlightBackground;
}

Color *HighlightItem::getHighlightForeground(void)
{
    return highlightForeground;
}

HighlightItem::~HighlightItem()
{
    //dtor
}

}

}
