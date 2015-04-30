#ifndef EFFECTEVENTARGS_H
#define EFFECTEVENTARGS_H
#include "Item.h"
namespace StiGame
{

namespace Gui
{

namespace Effects
{

class ItemEffect;

enum EffectEventType {
    EET_None,
    EET_Started,
    EET_Ticking,
    EET_Terminated
};

class EffectEventArgs
{
public:
    EffectEventArgs();
    EffectEventArgs(ItemEffect *m_effect, EffectEventType m_type);
    virtual ~EffectEventArgs();

    Item* getItem(void);
    ItemEffect* getEffect(void);
    EffectEventType getType(void);

private:
    ItemEffect *effect;
    EffectEventType type;

};

}

}

}


#endif // EFFECTEVENTARGS_H
