#ifndef TABLE_H
#define TABLE_H

#include "Item.h"
#include "TableRow.h"
#include <vector>

namespace StiGame
{

namespace Gui
{

struct TableColumn
{
	std::string name;
	int width;
	Surface* surface;
};

//WIP
class Table :
	public Item
{
public:
	static const int DEFAULT_COL_WIDTH;
	static const int DEFAULT_ROW_HEIGHT;
	Table();
	virtual ~Table();
	Surface* render(void);
	
	int countRows(void);
	
	void addColumn(std::string c_name);
	void addColumn(std::string c_name, int width);
	
	TableRow* newRow(void);
	
	Font *getFont(void);
	void setFont(Font *m_font);
	
	TableRow* getRow(int index);
	
	virtual void setForeground(Color* m_foreground);
	
	int getRowHeight(void);
	void setRowHeight(int m_rowHeight);
	
protected:
	std::vector<TableRow*> rows;
	std::vector<TableColumn*> columns;
	Font *font;
	int nbColumns;
	int rowHeight;
	static int MinWidth(int w1, int w2);
};

}


}

#endif