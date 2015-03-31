#ifndef TABITEM_H
#define TABITEM_H

#include "Item.h"
#include <list>

namespace StiGame
{

namespace Gui
{

/// \class TabItem
/// \brief Container Tab Item
class TabItem :
	public Item
{
public:
	/// \brief Constructor
	TabItem();
	/// \brief Create a new tab with the specified name
	/// \param m_tabName Tab name
	TabItem(std::string m_tabName);
	/// \brief Destructor
	virtual ~TabItem();
	/// \brief Add an Item to the panel
	/// \param item Item Pointer
	void add(Item *item);
	/// \brief Remove and Item from the panel
	/// \param item Item to remove
	void remove(Item *item);
	/// \brief Get the tab name
	/// \return Tab name
	std::string getTabName(void);

	virtual void onClick(Point *relpt);
	virtual void onMouseMotion(Point *relpt);

	Surface* render(void);
	
	virtual void setMouseOver(bool m_mouseOver);
protected:
	/// \brief Tab Name
	std::string tabName;
	/// \brief Items Container
	std::list<Item*> items;
};


}

}

#endif
