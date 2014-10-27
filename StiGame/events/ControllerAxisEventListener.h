#ifndef CONTROLLERAXISEVENTLISTENER_H
#define CONTROLLERAXISEVENTLISTENER_H

#include "ControllerAxisEventArgs.h"

namespace StiGame
{

class ControllerAxisEventThrower;

class ControllerAxisEventListener
{
public:
	ControllerAxisEventListener();
	virtual ~ControllerAxisEventListener();
	virtual void handleEvent(ControllerAxisEventThrower *src, ControllerAxisEventArgs *args);
};

}

#endif