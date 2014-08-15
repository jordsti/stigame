#ifndef DECORATEDBUTTON_H
#define DECORATEDBUTTON_H
#include "Item.h"
#include "StringRenderer.h"

namespace StiGame
{
namespace Gui
{

class DecoratedButton :
    public Item
{
    public:
        DecoratedButton();
        virtual ~DecoratedButton();

        Surface* render(void);

        std::string getCaption(void);
        void setCaption(std::string m_caption);

    protected:
        void resized(void);
        Surface *buttonLeft;
        Surface *buttonRight;
        Surface *buttonBackground;

        Surface *surfaceBackground;

        StringRenderer stringBuffer;

        void drawBackground(void);

        std::string caption;
    private:
};

}
}

#endif // DECORATEDBUTTON_H
