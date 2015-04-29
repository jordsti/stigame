#ifndef SAMPLESTATE_H
#define SAMPLESTATE_H

#include <GuiState.h>
#include <Button.h>
#include <Label.h>
#include <SpriteLibrary.h>

namespace Sample
{

class SampleState :
    public StiGame::Gui::GuiState,
    public StiGame::EventListener
{
    public:
        SampleState();
        virtual ~SampleState();
        bool handleEvent(StiGame::EventThrower *src, StiGame::EventArgs *evt);
        void onPaint(SDL_Renderer *renderer);
        void onStart();
    protected:
        StiGame::Gui::Button btnQuit;
        StiGame::Gui::Label lblTitle;
        StiGame::SpriteLibrary sprites;
    private:
        void initComponents(void);
};

}

#endif // SAMPLESTATE_H
