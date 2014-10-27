#include "MouseMotionEventThrower.h"

namespace StiGame
{

MouseMotionEventThrower::MouseMotionEventThrower()
{

}

MouseMotionEventThrower::~MouseMotionEventThrower()
{

}

void MouseMotionEventThrower::subscribe(MouseMotionEventListener *listener)
{
	motionListeners.push_back(listener);
}

void MouseMotionEventThrower::remove(MouseMotionEventListener *listener)
{
	motionListeners.remove(listener);
}

void MouseMotionEventThrower::publish(MouseMotionEventThrower *src, MouseMotionEventArgs *args)
{
	std::list<MouseMotionEventListener*>::iterator lit(motionListeners.begin()), lend(motionListeners.end());
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(src, args);
	}
}

}