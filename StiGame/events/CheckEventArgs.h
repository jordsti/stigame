#ifndef CHECKEVENTARGS_H
#define CHECKEVENTARGS_H
#include <string>
#include "EventArgs.h"

namespace StiGame
{
/// \class CheckEventArgs
/// \brief The Check State of an element has changed
class CheckEventArgs :
    public EventArgs
{
    public:
        /// \brief New Check Event Args
        /// \param m_checked New Checked Value
        /// \param m_caption Caption of the element
        CheckEventArgs(bool m_checked, std::string m_caption);
        /// \brief Destructor
        virtual ~CheckEventArgs();
        /// \brief Is Checked
        /// \return Checked or not
        bool isChecked(void);
        /// \brief Get the caption
        /// \return Element Caption
        std::string getCaption(void);
    protected:
        /// \brief Checked value
        bool checked;
        /// \brief Element Caption
        std::string caption;
    private:
};
}

#endif // CHECKEVENTARGS_H
