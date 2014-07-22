#include "SampleState.h"
using namespace StiGame;
using namespace Gui;

namespace Sample
{

SampleState::SampleState() : GuiState()
{
    //ctor
    initComponents();
}

SampleState::~SampleState()
{
    //dtor
}

void SampleState::initComponents(void)
{
    //init your gui items here
    btnQuit = Button();
    btnQuit.setCaption("Quit");
    btnQuit.set(300, 400);
    btnQuit.subscribe(this);

    lblTitle = Label();
    lblTitle.setCaption("Sample StiGame State !");
    lblTitle.set(100, 10);

    add(&btnQuit);
    add(&lblTitle);
}

void SampleState::handleEvent(EventThrower *src, EventArgs *evt)
{
    if(src == &btnQuit)
    {
        running = false;
    }
}

}
