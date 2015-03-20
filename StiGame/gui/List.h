#ifndef LIST_H
#define LIST_H

#include "HighlightItem.h"
#include "ValueObject.h"
#include "SelectionEventThrower.h"
#include <vector>
#include <map>

namespace StiGame
{

namespace Gui
{
/// \class List
/// \brief Simple Selection List, only one element can be selected
class List :
	public HighlightItem,
	public SelectionEventThrower
{
public:
	/// \brief Default Line Height (px)
	static const int DEFAULT_LINE_HEIGHT;
	/// \brief Constructor
	List();
	/// \brief Destructor
	virtual ~List();
	
	Surface* render(void);
	/// \brief Add an element to the list
	/// \param vo Value Object Pointer
	void add(ValueObject *vo);
	/// \brief Remove an element from the list
	/// \param vo Value Object Poiter
	void remove(ValueObject *vo);
	/// \brief Get Selected Index
	/// \return Index of the element
	int getSelectedIndex(void);
	/// \brief Set Selected Index
	/// \param index Index of the element
	void setSelectedIndex(int index);
	/// \brief Get the selected Item
	/// \return Value Object Pointer
	ValueObject* getSelectedItem(void);
	/// \brief Get the items count (rename this to itemsCount ?)
	/// \return Items Count
	int getNbItems(void);
	/// \brief Set the rendering Font
	/// \param m_font Font
	void setFont(Font *m_font);
	/// \brief Get the rendering Font
	/// \return Font
	Font* getFont(void);
        /// \brief Get the current Line height
	/// \return Height (px)
	int getLineHeight(void);
	/// \brief Set the line height
	/// \param m_lineHeight Line Height (px)
	void setLineHeight(int m_lineHeight);

	void onClick(Point *relpt);

	/// \brief Set the Draw Border value
	/// \param m_drawBorder Draw Border or not
	void setDrawBorder(bool m_drawBorder);
	/// \brief Get the draw border value
	/// \return Draw Border or not
	bool isDrawBorder(void);

protected:
	/// \brief Draw Border
	bool drawBorder;
	/// \brief Value Object of the list
	std::vector<ValueObject*> values;
	/// \brief Items buffer
	std::map<int, Surface*> strBuffers;
	/// \brief Selected Index
	int selectedIndex;
	/// \brief View Index, this is the first element to be drawed
	int viewIndex;
	/// \brief Up Arrow Graphics
	Surface *upArrow;
	/// \brief Down Arrow Graphics
	Surface *downArrow;
	/// \brief Rendering Font
	Font *font;
	/// \brief Line Height (px)
	int lineHeight;
	/// \brief Mouse Over Index
	int mouseOverIndex;
private:
	/// \brief Show Scroll Button (Up and Down arrows)
	bool _showScrollButtons;
};

}

}


#endif
