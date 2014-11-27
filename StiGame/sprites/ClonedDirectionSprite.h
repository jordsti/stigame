#ifndef CLONEDDIRECTIONSPRITE_H
#define CLONEDDIRECTIONSPRITE_H

#include "DirectionSprite.h"

namespace StiGame {

class ClonedDirectionSprite :
        public IDirectionSprite
{
public:
    ClonedDirectionSprite(DirectionSprite *m_sprite);
    virtual ~ClonedDirectionSprite();

    void setDirection(SDirection m_direction);
    SDirection getDirection(void);

    void render(void);
    void render(SDirection m_direction, int m_frameTick);

    DirectionSprite* getDirectionSprite(void);

    void tick(void);
protected:
    DirectionSprite *sprite;
    int _tick;
    SDirection direction;
};

}

#endif // CLONEDDIRECTIONSPRITE_H
