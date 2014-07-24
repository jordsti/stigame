#ifndef TESTTABITEM_H
#define TESTTABITEM_H
#include <TabItem.h>
#include <Button.h>
#include <List.h>
#include <EventListener.h>

class TestTabItem :
    public StiGame::Gui::TabItem,
    public StiGame::EventListener
{
    public:
        TestTabItem();
        virtual ~TestTabItem();
    protected:
        StiGame::Gui::Button *btnOk;
        StiGame::Gui::Button *btnCancel;
        StiGame::Gui::List *listOptions;

        StiGame::Gui::ValueObject *vo_1;
        StiGame::Gui::ValueObject *vo_2;
        StiGame::Gui::ValueObject *vo_3;
        StiGame::Gui::ValueObject *vo_4;

        void resized(void);
        void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *args);
    private:
        void initComponents(void);
};

#endif // TESTTABITEM_H
