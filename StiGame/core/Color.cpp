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

bool Color::equals(Color *color)
{
    return (color->getRed() == red && color->getGreen() == green && color->getBlue() == blue && color->getAlpha() == alpha);
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
        //map = SDL_MapRGB(format, red, green, blue);
        map = SDL_MapRGBA(format, red, green, blue, alpha);
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
	color.g = green;
	color.b = blue;
	return color;
}

void Color::setRGBA(Uint8 m_r, Uint8 m_g, Uint8 m_b, Uint8 m_a)
{
    if(red != m_r || green != m_g || blue != m_b || alpha != m_a)
    {
        red = m_r;
        green = m_g;
        blue = m_b;
        alpha = m_a;
        mapped = false;
    }
}

void Color::setRGB(Uint8 m_r, Uint8 m_g, Uint8 m_b)
{
    if(red != m_r || green != m_g || blue != m_b)
    {
        red = m_r;
        green = m_g;
        blue = m_b;
        mapped = false;
    }
}

}

#ifdef C_WRAPPER

extern "C"
{
    StiGame::Color* Color_new()
    {
        return new StiGame::Color();
    }

    Uint8 Color_getRed(StiGame::Color *color)
    {
        return color->getRed();
    }
    Uint8 Color_getGreen(StiGame::Color *color)
    {
        return color->getGreen();
    }

    Uint8 Color_getBlue(StiGame::Color *color)
    {
        return color->getBlue();
    }

    Uint8 Color_getAlpha(StiGame::Color *color)
    {
        return color->getAlpha();
    }

    void Color_setRGBA(StiGame::Color *color, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    {
        color->setRGBA(r, g, b, a);
    }
}

#endif // C_WRAPPER
