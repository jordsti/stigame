#ifndef EFFECTUNWRAPPER_H
#define EFFECTUNWRAPPER_H
#include "EffectListener.h"
#include "GuiState.h"
namespace StiGame
{

namespace Gui
{

namespace Effects
{


class EffectUnwrapper :
        public EffectListener
{
public:
    EffectUnwrapper(GuiState *m_state);
    virtual ~EffectUnwrapper();

    void handleEvent(EffectEventThrower *src, EffectEventArgs *args);
private:
    GuiState *state;
    std::list<ItemEffect*> effects;
};

}

}

}

#endif // EFFECTUNWRAPPER_H
