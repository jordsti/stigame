#ifndef SPACER_H
#define SPACER_H

#include "Item.h"

namespace StiGame
{
namespace Gui
{
/// \class Spacer
/// \brief Spacer Item for the Layout
class Spacer :
    public Item
{
    public:
	/// \brief Constructor
    Spacer();
	/// \brief Destructor
    virtual ~Spacer();
	
    Surface* render(void);
    protected:
    private:
};


}

}

#endif // SPACER_H
