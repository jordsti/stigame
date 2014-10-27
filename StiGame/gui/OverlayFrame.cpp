#include "OverlayFrame.h"

namespace StiGame
{

namespace Gui
{

OverlayFrame::OverlayFrame()
	: Item("OverlayFrame")
{
	visible = false;
}

OverlayFrame::~OverlayFrame()
{

}

void OverlayFrame::onMouseMotion(Point *relp)
{
	std::list<Item*>::iterator lit(items.begin()), lend(items.end());
	for(;lit!=lend;++lit)
	{
		if((*lit)->contains(relp))
		{
			Point relpt = Point(relp->getX() - (*lit)->getX(), relp->getY() - (*lit)->getY());
			(*lit)->onMouseMotion(&relpt);
		}
	}
}

void OverlayFrame::onClick(Point *relp)
{
	std::list<Item*>::iterator lit(items.begin()), lend(items.end());
	for(;lit!=lend;++lit)
	{
		if((*lit)->contains(relp))
		{
			Point relpt = Point(relp->getX() - (*lit)->getX(), relp->getY() - (*lit)->getY());
			(*lit)->onClick(&relpt);
		}
	}
}

void OverlayFrame::tick(void)
{

}


Surface* OverlayFrame::render(void)
{
    tick();

	Surface *buffer = new Surface(width, height);
	buffer->fill(background);

	SDL_Rect *src = new SDL_Rect();
	SDL_Rect *dst = new SDL_Rect();

	std::list<Item*>::iterator lit(items.begin()), lend(items.end());
	for(;lit!=lend;++lit)
	{
	    Item *item = (*lit);

		Surface *ibuf = item->render();

		ibuf->updateSDLRect(src);
		ibuf->updateSDLRect(dst, (*lit));

		buffer->blit(ibuf, src, dst);

		delete ibuf;
	}

	delete src;
	delete dst;

	return buffer;
}

bool OverlayFrame::isVisible(void)
{
	return visible;
}

void OverlayFrame::setVisible(bool m_visible)
{
	visible = m_visible;
}

void OverlayFrame::add(Item *item)
{
	items.push_back(item);
}



}

}
