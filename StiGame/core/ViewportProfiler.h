#ifndef VIEWPORTPROFILER_H
#define VIEWPORTPROFILER_H

#include "BaseGameState.h"

namespace StiGame
{

class ViewportProfiler
{
public:
    ViewportProfiler();
    virtual ~ViewportProfiler();

    virtual void frameRenderTime(long long frame_time);
    virtual void stateChanged(BaseGameState *new_state);
    virtual void resolutionChanged(int m_width, int m_height);
    virtual void stateCleaned(void);
};

}

#endif // VIEWPORTPROFILER_H
