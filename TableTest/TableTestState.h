#ifndef TABLETESTSTATE_H
#define TABLETESTSTATE_H

#include <GuiState.h>
#include <Table.h>
#include <TableClickEventListener.h>

class TableTestState :
        public StiGame::Gui::GuiState,
        public StiGame::Gui::TableClickEventListener
{
public:
    TableTestState();
    virtual ~TableTestState();

    void handleEvent(StiGame::Gui::TableClickEventThrower *src, StiGame::Gui::TableClickEventArgs *args);
private:
    void initComponents(void);

    StiGame::Gui::Table table;
};

#endif // TABLETESTSTATE_H
