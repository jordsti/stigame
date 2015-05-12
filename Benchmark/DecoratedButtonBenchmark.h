#ifndef DECORATEDBUTTONBENCHMARK_H
#define DECORATEDBUTTONBENCHMARK_H

#include <BaseGameState.h>
#include <ViewportProfiler.h>
#include <DecoratedButton.h>
#include <vector>

class DecoratedButtonBenchmark :
        public StiGame::BaseGameState,
        public StiGame::ViewportProfiler
{
public:
    DecoratedButtonBenchmark();
    virtual ~DecoratedButtonBenchmark();
    void onStart(void);
    void onPaint(SDL_Renderer *renderer);
    void frameRenderTime(long long frame_time);
private:
    std::vector<StiGame::Gui::DecoratedButton*> buttons;
    int max_frame_time;
};

#endif // DECORATEDBUTTONBENCHMARK_H
