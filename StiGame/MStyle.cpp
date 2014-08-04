#include "MStyle.h"


namespace StiGame
{

namespace Gui
{

MStyle::MStyle()
{
    //ctor
    foreground = Color();
    background = Color();
    highlightForeground = Color();
    highlightBackground = Color();

    dropListArrow = nullptr;
    upArrow = nullptr;
    downArrow = nullptr;
    checkbox = nullptr;
    checkboxChecked = nullptr;
    radio = nullptr;
    radioChecked = nullptr;
    normalFont = nullptr;
}

MStyle::~MStyle()
{
    //dtor
}

void MStyle::setForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    foreground.setRGBA(r, g, b, a);
}

void MStyle::setBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    background.setRGBA(r, g, b, a);
}

void MStyle::setHighlightForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    highlightForeground.setRGBA(r, g, b, a);
}

void MStyle::setHighlightBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
        highlightBackground.setRGBA(r, g, b, a);
}

void MStyle::setDropListArrow(Surface *surface)
{
    dropListArrow = surface;
}

void MStyle::setUpArrow(Surface *surface)
{
    upArrow = surface;
}

void MStyle::setDownArrow(Surface *surface)
{
        downArrow = surface;
}

void MStyle::setCheckBox(Surface *surface)
{
        checkbox = surface;
}

void MStyle::setCheckBoxChecked(Surface *surface)
{
        checkboxChecked = surface;
}

void MStyle::setRadio(Surface *surface)
{
        radio = surface;
}

void MStyle::setRadioChecked(Surface *surface)
{
        radioChecked = surface;
}

void MStyle::setNormalFont(Font *font)
{
    normalFont = font;
}

}

}
