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
    bigFont = nullptr;

    buttonLeft = nullptr;
    buttonRight = nullptr;
    buttonBackground = nullptr;

    buttonHighlightLeft = nullptr;
    buttonHighlightRight = nullptr;
    buttonHighlightBackground = nullptr;
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

void MStyle::setButtonLeft(Surface *surface)
{
    buttonLeft = surface;
}
void MStyle::setButtonRight(Surface *surface)
{
    buttonRight = surface;
}
void MStyle::setButtonBackground(Surface *surface)
{
    buttonBackground = surface;
}

void MStyle::setHighlightButtonLeft(Surface *surface)
{
    buttonHighlightLeft = surface;
}

void MStyle::setHighlightButtonRight(Surface *surface)
{
    buttonHighlightRight = surface;
}

void MStyle::setHighlightButtonBackground(Surface *surface)
{
    buttonHighlightBackground = surface;
}

void MStyle::setBigFont(Font *m_bigFont)
{
    bigFont = m_bigFont;
}

}

}

#ifdef C_WRAPPER

extern "C"
{
    StiGame::Gui::MStyle* MStyle_new()
    {
        return new StiGame::Gui::MStyle();
    }

    void MStyle_setForeground(StiGame::Gui::MStyle *style, StiGame::Color *color)
    {
        style->setForeground(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }

    void MStyle_setBackground(StiGame::Gui::MStyle *style, StiGame::Color *color)
    {
        style->setBackground(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }

    void MStyle_setHighlightForeground(StiGame::Gui::MStyle *style, StiGame::Color *color)
    {
        style->setHighlightForeground(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }

    void MStyle_setHighlightBackground(StiGame::Gui::MStyle *style, StiGame::Color *color)
    {
        style->setHighlightBackground(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }

    void MStyle_setDropListArrow(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setDropListArrow(surface);
    }

    void MStyle_setUpArrow(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setUpArrow(surface);
    }

    void MStyle_setDownArrow(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setDownArrow(surface);
    }

    void MStyle_setCheckbox(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setCheckBox(surface);
    }

    void MStyle_setCheckboxChecked(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setCheckBoxChecked(surface);
    }

    void MStyle_setRadio(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setRadio(surface);
    }

    void MStyle_setRadioChecked(StiGame::Gui::MStyle *style, StiGame::Surface *surface)
    {
        style->setRadioChecked(surface);
    }

    void MStyle_setNormalFont(StiGame::Gui::MStyle *style, StiGame::Font *font)
    {
        style->setNormalFont(font);
    }

}

#endif // C_WRAPPER
