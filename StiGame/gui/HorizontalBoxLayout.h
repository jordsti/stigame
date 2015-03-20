#ifndef HORIZONTALBOXLAYOUT_H
#define HORIZONTALBOXLAYOUT_H

#include "Layout.h"

namespace StiGame
{
namespace Gui
{
/// \class HorizontalBoxLayout Horizontal Layout Implementation
class HorizontalBoxLayout :
    public Layout
{
    public:
        /// \brief Constructor
        HorizontalBoxLayout();
	/// \brief Destructor
        virtual ~HorizontalBoxLayout();

        void setChildsPosition();
    protected:
    private:
};

}
}

#endif // HORIZONTALBOXLAYOUT_H
