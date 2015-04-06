#include "TabItem.h"

namespace StiGame
{

namespace Gui
{

TabItem::TabItem() : Item("TabItem")
{
	tabName = "Untitled";
}

TabItem::TabItem(std::string m_tabName) : Item("TabItem")
{
	tabName = m_tabName;
}

TabItem::~TabItem()
{

}

void TabItem::add(Item *item)
{
    container.add(item);
}

void TabItem::remove(Item *item)
{
    container.remove(item);
}

std::string TabItem::getTabName(void)
{
	return tabName;
}

void TabItem::onClick(Point *relpt)
{
    container.iterator().publishOnClick(relpt);
}

void TabItem::onMouseMotion(Point *relpt)
{
    container.iterator().publishOnMouseMotion(relpt);
}

void TabItem::setMouseOver(bool m_mouseOver)
{
    if(!m_mouseOver)
    {
        for(ItemIterator it = container.iterator(); it.next();)
        {
            it.item()->setMouseOver(false);
        }
    }
}

Surface* TabItem::render(void)
{
	Surface *buffer = new Surface(width, height);
	buffer->fill(background);
	SDL_Rect src = SDL_Rect();
	SDL_Rect dst = SDL_Rect();

    for(ItemIterator it = container.iterator(); it.next();)
	{
        Item *item = it.item();
        src.w = item->getWidth();
        src.h = item->getHeight();
		dst.w = src.w;
		dst.h = src.h;
        dst.x = item->getX();
        dst.y = item->getY();

        Surface *ibuf = item->render();

		buffer->blit(ibuf, &src, &dst);

		delete ibuf;
	}

	return buffer;
}


}

}
