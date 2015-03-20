#ifndef HIGHLIGHTITEM_H
#define HIGHLIGHTITEM_H

#include "Item.h"

namespace StiGame
{

namespace Gui
{


/// \class HighlightItem
/// \brief Interface for highlight-able Item
class HighlightItem :
    public Item
{
    public:
	/// \brief Create a new Highlight Item
        HighlightItem();
	/// \brief Create a new Highlight Item with his name
	/// \param i_name Item Name
	HighlightItem(std::string i_name);
		
	/// \brief Destructor
        virtual ~HighlightItem();
	/// \brief Set highlight Foreground Color
	/// \param color Color
        void setHighlightForeground(Color *color);
	/// \brief Set highlight Background Color
	/// \param color Color
        void setHighlightBackground(Color *color);
	/// \brief Get highlight Foreground Color
	/// \return Foreground Color
        Color *getHighlightForeground(void);
	/// \brief Get highlight Background Color
	/// \return Background Color
        Color *getHighlightBackground(void);

    protected:
	/// \brief Highlight Foreground Color
        Color *highlightForeground;
	/// \brief Highlight Background Color
        Color *highlightBackground;
    private:
};

}

}
#endif // HIGHLIGHTITEM_H
