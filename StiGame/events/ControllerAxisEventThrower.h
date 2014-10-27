#ifndef CONTROLLERAXISEVENTTHROWER_H
#define CONTROLLERAXISEVENTTHROWER_H

#include "ControllerAxisEventListener.h"
#include <list>

namespace StiGame
{

class ControllerAxisEventThrower
{
public:
	ControllerAxisEventThrower();
	virtual ~ControllerAxisEventThrower();
	virtual void subscribe(ControllerAxisEventListener *listener);
	virtual void remove(ControllerAxisEventListener *listener);
protected:
	virtual void publish(ControllerAxisEventThrower *src, ControllerAxisEventArgs *args);
	
	std::list<ControllerAxisEventListener*> axisListeners;
	
};

}

#endif