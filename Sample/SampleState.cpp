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
    btnQuit.setPoint(300, 400);
    btnQuit.subscribe(this);

    lblTitle = Label();
    lblTitle.setCaption("Sample StiGame State !");
    lblTitle.setPoint(100, 10);

    add(&btnQuit);
    add(&lblTitle);
}

void SampleState::onPaint(SDL_Renderer *renderer)
{


    GuiState::onPaint(renderer);

    Sprite *spr = sprites.getSprite("test");
    spr->setPoint(10, 10);
    spr->tick();
    spr->render();
}

bool SampleState::handleEvent(EventThrower *src, EventArgs *evt)
{
    if(src == &btnQuit)
    {
        running = false;
    }
}

void SampleState::onStart()
{
    sprites.setRenderer(viewport->getRenderer());
    sprites.loadVarFile("test");

    running = true;
}

}
