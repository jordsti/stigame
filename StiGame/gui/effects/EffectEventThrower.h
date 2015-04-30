#ifndef EFFECTEVENTTHROWER_H
#define EFFECTEVENTTHROWER_H
#include "EffectListener.h"
#include <list>
namespace StiGame
{

namespace Gui
{

namespace Effects
{

class EffectEventArgs;

class EffectEventThrower
{
public:
    EffectEventThrower();
    virtual ~EffectEventThrower();

    void subscribe(EffectListener *listener);
    void remove(EffectListener *listener);
protected:
    virtual void publish(EffectEventArgs *args);
private:
    std::list<EffectListener*> listeners;
};

}

}

}

#endif // EFFECTEVENTTHROWER_H
