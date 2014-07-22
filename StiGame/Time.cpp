#include "Time.h"
#include <chrono>
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

unsigned long long Time::GetMsTimestamp(void)
{
    std::chrono::time_point<std::chrono::steady_clock> tp = std::chrono::steady_clock::now();

    unsigned long long stamp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();

    return stamp;
}


}
