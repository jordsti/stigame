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
    if(eventDuringEffect)
        item->onClick(relp);
}

void ItemEffect::onKeyUp(SDL_KeyboardEvent *evt)
{
    if(eventDuringEffect)
        item->onKeyUp(evt);
}

void ItemEffect::setMouseOver(bool m_mouseOver)
{
    if(eventDuringEffect)
        item->setMouseOver(m_mouseOver);
}

void ItemEffect::onMouseMotion(Point *relp)
{
    if(eventDuringEffect)
        item->onMouseMotion(relp);
}

void ItemEffect::onTextInput(char* text)
{
    if(eventDuringEffect)
        item->onTextInput(text);
}


bool ItemEffect::isTerminated(void)
{
    return terminated;
}


void ItemEffect::setTerminated(bool m_terminated)
{
    terminated = m_terminated;
}

Surface* ItemEffect::render(void)
{
    if(effectBuffer == nullptr)
    {
        effectBuffer = item->render();
    }

    if(visible)
    {
        if(!terminated)
        {
            tickEffect();
            return renderWithEffect();
        }
    }

    return item->render();
}




}

}

}
