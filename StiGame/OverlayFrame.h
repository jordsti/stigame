#ifndef OVERLAYFRAME_H
#define OVERLAYFRAME_H

#include "Item.h"
#include <list>


namespace StiGame
{

namespace Gui
{

class OverlayFrame :
	public Item
{
public:
	OverlayFrame();
	virtual ~OverlayFrame();
	virtual void onMouseMotion(Point *relp);
	virtual void onClick(Point *relp);
	virtual Surface* render(void);
    virtual void tick(void);

	bool isVisible(void);
	void setVisible(bool m_visible);

	void add(Item *item);
protected:
	bool visible;
	std::list<Item*> items;
};

}

}


#endif
