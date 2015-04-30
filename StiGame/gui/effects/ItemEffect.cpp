#include "ItemEffect.h"

namespace StiGame {

namespace Gui {

namespace Effects {

ItemEffect::ItemEffect(Item *m_item, BaseGameState *m_state) :
    Item("ItemEffect")
{
    item = m_item;
    state = m_state;
    effectBuffer = nullptr;
    terminated = false;
    eventDuringEffect = false;
    width = m_item->getWidth();
    height = m_item->getHeight();
    redrawAtEachFrame = false;
}

ItemEffect::~ItemEffect()
{
    if(effectBuffer != nullptr)
    {
        delete effectBuffer;
    }
}


void ItemEffect::onClick(Point *relp)
{
    if(eventDuringEffect || terminated)
        item->onClick(relp);
}

void ItemEffect::onKeyUp(SDL_KeyboardEvent *evt)
{
    if(eventDuringEffect || terminated)
        item->onKeyUp(evt);
}

void ItemEffect::setMouseOver(bool m_mouseOver)
{
    if(eventDuringEffect || terminated)
        item->setMouseOver(m_mouseOver);
}

void ItemEffect::onMouseMotion(Point *relp)
{
    if(eventDuringEffect || terminated)
        item->onMouseMotion(relp);
}

void ItemEffect::onTextInput(char* text)
{
    if(eventDuringEffect || terminated)
        item->onTextInput(text);
}


bool ItemEffect::isHandleKey(void)
{
    return item->isHandleKey();
}

bool ItemEffect::isTerminated(void)
{
    return terminated;
}


Item* ItemEffect::getItem(void)
{
    return item;
}

BaseGameState* ItemEffect::getState(void)
{
    return state;
}

Surface* ItemEffect::render(void)
{
    if(effectBuffer == nullptr)
    {
        EffectEventArgs args (this, EET_Started);
        publish(&args);
    }

    if(redrawAtEachFrame)
    {
        if(effectBuffer != nullptr)
        {
            delete effectBuffer;
        }

        effectBuffer = item->render();
    }

    if(effectBuffer == nullptr)
    {
        effectBuffer = item->render();
    }

    if(visible)
    {
        if(!terminated)
        {
            tickEffect();
            EffectEventArgs args (this, EET_Ticking);
            publish(&args);
            return renderWithEffect();
        }
    }

    return item->render();
}

void ItemEffect::setTerminated(bool m_terminated)
{
    if(m_terminated)
    {
        EffectEventArgs args (this, EET_Terminated);
        publish(&args);
    }

    terminated = m_terminated;
}




}

}

}
