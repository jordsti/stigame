#include <Viewport.h>
#include "TestGui.h"

using namespace StiGame;

int main(int argc, char ** argv)
{
    Viewport *vpt = new Viewport(900, 600);

    vpt->setTitle("Gui Test");

    vpt->setFps(50);

    TestGui *tg = new TestGui();

    vpt->push(tg);
    vpt->startLoop();

    delete vpt;
    delete tg;

    SDL_Quit();

    return 0;
}
