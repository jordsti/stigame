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

class List :
	public HighlightItem,
	public SelectionEventThrower
{
public:
	static const int DEFAULT_LINE_HEIGHT;

	List();
	virtual ~List();

	Surface* render(void);

	void add(ValueObject *vo);

	void remove(ValueObject *vo);

	int getSelectedIndex(void);
	void setSelectedIndex(int index);

    ValueObject* getSelectedItem(void);

	int getNbItems(void);

	void setFont(Font *m_font);
	Font* getFont(void);

	int getLineHeight(void);
	void setLineHeight(int m_lineHeight);

	void onClick(Point *relpt);

    void setDrawBorder(bool m_drawBorder);
    bool isDrawBorder(void);

protected:
    bool drawBorder;
    std::vector<ValueObject*> values;
	std::map<int, Surface*> strBuffers;
	int selectedIndex;
	int viewIndex;
	Surface *upArrow;
	Surface *downArrow;
	Font *font;
	int lineHeight;
	int mouseOverIndex;
private:
    bool _showScrollButtons;
};

}

}


#endif
