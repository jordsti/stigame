#ifndef EVENTTHROWER_H
#define EVENTTHROWER_H
#include "EventListener.h"
#include <list>
namespace StiGame
{
/// \class EventThrower
/// \brief Class to implement if you want to make a EventListenable object
class EventThrower
{
public:
    /// \brief Constructor
	EventThrower(void);
	/// \brief Destructor
	~EventThrower(void);
	/// \brief method that can be override
	/// Suscribe a EventListener to this object
	/// \param listener EventListener
	virtual void subscribe(EventListener *listener);
	/// \brief Unsucribe a Listener
	/// \param EventListener
	virtual void remove(EventListener *listener);
protected:
	/// \brief Suscribed listeners
	std::list<EventListener*> listeners;
	/// \brief Publish an event
	/// \param source Thrower
	/// \param evt Event Args
	virtual void publish(EventThrower *source, EventArgs *evt);
};

}

#endif
