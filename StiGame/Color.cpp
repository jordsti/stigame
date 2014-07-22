#include "Color.h"

namespace StiGame
{

Color::Color(void)
{
	red = 0;
	green = 0;
	blue = 0;
	mapped = false;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b)
{
	red = r;
	green = g;
	blue = b;
	alpha = 255;
	mapped = false;
}

Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
	mapped = false;
}



Color::~Color(void)
{
}

bool Color::isMapped(void)
{
	return mapped;
}

Uint8 Color::getRed(void)
{
    return red;
}

Uint8 Color::getBlue(void)
{
    return blue;
}

Uint8 Color::getGreen(void)
{
    return green;
}

Uint8 Color::getAlpha(void)
{
    return alpha;
}


void Color::mapColor(SDL_PixelFormat *format)
{
	if(!mapped)
	{
		map = SDL_MapRGB(format, red, blue, green);
		mapped = true;
	}
}

Uint32 Color::getMap(void)
{
	return map;
}

SDL_Color Color::getSDLColor(void)
{
	SDL_Color color = SDL_Color();
	color.r = red;
	color.b = blue;
	color.g = green;
	return color;
}

}
