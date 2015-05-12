#include "Rectangle.h"

namespace StiGame
{

Rectangle::Rectangle(void) :
    MPoint(),
    MDimension()
{

}

Rectangle::Rectangle(int m_x, int m_y, int m_width, int m_height) :
    MPoint(m_x, m_y),
    MDimension(m_width, m_height)
{

}

Point* Rectangle::getLeftTop(void)
{
    return new Point(x, y);
}
Point* Rectangle::getLeftBottom(void)
{
    return new Point(x, y + height);
}
Point* Rectangle::getRightTop(void)
{
    return new Point(x + width, y);
}
Point* Rectangle::getRightBottom(void)
{
    return new Point(x + width, y + height);
}


void Rectangle::fromSDLRect(SDL_Rect *rect)
{
	x = rect->x;
	y = rect->y;
	width = rect->w;
	height = rect->h;
}

SDL_Rect *Rectangle::getSDLRect(void)
{
	SDL_Rect *rect = new SDL_Rect();
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;

	return rect;
}

bool Rectangle::equals(int r_x, int r_y, int r_w, int r_h)
{
	return (
		x == r_x && y == r_y &&
		width == r_w && height == r_h
	);
}

bool Rectangle::equals(Rectangle *rect)
{
	return (
		x == rect->getX() && y == rect->getY() &&
		width == rect->getWidth() && height == rect->getHeight()
	);
}

bool Rectangle::equals(SDL_Rect *rect)
{
	return (
		x == rect->x && y == rect->y &&
		width == rect->w && height == rect->h
	);
}

bool Rectangle::contains(Point *pt)
{
	return contains(pt->getX(), pt->getY());
}

void Rectangle::updateSDLRect(SDL_Rect *rect)
{
    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
}

bool Rectangle::contains(int p_x, int p_y)
{
	return ( ( p_x >= x && p_x <= x + width ) && ( p_y >= y && p_y <= y + height ) );
}

bool Rectangle::intersect(Rectangle *rect)
{
    bool xlap = Rectangle::valueInRange(x, rect->getX(), rect->getX() + rect->getWidth()) ||
                Rectangle::valueInRange(rect->getX(), x, x + width);
    bool ylap = Rectangle::valueInRange(y, rect->getY(), rect->getY() + rect->getHeight()) ||
                Rectangle::valueInRange(rect->getY(), y, y + height);

    return xlap && ylap;

}

bool Rectangle::valueInRange(int value, int min, int max)
{
    return (value >= min) || (value <= max);
}

void Rectangle::Copy(SDL_Rect *src, SDL_Rect *copy)
{
	copy->x = src->x;
	copy->y = src->y;
	copy->w = src->w;
	copy->h = src->h;
}

void Rectangle::Copy(Rectangle *src, Rectangle *copy)
{
	copy->setX(src->getX());
	copy->setY(src->getY());
	copy->setWidth(src->getWidth());
	copy->setHeight(src->getHeight());
}

void Rectangle::Copy(Rectangle *src, SDL_Rect *copy)
{
    copy->x = src->getX();
    copy->y = src->getY();
    copy->w = src->getWidth();
    copy->h = src->getHeight();
}

void Rectangle::Copy(SDL_Rect *src, Rectangle *copy)
{
    copy->setDimension(src->w, src->h);
    copy->setPoint(src->x, src->y);
}

void Rectangle::setRectangle(int m_x, int m_y, int m_width, int m_height)
{
    x = m_x;
    y = m_y;
    width = m_width;
    height = m_height;
}

RectangleF Rectangle::toRectangleF(void)
{
    RectangleF rect (x, y, width, height);
    return rect;
}


Rectangle::~Rectangle(void)
{
}


}
