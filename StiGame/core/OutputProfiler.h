#ifndef OUTPUTPROFILER_H
#define OUTPUTPROFILER_H

#include "ViewportProfiler.h"

namespace StiGame
{

class OutputProfiler :
        public ViewportProfiler
{
public:
    OutputProfiler();
    virtual ~OutputProfiler();

    void frameRenderTime(long long frame_time);
    void stateChanged(BaseGameState *new_state);
    void resolutionChanged(int m_width, int m_height);
    void stateCleaned(void);
};

}

#endif // OUTPUTPROFILER_H
