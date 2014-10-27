#include "ControllerDeviceEventThrower.h"

namespace StiGame
{

ControllerDeviceEventThrower::ControllerDeviceEventThrower() {}
ControllerDeviceEventThrower::~ControllerDeviceEventThrower() {}

void ControllerDeviceEventThrower::subscribe(ControllerDeviceEventListener *listener)
{
	cdeviceListeners.push_back(listener);
}

void ControllerDeviceEventThrower::remove(ControllerDeviceEventListener *listener)
{
	cdeviceListeners.remove(listener);
}

void ControllerDeviceEventThrower::publish(ControllerDeviceEventThrower *src, ControllerDeviceEventArgs *args)
{
	std::list<ControllerDeviceEventListener*>::iterator lit(cdeviceListeners.begin()), lend(cdeviceListeners.end());
	
	for(;lit!=lend;++lit)
	{
		(*lit)->handleEvent(src, args);
	}
}

//std::list<ControllerDeviceEventListener*> cdeviceListeners;

}