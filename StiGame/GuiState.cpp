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
	items.push_back(n_item);
}

void GuiState::onStart(void)
{
	running = true;
}

void GuiState::onPaint(SDL_Renderer *renderer)
{
    //need to rework all this, maybe GUI will be generated with Surface and drawing with Texture..
    if(sBuffer->getHeight() != viewport->getHeight() && sBuffer->getWidth() != viewport->getWidth())
    {
        delete sBuffer;
        sBuffer = new Surface(viewport->getWidth(), viewport->getHeight());
    }

	//rendering items
	sBuffer->fill(style->getBackground());

	std::list<Item*>::iterator lit (items.begin()), lend(items.end());

    MPoint *relp = new MPoint();

	for(;lit!=lend;++lit)
	{
	    if( (*lit)->contains(mouse_x, mouse_y) )
        {
            //assigning value to the relative point
            relp->set( mouse_x - (*lit)->getX(),
                       mouse_y - (*lit)->getY() );
            (*lit)->setMouseOver(true);
            (*lit)->onMouseMotion(relp);
        }
        else
        {
            (*lit)->setMouseOver(false);
        }

		Surface *igfx = (*lit)->render();

		SDL_Rect *src = igfx->getRect();
		SDL_Rect *dst = igfx->getRect((*lit)->getX(), (*lit)->getY());

		sBuffer->blit(igfx, src, dst);

		delete igfx;
		delete src;
		delete dst;
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

	if(evt->type == SDL_MOUSEMOTION)
	{
		mouse_x = evt->motion.x;
		mouse_y = evt->motion.y;
	}
	else if(evt->type == SDL_MOUSEBUTTONUP)
	{
		mouse_x = evt->button.x;
		mouse_y = evt->button.y;

		std::list<Item*>::iterator lit (items.begin()), lend(items.end());

		for(;lit!=lend;++lit)
		{
			if((*lit)->contains(mouse_x, mouse_y))
			{
			    Point *relp = new Point(mouse_x - (*lit)->getX(), mouse_y - (*lit)->getY());

				(*lit)->onClick(relp);

				delete relp;
			}
		}
	}
	else if(evt->type == SDL_TEXTINPUT)
    {
        std::list<Item*>::iterator lit (items.begin()), lend(items.end());

		for(;lit!=lend;++lit)
		{
			if((*lit)->isHandleKey())
			{
				(*lit)->onTextInput(evt->edit.text);
			}
		}
    }
    else if(evt->type == SDL_KEYUP)
    {
        std::list<Item*>::iterator lit (items.begin()), lend(items.end());

		for(;lit!=lend;++lit)
		{
			if((*lit)->isHandleKey())
			{
				(*lit)->onKeyUp(&evt->key);
			}
		}
    }
}

void GuiState::unload(void)
{
	std::list<Item*>::iterator lit (items.begin()), lend(items.end());

	for(;lit!=lend;++lit)
	{
		(*lit)->clear();
	}
}

}

}
