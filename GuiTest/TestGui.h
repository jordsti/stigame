#ifndef TESTGUI_H
#define TESTGUI_H
#include <EventListener.h>
#include <SelectionEventListener.h>
#include <GuiState.h>
#include <List.h>
#include <CheckBox.h>
#include <TabPanel.h>
#include <Label.h>
#include <Button.h>

class TestGui :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener,
    public StiGame::Gui::SelectionEventListener
{
    public:
        TestGui();
        virtual ~TestGui();
        void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
        void handleEvent(StiGame::Gui::SelectionEventThrower *src, StiGame::Gui::SelectionEventArgs *args);
    protected:
        StiGame::Gui::List guiList;
        StiGame::Gui::CheckBox cb1;
        StiGame::Gui::TabPanel tabPanel;
        StiGame::Gui::TabItem tab1;
        StiGame::Gui::TabItem tab2;
        StiGame::Gui::Label tab1Label;
        StiGame::Gui::Button tab1Btn;
    private:
        void initComponents(void);
};

#endif // TESTGUI_H
