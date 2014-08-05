#ifndef LAYOUT_H
#define LAYOUT_H

#include "Item.h"
#include <list>

namespace StiGame
{

namespace Gui
{

class Layout :
    public Item
{
    public:
        Layout();
        virtual ~Layout();

        Item* getChildAt(int index);
        virtual void addChild(Item *child);
        virtual void removeChild(Item *to_remove);
        unsigned int childsCount();

        //need to override all the event stack
        virtual void onClick(Point *relp);
        virtual void onMouseMotion(Point *relp);

        Surface* render(void);

    protected:
        void resized();
        virtual void setChildsPosition(void) = 0;

        std::list<Item*> childs;
    private:
};

}


}
#endif // LAYOUT_H
