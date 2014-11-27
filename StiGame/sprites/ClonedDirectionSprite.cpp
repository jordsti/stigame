#include "ClonedDirectionSprite.h"

namespace StiGame {

ClonedDirectionSprite::ClonedDirectionSprite(DirectionSprite *m_sprite)
{
    sprite = m_sprite;
    _tick = 1;
    width = m_sprite->getWidth();
    height = m_sprite->getHeight();
    direction = SD_IDLE;
}

ClonedDirectionSprite::~ClonedDirectionSprite()
{

}


DirectionSprite* ClonedDirectionSprite::getDirectionSprite(void)
{
    return sprite;
}

void ClonedDirectionSprite::setDirection(SDirection m_direction)
{
    direction = m_direction;
}

SDirection ClonedDirectionSprite::getDirection(void)
{
    return direction;
}

void ClonedDirectionSprite::render(void)
{
    Texture *tex = sprite->getTexture(direction, _tick);
    tex->renderCopy(this);

    //todo maybe tick separately..
    //tick++;
}

void ClonedDirectionSprite::render(SDirection m_direction, int m_frameTick)
{
    sprite->render(m_direction, m_frameTick);
}

void ClonedDirectionSprite::tick()
{
    _tick++;
}


}
