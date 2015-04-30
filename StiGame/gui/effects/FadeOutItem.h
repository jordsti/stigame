#ifndef FADEOUTITEM_H
#define FADEOUTITEM_H

#include "ItemEffect.h"

namespace StiGame
{

namespace Gui
{

namespace Effects
{

class FadeOutItem :
        public ItemEffect
{
public:
    FadeOutItem(Item *m_item, BaseGameState *m_state, int m_fadeStep, int m_endAlpha);
    virtual ~FadeOutItem();

    int getFadeStep(void);
    void setFadeStep(int m_fadeStep);

    int getEndAlpha(void);
    void setEndAlpha(int m_endAlpha);

protected:
    virtual Surface *renderWithEffect(void);
    virtual void tickEffect(void);

private:
    int alpha;
    int endAlpha;
    int fadeStep;


};

}
}
}
#endif // FADEOUTITEM_H
