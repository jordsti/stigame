#include "RadioButton.h"
#include "RadioGroup.h"

namespace StiGame
{

namespace Gui
{

const int RadioButton::DefaultCaptionOffset = 4;

RadioButton::RadioButton() : Item("RadioButton")
{
    surfaceEmpty = style->getRadio();
    surfaceChecked = style->getRadioChecked();
    captionOffset = DefaultCaptionOffset;
    checked = false;
    group = 0;
}

void RadioButton::setGroup(RadioGroup *m_group)
{
    group = m_group;
}

void RadioButton::setChecked(bool m_checked)
{
    checked = m_checked;
}

bool RadioButton::isChecked(void)
{
    return checked;
}

void RadioButton::setForeground(Color *m_foreground)
{
    foreground = m_foreground;
    stringRenderer.setColor(foreground);
}

void RadioButton::setFont(Font *m_font)
{
    font = m_font;
    stringRenderer.setFont(m_font);
}

void RadioButton::onClick(Point *relp)
{
    //checking if the mouse click was in the radio image

    Rectangle *radioRect = surfaceEmpty->getRectangle(width - surfaceEmpty->getWidth(), 0);

    if(radioRect->contains(relp))
    {
        checked = !checked;
        if(checked)
        {
            if(group != 0)
            {
                group->setActive(this);
            }
        }

        //throw event here
        CheckEventArgs *args = new CheckEventArgs(checked, stringRenderer.getText());
        publish(this, args);
        delete args;
    }

}

Surface *RadioButton::render(void)
{
    width = stringRenderer.getWidth() + captionOffset + surfaceEmpty->getWidth();
    height = surfaceEmpty->getHeight();

    Surface *buffer = new Surface(width, height);
    buffer->fill(background);

    //caption drawing

    SDL_Rect *src,*dst;
    Surface *stringBuffer = stringRenderer.getSurface();
    src = stringBuffer->getRect();
    dst = stringBuffer->getRect(0, height / 2 - stringBuffer->getHeight()/2);

    buffer->blit(stringBuffer, src, dst);

    delete src;
    delete dst;

    //drawing the image

    Surface *radio_sur;

    if(checked)
    {
        radio_sur = surfaceChecked;
    }
    else
    {
        radio_sur = surfaceEmpty;
    }

    src = radio_sur->getRect();
    dst = radio_sur->getRect(width - radio_sur->getWidth(), 0);

    buffer->blit(radio_sur, src, dst);

    delete src;
    delete dst;

    return buffer;

}

RadioButton::~RadioButton()
{
    //dtor

}

}

}

#ifdef C_WRAPPER
extern "C"
{
    StiGame::Gui::RadioButton* RadioButton_new()
    {
        return new StiGame::Gui::RadioButton();
    }

    void RadioButton_setCaption(StiGame::Gui::RadioButton *button, char *text)
    {
        button->setCaption(text);
    }

    const char* RadioButton_getCaption(StiGame::Gui::RadioButton *button)
    {
        return button->getCaption().c_str();
    }


}
#endif // C_WRAPPER
