#include "EffectEventArgs.h"
#include "ItemEffect.h"
namespace StiGame
{

namespace Gui
{

namespace Effects
{

EffectEventArgs::EffectEventArgs()
{
    effect = nullptr;
    type = EET_None;
}

EffectEventArgs::EffectEventArgs(ItemEffect *m_effect, EffectEventType m_type)
{
    effect = m_effect;
    type = m_type;
}

EffectEventArgs::~EffectEventArgs()
{

}

Item* EffectEventArgs::getItem(void)
{
    return effect->getItem();
}

ItemEffect* EffectEventArgs::getEffect(void)
{
    return effect;
}

EffectEventType EffectEventArgs::getType(void)
{
    return type;
}

}

}

}
