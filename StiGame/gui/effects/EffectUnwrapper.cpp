#include "EffectUnwrapper.h"
#include "ItemEffect.h"
namespace StiGame
{

namespace Gui
{

namespace Effects
{

EffectUnwrapper::EffectUnwrapper(GuiState *m_state)
{
    state = m_state;
}

EffectUnwrapper::~EffectUnwrapper()
{

}

void EffectUnwrapper::handleEvent(EffectEventThrower *src, EffectEventArgs *args)
{
    if(args->getType() == EET_Terminated)
    {
        if(args->getEffect()->getState() == state)
        {
            Item *item = args->getItem();

            state->removeItem(args->getEffect());

            state->add(item);

            effects.push_back(args->getEffect());
        }
    }
}

}
}
}
