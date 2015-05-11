#include "CellValueChangedEventArgs.h"
#include "TableCell.h"
namespace StiGame
{

namespace Gui
{

CellValueChangedEventArgs::CellValueChangedEventArgs(TableCell *m_cell, std::string m_oldValue)
{
    cell = m_cell;
    oldValue = m_oldValue;
}

CellValueChangedEventArgs::~CellValueChangedEventArgs()
{

}

TableCell* CellValueChangedEventArgs::getCell(void)
{
    return cell;
}

std::string CellValueChangedEventArgs::getOldValue(void)
{
    return oldValue;
}

std::string CellValueChangedEventArgs::getNewValue(void)
{
    return cell->getValue();
}

}


}
