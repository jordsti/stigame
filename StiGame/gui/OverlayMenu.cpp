#include "OverlayMenu.h"
#include "PLine.h"

namespace StiGame
{

namespace Gui
{


const int OverlayMenu::DEFAULT_OFFSET = 4;
const int OverlayMenu::DEFAULT_TIME_VISIBILITY = 32;

OverlayMenu::OverlayMenu() : Item("Overlay")
{
    //ctor
	position = OP_MIDDLE;
	visible = false;
	_tick = 0;
}

OverlayMenu::~OverlayMenu()
{
    //dtor
}

OverlayPosition OverlayMenu::getPosition(void)
{
	return position;
}

void OverlayMenu::setPosition(OverlayPosition m_position)
{
	position = m_position;
}

void OverlayMenu::fixPosition(int m_width, int m_height)
{
	int n_height = DEFAULT_OFFSET;

    for(ItemIterator it = container.iterator(); it.next();)
	{
        Item *item = it.item();
        if(item->getWidth() == 0 && item->getHeight() == 0)
		{
            delete item->render();
		}

		if(width == 0)
		{
            width = item->getWidth() + DEFAULT_OFFSET*2;
		}

        item->setX( (width - item->getWidth()) / 2 );
        item->setY(n_height);

        n_height += (item->getHeight() + DEFAULT_OFFSET);
	}

	height = n_height;

	switch(position)
	{
		case OP_MIDDLE:
			x = (m_width - width) / 2;
			y = (m_height - height) / 2;
		break;

		case OP_TOP_LEFT_CORNER:
			x = 0;
			y = 0;
		break;

		case OP_TOP_RIGHT_CORNER:
			x = m_width - width;
			y = 0;
		break;

		case OP_BOTTOM_LEFT_CORNER:
			x = 0;
			y = m_height - height;
		break;

		case OP_BOTTOM_RIGHT_CORNER:
			x = m_width - width;
			y = m_height - height;
		break;
	}

}

void OverlayMenu::add(Item *item)
{
    container.add(item);
}

Item* OverlayMenu::getLastItem(void)
{
	int y = -1;
    Item *item = nullptr;

    for(ItemIterator it = container.iterator(); it.next();)
	{
        if(it.item()->getY() > y)
		{
            y = it.item()->getY();
            item = it.item();
		}
	}

	return item;
}

void OverlayMenu::onMouseMotion(Point *relp)
{
    container.iterator().publishOnMouseMotion(relp);
}

void OverlayMenu::onClick(Point *relp)
{
    container.iterator().publishOnClick(relp);
}

bool OverlayMenu::isVisible(void)
{
    return visible;
}

void OverlayMenu::setVisible(bool m_visible)
{
    _tick = 0;
    visible = m_visible;
}

/*void OverlayMenu::handleEvent(KeyEventThrower *src, KeyEventArgs *args)
{
    if(visible && _tick >= DEFAULT_TIME_VISIBILITY)
    {
        if(args->getKeyboardEvent()->keysym.sym == SDLK_ESCAPE && args->getState() == KS_UP)
        {
            visible = false;
        }
    }
}*/

Surface* OverlayMenu::render(void)
{
    _tick++;
    Surface *buffer = new Surface(width, height);
    buffer->fill(background);

    SDL_Rect *src = new SDL_Rect();
    SDL_Rect *dst = new SDL_Rect();
    for(ItemIterator it = container.iterator(); it.next();)
    {
        Item *item = it.item();
        Surface *ibuf = item->render();
        ibuf->updateSDLRect(src);
        ibuf->updateSDLRect(dst, item->getX(), item->getY());

        buffer->blit(ibuf, src, dst);

        delete ibuf;
    }

    delete src;
    delete dst;

	//border
	PLine line = PLine();
	line.set1(0,0);
	line.set2(width - 1, 0);

	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(0,0);
	line.set2(0, height - 1);

	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(width - 1, 0);
	line.set2(width - 1, height - 1);

	line.draw(buffer->getSDLSurface(), foreground);

	line.set1(0, height - 1);
	line.set2(width - 1, height - 1);

	line.draw(buffer->getSDLSurface(), foreground);

    return buffer;
}

}

}
