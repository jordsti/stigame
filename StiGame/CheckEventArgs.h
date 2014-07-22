#ifndef CHECKEVENTARGS_H
#define CHECKEVENTARGS_H
#include <string>
#include "EventArgs.h"

namespace StiGame
{
class CheckEventArgs :
    public EventArgs
{
    public:
        CheckEventArgs(bool m_checked, std::string m_caption);
        virtual ~CheckEventArgs();
        bool isChecked(void);
        std::string getCaption(void);
    protected:
        bool checked;
        std::string caption;
    private:
};
}

#endif // CHECKEVENTARGS_H
