
#include "EventListener.h"

namespace StiGame
{
EventListener::EventListener(void)
{
}


EventListener::~EventListener(void)
{
}

bool EventListener::handleEvent(EventThrower *src, EventArgs *evt)
{
    return false;
}

}
