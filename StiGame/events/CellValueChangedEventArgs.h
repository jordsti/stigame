#ifndef CELLVALUECHANGEDEVENTARGS_H
#define CELLVALUECHANGEDEVENTARGS_H

#include <string>

namespace StiGame
{

namespace Gui
{

class TableCell;

class CellValueChangedEventArgs
{
public:
    CellValueChangedEventArgs(TableCell *m_cell, std::string m_oldValue);
    virtual ~CellValueChangedEventArgs();

    TableCell* getCell(void);

    std::string getOldValue(void);
    std::string getNewValue(void);

private:
    std::string oldValue;
    TableCell *cell;
};

}

}

#endif // CELLVALUECHANGEDEVENTARGS_H
