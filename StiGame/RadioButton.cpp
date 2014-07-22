#include "RadioButton.h"
#include "RadioGroup.h"

namespace StiGame
{

namespace Gui
{

const int RadioButton::DefaultCaptionOffset = 4;

RadioButton::RadioButton() : Item()
{
    font = style->getNormalFont();
    surfaceEmpty = style->getRadio();
    surfaceChecked = style->getRadioChecked();
    captionOffset = DefaultCaptionOffset;
    checked = false;
    stringBuffer = 0;
    group = 0;
}

void RadioButton::setGroup(RadioGroup *m_group)
{
    group = m_group;
}

void RadioButton::setCaption(std::string m_caption)
{
    caption = m_caption;
    renderCaption();
}

std::string RadioButton::getCaption(void)
{
    return caption;
}

void RadioButton::setChecked(bool m_checked)
{
    checked = m_checked;
}

bool RadioButton::isChecked(void)
{
    return checked;
}

void RadioButton::renderCaption(void)
{
    if(stringBuffer != 0)
    {
        delete stringBuffer;
    }

    stringBuffer = font->renderText(caption, foreground);
    width = stringBuffer->getWidth() + captionOffset + surfaceEmpty->getWidth();
    height = surfaceEmpty->getHeight();
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
        CheckEventArgs *args = new CheckEventArgs(checked, caption);
        publish(this, args);
        delete args;
    }

}

Surface *RadioButton::render(void)
{
    if(stringBuffer == 0)
    {
        renderCaption();
    }

    Surface *buffer = new Surface(width, height);
    buffer->fill(background);

    //caption drawing

    SDL_Rect *src,*dst;

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
