#include "Point.h"

namespace StiGame
{

Point::Point(void)
{
	x = 0;
	y = 0;
}

Point::Point(PointStruct *pt)
{
    x = pt->x;
    y = pt->y;
}

Point::Point(int m_x, int m_y)
{
	x = m_x;
	y = m_y;
}

Point::~Point(void)
{
}

int Point::getX(void)
{
	return x;
}


int Point::getY(void)
{
	return y;
}


PointStruct* Point::getPointStruct(void)
{
    PointStruct *pt = new PointStruct();
    pt->x = x;
    pt->y = y;

    return pt;
}

SDL_Point* Point::getSDLPoint(void)
{
    SDL_Point *pt = new SDL_Point();
    updateSDLPoint(pt);
    return pt;
}
void Point::updateSDLPoint(SDL_Point *sdlPt)
{
    sdlPt->x = x;
    sdlPt->y = y;
}

bool Point::equals(int m_x, int m_y)
{
    return (m_x == x && m_y == y);
}

bool Point::equals(Point *pt)
{
    return equals(pt->getX(), pt->getY());
}

bool Point::equals(SDL_Point *pt)
{
	return (
		x == pt->x &&
		y == pt->y
	);
}

}
