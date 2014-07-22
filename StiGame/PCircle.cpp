
#include "PCircle.h"
#include "SDL.h"
#include "Color.h"
#include "Primitive.h"
#include "math.h"
#include "SDL2_gfxPrimitives.h"

namespace StiGame
{

PCircle::PCircle(void) : Primitive()
{
	x = 0;
	y = 0;
	radius = 0;
}

PCircle::PCircle(int m_x, int m_y): Primitive()
{
	x = m_x;
	y = m_y;
	radius = 0;
}

PCircle::PCircle(int m_x, int m_y, double m_radius): Primitive()
{
	x = m_x;
	y = m_y;
	radius = m_radius;
}


void PCircle::draw(SDL_Surface *surface, Color *color)
{
	if(!color->isMapped())
	{
		color->mapColor(surface->format);
	}

	double err = (double)-radius;
	double x0 = (double)radius - 0.5;
	double y0 = (double)0.5;
	double cx = x - 0.5;
	double cy = y - 0.5;

	while(x0 >= y0)
	{
		setPixel(surface, (int)(cx + x0), (int)(cy + y0), color->getMap());
		setPixel(surface, (int)(cx + y0), (int)(cy + x0), color->getMap());

		if(x0 != 0)
		{
			setPixel(surface, (int)(cx - x0), (int)(cy + y0), color->getMap());
			setPixel(surface, (int)(cx + y0), (int)(cy - x0), color->getMap());
		}

		if(y0 != 0)
		{
			setPixel(surface, (int)(cx + x0), (int)(cy - y0), color->getMap());
			setPixel(surface, (int)(cx - y0), (int)(cy + x0), color->getMap());
		}

		if(x0 != 0 && y0 != 0)
		{
			setPixel(surface, (int)(cx - x0), (int)(cy - y0), color->getMap());
			setPixel(surface, (int)(cx - y0), (int)(cy - x0), color->getMap());

		}

		err += y0;
		++y0;
		err += y0;

		if(err >= 0)
		{
			--x0;
			err -= x0;
			err -= x0;
		}
	}
}

void PCircle::fill(SDL_Surface *surface, Color *color)
{
	if(!color->isMapped())
	{
		color->mapColor(surface->format);
	}

	static const int BPP = 4;

	for(double dy = 1; dy <= radius; dy += 1.0)
	{
		double dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
		int tx = x - dx;

		Uint8 *target_pixel_a = (Uint8 *)surface->pixels + ((int)(y + radius - dy)) * surface->pitch + tx * BPP;
		Uint8 *target_pixel_b = (Uint8 *)surface->pixels + ((int)(y - radius + dy)) * surface->pitch + tx * BPP;

		for(; tx <= x + dx; tx++)
		{
			*(Uint32 *)target_pixel_a = color->getMap();
			*(Uint32 *)target_pixel_b = color->getMap();
			target_pixel_a += BPP;
			target_pixel_b += BPP;
		}

	}
}


int PCircle::getX(void)
{
	return x;
}

void PCircle::setX(int m_x)
{
	x = m_x;
}

int PCircle::getY(void)
{
	return y;
}

void PCircle::setY(int m_y)
{
	y = m_y;
}

void PCircle::setMiddle(int m_x, int m_y)
{
	setX(m_x);
	setY(m_y);
}

double PCircle::getRadius(void)
{
	return radius;
}

void PCircle::setRadius(double m_radius)
{
	radius = m_radius;
}


void PCircle::draw(SDL_Renderer *renderer, Color *color)
{
    circleRGBA(renderer, x, y, radius, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
}

void PCircle::fill(SDL_Renderer *renderer, Color *color)
{
    filledCircleRGBA(renderer, x, y, radius, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
}


PCircle::~PCircle(void)
{
}

}
