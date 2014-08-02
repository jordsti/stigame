
#include "Item.h"
#include "SDL.h"
#include <string>
#include "Runtime.h"

namespace StiGame
{

namespace Gui
{

Item::Item(void)
{
	style = Runtime::getInstance()->getStyle();
	name = "GuiItem";
	init();
}

Item::Item(std::string iname)
{
	style = Runtime::getInstance()->getStyle();
	name = iname;
	init();
}


Item::~Item(void)
{

}

void Item::init(void)
{
	mouseOver = false;
	handleKey = false;
	focus = false;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	background = style->getBackground();
	foreground = style->getForeground();
}

bool Item::isFocus(void)
{
    return focus;
}

void Item::setFocus(bool m_focus)
{
    focus = m_focus;
}

void Item::onClick(Point *relp)
{

}

void Item::onMouseMotion(Point *relp)
{

}

void Item::clear(void)
{
	//clear your buffer here !
}

Style *Item::getStyle(void)
{
	return style;
}

std::string Item::getName(void)
{
	return name;
}

void Item::setBackground(Color *c)
{
	background = c;
}

Color *Item::getBackground(void)
{
	return background;
}

void Item::setForeground(Color *c)
{
	foreground = c;
}

Color *Item::getForeground(void)
{
	return foreground;
}

void Item::setMouseOver(bool m_over)
{
	mouseOver = m_over;
}

bool Item::getMouseOver(void)
{
	return mouseOver;
}

void Item::setWidth(int m_width)
{
    width = m_width;
    resized();
}

void Item::setHeight(int m_height)
{
    height = m_height;
    resized();
}

void Item::resized(void)
{
    //to override
}

void Item::setRectangle(int m_x, int m_y, int m_width, int m_height)
{
    setPoint(m_x, m_y);
    setDimension(m_width, m_height); //for resized call
}

void Item::setDimension(int m_width, int m_height)
{
    width = m_width;
    height = m_height;
    resized();
}

bool Item::isHandleKey(void)
{
    return handleKey;
}

void Item::onKeyUp(SDL_KeyboardEvent *evt)
{

}

void Item::onTextInput(char * text)
{

}

}

}

#ifdef C_WRAPPER

extern "C"
{
    int Item_getWidth(StiGame::Gui::Item *item)
    {
        return item->getWidth();
    }

    int Item_getHeight(StiGame::Gui::Item *item)
    {
        return item->getHeight();
    }

    void Item_setDimension(StiGame::Gui::Item *item, int width, int height)
    {
        item->setDimension(width, height);
    }

    int Item_getX(StiGame::Gui::Item *item)
    {
        return item->getX();
    }

    int Item_getY(StiGame::Gui::Item *item)
    {
        return item->getY();
    }

    void Item_setPoint(StiGame::Gui::Item *item, int x, int y)
    {
        item->setPoint(x, y);
    }

    StiGame::Surface* Item_render(StiGame::Gui::Item *item)
    {
        return item->render();
    }

#endif

}
