#ifndef TABPANEL_H
#define TABPANEL_H

#include "HighlightItem.h"
#include "TabItem.h"
#include <vector>

namespace StiGame
{

namespace Gui
{

class TabPanel :
	public HighlightItem
{
public:
	static const int NONE_SELECTED;
	static const int TAB_HEIGHT;
	static const int TAB_WIDTH_OFFSET;
	TabPanel();
	virtual ~TabPanel();
	
	void addTab(TabItem *item);
	void clearTabs(void);
	
	int getSelectedTab(void);
	void setSelectedTab(int m_selectedTab);
	
	int getNbTab(void);
	int getTabHeight(void);
	
	void setTabHeight(int m_tabHeight);
	
	virtual void onClick(Point *relpt);
	virtual void onMouseMotion(Point *relpt);
	
	virtual Surface* render(void);
	
protected:
	Font *font;
	std::vector<TabItem*> tabs;
	std::vector<Surface*> tabsCaption;
	int selectedTab;
	int tabHeight;
	int nbTab;
	int tabHighlighted;
	int tabWidthOffset;
};

}

}

#endif