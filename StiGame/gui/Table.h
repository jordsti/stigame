#ifndef TABLE_H
#define TABLE_H

#include "Item.h"
#include "TableRow.h"
#include <vector>

namespace StiGame
{

namespace Gui
{

/// \struct TableColumn
/// \brief Structure to specify column data
struct TableColumn
{
	/// \brief Column Name
	std::string name;
	/// \brief Column Width (px)
	int width;
	/// \brief Column Header Surface
	Surface* surface;
};

//WIP : maybe a namespace for wip class can be interesting

/// \class Table
/// \brief Item that draw a Table [WIP]
class Table :
	public Item
{
public:
	/// \brief Default Column Width (px)
	static const int DEFAULT_COL_WIDTH;
	/// \brief Default Row Height (px)
	static const int DEFAULT_ROW_HEIGHT;
	/// \brief Constructor
	Table();
	/// \brief Destructor
	virtual ~Table();
	
	Surface* render(void);
	/// \brief Get Rows Count (need to rename this method)
	/// \return Rows Count
	int countRows(void);
	
	/// \brief Add a column
	/// \param c_name Column Name
	void addColumn(std::string c_name);
	/// \brief Add a column
	/// \param c_name Column Name
	/// \param width Column Width (px)
	void addColumn(std::string c_name, int width);
	
	/// \brief Create a new row with table data (columns)
	/// \return New Row Pointer
	TableRow* newRow(void);
	
	/// \brief Get the current rendering font
	/// \return Rendering Font
	Font *getFont(void);
	/// \brief Set the rendering font
	/// \param m_font Rendering Font
	void setFont(Font *m_font);
	
	/// \brief Get Row at the specified index
	/// \param index Row Indow
	/// \return Row Pointer
	TableRow* getRow(int index);
	
	virtual void setForeground(Color* m_foreground);
	
	/// \brief Get Row Height
	/// \return Row Height (px)
	int getRowHeight(void);
	/// \brief Set Row Height
	/// \param m_rowHeight Height (px)
	void setRowHeight(int m_rowHeight);
	
protected:
	/// \brief Rows
	std::vector<TableRow*> rows;
	/// \brief Columns
	std::vector<TableColumn*> columns;
	/// \brief Rendering Font
	Font *font;
	/// \brief Columns Count
	int nbColumns;
	/// \brief Row Height
	int rowHeight;
	/// \brief Minimum
	/// \param w1 Width 1
	/// \param w2 Width 2
	static int MinWidth(int w1, int w2);
};

}


}

#endif