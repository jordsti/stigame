#ifndef CONTROLLERBUTTONEVENTTHROWER_H
#define CONTROLLERBUTTONEVENTTHROWER_H

#include "ControllerButtonEventListener.h"
#include <list>

namespace StiGame
{

class ControllerButtonEventThrower
{
public:
	ControllerButtonEventThrower();
	virtual ~ControllerButtonEventThrower();
	virtual void subscribe(ControllerButtonEventListener *listener);
	virtual void remove(ControllerButtonEventListener *listener);
protected:
	virtual void publish(ControllerButtonEventThrower *src, ControllerButtonEventArgs *args);
	
	std::list<ControllerButtonEventListener*> cbuttonListeners;
};

}


#endif