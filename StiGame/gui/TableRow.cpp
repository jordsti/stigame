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
    auto cit(cells.begin()), cend(cells.end());
    for(;cit!=cend;++cit)
    {
        delete (*cit);
    }
}

void TableRow::addCell(TableCell *cell)
{
	cells.push_back(cell);
}

TableCell* TableRow::getCell(int index)
{
	return cells[index];
}

int TableRow::cellsCount(void)
{
	return cells.size();
}

void TableRow::subscribeCells(CellValueChangedEventListener *listener)
{
    auto cit(cells.begin()), cend(cells.end());
    for(;cit!=cend;++cit)
    {
        TableCell *cell = (*cit);
        cell->subscribe(listener);
    }
}

int TableRow::getCellIndex(TableCell *cell)
{
    int i=0;
    auto cit(cells.begin()), cend(cells.end());
    for(;cit!=cend;++cit)
    {
        if((*cit) == cell)
        {
            return i;
        }

        i++;
    }

    return -1;
}

}

}
