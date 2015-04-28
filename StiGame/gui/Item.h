#pragma once
#include "Surface.h"
#include "Color.h"
#include <string>
#include "Style.h"
#include "Rectangle.h"
namespace StiGame
{

namespace Gui
{

/// \class Item
/// \brief Base class for GuiItem
class Item :
	public Rectangle
{
public:
    static const int MAX_WIDTH;
    static const int MAX_HEIGHT;
	/// \brief Create an GuiItem
	Item(void);
	/// \brief Create an GuiItem
	/// \param m_name Name of the item
	Item(std::string m_name);
	/// \brief Destructor
	virtual ~Item(void);
	/// \brief GuiItem Render method
	/// \return Rendered surface of the item
	virtual Surface* render(void) = 0;
	/// \brief Clear item members
	virtual void clear(void);
	/// \brief Get the name of the item
	/// \return Name
	std::string getName(void);
	/// \brief Set the background color
	/// \param m_background SColor pointer
	virtual void setBackground(Color* m_background);
	/// \brief Get the background color pointer
	/// \return SColor pointer
	Color *getBackground(void);
	/// \brief Set the foreground color
	/// \param m_foreground SColor pointer
	virtual void setForeground(Color* m_foreground);
	/// \brief Get the foreground color
	/// \return SColor pointer
	Color *getForeground(void);
	/// \brief Get the style of the item
	/// \return GuiStyle pointer
	Style *getStyle(void);
	/// \brief Get mouse over
	bool getMouseOver(void);
	/// \brief Set mouse over
	virtual void setMouseOver(bool);
	/// \brief Virtual method to override, provide mouse position, only over the GuiItem region
	/// \param relp Relative position over the Item
	virtual void onMouseMotion(Point *relp);
	/// \brief Virtual method to override, called when the item is clicked
	/// \param relp Relative position of the click
	virtual void onClick(Point *relp);
	/// \brief Text Input Event Handling
	/// \param text New Char to append
	virtual void onTextInput(char* text);
	/// \brief On Key Up Event handling
	/// \param evt SDL_KeyboardEvent Pointer
	virtual void onKeyUp(SDL_KeyboardEvent *evt);
	/// \brief Set the Item Rectangle (Position and dimension)
	/// \param m_x X Position (px)
	/// \param m_y Y Position (px)
	/// \param m_width Width (px)
	/// \param m_height Height (px)
	virtual void setRectangle(int m_x, int m_y, int m_width, int m_height);
    
	/// \brief Set current width of the Item
	/// \param m_width Width (px)
	void setWidth(int m_width);
	
	/// \brief Set current height of the Item
	/// \param m_height Height (px)
	void setHeight(int m_height);
	
	/// \brief Set Item Current Dimension
	/// \param m_width Width (px)
	/// \param m_height Height (px)
	void setDimension(int m_width, int m_height);

	/// \brief Is the Key Event Handled by this Item
	/// \return Handled or not
    virtual bool isHandleKey(void);
	
	/// \brief Is the Item has focus
	/// \return Focused or not
	virtual bool isFocus(void);
	
	/// \brief Set the Focus of the Item
	/// \param m_focus New Focus value
	virtual void setFocus(bool m_focus);
	
	/// \brief Set the minimum size of the Item, for Layout placement
	/// \param m_width Minimum Width (px)
	/// \param m_height Minimum Height (px)
	void setMinimumSize(int m_width, int m_height);
	
	/// \brief Set the maximum size of the Item, for Layout placement
	/// \param m_width Maximum Width (px)
	/// \param m_height Maximum Height (px)
	void setMaximumSize(int m_width, int m_height);

	/// \brief Set the maximum, minimum and current Size of the Item
	/// \param m_width Fixed Width (px)
	/// \param m_height Fixed Height (px)
	void setFixedSize(int m_width, int m_height);

	/// \brief Get Current Minimum Size
	/// \return Dimension Pointer of the minimum size
	Dimension* getMinimumSize(void);
	
	/// \brief Get Current Maximum Size
	/// \return Dimension Pointer of the minimum size
	Dimension* getMaximumSize(void);

	/// \brief Is the Item Visible
	/// \return Visible or not
	bool isVisible(void);
	
	/// \brief Set the new visibility
	/// \param m_visible Visible or not
	void setVisible(bool m_visible);

    int getId(void);

protected:
	/// \brief Name of the item
	std::string name;
	/// \brief Background color
	Color *background;
	/// \brief Foreground color
	Color *foreground;
	/// \brief Item GuiStyle
	Style *style;
	/// \brief is mouse over
	bool mouseOver;
	/// \brief Event Key Handled
	bool handleKey;

	/// \brief Resize callback
	virtual void resized(void);

	/// \brief Current Focus value
	bool focus;
	
	/// \brief Visibility
	bool visible;
	
	/// \brief Minimum Size
	MDimension minimumSize;
	/// \brief Maximum Size
	MDimension maximumSize;
private:
    static int incrementId(void);
    static int _currentId;
    int _id;
	/// \brief Initialization
	void init(void);
};

}

}
