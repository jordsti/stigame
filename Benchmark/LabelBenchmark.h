#ifndef LABELBENCHMARK_H
#define LABELBENCHMARK_H

#include <BaseGameState.h>
#include <ViewportProfiler.h>
#include <vector>
#include <Label.h>


class LabelBenchmark :
        public StiGame::BaseGameState,
        public StiGame::ViewportProfiler
{
public:
    LabelBenchmark();
    virtual ~LabelBenchmark();
    void onStart(void);
    void onPaint(SDL_Renderer *renderer);
    void frameRenderTime(long long frame_time);
private:
    int max_frame_time;
    std::vector<StiGame::Gui::Label*> labels;
};

#endif // LABELBENCHMARK_H
