#include "ActionBind.h"
#include "KeyActionMap.h"
#include "MouseActionMap.h"
#include "PRect.h"

namespace StiGame
{

namespace Gui
{

const int ActionBind::DefaultWidth = 100;
const int ActionBind::DefaultHeight = 20;

ActionBind::ActionBind()
	: HighlightItem("ActionBind")
{
	font = style->getNormalFont();
	width = DefaultWidth;
	height = DefaultHeight;
	stringBuffer = 0;
	focus = false;
	handleMouse = false;
	mbutton = MB_LEFT;
	mouseButton = false;
	keycode = SDLK_0;
}

ActionBind::~ActionBind()
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}
}

ActionMap* ActionBind::createActionMap(std::string a_name)
{
	if(mouseButton)
	{
		Uint8 mb = MouseButtonEventArgs::GetSDLButton(mbutton);
		MouseActionMap *mmap = new MouseActionMap(a_name, mb);
		return mmap;
	}
	else
	{
		KeyActionMap *kmap = new KeyActionMap(a_name, keycode);
		return kmap;
	}
}

void ActionBind::fromActionMap(ActionMap *amap)
{
	if(amap->getInputType() == IT_COMP)
	{
		CompActionMap *cmap = dynamic_cast<CompActionMap*>(amap);
		fromActionMap(cmap, 0);
	}
	else if(amap->getInputType() == IT_KEYBOARD)
	{
		SDL_Keycode kc = static_cast<SDL_Keycode>(amap->getIntValue());
		keycode = kc;
		mouseButton = false;
		renderCaption();
	}
	else if(amap->getInputType() == IT_MOUSE)
	{
		Uint8 sdl_mb = static_cast<Uint8>(amap->getIntValue());
		mbutton = MouseButtonEventArgs::GetMouseButtonFromSDL(sdl_mb);
		mouseButton = true;
		renderCaption();
	}
}

void ActionBind::fromActionMap(CompActionMap *cmap, int index)
{
	ActionMap *amap = cmap->getMap(index);

	fromActionMap(amap);

}

Surface* ActionBind::render(void)
{
	Surface *buffer = new Surface(width, height);

	if(focus)
	{
		buffer->fill(highlightBackground);
	}
	else
	{
		buffer->fill(background);
	}

	SDL_Rect src = SDL_Rect();
	SDL_Rect dst = SDL_Rect();

	stringBuffer->updateSDLRect(&src);
	stringBuffer->updateSDLRect(&dst);

	dst.x = (width - dst.w) / 2;
	dst.y = (height - dst.h) / 2;

	buffer->blit(stringBuffer, &src, &dst);

	PRect border = PRect();

	border.setX(0);
	border.setY(0);
	border.setWidth(width - 1);
	border.setHeight(height - 1);

	Color *c_border = foreground;

	if(focus)
	{
		c_border = highlightForeground;
	}

	border.draw(buffer->getSDLSurface(), c_border);

	return buffer;
}

void ActionBind::handleEvent(KeyEventThrower *src, KeyEventArgs *args)
{
	if(focus)
	{
		keycode = args->getKeyboardEvent()->keysym.sym;
		renderCaption();
		mouseButton = false;
		focus = false;
	}
}

void ActionBind::handleEvent(MouseButtonEventThrower *src, MouseButtonEventArgs *args)
{
    if(contains(args->getX(), args->getY()) && args->isDown())
    {
        if(focus && handleMouse)
        {
            mbutton = args->getMouseButton();
            renderCaption();
            mouseButton = true;
            focus = false;
        }
        else if(!focus)
        {
            focus = true;
        }
    }

}

/*void ActionBind::onClick(Point *relpt)
{
	if(!focus)
	{
		//need to test the behaviour on this when a MouseButtonEvent is launched
		focus = true;
	}
}*/

SDL_Keycode ActionBind::getKey(void)
{
	return keycode;
}

void ActionBind::setKey(SDL_Keycode m_keycode)
{
	keycode = m_keycode;
}

MouseButton ActionBind::getMouseButton(void)
{
	return mbutton;
}

void ActionBind::setMouseButton(MouseButton m_mbutton)
{
	mbutton = m_mbutton;
	handleMouse = true;
	mouseButton = true;
}

bool ActionBind::isMouseButton(void)
{
	return mouseButton;
}

bool ActionBind::isHandleMouse(void)
{
	return handleMouse;
}

void ActionBind::setHandleMouse(bool m_handleMouse)
{
	handleMouse = m_handleMouse;
}

Font* ActionBind::getFont(void)
{
	return font;
}

void ActionBind::setFont(Font *m_font)
{
	font = m_font;
}

void ActionBind::renderCaption(void)
{
	if(stringBuffer != 0)
	{
		delete stringBuffer;
	}

	std::string txt = "";

	if(mouseButton)
	{
		txt = GetMouseString(mbutton);
	}
	else
	{
		txt = SDL_GetKeyName(keycode);
	}

	stringBuffer = font->renderText(txt, foreground);
}

std::string ActionBind::GetMouseString(MouseButton mbutton)
{
	std::string m_str = "NONE";

	if(mbutton == MB_LEFT)
	{
		m_str = "MB LEFT";
	}
	else if(mbutton == MB_MIDDLE)
	{
		m_str = "MB MIDDLE";
	}
	else if(mbutton == MB_RIGHT)
	{
		m_str = "MB RIGHT";
	}
	else if(mbutton == MB_X1)
	{
		m_str = "MB X1";
	}
	else if(mbutton == MB_X2)
	{
		m_str = "MB X2";
	}

	return m_str;
}

}


}
