#ifndef OVERLAYFRAME_H
#define OVERLAYFRAME_H

#include "Item.h"
#include <list>


namespace StiGame
{

namespace Gui
{
/// \class OverlayFrame
/// \brief Represent an Container Item that will be drawed in front of the other items
class OverlayFrame :
	public Item
{
public:
	/// \brief Constructor
	OverlayFrame();
	/// \brief Destructor
	virtual ~OverlayFrame();
	
	virtual void onMouseMotion(Point *relp);
	virtual void onClick(Point *relp);
	virtual Surface* render(void);
	/// \brief Tick the Overlay Frame
	virtual void tick(void);
    
	bool isVisible(void);
	void setVisible(bool m_visible);

	/// \brief Add a new item to the Overlay Frame
	/// \param item Item to add
	void add(Item *item);
protected:
	/// \brief Is the overlay visible
	bool visible;
	/// \brief Childs
	std::list<Item*> items;
};

}

}


#endif
