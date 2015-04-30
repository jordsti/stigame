#include "FadeInItem.h"

namespace StiGame
{

namespace Gui
{

namespace Effects
{

FadeInItem::FadeInItem(Item *m_item, BaseGameState *m_state, int m_fadeStep, int m_startAlpha) :
    ItemEffect(m_item, m_state)
{
    fadeStep = m_fadeStep;
    startAlpha = m_startAlpha;
    width = item->getWidth();
    height = item->getHeight();
    x = item->getX();
    y = item->getY();
    alpha = startAlpha;
    eventDuringEffect = true;
    redrawAtEachFrame = true;
}

FadeInItem::~FadeInItem()
{

}

int FadeInItem::getFadeStep(void)
{
    return fadeStep;
}

void FadeInItem::setFadeStep(int m_fadeStep)
{
    fadeStep = m_fadeStep;
}

int FadeInItem::getStartAlpha(void)
{
    return startAlpha;
}

void FadeInItem::setStartAlpha(int m_startAlpha)
{
    startAlpha = m_startAlpha;
}


Surface* FadeInItem::renderWithEffect(void)
{
    Surface *buffer = new Surface(width, height);
    Point dst (0,0);
    buffer->blit(effectBuffer, &dst);

    buffer->setBlendMode(SDL_BLENDMODE_BLEND);
    //buffer->setAlpha(alpha);
    buffer->setAlphaMod(alpha);

    return buffer;
}

void FadeInItem::tickEffect(void)
{
    if(alpha < 255)
    {
        alpha += fadeStep;

        if(alpha > 255)
        {
            alpha = 255;
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
