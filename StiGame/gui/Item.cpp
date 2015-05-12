#include "Item.h"
#include "SDL.h"
#include <string>
#include "Runtime.h"
#include <iostream>
namespace StiGame
{

namespace Gui
{

const int Item::MAX_WIDTH = 2048;
const int Item::MAX_HEIGHT = 2048;

int Item::_currentId = 0;

int Item::incrementId()
{
    int _id = _currentId;
    _currentId++;
    return _id;
}

Item::Item(void)
{
	style = Runtime::getInstance()->getStyle();
	name = "GuiItem";
    _id = incrementId();
	init();
}

Item::Item(std::string iname)
{
	style = Runtime::getInstance()->getStyle();
	name = iname;
    _id = incrementId();
	init();
}


Item::~Item(void)
{

}

int Item::getId(void)
{
    return _id;
}

void Item::init(void)
{
    minimumSize = MDimension(0 , 0);
    maximumSize = MDimension(MAX_WIDTH, MAX_HEIGHT);
	mouseOver = false;
	handleKey = false;
	focus = false;
	x = 0;
	y = 0;
	width = 0;
	height = 0;
	background = style->getBackground();
	foreground = style->getForeground();
    visible = true;
}

bool Item::isFocus(void)
{
    return focus;
}


void Item::setFocus(bool m_focus)
{
    focus = m_focus;
}

bool Item::isVisible(void)
{
    return visible;
}

void Item::setVisible(bool m_visible)
{
    visible = m_visible;
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

    if(m_width <= maximumSize.getWidth() && m_width >= minimumSize.getWidth())
    {
        width = m_width;
        resized();
    }
}

void Item::setHeight(int m_height)
{
    if(m_height <= maximumSize.getHeight() && m_height >= minimumSize.getHeight())
    {
        height = m_height;
        resized();
    }
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
    bool _resized = false;

    if(m_width <= maximumSize.getWidth() && m_width >= minimumSize.getWidth())
    {
        width = m_width;
        _resized = true;
    }

    if(m_height <= maximumSize.getHeight() && m_height >= minimumSize.getHeight())
    {
        height = m_height;
        _resized = true;
    }

    if(_resized)
    {
        resized();
    }
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

void Item::setMinimumSize(int m_width, int m_height)
{
    minimumSize.setDimension(m_width, m_height);
}

void Item::setMaximumSize(int m_width, int m_height)
{
    maximumSize.setDimension(m_width, m_height);
}

void Item::setFixedSize(int m_width, int m_height)
{
    minimumSize.setDimension(m_width, m_height);
    maximumSize.setDimension(m_width, m_height);
    setDimension(m_width,m_height);
}

Dimension* Item::getMinimumSize()
{
    return &minimumSize;
}

Dimension* Item::getMaximumSize()
{
    return &maximumSize;
}

void Item::prerender(void)
{
    delete render();
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

    void Item_setRectangle(StiGame::Gui::Item *item, int x, int y, int width, int height)
    {
        item->setRectangle(x, y, width, height);
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

    StiGame::Gui::Style* Item_getStyle(StiGame::Gui::Item *item)
    {
        return item->getStyle();
    }

    void Item_setMinimumSize(StiGame::Gui::Item *item, int width, int height)
    {
        item->setMinimumSize(width, height);
    }

    void Item_setMaximumSize(StiGame::Gui::Item *item, int width, int height)
    {
        item->setMaximumSize(width, height);
    }

    void Item_setFixedSize(StiGame::Gui::Item *item, int width, int height)
    {
        item->setFixedSize(width, height);
    }

}
#endif

