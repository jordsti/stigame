#include <Viewport.h>
#include "SampleState.h"

using namespace StiGame;
using namespace Sample;

int main(int argc, char ** argv)
{

    Viewport *viewport = new Viewport(800, 600);
    viewport->setTitle("Sample State");

    SampleState *state = new SampleState();

    viewport->push(state);

    viewport->startLoop();

    delete viewport;
    delete state;

    SDL_Quit();

    return 0;
}
