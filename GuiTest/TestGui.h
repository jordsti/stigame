#ifndef TESTGUI_H
#define TESTGUI_H
#include <GuiState.h>
#include <List.h>
#include <CheckBox.h>

class TestGui : public StiGame::Gui::GuiState
{
    public:
        TestGui();
        virtual ~TestGui();
    protected:
        StiGame::Gui::List guiList;
        StiGame::Gui::CheckBox cb1;
    private:
        void initComponents(void);
};

#endif // TESTGUI_H
