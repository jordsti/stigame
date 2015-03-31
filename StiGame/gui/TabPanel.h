#ifndef TABPANEL_H
#define TABPANEL_H

#include "HighlightItem.h"
#include "TabItem.h"
#include <vector>

namespace StiGame
{

namespace Gui
{

/// \class TabPanel
/// \brief Contains TabItem and the user is able to switch between tabs
class TabPanel :
	public HighlightItem
{
public:
	/// \brief None Item Selected Constan
	static const int NONE_SELECTED;
	/// \brief Default Tab Height
	static const int TAB_HEIGHT;
	/// \brief Tab Width Offset
	static const int TAB_WIDTH_OFFSET;
	
	/// \brief Constructor
	TabPanel();
	/// \brief Destructor
	virtual ~TabPanel();
	/// \brief Add a new Tab 
	/// \param item Tab Item to add
	void addTab(TabItem *item);
	/// \brief Clear all the tabs
	void clearTabs(void);
	/// \brief Get the selected tab index
	/// \return Tab index
	int getSelectedTab(void);
	/// \brief Set the selected tab index
	/// \param m_selectedTab Selected Tab Index
	void setSelectedTab(int m_selectedTab);
	/// \brief Get Tab Count ( To rename -> tabCount)
	/// \return Tabs Count
	int getNbTab(void);
	/// \brief Get Tab Height
	/// \return Tab Height (px)
	int getTabHeight(void);
	/// \brief Set Tab Height
	/// \param m_tabHeight Tab Height (px)
	void setTabHeight(int m_tabHeight);

	virtual void onClick(Point *relpt);
	virtual void onMouseMotion(Point *relpt);

	virtual Surface* render(void);

    virtual void setMouseOver(bool m_mouseOver);
protected:
      void resized(void);
      /// \brief Rendering Font
      Font *font;
      /// \brief Tab Items Container
      std::vector<TabItem*> tabs;
      /// \brief Tabs Caption String
      std::vector<Surface*> tabsCaption;
      /// \brief Selected Tab Index
      int selectedTab;
      /// \brief Tab Height (px)
      int tabHeight;
      /// \brief Highlighted Tab Index
      int tabHighlighted;
      /// \brief Tab Width Offset (px)
      int tabWidthOffset;
};

}

}

#endif
