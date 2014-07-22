
#include "PLine.h"
#include <cmath>
#include <algorithm>
#include "Surface.h"
#include "SDL2_gfxPrimitives.h"
namespace StiGame
{

PLine::PLine(void)
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	size = 1;
}


PLine::~PLine(void)
{
}

void PLine::setSize(int m_size)
{
	size = m_size;
}

int PLine::getSize(void)
{
	return size;
}

void PLine::fill(SDL_Surface* surface, Color *color)
{
	if(y1 == y2)
	{
		//horizontal line
		fillHLine(surface,color);
	}
	else if(x1 == x2)
	{
		//vertical line
		fillVLine(surface,color);
	}
	else
	{
		//angle
		fillTanLine(surface,color);
	}
}

void PLine::switchPoints(void)
{
	int t_x = x1;
	int t_y = y1;

	x1 = x2;
	y1 = y2;
	x2 = t_x;
	y2 = t_y;
}

void PLine::fillHLine(SDL_Surface *surface, Color *color)
{
	int dx = 0;
	int sx = std::min(x1,x2);
	if(sx == x1)
	{
		dx = x2 - x1;
	}
	else
	{
		dx = x1 - x2;
	}
	Surface *buffer = new Surface(surface);
	SDL_Rect *lrct = new SDL_Rect();
	lrct->x = sx;
	lrct->y = y1;
	lrct->w = dx;
	lrct->h = size;

	buffer->setReleaseSurface(false);
	buffer->fillRect(lrct, color);

	delete lrct;
	delete buffer;
}

void PLine::fillVLine(SDL_Surface *surface, Color *color)
{
	int dy = 0;
	int sy = std::min(y1,y2);
	if(sy == y1)
	{
		dy = y2 - y1;
	}
	else
	{
		dy = y1 - y2;
	}
	Surface *buffer = new Surface(surface);
	SDL_Rect *lrct = new SDL_Rect();
	lrct->x = x1;
	lrct->y = sy;
	lrct->w = size;
	lrct->h = dy;

	buffer->setReleaseSurface(false);
	buffer->fillRect(lrct, color);

	delete lrct;
	delete buffer;

}

void PLine::fillTanLine(SDL_Surface *surface, Color *color)
{
	//pt1 -> pt2
	if(!color->isMapped())
	{
		color->mapColor(surface->format);
	}

	int dy = std::abs(y2 - y1);
	int dx = std::abs(x2 - x1);
	int max_d = std::max(dy, dx);

	//draw by y
	if(max_d == dy)
	{
		double ddy = (double)(y2 - y1);
		double ddx = (double)(x2 - x1);

		if(ddy < 0)
		{
			switchPoints();
		}

		double angle = std::atan( ddx / ddy );
		//double dx1 = (double)x1;

		for(double ny=0; ny<=dy; ny+=1.0)
		{
			double x = (double)x1 + ny*std::tan(angle);
			int ix = (int)std::floor(x);

			setPixel(surface, ix, ny + y1, color->getMap());
		}
	}
	//draw by x
	else
	{
		double ddy = (double)(y2 - y1);
		double ddx = (double)(x2 - x1);

		if(ddx < 0)
		{
			switchPoints();
		}


		double angle = std::atan( ddy / ddx );
		//double dy1 = (double)y1;

		for(double nx=0; nx<=dx; nx+=1.0)
		{
			double y = (double)y1 + nx*std::tan(angle);
			int iy = (int)std::floor(y);

			setPixel(surface, nx + x1, iy, color->getMap());
		}
	}
}


void PLine::draw(SDL_Surface* surface, Color *color)
{
	//sorry bro, just fillin
	fill(surface, color);
}

void PLine::set1(int m_x, int m_y)
{
	x1 = m_x;
	y1 = m_y;
}

void PLine::set2(int m_x, int m_y)
{
	x2 = m_x;
	y2 = m_y;
}

int PLine::getX1(void)
{
	return x1;
}

int PLine::getX2(void)
{
	return x2;
}


int PLine::getY1(void)
{
	return y1;
}


int PLine::getY2(void)
{
	return y2;
}

void PLine::draw(SDL_Renderer *renderer, Color *color)
{
    lineRGBA(renderer, x1, y2, x2, y2, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
}

void PLine::fill(SDL_Renderer *renderer, Color *color)
{
    lineRGBA(renderer, x1, y2, x2, y2, color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
}


}
