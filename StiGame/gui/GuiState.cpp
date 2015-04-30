#include "GuiState.h"
#include "PLine.h"
#include "MPoint.h"
#include <iostream>

namespace StiGame
{

namespace Gui
{


GuiState::GuiState(void) : BaseGameState()
{
	rendering = false;
	sBuffer = new Surface(1,1);
	sBuffer->setReleaseSurface(true);
	mouse_x = 0;
	mouse_y = 0;
	style = Runtime::getInstance()->getStyle();
}


GuiState::~GuiState(void)
{
    if(sBuffer != nullptr)
    {
        delete sBuffer;
    }
}

int GuiState::getMouseX(void)
{
	return mouse_x;
}

int GuiState::getMouseY(void)
{
	return mouse_y;
}

void GuiState::add(Item *n_item)
{
    container.add(n_item);
}

void GuiState::onStart(void)
{
	running = true;
}

Surface* GuiState::render()
{
    //need to rework all this, maybe GUI will be generated with Surface and drawing with Texture..
    if(sBuffer->getHeight() != width && sBuffer->getWidth() != height)
    {
        delete sBuffer;
        sBuffer = new Surface(width, height);
    }

	//rendering items
	sBuffer->fill(style->getBackground());
    //MPoint *relp = new MPoint();

    container.iterator().publishOnMouseMotion(mouse_x, mouse_y);

    /*for(ItemIterator it = container.iterator(); it.next();)
    {
        it.
        Item *item = it.item();

        if(item->contains(mouse_x, mouse_y))
        {
            relp->setPoint(mouse_x - item->getX(), mouse_y - item->getY());
            item->setMouseOver(true);
            item->onMouseMotion(relp);
        }
        else
        {
            item->setMouseOver(false);
        }

        if(item->isVisible())
        {
            Surface *itemBuffer = item->render();
            sBuffer->blit(itemBuffer, item);
            delete itemBuffer;
        }
    }

    delete relp;*/

    return sBuffer;

}

void GuiState::onPaint(SDL_Renderer *renderer)
{
    //need to rework all this, maybe GUI will be generated with Surface and drawing with Texture..
    if(sBuffer->getHeight() != viewport->getHeight() || sBuffer->getWidth() != viewport->getWidth())
    {
        delete sBuffer;
        sBuffer = new Surface(viewport->getWidth(), viewport->getHeight());
    }

	//rendering items
	sBuffer->fill(style->getBackground());

    MPoint *relp = new MPoint();

    for(ItemIterator it = container.iterator(); it.next();)
    {
        Item *item = it.item();
        if(item->contains(mouse_x, mouse_y))
        {
            relp->setPoint(mouse_x - item->getX(), mouse_y - item->getY());
            item->setMouseOver(true);
            item->onMouseMotion(relp);
        }
        else
        {
            item->setMouseOver(false);
        }

        if(item->isVisible())
        {
            Surface *itemBuffer = item->render();
            sBuffer->blit(itemBuffer, item);
            delete itemBuffer;
        }
    }


	delete relp;

    //so lazy, need to be rework soon...
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, sBuffer->getSDLSurface());
	SDL_Rect *dim = new SDL_Rect();

	dim->h = viewport->getHeight();
	dim->w = viewport->getWidth();
	dim->x = 0;
	dim->y = 0;

	SDL_RenderCopy(renderer, texture, dim, dim);

	delete dim;

	SDL_DestroyTexture(texture);

}

void GuiState::onResize(int nw,int nh)
{
	width = nw;
	height = nh;
}

void GuiState::onQuit(SDL_Event* evt)
{
	running = false;
}

void GuiState::onEvent(SDL_Event* evt)
{
    BaseGameState::onEvent(evt);

    if(!running)
    {
        return;
    }

	if(evt->type == SDL_MOUSEMOTION)
	{
		mouse_x = evt->motion.x;
		mouse_y = evt->motion.y;
	}
	else if(evt->type == SDL_MOUSEBUTTONUP)
	{
		mouse_x = evt->button.x;
		mouse_y = evt->button.y;

        ItemIterator it = container.iterator();
        it.publishOnClick(mouse_x, mouse_y);
	}
	else if(evt->type == SDL_TEXTINPUT)
    {

        ItemIterator it = container.iterator();
        it.publishTextInput(evt->edit.text);
    }
    else if(evt->type == SDL_KEYUP)
    {
        ItemIterator it = container.iterator();
        it.publishOnKeyUp(&evt->key);
    }
}

void GuiState::unload(void)
{
    if(sBuffer != nullptr)
    {
        delete sBuffer;
        sBuffer = nullptr;
    }

}

void GuiState::removeItem(Item *item)
{
    container.remove(item);
}

}

}

#ifdef C_WRAPPER

extern "C" {
    StiGame::Gui::GuiState* GuiState_new()
    {
        return new StiGame::Gui::GuiState;
    }

    void GuiState_add(StiGame::Gui::GuiState *state, StiGame::Gui::Item *item)
    {
        state->add(item);
    }

    void GuiState_onResize(StiGame::Gui::GuiState *state, int width, int height)
    {
        state->onResize(width, height);
    }

    StiGame::Surface* GuiState_render(StiGame::Gui::GuiState *state)
    {
        StiGame::Surface *surface = state->render();
        return surface;
    }

}

#endif
