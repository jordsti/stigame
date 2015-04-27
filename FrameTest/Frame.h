#ifndef FRAME_H
#define FRAME_H

#include <string>
#include "GuiFrameState.h"
#include "EventListener.h"

class Frame :
        public StiGame::Gui::GuiFrameState,
        public StiGame::EventListener
{
public:
    Frame(std::string path);
    virtual ~Frame();

    bool handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
protected:
    virtual void initItems(void);
};

#endif // FRAME_H
