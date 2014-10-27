#include "MouseButtonEventListener.h"
#include "MouseButtonEventThrower.h"

namespace StiGame
{
MouseButtonEventListener::MouseButtonEventListener()
{


}

MouseButtonEventListener::~MouseButtonEventListener()
{

}

void MouseButtonEventListener::handleEvent(MouseButtonEventThrower *src, MouseButtonEventArgs *args)
{
	//to override
}

}