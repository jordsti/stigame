#ifndef MSTYLE_H
#define MSTYLE_H

#include "Style.h"

namespace StiGame
{

namespace Gui
{

class MStyle :
    public Style
{
    public:
        MStyle();
        virtual ~MStyle();
        void setForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setHighlightForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setHighlightBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setDropListArrow(Surface *surface);
        void setUpArrow(Surface *surface);
        void setDownArrow(Surface *surface);
        void setCheckBox(Surface *surface);
        void setCheckBoxChecked(Surface *surface);
        void setRadio(Surface *surface);
        void setRadioChecked(Surface *surface);
        void setButtonLeft(Surface *surface);
        void setButtonRight(Surface *surface);
        void setButtonBackground(Surface *surface);
        void setHighlightButtonLeft(Surface *surface);
        void setHighlightButtonRight(Surface *surface);
        void setHighlightButtonBackground(Surface *surface);

        void setNormalFont(Font *font);
        void setBigFont(Font *font);
    protected:
    private:
};

}

}

#endif // MSTYLE_H
