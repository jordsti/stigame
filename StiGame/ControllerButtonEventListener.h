#ifndef CONTROLLERBUTTONEVENTLISTENER_H
#define CONTROLLERBUTTONEVENTLISTENER_H

#include "ControllerButtonEventArgs.h"

namespace StiGame
{

class ControllerButtonEventThrower;

class ControllerButtonEventListener
{
public:
	ControllerButtonEventListener();
	virtual ~ControllerButtonEventListener();
	virtual void handleEvent(ControllerButtonEventThrower *src, ControllerButtonEventArgs *args);
};

}

#endif