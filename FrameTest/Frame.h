#ifndef FRAME_H
#define FRAME_H

#include <string>
#include "GuiFrameState.h"
#include "EventListener.h"
#include "SelectionEventListener.h"
#include "Button.h"
#include "List.h"
#include "ComboBox.h"
class Frame :
        public StiGame::Gui::GuiFrameState,
        public StiGame::EventListener,
        public StiGame::Gui::SelectionEventListener
{
public:
    Frame(std::string path);
    virtual ~Frame();

    bool handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
    void handleEvent(StiGame::Gui::SelectionEventThrower *src, StiGame::Gui::SelectionEventArgs *args);
protected:
    virtual void initItems(void);
private:
    StiGame::Gui::Button *btn1;
    StiGame::Gui::List *list;
    StiGame::Gui::ComboBox *cb;

};

#endif // FRAME_H
