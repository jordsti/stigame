#ifndef FADEINITEM_H
#define FADEINITEM_H
#include "ItemEffect.h"

namespace StiGame
{

namespace Gui
{

namespace Effects
{

class FadeInItem :
        public ItemEffect
{
public:
    FadeInItem(Item *m_item, BaseGameState *m_state, int m_fadeStep, int m_startAlpha);
    virtual ~FadeInItem();

    int getFadeStep(void);
    void setFadeStep(int m_fadeStep);

    int getStartAlpha(void);
    void setStartAlpha(int m_startAlpha);

protected:
    virtual Surface *renderWithEffect(void);
    virtual void tickEffect(void);

private:
    int alpha;
    int startAlpha;
    int fadeStep;


};

}
}
}

#endif // FADEINITEM_H
