#include "ControllerButtonEventThrower.h"

namespace StiGame
{

ControllerButtonEventThrower::ControllerButtonEventThrower() {}
ControllerButtonEventThrower::~ControllerButtonEventThrower() {}
void ControllerButtonEventThrower::subscribe(ControllerButtonEventListener *listener)
{
	cbuttonListeners.push_back(listener);
}

void ControllerButtonEventThrower::remove(ControllerButtonEventListener *listener)
{
	cbuttonListeners.remove(listener);
}

void ControllerButtonEventThrower::publish(ControllerButtonEventThrower *src, ControllerButtonEventArgs *args)
{
	std::list<ControllerButtonEventListener*>::iterator lit(cbuttonListeners.begin()), lend(cbuttonListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(src, args);
	}
}

//std::list<ControllerButtonEventListener*> cbuttonListeners;

}