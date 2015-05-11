#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "Item.h"

namespace StiGame
{

namespace Gui
{
/// \class ProgressBar
/// \brief Item that draw a progress bar
class ProgressBar :
	public Item
{
public:
	/// \brief Default Height (px)
	static const int DEFAULT_HEIGHT;
	/// \brief Default Width (px)
	static const int DEFAULT_WIDTH;
	/// \brief Default Progress Bar Color
	static Color* DEFAULT_BAR_COLOR;
	/// \brief Constructor
	ProgressBar();
	/// \brief Destructor
	virtual ~ProgressBar();
	
	Surface *render(void);
	/// \brief Get the maximum
	/// \return Maximum
	int getMax(void);
	/// \brief Set the progress bar maximum
	/// \param m_max New Maximum
	void setMax(int m_max);
	/// \brief Get current value
	/// \return Current Value
	int getCurrent(void);
	/// \brief Set the current value
	/// \param m_current New Current value
	void setCurrent(int m_current);
	/// \brief Get Draw Border Value
	/// \return Draw Border or not
	bool getDrawBorder(void);
	/// \brief Set draw border value
	/// \param m_drawBorder
	void setDrawBorder(bool m_drawBorder);
	/// \brief Get Bar Color
	/// \return Bar Color
	Color* getBarColor(void);
	/// \brief Set bar Color
	/// \param m_barColor Bar Color
	void setBarColor(Color *m_barColor);

    void increment(int step);
	
protected:
	/// \brief Maximum
	int max;
	/// \brief Current
	int current;
	/// \brief Draw Border
	bool drawBorder;
	/// \brief Progress Bar color
	Color *barColor;

};

}

}


#endif
