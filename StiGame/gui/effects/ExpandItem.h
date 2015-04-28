#ifndef EXPANDITEM_H
#define EXPANDITEM_H
#include "ItemEffect.h"
namespace StiGame
{

namespace Gui
{

namespace Effects
{

class ExpandItem :
        public ItemEffect
{
public:
    ExpandItem(Item *m_item, BaseGameState *m_state, float percentPerFrame, Dimension startingSize);
    virtual ~ExpandItem();

    Dimension* getCurrentSize(void);
    int getSpeed(void);



protected:
    virtual Surface *renderWithEffect(void);

    virtual void tickEffect(void);

    MDimension currentSize;
    float speed;
};

}

}

}

#endif // EXPANDITEM_H
