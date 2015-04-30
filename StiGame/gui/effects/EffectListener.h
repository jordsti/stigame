#ifndef EFFECTLISTENER_H
#define EFFECTLISTENER_H
#include "EffectEventArgs.h"
#include <list>
namespace StiGame
{

namespace Gui
{

namespace Effects
{

class EffectEventThrower;

class EffectListener
{
public:
    EffectListener();
    virtual ~EffectListener();
    virtual void handleEvent(EffectEventThrower *src, EffectEventArgs *args);
};

}

}

}

#endif // EFFECTLISTENER_H
