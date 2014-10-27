
#include "Primitive.h"
#include "SDL.h"
#include "Color.h"
#include "Surface.h"
namespace StiGame
{
Primitive::Primitive(void)
{
}


Primitive::~Primitive(void)
{
}


void Primitive::draw(Surface *surface, Color *color)
{
	draw(surface->getSDLSurface(), color);
}

void Primitive::fill(Surface *surface, Color *color)
{
	fill(surface->getSDLSurface(), color);
}

void Primitive::setPixel(SDL_Surface *surface, int px, int py, Uint32 pixel)
{
	Uint8 *target_pixel = (Uint8 *)surface->pixels + py * surface->pitch + px * 4;
	*(Uint32 *)target_pixel = pixel;
}

}
