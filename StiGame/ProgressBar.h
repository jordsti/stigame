#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "Item.h"

namespace StiGame
{

namespace Gui
{

class ProgressBar :
	public Item
{
public:
	static const int DEFAULT_HEIGHT;
	static const int DEFAULT_WIDTH;
	static Color* DEFAULT_BAR_COLOR;
	
	ProgressBar();
	virtual ~ProgressBar();
	
	Surface *render(void);
	
	int getMax(void);
	void setMax(int m_max);
	
	int getCurrent(void);
	void setCurrent(int m_current);
	
	bool getDrawBorder(void);
	void setDrawBorder(bool m_drawBorder);
	
	Color* getBarColor(void);
	void setBarColor(Color *m_barColor);
	
protected:
	int max;
	int current;
	bool drawBorder;
	Color *barColor;

};

}

}


#endif