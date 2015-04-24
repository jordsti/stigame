#ifndef IDIRECTIONSPRITE_H
#define IDIRECTIONSPRITE_H

#include "ISprite.h"

namespace StiGame
{

enum SDirection { SD_UP = 1, SD_DOWN = 2, SD_LEFT = 4, SD_RIGHT = 8, SD_IDLE = 16 }    ;


class IDirectionSprite :
        public ISprite
{
public:
    IDirectionSprite();
    virtual ~IDirectionSprite();

    virtual SDirection getDirection(void) = 0;
    virtual void setDirection(SDirection m_direction) = 0;

    virtual void render(void) = 0;
    /// \brief Render Direction Sprite
    /// \param m_direction Sprite Direction
    /// \param m_frameTick Frame Tick
    virtual void render(SDirection m_direction, int m_frameTick) = 0;

    virtual void tick(void) = 0;
};

}

#endif // IDIRECTIONSPRITE_H
