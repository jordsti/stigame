#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "SDL.h"
#include "EventArgs.h"
namespace StiGame
{

class EventThrower;
/// \class EventListener
/// \brief Class to implement if you want to be able do handle GuiItem Events
class EventListener
{
public:
    /// \brief Constructor
	EventListener(void);
	/// \brief Destructor
	virtual ~EventListener(void);
	/// \brief Method to override to handle your event
	/// \param src Event source
	/// \param evt Event args
    virtual bool handleEvent(EventThrower *src, EventArgs *evt);
};

}

#endif
