#include "PRect.h"
#include "PLine.h"
#include "SDL2_gfxPrimitives.h"
namespace StiGame
{

PRect::PRect(void) : Rectangle()
{
}

void PRect::draw(SDL_Surface *surface, Color *color)
{
	if(!color->isMapped())
	{
		color->mapColor(surface->format);
	}

	//draw four lines
	PLine l1 = PLine();
	l1.set1(x, y);
	l1.set2(x, y + height - 1);

	PLine l2 = PLine();
	l2.set1(x, y);
	l2.set2(x + width - 1, y);

	PLine l3 = PLine();
	l3.set1(x, y + height - 1);
	l3.set2(x + width - 1, y + height - 1);

	PLine l4 = PLine();
	l4.set1(x + width - 1, y);
	l4.set2(x + width - 1, y + height - 1);

	l1.draw(surface, color);
	l2.draw(surface, color);
	l3.draw(surface, color);
	l4.draw(surface, color);

}

void PRect::fill(SDL_Surface *surface, Color *color)
{
	if(!color->isMapped())
	{
		color->mapColor(surface->format);
	}

	SDL_Rect *rect = getSDLRect();
	SDL_FillRect(surface, rect, color->getMap());
	delete rect;
}

void PRect::draw(SDL_Renderer *renderer, Color *color)
{
    rectangleRGBA(renderer, x, y, x + width, y + height, color->getRed(), color->getBlue(), color->getGreen(), color->getAlpha());
}

void PRect::fill(SDL_Renderer *renderer, Color *color)
{
    boxRGBA(renderer, x, y, x + width, y + height, color->getRed(), color->getBlue(), color->getGreen(), color->getAlpha());
}

PRect::~PRect(void)
{
}

}
