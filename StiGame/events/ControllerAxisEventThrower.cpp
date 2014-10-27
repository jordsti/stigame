#include "ControllerAxisEventThrower.h"

namespace StiGame
{

ControllerAxisEventThrower::ControllerAxisEventThrower() {}
ControllerAxisEventThrower::~ControllerAxisEventThrower() {}

void ControllerAxisEventThrower::subscribe(ControllerAxisEventListener *listener)
{
	axisListeners.push_back(listener);
}

void ControllerAxisEventThrower::remove(ControllerAxisEventListener *listener)
{
	axisListeners.remove(listener);
}

void ControllerAxisEventThrower::publish(ControllerAxisEventThrower *src, ControllerAxisEventArgs *args)
{
	std::list<ControllerAxisEventListener*>::iterator lit(axisListeners.begin()), lend(axisListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(src, args);
	}
}
	
	//std::list<ControllerAxisEventListener*> axisListeners;

}