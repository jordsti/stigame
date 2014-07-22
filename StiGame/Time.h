#ifndef TIME_H
#define TIME_H

namespace StiGame
{

class Time
{
    public:
        Time();
        virtual ~Time();
        static unsigned long long GetMsTimestamp(void);
    protected:
    private:
};

}

#endif // STIME_H
