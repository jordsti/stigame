#ifndef LAYOUT_H
#define LAYOUT_H

#include "Item.h"
#include <list>

namespace StiGame
{

namespace Gui
{

enum LayoutVerticalAlign
{
    LVA_Top,
    LVA_Middle,
    LVA_Bottom
};

enum LayoutHorizontalAlign
{
    LHA_Left,
    LHA_Center,
    LHA_Right
};

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

        virtual void setVerticalAlign(LayoutVerticalAlign m_verticalAlign);
        virtual void setHorizontalAlign(LayoutHorizontalAlign m_horizontalAlign);

        LayoutVerticalAlign getVerticalAlign(void);
        LayoutHorizontalAlign getHorizontalAlign(void);

        //need to override all the event stack
        virtual void onClick(Point *relp);
        virtual void onMouseMotion(Point *relp);
        virtual void onKeyUp(SDL_KeyboardEvent *evt);
        virtual void onTextInput(char* text);
        Surface* render(void);

        void setDrawBorder(bool m_drawBorder);

    protected:
        void resized();
        virtual void setChildsPosition(void) = 0;

        MPoint mouse;
        std::list<Item*> childs;
        LayoutVerticalAlign verticalAlign;
        LayoutHorizontalAlign horizontalAlign;
        bool childsChanged;
        bool drawBorder;
    private:

};

}


}
#endif // LAYOUT_H
