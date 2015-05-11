#include <Viewport.h>
#include "TableTestState.h"

int main(int argc, char ** argv)
{

    StiGame::Viewport *viewport = new StiGame::Viewport(800, 600);

    viewport->setTitle("Table Test");

    TableTestState *state = new TableTestState();

    viewport->push(state);
    viewport->startLoop();

	return 0;
}
