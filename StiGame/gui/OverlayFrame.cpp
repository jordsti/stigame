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
    container.iterator().publishOnMouseMotion(relp->getX(), relp->getY());
}

void OverlayFrame::onClick(Point *relp)
{
    container.iterator().publishOnClick(relp->getX(), relp->getY());
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

    for(ItemIterator it = container.iterator(); it.next();)
	{
        Item *item = it.item();

		Surface *ibuf = item->render();

		ibuf->updateSDLRect(src);
        ibuf->updateSDLRect(dst, item);

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
    container.add(item);
}



}

}
