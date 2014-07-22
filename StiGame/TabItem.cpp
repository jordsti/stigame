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
	items.push_back(item);
}

void TabItem::remove(Item *item)
{
	items.remove(item);
}

std::string TabItem::getTabName(void)
{
	return tabName;
}

void TabItem::onClick(Point *relpt)
{
	std::list<Item*>::iterator lit(items.begin()), lend(items.end());
	for(;lit!=lend;++lit)
	{
		MPoint pt = MPoint();
	
		if((*lit)->contains(relpt))
		{
			pt.setX(relpt->getX() - (*lit)->getX());
			pt.setY(relpt->getY() - (*lit)->getY());
			
			(*lit)->onClick(&pt);
		}
	}
}

void TabItem::onMouseMotion(Point *relpt)
{
	std::list<Item*>::iterator lit(items.begin()), lend(items.end());
	for(;lit!=lend;++lit)
	{
		MPoint pt = MPoint();
	
		if((*lit)->contains(relpt))
		{
			pt.setX(relpt->getX() - (*lit)->getX());
			pt.setY(relpt->getY() - (*lit)->getY());
			
			(*lit)->onMouseMotion(&pt);
		}
	}
}

Surface* TabItem::render(void)
{
	Surface *buffer = new Surface(width, height);
	
	std::list<Item*>::iterator lit(items.begin()), lend(items.end());
	
	SDL_Rect src = SDL_Rect();
	SDL_Rect dst = SDL_Rect();
	
	for(;lit!=lend;++lit)
	{
		src.w = (*lit)->getWidth();
		src.h = (*lit)->getHeight();
		dst.w = src.w;
		dst.h = src.h;
		dst.x = (*lit)->getX();
		dst.y = (*lit)->getY();
		
		Surface *ibuf = (*lit)->render();
		
		buffer->blit(ibuf, &src, &dst);
		
		delete ibuf;
	}
	
	return buffer;
}

/* Members
std::string tabName;
std::list<Item*> items;
*/
}

}