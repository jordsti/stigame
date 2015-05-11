#include "TableTestState.h"
#include <iostream>
TableTestState::TableTestState() :
    StiGame::Gui::GuiState()
{
    initComponents();
}

TableTestState::~TableTestState()
{

}


void TableTestState::initComponents(void)
{
    table.setDimension(400, 500);
    add(&table);

    //filling table
    table.addColumn("Id", 75);
    table.addColumn("Name", 150);
    table.addColumn("Value", 100);

    StiGame::Gui::TableRow *row;

    row = table.newRow();

    row->getCell(0)->setValue("1");
    row->getCell(1)->setValue("Josh");
    row->getCell(2)->setValue("101010");

    row = table.newRow();

    row->getCell(0)->setValue("2");
    row->getCell(1)->setValue("John Doe");
    row->getCell(2)->setValue("121212");

    row = table.newRow();

    row->getCell(0)->setValue("3");
    row->getCell(1)->setValue("Josh Limit");
    row->getCell(2)->setValue("131313");

    table.subscribe(this);
}


void TableTestState::handleEvent(StiGame::Gui::TableClickEventThrower *src, StiGame::Gui::TableClickEventArgs *args)
{
    if(args->isHeaderClicked())
    {
        std::cout << "Header Clicked :" << args->getColumnIndex() << std::endl;
    }
    else
    {
        std::cout << "Table Click Event : " << args->getRowIndex() << ", " << args->getColumnIndex() << ", " << args->getCell()->getValue() << std::endl;
        table.removeRow(args->getRowIndex());
    }
}
