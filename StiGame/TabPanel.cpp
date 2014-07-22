#include "TabPanel.h"
#include "PRect.h"

namespace StiGame
{

namespace Gui
{

const int TabPanel::NONE_SELECTED = -1;
const int TabPanel::TAB_HEIGHT = 22;
const int TabPanel::TAB_WIDTH_OFFSET = 4;

TabPanel::TabPanel() : HighlightItem("TabPanel")
{
	font = style->getNormalFont();
	selectedTab = NONE_SELECTED;
	nbTab = 0;
	tabHeight = TAB_HEIGHT;
	tabHighlighted = NONE_SELECTED;
	tabWidthOffset = TAB_WIDTH_OFFSET;
}

TabPanel::~TabPanel()
{

}

void TabPanel::addTab(TabItem *item)
{
	tabs.push_back(item);
	
	item->setWidth(width);
	item->setHeight(height);
	item->setX(0);
	item->setY(0);
	
	std::string tabname = item->getTabName();
	
	Surface *caption = font->renderText(tabname, foreground);
	
	tabsCaption.push_back(caption);
	
}

void TabPanel::clearTabs(void)
{
	tabs.clear();
	tabsCaption.clear();
	nbTab = 0;
	selectedTab = NONE_SELECTED;
	tabHighlighted = NONE_SELECTED;
}

int TabPanel::getSelectedTab(void)
{
	return selectedTab;
}

void TabPanel::setSelectedTab(int m_selectedTab)
{
	if(m_selectedTab < nbTab)
	{
		selectedTab = m_selectedTab;
	}
}

int TabPanel::getNbTab(void)
{
	return nbTab;
}

int TabPanel::getTabHeight(void)
{
	return tabHeight;
}

void TabPanel::setTabHeight(int m_tabHeight)
{
	tabHeight = m_tabHeight;
}

void TabPanel::onClick(Point *relpt)
{
	if(relpt->getY() <= tabHeight)
	{
		Rectangle rect = Rectangle();
		rect.setHeight(tabHeight);
		rect.setX(0);
		rect.setY(0);
		
		std::vector<Surface*>::iterator tit(tabsCaption.begin()), tend(tabsCaption.end());
		int index = 0;
		for(;tit!=tend;++tit)
		{
			rect.setWidth((*tit)->getWidth() + tabWidthOffset*2);
			
			if(rect.contains(relpt))
			{
				selectedTab = index;
			}
			
			index++;
		}
	}

	std::vector<TabItem*>::iterator lit(tabs.begin()), lend(tabs.end());
	int index = 0;
	for(;lit!=lend;++lit)
	{
		if(index == selectedTab)
		{
			MPoint mpt = MPoint();
			
			if((*lit)->contains(relpt))
			{
				mpt.setX(relpt->getX() - (*lit)->getX());
				mpt.setY(relpt->getY() - (*lit)->getY());
				
				(*lit)->onClick(&mpt);
			}
		}
		
		index++;
	}
}

void TabPanel::onMouseMotion(Point *relpt)
{
	/*if(relpt->getY() <= tabHeight)
	{
	
	}*/

	std::vector<TabItem*>::iterator lit(tabs.begin()), lend(tabs.end());
	int index = 0;
	for(;lit!=lend;++lit)
	{
		if(index == selectedTab)
		{
			MPoint mpt = MPoint();
			
			if((*lit)->contains(relpt))
			{
				mpt.setX(relpt->getX() - (*lit)->getX());
				mpt.setY(relpt->getY() - (*lit)->getY());
				
				(*lit)->onMouseMotion(&mpt);
			}
		}
		
		index++;
	}
}

Surface* TabPanel::render(void)
{
	Surface *buffer = new Surface(width, height);
	
	buffer->fill(background);
	
	PRect border = PRect();
	border.setX(0);
	border.setY(0);
	border.setWidth(width - 1);
	border.setHeight(height - 1);
	
	buffer->draw(&border, foreground);
	
	std::vector<Surface*>::iterator tit(tabsCaption.begin()), tend(tabsCaption.end());
	int cur_x = 0;
	int index = 0;
	SDL_Rect src = SDL_Rect();
	SDL_Rect dst = SDL_Rect();
	
		
	//drawing current tab
	
	if(selectedTab != NONE_SELECTED)
	{
		TabItem *tab = tabs[selectedTab];
		Surface *tab_sur = tab->render();
		
		src.x = 0;
		src.y = 0;
		src.w = tab->getWidth();
		src.h = tab->getHeight();
		
		Rectangle::Copy(&src, &dst);
			
		buffer->blit(tab_sur, &src, &dst);
		
		delete tab_sur;
	}
	
	
	for(;tit!=tend;++tit)
	{
		src.w = (*tit)->getWidth();
		src.h = (*tit)->getHeight();
	
		dst.x = cur_x + tabWidthOffset;
		dst.y = (tabHeight - (*tit)->getHeight()) / 2;
		dst.w = src.w;
		dst.h = src.h;
	
		if(selectedTab == index)
		{
			border.setX(cur_x);
			border.setY(0);
			border.setWidth(tabWidthOffset*2 + dst.w);
			border.setHeight(tabHeight);
			
			buffer->fill(&border, highlightBackground);
		}
		
		buffer->blit((*tit), &src, &dst);
		
		index++;
	}
	
	return buffer;
}
	
/*	Members
	Font *font;
	std::vector<TabItem*> tabs;
	std::vector<Surface*> tabsCaption;
	int selectedTab;
	int tabHeight;
	int nbTab;
	int tabHighlighted
*/

}

}