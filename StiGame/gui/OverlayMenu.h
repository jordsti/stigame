#ifndef OVERLAYMENU_H
#define OVERLAYMENU_H

#include "KeyEventListener.h"
#include "ItemContainer.h"

namespace StiGame
{

namespace Gui
{

enum OverlayPosition { OP_MIDDLE,
		      OP_TOP_LEFT_CORNER,
		      OP_TOP_RIGHT_CORNER,
		      OP_BOTTOM_LEFT_CORNER,
		      OP_BOTTOM_RIGHT_CORNER,
		      OP_CUSTOM };
/// \class OverlayMenu
/// \brief Overlay Menu, useful for in-game menu
class OverlayMenu :
    public Item/*,
    public KeyEventListener*/
{
    public:
	/// \brief Default Time for visibility of the overlay menu
        static const int DEFAULT_TIME_VISIBILITY;
	/// \brief Default Offset between menu items
	static const int DEFAULT_OFFSET;
	/// \brief Constructor
    OverlayMenu();
	/// \brief Destructor
    virtual ~OverlayMenu();

    virtual void onMouseMotion(Point *relp);
    virtual void onClick(Point *relp);
    virtual Surface* render(void);
    bool isVisible(void);
    void setVisible(bool m_visible);
	/// \brief Get the overlay position value
	/// \return Overlay Position
	OverlayPosition getPosition(void);
	/// \brief Set the new Overlay Position
	/// \param m_position Overylay Position
	void setPosition(OverlayPosition m_position);
	/// \brief Calculate the position of the Overlay Menu
	/// \param m_width Viewport Width (px)
	/// \param m_height Viewport Height (px)
	void fixPosition(int m_width, int m_height);
	/// \brief Add a menu item
	/// \param item Item Pointer
	void add(Item *item);
        /*virtual void handleEvent(KeyEventThrower *src, KeyEventArgs *args);*/
    protected:
	/// \brief Get the last menu item
	/// \return Item Pointer
	Item* getLastItem(void);
	/// \brief Overlay Position
	OverlayPosition position;
	/// \brief Menu items
    ItemContainer container;
	/// \brief Visibility
    bool visible;
	/// \brief Auto Size
	bool autosize;
	/// \brief Render Tick
	int _tick;
    private:
};

}

}

#endif // OVERLAY_H
