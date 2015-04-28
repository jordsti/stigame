#ifndef LAYOUT_H
#define LAYOUT_H

#include "Item.h"
#include "ItemContainer.h"
#include "BaseChildSupport.h"

namespace StiGame
{

namespace Gui
{

enum LayoutVerticalAlign
{
    LVA_Top,
    LVA_Middle,
    LVA_Bottom
};

enum LayoutHorizontalAlign
{
    LHA_Left,
    LHA_Center,
    LHA_Right
};

/// \class Layout
/// \brief Base class for layout handling, provide horizontal and vertical alignment
class Layout :
    public Item,
    public BaseChildSupport
{
    public:
	/// \brief Constructor
    /// \param name Item name
    Layout(std::string name);
	/// \brief Destructor
    virtual ~Layout();
	
    /// \brief Get Item located at this index
    /// \param index Item Index
    /// \return Item Pointer
    Item* getChildAt(int index);
    /// \brief Add Child Item to the Layout
    /// \param child Item to add
    virtual void addChild(Item *child);
    /// \brief Remove an Item from the Layout
    /// \param to_remove Item to remove
    virtual void removeChild(Item *to_remove);
    /// \brief Get the Childs Item count
    /// \return Childs count
    unsigned int childsCount();
	/// \brief Set the Vertical Alignment
	/// \param m_verticalAlign Vertical Alignment
    virtual void setVerticalAlign(LayoutVerticalAlign m_verticalAlign);
	/// \brief Set the Horizontal Aligment
	/// \param m_horizontalAlign Horizontal Aligment
    virtual void setHorizontalAlign(LayoutHorizontalAlign m_horizontalAlign);
	/// \brief Get the current Vertical Alignment
	/// \return Current Vertical Alignment
    LayoutVerticalAlign getVerticalAlign(void);
	/// \brief Get the current Horizontal Alignment
	/// \return Current Horizontal Alignment
    LayoutHorizontalAlign getHorizontalAlign(void);

    //need to override all the event stack
	
    virtual void onClick(Point *relp);
    virtual void onMouseMotion(Point *relp);
    virtual void onKeyUp(SDL_KeyboardEvent *evt);
    virtual void onTextInput(char* text);
    Surface* render(void);

	/// \brief Draw Layout Border
	/// \param m_drawBorder Draw Border or not
    void setDrawBorder(bool m_drawBorder);

protected:
    void resized();
	/// \brief Method to override by the Layout implementation
    virtual void setChildsPosition(void) = 0;
	/// \brief Current mouse position
    MPoint mouse;
	/// \brief Vertical Alignment
    LayoutVerticalAlign verticalAlign;
	/// \brief Horizontal Alignment
    LayoutHorizontalAlign horizontalAlign;
	/// \brief Childs has changed
    bool childsChanged;
	/// \brief Draw border or not
    bool drawBorder;


private:

};

}


}
#endif // LAYOUT_H
