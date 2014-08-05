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
        Layout(std::string name);
        virtual ~Layout();

        Item* getChildAt(int index);
        virtual void addChild(Item *child);
        virtual void removeChild(Item *to_remove);
        unsigned int childsCount();

        //need to override all the event stack
        virtual void onClick(Point *relp);
        virtual void onMouseMotion(Point *relp);
        virtual void onKeyUp(SDL_KeyboardEvent *evt);
        virtual void onTextInput(char* text);
        Surface* render(void);

    protected:
        void resized();
        virtual void setChildsPosition(void) = 0;
        MPoint mouse;
        std::list<Item*> childs;
    private:
};

}


}
#endif // LAYOUT_H
