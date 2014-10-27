#ifndef DECORATEDBUTTON_H
#define DECORATEDBUTTON_H
#include "Item.h"
#include "StringRenderer.h"
#include "EventThrower.h"

namespace StiGame
{
namespace Gui
{

class DecoratedButton :
    public Item,
    public EventThrower
{
    public:
        DecoratedButton();
        virtual ~DecoratedButton();

        Surface* render(void);

        std::string getCaption(void);
        void setCaption(std::string m_caption);
        void onClick(Point *relp);

    protected:
        void resized(void);
        Surface *buttonLeft;
        Surface *buttonRight;
        Surface *buttonBackground;

        Surface *buttonHighlightLeft;
        Surface *buttonHighlightRight;
        Surface *buttonHighlightBackground;

        Surface *surfaceBackground;
        Surface *surfaceHighlightBackground;

        StringRenderer stringBuffer;

        void drawBackground(void);

        std::string caption;
    private:
};

}
}

#endif // DECORATEDBUTTON_H
