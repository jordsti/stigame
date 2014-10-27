#include "TableRow.h"

namespace StiGame
{

namespace Gui
{

TableRow::TableRow()
{

}

TableRow::~TableRow()
{

}

void TableRow::addCell(TableCell *cell)
{
	cells.push_back(cell);
}

TableCell* TableRow::getCell(int index)
{
	return cells[index];
}

int TableRow::countCells(void)
{
	return cells.size();
}

}

}