#ifndef VERTICALBOXLAYOUT_H
#define VERTICALBOXLAYOUT_H

#include "Layout.h"

namespace StiGame
{
namespace Gui
{
/// \class VerticalBoxLayout
/// \brief Vertical Layout implementation
class VerticalBoxLayout :
    public Layout
{
    public:
        /// \brief Constructor
        VerticalBoxLayout();
	/// \brief Destructor
        virtual ~VerticalBoxLayout();
	
        void setChildsPosition(void);
    protected:
    private:
};

}

}


#endif // VERTICALBOXLAYOUT_H
