#ifndef MOUEEBUTTONEVENTTHROWER_H
#define MOUSEBUTTONEVENTTHROWER_H

#include "MouseButtonEventListener.h"
#include <list>

namespace StiGame
{


class MouseButtonEventThrower
{
public:
	MouseButtonEventThrower();
	virtual ~MouseButtonEventThrower();
	
	virtual void subscribe(MouseButtonEventListener *listener);
	virtual void remove(MouseButtonEventListener *listener);
protected:
	std::list<MouseButtonEventListener*> mouseListeners;
	
	virtual void publish(MouseButtonEventThrower *source, MouseButtonEventArgs *args);

};

}


#endif