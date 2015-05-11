#include "TableClickEventArgs.h"

namespace StiGame
{

namespace Gui
{

TableClickEventArgs::TableClickEventArgs(Table *m_table, TableRow *m_row, TableCell *m_cell, int m_rowIndex, int m_columnIndex)
{
    table = m_table;
    row = m_row;
    cell = m_cell;
    rowIndex = m_rowIndex;
    columnIndex = m_columnIndex;
}

TableClickEventArgs::TableClickEventArgs(int m_rowIndex, int m_columnIndex)
{
    table = nullptr;
    row = nullptr;
    cell = nullptr;
    rowIndex = m_rowIndex;
    columnIndex = m_columnIndex;
}

TableClickEventArgs::~TableClickEventArgs()
{

}

bool TableClickEventArgs::isHeaderClicked(void)
{
    return rowIndex == -1;
}

TableRow* TableClickEventArgs::getRow(void)
{
    return row;
}

Table* TableClickEventArgs::getTable(void)
{
    return table;
}

TableCell* TableClickEventArgs::getCell(void)
{
    return cell;
}

int TableClickEventArgs::getRowIndex(void)
{
    return rowIndex;
}

int TableClickEventArgs::getColumnIndex(void)
{
    return columnIndex;
}

}

}
