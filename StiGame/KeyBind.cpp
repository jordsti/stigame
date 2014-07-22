#include "KeyBind.h"
#include "PLine.h"

namespace StiGame
{

namespace Gui
{

const int KeyBind::DefaultHeight = 20;
const int KeyBind::DefaultWidth = 60;

KeyBind::KeyBind() : HighlightItem()
{
    //ctor
    width = DefaultWidth;
    height = DefaultHeight;
    stringBuffer = 0;
    keyCaption = "0";
    font = style->getNormalFont();
    key = SDLK_0;
    focus = false;
}

void KeyBind::renderCaption(void)
{
    if(stringBuffer != 0)
    {
        delete stringBuffer;
    }

    stringBuffer = font->renderText(keyCaption, foreground);
}

KeyActionMap* KeyBind::createKeyActionMap(std::string a_name)
{
	KeyActionMap *kmap = new KeyActionMap(a_name, key);
	return kmap;
}

void KeyBind::fromActionMap(ActionMap *amap)
{
	if(amap->getInputType() == IT_KEYBOARD)
	{
		SDL_Keycode kc = static_cast<SDL_Keycode>(amap->getIntValue());
		setKey(kc);
	}
}

Surface *KeyBind::render(void)
{
    if(stringBuffer == 0)
    {
        renderCaption();
    }

    Surface *buffer = new Surface(width, height);

    if(focus)
    {
        buffer->fill(highlightBackground);
    }
    else
    {
        buffer->fill(background);
    }


    //key caption

    SDL_Rect *src,*dst;

    src = stringBuffer->getRect();
    dst = stringBuffer->getRect(width / 2 - stringBuffer->getWidth() / 2, height / 2 - stringBuffer->getHeight() / 2);

    buffer->blit(stringBuffer, src, dst);

    delete src;
    delete dst;

    //border
    PLine l1 = PLine();
    PLine l2 = PLine();
    PLine l3 = PLine();
    PLine l4 = PLine();

    l1.set1(0, 0);
    l1.set2(width - 1, 0);

    l2.set1(0, 0);
    l2.set2(0, height - 1);

    l3.set1(width - 1, 0);
    l3.set2(width - 1, height - 1);

    l4.set1(0, height - 1);
    l4.set2(width - 1, height - 1);

    buffer->draw(&l1, foreground);
    buffer->draw(&l2, foreground);
    buffer->draw(&l3, foreground);
    buffer->draw(&l4, foreground);

    return buffer;
}

void KeyBind::onClick(Point *relp)
{
    focus = !focus;
}

void KeyBind::handleEvent(KeyEventThrower *src, KeyEventArgs *args)
{
    if(focus)
    {
        setKey(args->getKeyboardEvent()->keysym.sym);
        focus = false;
    }
}

SDL_Keycode KeyBind::getKey(void)
{
    return key;
}

void KeyBind::setKey(SDL_Keycode m_key)
{
    key = m_key;

    keyCaption = SDL_GetKeyName(key);

    renderCaption();
}

KeyBind::~KeyBind()
{
    //dtor
}

}

}
