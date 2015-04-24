#include "ClonedSprite.h"

namespace StiGame
{


ClonedSprite::ClonedSprite()
{
    //ctor
    baseSprite = 0;
    initialize();
}

ClonedSprite::ClonedSprite(Sprite* m_baseSprite)
{
    initialize();
    baseSprite = m_baseSprite;
    width =  baseSprite->getWidth();
    height = baseSprite->getHeight();
}

void ClonedSprite::initialize(void)
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    _tick = 0;
}

void ClonedSprite::render(void)
{
    if(baseSprite != 0)
    {
        Texture *tx = baseSprite->getTexture(_tick);
        SDL_Rect *src = getSDLRect();
        src->x = 0;
        src->y = 0;

        SDL_Rect *dst = getSDLRect();

        tx->renderCopy(src, dst);

        delete src;
        delete dst;
    }
}

Sprite* ClonedSprite::getBaseSprite(void)
{
    return baseSprite;
}

void ClonedSprite::tick()
{
    _tick++;
}

ClonedSprite::~ClonedSprite()
{
    //dtor
}

}
