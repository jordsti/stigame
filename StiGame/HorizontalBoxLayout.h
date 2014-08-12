#ifndef HORIZONTALBOXLAYOUT_H
#define HORIZONTALBOXLAYOUT_H

#include "Layout.h"

namespace StiGame
{
namespace Gui
{

class HorizontalBoxLayout :
    public Layout
{
    public:
        HorizontalBoxLayout();
        virtual ~HorizontalBoxLayout();
        void setChildsPosition();
    protected:
    private:
};

}
}

#endif // HORIZONTALBOXLAYOUT_H
