#ifndef TABLEROW_H
#define TABLEROW_H

#include "TableCell.h"
#include <vector>

namespace StiGame
{

namespace Gui
{

class TableRow 
{
public:
	TableRow();
	virtual ~TableRow();
	void addCell(TableCell *cell);
	TableCell* getCell(int index);
	int countCells(void);
protected:
	std::vector<TableCell*> cells;
};


}


}

#endif