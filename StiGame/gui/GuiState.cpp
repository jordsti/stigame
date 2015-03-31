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
#ifdef FUTURE
    container.add(n_item);
#else
    items.push_back(n_item);
#endif
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
    MPoint *relp = new MPoint();
#ifdef FUTURE
    for(_future::ItemIterator it = container.iterator(); it.next();)
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

#else
    std::list<Item*>::iterator lit (items.begin()), lend(items.end());

	for(;lit!=lend;++lit)
	{
	    if( (*lit)->contains(mouse_x, mouse_y) )
        {
            //assigning value to the relative point
            relp->setPoint( mouse_x - (*lit)->getX(),
                       mouse_y - (*lit)->getY() );
            (*lit)->setMouseOver(true);
            (*lit)->onMouseMotion(relp);
        }
        else
        {
            (*lit)->setMouseOver(false);
        }

        if((*lit)->isVisible())
        {
            Surface *igfx = (*lit)->render();

            SDL_Rect *src = igfx->getRect();
            SDL_Rect *dst = igfx->getRect((*lit)->getX(), (*lit)->getY());

            sBuffer->blit(igfx, src, dst);

            delete igfx;
            delete src;
            delete dst;
        }
	}

#endif
	delete relp;

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

#ifdef FUTURE
    for(_future::ItemIterator it = container.iterator(); it.next();)
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

#else
    std::list<Item*>::iterator lit (items.begin()), lend(items.end());



	for(;lit!=lend;++lit)
	{
	    if( (*lit)->contains(mouse_x, mouse_y) )
        {
            //assigning value to the relative point
            relp->setPoint( mouse_x - (*lit)->getX(),
                       mouse_y - (*lit)->getY() );
            (*lit)->setMouseOver(true);
            (*lit)->onMouseMotion(relp);
        }
        else
        {
            (*lit)->setMouseOver(false);
        }

        if((*lit)->isVisible())
        {
            Surface *igfx = (*lit)->render();

            SDL_Rect *src = igfx->getRect();
            SDL_Rect *dst = igfx->getRect((*lit)->getX(), (*lit)->getY());

            sBuffer->blit(igfx, src, dst);

            delete igfx;
            delete src;
            delete dst;
        }
	}

#endif

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
#ifdef FUTURE
        _future::ItemIterator it = container.iterator();
        it.publishOnClick(mouse_x, mouse_y);
#else
		std::list<Item*>::iterator lit (items.begin()), lend(items.end());

		for(;lit!=lend;++lit)
		{
			if((*lit)->contains(mouse_x, mouse_y))
			{
			    Point *relp = new Point(mouse_x - (*lit)->getX(), mouse_y - (*lit)->getY());

				(*lit)->onClick(relp);

				delete relp;
			}
			else
            {
                (*lit)->setFocus(false);
            }
		}
#endif
	}
	else if(evt->type == SDL_TEXTINPUT)
    {
#ifdef FUTURE
        _future::ItemIterator it = container.iterator();
        it.publishTextInput(evt->edit.text);
#else
        std::list<Item*>::iterator lit (items.begin()), lend(items.end());

		for(;lit!=lend;++lit)
		{
			if((*lit)->isHandleKey())
			{
				(*lit)->onTextInput(evt->edit.text);
			}
		}
#endif
    }
    else if(evt->type == SDL_KEYUP)
    {
#ifdef FUTURE
        _future::ItemIterator it = container.iterator();
        it.publishOnKeyUp(&evt->key);
#else
        std::list<Item*>::iterator lit (items.begin()), lend(items.end());

		for(;lit!=lend;++lit)
		{
			if((*lit)->isHandleKey())
			{
				(*lit)->onKeyUp(&evt->key);
			}
		}
#endif
    }
}

void GuiState::unload(void)
{
#ifndef FUTURE
	std::list<Item*>::iterator lit (items.begin()), lend(items.end());

	for(;lit!=lend;++lit)
	{
		(*lit)->clear();
	}
#endif
    if(sBuffer != nullptr)
    {
        delete sBuffer;
        sBuffer = nullptr;
    }

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
