#ifndef TABLECLICKEVENTARGS_H
#define TABLECLICKEVENTARGS_H


namespace StiGame
{

namespace Gui
{

class Table;
class TableRow;
class TableCell;

class TableClickEventArgs
{
public:
    TableClickEventArgs(int m_rowIndex, int m_columnIndex);
    TableClickEventArgs(Table *m_table, TableRow *m_row, TableCell *m_cell, int m_rowIndex, int m_columnIndex);
    virtual ~TableClickEventArgs();

    TableRow* getRow(void);
    Table* getTable(void);
    TableCell* getCell(void);
    int getRowIndex(void);
    int getColumnIndex(void);

    bool isHeaderClicked(void);
private:
    TableRow *row;
    TableCell *cell;
    Table *table;
    int rowIndex;
    int columnIndex;
};

}

}

#endif // TABLECLICKEVENTARGS_H
