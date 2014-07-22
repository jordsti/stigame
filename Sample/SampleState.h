#ifndef SAMPLESTATE_H
#define SAMPLESTATE_H

#include <GuiState.h>
#include <Button.h>
#include <Label.h>

namespace Sample
{

class SampleState :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener
{
    public:
        SampleState();
        virtual ~SampleState();
        void handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
    protected:
        StiGame::Gui::Button btnQuit;
        StiGame::Gui::Label lblTitle;
    private:
        void initComponents(void);
};

}

#endif // SAMPLESTATE_H
