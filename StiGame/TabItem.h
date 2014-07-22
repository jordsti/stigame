#ifndef TABITEM_H
#define TABITEM_H

#include "Item.h"
#include <list>

namespace StiGame
{

namespace Gui
{

class TabItem : 
	public Item
{
public:
	TabItem();
	TabItem(std::string m_tabName);
	virtual ~TabItem();

	void add(Item *item);
	void remove(Item *item);
	
	std::string getTabName(void);
	
	virtual void onClick(Point *relpt);
	virtual void onMouseMotion(Point *relpt);
	
	virtual	Surface* render(void);
protected:
	std::string tabName;
	std::list<Item*> items;
};


}

}

#endif