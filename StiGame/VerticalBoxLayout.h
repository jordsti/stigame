#ifndef VERTICALBOXLAYOUT_H
#define VERTICALBOXLAYOUT_H

#include "Layout.h"

namespace StiGame
{
namespace Gui
{

class VerticalBoxLayout :
    public Layout
{
    public:
        VerticalBoxLayout();
        virtual ~VerticalBoxLayout();
        void setChildsPosition(void);
    protected:
    private:
};

}

}


#endif // VERTICALBOXLAYOUT_H
