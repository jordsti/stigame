#ifndef STIGAME_TIME_H
#define STIGAME_TIME_H

#include <chrono>

namespace StiGame
{

class Time
{
    public:
        Time();
        virtual ~Time();
        static long long GetMsTimestamp(void);
        static int GenerateSeed(void);
    protected:
        static std::chrono::time_point<std::chrono::high_resolution_clock> time_start;
    private:
};

}

#endif // STIME_H
