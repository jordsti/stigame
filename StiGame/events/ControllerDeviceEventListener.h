#ifndef CONTROLLERDEVICEEVENTLISTENER_H
#define CONTROLLERDEVICEEVENTLISTENER_H

#include "ControllerDeviceEventArgs.h"

namespace StiGame
{

class ControllerDeviceEventThrower;

class ControllerDeviceEventListener
{
public:
	ControllerDeviceEventListener();
	virtual ~ControllerDeviceEventListener();
	virtual void handleEvent(ControllerDeviceEventThrower *src, ControllerDeviceEventArgs *args);
};

}

#endif