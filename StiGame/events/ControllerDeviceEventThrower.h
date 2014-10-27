#ifndef CONTROLLERDEVICEEVENTTHROWER_H
#define CONTROLLERDEVICEEVENTTHROWER_H

#include "ControllerDeviceEventListener.h"
#include <list>

namespace StiGame
{

class ControllerDeviceEventThrower
{
public:
	ControllerDeviceEventThrower();
	virtual ~ControllerDeviceEventThrower();
	virtual void subscribe(ControllerDeviceEventListener *listener);
	virtual void remove(ControllerDeviceEventListener *listener);
protected:
	virtual void publish(ControllerDeviceEventThrower *src, ControllerDeviceEventArgs *args);
	
	std::list<ControllerDeviceEventListener*> cdeviceListeners;
};

}

#endif