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

void TableRow::setValue(int index, std::string m_value)
{
    if(index < cells.size())
    {
        TableCell *cell = cells[index];
        cell->setValue(m_value);
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

void TableRow::setForeground(Color *m_foreground)
{
    auto cit(cells.begin()), cend(cells.end());
    for(;cit!=cend;++cit)
    {
        (*cit)->setForeground(m_foreground);
    }
}

void TableRow::setFont(Font *m_font)
{
    auto cit(cells.begin()), cend(cells.end());
    for(;cit!=cend;++cit)
    {
        (*cit)->setFont(m_font);
    }
}

}

}
