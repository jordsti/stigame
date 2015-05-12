#include <Viewport.h>
#include "LabelBenchmark.h"
#include "DecoratedButtonBenchmark.h"
int main(int argc, char ** argv)
{
    StiGame::Viewport *viewport = new StiGame::Viewport();

    //LabelBenchmark *benchmark = new LabelBenchmark();
    DecoratedButtonBenchmark *benchmark = new DecoratedButtonBenchmark();
    viewport->setTitle("StiGame Benchmark");
    viewport->addProfiler(benchmark);

    viewport->setFps(50);
    viewport->push(benchmark);

    viewport->startLoop();

    return 0;
}
