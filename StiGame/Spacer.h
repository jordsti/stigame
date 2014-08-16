#ifndef SPACER_H
#define SPACER_H

#include "Item.h"

namespace StiGame
{
namespace Gui
{

class Spacer :
    public Item
{
    public:
        Spacer();
        virtual ~Spacer();
        Surface* render(void);
    protected:
    private:
};


}

}

#endif // SPACER_H
