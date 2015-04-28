#ifndef TABITEM_H
#define TABITEM_H

#include "ItemContainer.h"
#include "BaseChildSupport.h"

namespace StiGame
{

namespace Gui
{

/// \class TabItem
/// \brief Container Tab Item
class TabItem :
    public Item,
    public BaseChildSupport
{
public:
	/// \brief Constructor
	TabItem();
	/// \brief Create a new tab with the specified name
	/// \param m_tabName Tab name
	TabItem(std::string m_tabName);
	/// \brief Destructor
	virtual ~TabItem();

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
};


}

}

#endif
