#include <Viewport.h>
#include "TestGui.h"

using namespace StiGame;

int main(int argc, char ** argv)
{
    Viewport *vpt = new Viewport(900, 600);

    vpt->setTitle("Gui Test");

    vpt->setFps(50);

    BaseGameState *gs = new TestGui();

    vpt->push(gs);
    vpt->startLoop();

    delete vpt;
    delete gs;

    SDL_Quit();

    return 0;
}
