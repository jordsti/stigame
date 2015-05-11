#ifndef COMBOBOX_H
#define COMBOBOX_H
#include <list>
#include <map>
#include "HighlightItem.h"
#include "ValueObject.h"
#include "SelectionEventThrower.h"

namespace StiGame {

namespace Gui
{

/// \class ComboBox
/// \brief Combo Box Gui Item
class ComboBox :
    public HighlightItem,
    public SelectionEventThrower
{
public:
	/// \brief Create a new Combo Box
    ComboBox();
	/// \brief Destructor
    virtual ~ComboBox();
	/// \brief Get Selected Item
	/// \return Selected Value Object
    ValueObject *getSelectedItem(void);
	/// \brief Get Selected Item Index
	/// \return Index
    int getSelectedIndex(void);
	/// \brief Set Selected Item Index
	/// \param m_selectionIndex Index
    void setSelectedIndex(int m_selectedIndex);
	/// \brief Set Selected Item
	/// \param selectedItem Item
    void setSelectedItem(ValueObject *selectedItem);
	/// \brief Add a Value Object to the Combo Box
	/// \param vo Value Object to add
    void add(ValueObject *vo);
	/// \brief Remove a Value Object of the Combo Box
	/// \param vo Value Object to remove
    void remove(ValueObject *vo);
	/// \brief Set Text font
	/// \param m_font Font
    void setFont(Font *m_font);
	/// \brief On Click Event
	/// \param relp Relative mouse position
    void onClick(Point *relp);
	/// \brief Render the Gui Item
	/// \return Rendered Combo Box
    Surface *render(void);
	/// \brief Mouse Motion Event
	/// \param relp Relative Mouse position
    void onMouseMotion(Point *relp);

protected:
	/// \brief Render Drop List
	/// \param buffer Item Buffer
    void renderDroplist(Surface *buffer);
	/// \brief Show the Drop List
    void showDroplist(void);
	/// \brief Close the Drop List
    void closeDroplist(void);
	/// \brief Current Item
    int currentItem;
	/// \brief Item Size
    int itemSize;
	/// \brief Closed Combo Box Height
    int closedHeight;
	/// \brief Selected Item Id
    int selectedId;
	/// \brief Text Offset
    int textOffset;
	/// \brief Item Hover
    int itemHover;
	/// \brief Text Font
    Font *font;
	/// \brief Value Object List
    std::list<ValueObject*> items;
	/// \brief Value Object String Buffer
    std::map<int, Surface*> stringsBuffer;
	/// \brief Drop Arrow Image
    Surface *dropArrow;
	/// \brief Drop List Up Arrow
    Surface *upArrow;
	/// \brief Drop List Down Arrow
    Surface *downArrow;
	/// \brief Numbers of item to show in the Drop List
    int nbItemsToShow;
	/// \brief Draw Drop List
    bool drawDroplist;
	/// \brief Default Number of items to show
	static const int DefaultNbItems;
	/// \brief Default Text Offset
	static const int DefaultTextOffset;
private:
};

}

}
#endif // COMBOBOX_H
