#ifndef CLONEDSPRITE_H
#define CLONEDSPRITE_H

#include "Sprite.h"

namespace StiGame
{


class ClonedSprite :
    public ISprite
{
    public:
        ClonedSprite(void);
        ClonedSprite(Sprite* m_baseSprite);
        virtual ~ClonedSprite();
        void render(void);
        Sprite* getBaseSprite(void);
    protected:
        void initialize(void);
    private:
        Sprite* baseSprite;
};

}

#endif // CLONEDSPRITE_H
