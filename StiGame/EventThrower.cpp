
#include "EventThrower.h"

namespace StiGame
{

EventThrower::EventThrower(void)
{
}

void EventThrower::subscribe(EventListener *listener)
{
	listeners.push_back(listener);
}

void EventThrower::remove(EventListener *listener)
{
	listeners.remove(listener);
}
void EventThrower::publish(EventThrower *source, EventArgs *evt)
{
	std::list<EventListener*>::iterator lit = (listeners.begin()), lend(listeners.end());
	for(; lit!=lend; ++lit)
	{
		(*lit)->handleEvent(source, evt);
	}
}

EventThrower::~EventThrower(void)
{
}

}
