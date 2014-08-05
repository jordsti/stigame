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
	/// \param relp Relative position over the GuiItem
	virtual void onMouseMotion(Point *relp);
	/// \brief Virtual method to override, called when the item is clicked
	virtual void onClick(Point *relp);

	virtual void onTextInput(char* text);

	virtual void onKeyUp(SDL_KeyboardEvent *evt);

	virtual void setRectangle(int m_x, int m_y, int m_width, int m_height);

    void setWidth(int m_width);

    void setHeight(int m_height);

    void setDimension(int m_width, int m_height);

    bool isHandleKey(void);

    virtual bool isFocus(void);

    virtual void setFocus(bool m_focus);

    void setMinimumSize(int m_width, int m_height);

    void setMaximumSize(int m_width, int m_height);

    void setFixedSize(int m_width, int m_height);

    Dimension* getMinimumSize(void);

    Dimension* getMaximumSize(void);

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

	bool handleKey;

    virtual void resized(void);

    bool focus;

    MDimension minimumSize;
    MDimension maximumSize;
private:
	/// \brief initialization
	void init(void);
};

}

}
