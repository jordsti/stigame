#include "TimeTools.h"

namespace StiGame
{

Time::Time()
{
    //ctor
}

Time::~Time()
{
    //dtor
}

std::chrono::time_point<std::chrono::high_resolution_clock> Time::time_start = std::chrono::high_resolution_clock::now();


long long Time::GetMsTimestamp(void)
{

    auto tp = std::chrono::high_resolution_clock::now();
    auto diff = tp - time_start;
    long long stamp = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
    return stamp;

}

int Time::GenerateSeed()
{
    auto tp = std::chrono::high_resolution_clock::now();
    long long stamp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();
    stamp = stamp % 1073741824;
    int seed = static_cast<int>(stamp);
    return seed;
}


}
