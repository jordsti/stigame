#include "FadeOutItem.h"

namespace StiGame
{

namespace Gui
{

namespace Effects
{

FadeOutItem::FadeOutItem(Item *m_item, BaseGameState *m_state, int m_fadeStep, int m_endAlpha) :
    ItemEffect(m_item, m_state)
{
    fadeStep = m_fadeStep;
    endAlpha = endAlpha;
    redrawAtEachFrame = true;
    width =  item->getWidth();
    height = item->getHeight();
    x = item->getX();
    y = item->getY();
    alpha = 255;
}

FadeOutItem::~FadeOutItem()
{

}

int FadeOutItem::getFadeStep(void)
{
    return fadeStep;
}

void FadeOutItem::setFadeStep(int m_fadeStep)
{
    fadeStep = m_fadeStep;
}

int FadeOutItem::getEndAlpha(void)
{
    return endAlpha;
}

void FadeOutItem::setEndAlpha(int m_endAlpha)
{
    endAlpha = m_endAlpha;
}

Surface* FadeOutItem::renderWithEffect(void)
{
    Surface *buffer = new Surface(width, height);
    Point dst (0,0);
    buffer->blit(effectBuffer, &dst);

    buffer->setBlendMode(SDL_BLENDMODE_BLEND);
    //buffer->setAlpha(alpha);
    buffer->setAlphaMod(alpha);

    return buffer;
}

void FadeOutItem::tickEffect(void)
{
    if(alpha > endAlpha)
    {
        alpha -= fadeStep;

        if(alpha < endAlpha)
        {
            alpha = endAlpha;
        }
    }
    else
    {
        setTerminated(true);
    }
}

}

}

}
