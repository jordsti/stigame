#ifndef DECORATEDBUTTONBENCHMARK_H
#define DECORATEDBUTTONBENCHMARK_H

#include <BaseGameState.h>
#include <ViewportProfiler.h>
#include <Button.h>
#include <vector>

class ButtonBenchmark :
        public StiGame::BaseGameState,
        public StiGame::ViewportProfiler
{
public:
    ButtonBenchmark();
    virtual ~ButtonBenchmark();
    void onStart(void);
    void onPaint(SDL_Renderer *renderer);
    void frameRenderTime(long long frame_time);
private:
    std::vector<StiGame::Gui::Button*> buttons;
    int max_frame_time;
};

#endif // DECORATEDBUTTONBENCHMARK_H
