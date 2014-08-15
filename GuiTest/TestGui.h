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
#include <DecoratedButton.h>
#include <TextBox.h>
#include <VerticalBoxLayout.h>
#include "TestTabItem.h"

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
        TestTabItem *tab3;
        StiGame::Gui::Label tab1Label;
        StiGame::Gui::Button tab1Btn;
        StiGame::Gui::TextBox tbName;
        StiGame::Gui::VerticalBoxLayout vlayout;
        StiGame::Gui::Label lbl_vlayout;
        StiGame::Gui::Label lbl_vlayout2;
        StiGame::Gui::Label lbl_vlayout3;
        StiGame::Gui::Label lbl_vlayout4;
        StiGame::Gui::Label lbl_vlayout5;
        StiGame::Gui::DecoratedButton dbtn1;
    private:
        void initComponents(void);
};

#endif // TESTGUI_H
