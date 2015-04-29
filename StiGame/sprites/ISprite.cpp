#include <sstream>
#include "ISprite.h"

namespace StiGame
{

ISprite::ISprite()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

ISprite::~ISprite()
{
    //dtor
}

void ISprite::move(int dx, int dy)
{
    x += dx;
    y += dy;
}

/*void ISprite::move(Math::Vector *d_vector)
{
    x += d_vector->getX();
    y += d_vector->getY();
}*/

SDL_Rect* ISprite::getSDLRect(void)
{
    SDL_Rect *rect = new SDL_Rect();

    rect->w = width;
    rect->h = height;
    rect->x = x;
    rect->y = y;

    return rect;
}

std::string ISprite::toString(int i)
{
    std::stringstream ss;
    ss << i;
    return ss.str();
}

Point* ISprite::getCenter()
{
    Point *pt = new Point(x + (width/2), y + (height/2));
    return pt;
}

}
