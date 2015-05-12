#include "OutputProfiler.h"
#include <iostream>
namespace StiGame
{

OutputProfiler::OutputProfiler()
{

}

OutputProfiler::~OutputProfiler()
{

}

void OutputProfiler::frameRenderTime(long long frame_time)
{
    std::cout << "Frame Render Time: " << frame_time << " ms" << std::endl;
}

void OutputProfiler::stateChanged(BaseGameState *new_state)
{
    std::cout << "State Changed: " << new_state << std::endl;
}

void OutputProfiler::resolutionChanged(int m_width, int m_height)
{
    std::cout << "Resolution Changed: " << m_width << "x" << m_height << std::endl;
}

void OutputProfiler::stateCleaned(void)
{
    std::cout << "State Cleaned" << std::endl;
}

}
