#include "Pixel.h"

namespace StiGame
{

Pixel::Pixel()
{
	init();
}

Pixel::Pixel(Uint32 m_pixel, SDL_PixelFormat *m_format)
{
	init();
	pixel = m_pixel;
	format = m_format;
	getRGBA();
}

Pixel::~Pixel()
{

}

void Pixel::init(void)
{
	pixel = 0;
	red = 0;
	green = 0;
	blue = 0;
	alpha = 0;
	format = 0;
}

Uint8 Pixel::getRed(void)
{
	return red;
}

Uint8 Pixel::getGreen(void)
{
	return green;
}

Uint8 Pixel::getBlue(void)
{
	return blue;
}

Uint8 Pixel::getAlpha(void)
{
	return alpha;
}

SDL_PixelFormat* Pixel::getFormat(void)
{
	return format;
}

SDL_Color Pixel::getSDLColor(void)
{
	SDL_Color color = SDL_Color();
	color.r = red;
	color.g = green;
	color.b = blue;
	color.a = alpha;
	return color;
}

Color Pixel::getColor(void)
{
	return Color(red, green, blue, alpha);
}

Uint32 Pixel::getPixel(void)
{
	return pixel;
}

void Pixel::getRGBA(void)
{
	SDL_GetRGBA(pixel, format, &red, &green, &blue, &alpha);
}

}
