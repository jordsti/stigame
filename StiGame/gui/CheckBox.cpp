#include "CheckBox.h"


namespace StiGame
{

namespace Gui
{

const int CheckBox::DefaultCaptionOffset = 4;

CheckBox::CheckBox() : Item("CheckBox"), CaptionSupport()
{
    //ctor
    captionOffset = DefaultCaptionOffset;
    surfaceEmpty = style->getCheckbox();
    surfaceChecked = style->getCheckboxChecked();
    checked = false;
}

void CheckBox::onClick(Point *relp)
{
    //determine if the checkbox is clicked
    Rectangle *cbRect = surfaceEmpty->getRectangle(width - surfaceEmpty->getWidth(), 0);

    if(cbRect->contains(relp))
    {
        checked = !checked;
        //throw event here
        CheckEventArgs *args = new CheckEventArgs(checked, getCaption());
        publish(this, args);
        delete args;
    }

    delete cbRect;
}


void CheckBox::setChecked(bool m_checked)
{
    checked = m_checked;
}

bool CheckBox::isChecked(void)
{
    return checked;
}

Surface *CheckBox::render(void)
{
    Surface *stringBuffer = stringRenderer.getSurface();

    width = stringBuffer->getWidth() + captionOffset + surfaceEmpty->getWidth();
    height = surfaceEmpty->getWidth();


    Surface *buffer = new Surface(width, height);

    buffer->fill(background);

    //blitting the caption

    SDL_Rect *src = stringBuffer->getRect();
    SDL_Rect *dst = stringBuffer->getRect(0, (height/2) - (stringBuffer->getHeight()/2) );

    buffer->blit(stringBuffer, src, dst);

    delete src;
    delete dst;

    //blitting the image
    Surface *checkbox_surface;

    if(checked)
    {
        checkbox_surface = surfaceChecked;
    }
    else
    {
        checkbox_surface = surfaceEmpty;
    }

    src = checkbox_surface->getRect();
    dst = checkbox_surface->getRect(width - checkbox_surface->getWidth(), 0);

    buffer->blit(checkbox_surface, src, dst);

    delete src;
    delete dst;

    return buffer;
}

CheckBox::~CheckBox()
{
    //dtor
}

}

}


#ifdef C_WRAPPER
extern "C"
{
    StiGame::Gui::CheckBox* CheckBox_new()
    {
        return new StiGame::Gui::CheckBox();
    }

    void CheckBox_setCaption(StiGame::Gui::CheckBox *checkBox, char *text)
    {
        checkBox->setCaption(text);
    }

    const char* CheckBox_getCaption(StiGame::Gui::CheckBox *checkBox)
    {
        return checkBox->getCaption().c_str();
    }

}
#endif // C_WRAPPER
