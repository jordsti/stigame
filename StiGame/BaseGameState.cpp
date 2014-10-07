
#include "BaseGameState.h"
#include "Viewport.h"
#include "Texture.h"
#include <iostream>

namespace StiGame
{


BaseGameState::BaseGameState(void)
{
    handleQuit = true;
	width = 0;
	height = 0;
	running = false;
	viewport = 0;
    gameMenu = nullptr;
}

void BaseGameState::setViewport(Viewport *m_viewport)
{
	viewport = m_viewport;
}

Viewport * BaseGameState::getViewport(void)
{
	return viewport;
}

void BaseGameState::setGameMenu(Gui::OverlayMenu *m_gameMenu)
{
	gameMenu = m_gameMenu;
}

Gui::OverlayMenu* BaseGameState::getGameMenu(void)
{
	return gameMenu;
}

bool BaseGameState::isRunning(void)
{
	return running;
}

void BaseGameState::onStart(void)
{

}

void BaseGameState::onResize(int n_width, int n_height)
{
	width = n_width;
	height = n_height;

	if(gameMenu != 0)
	{
		gameMenu->fixPosition(width, height);
	}
}

void BaseGameState::clearActions(void)
{
    auto lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }
}

void BaseGameState::unload(void)
{
	//unload your objects
}

void BaseGameState::onPaint(SDL_Renderer *renderer)
{
    renderGameMenu(renderer);
    renderOverlayFrames(renderer);
}

void BaseGameState::onQuit(SDL_Event *evt)
{
    running = false;
}

void BaseGameState::renderOverlayFrames(SDL_Renderer *renderer)
{
    std::list<Gui::OverlayFrame*>::iterator lit(frames.begin()), lend(frames.end());
    SDL_Rect *src = new SDL_Rect();
    SDL_Rect *dst = new SDL_Rect();

    for(;lit!=lend;++lit)
    {
        Gui::OverlayFrame *frame = (*lit);

        if(frame->isVisible())
        {
            Surface *sur = frame->render();

            sur->updateSDLRect(src);
            sur->updateSDLRect(dst, frame);

            Texture texture (renderer, sur);

            texture.renderCopy(src, dst);

            //delete sur; possible SEGFAULT cause
        }
    }

    delete src;
    delete dst;
}

void BaseGameState::tickActions(void)
{
    std::list<SDL_Keycode>::iterator klit(keyDowns.begin()), klend(keyDowns.end());
    for(;klit!=klend;++klit)
    {
        std::list<BaseGameAction*>::iterator glit(actions.begin()), glend(actions.end());
        for(;glit!=glend;++glit)
        {
            (*glit)->testKeycode((*klit));
        }
    }

    std::list<Uint8>::iterator mlit(mouseButtons.begin()), mlend(mouseButtons.end());
    for(;mlit!=mlend;++mlit)
    {
        std::list<BaseGameAction*>::iterator glit(actions.begin()), glend(actions.end());
        for(;glit!=glend;++glit)
        {
            (*glit)->testMouse((*mlit));
        }
    }
}

void BaseGameState::onEvent(SDL_Event *evt)
{
    //keyboard event handling
    if(evt->type == SDL_KEYDOWN)
    {
        KeyEventArgs *args = new KeyEventArgs(evt);
        keyDowns.push_back(evt->key.keysym.sym);
        KeyEventThrower::publish(this, args);
        delete args;
    }
    else if(evt->type == SDL_KEYUP)
    {
        KeyEventArgs *args = new KeyEventArgs(evt);
        keyDowns.remove(evt->key.keysym.sym);
        KeyEventThrower::publish(this, args);
        delete args;
    }
    else if(evt->type == SDL_MOUSEBUTTONDOWN)
    {
        Uint8 mbutton = evt->button.button;
        mouseButtons.push_back(mbutton);

		MouseButtonEventArgs mevt = MouseButtonEventArgs(evt);
		MouseButtonEventThrower::publish(this, &mevt);
    }
    else if(evt->type == SDL_MOUSEBUTTONUP)
    {
		if(gameMenu != 0)
		{
			if(gameMenu->isVisible() && gameMenu->contains(evt->button.x, evt->button.y))
			{
				Point relpt = Point(evt->button.x - gameMenu->getX(), evt->button.y - gameMenu->getY());
				gameMenu->onClick(&relpt);
			}
		}

		std::list<Gui::OverlayFrame*>::iterator lit(frames.begin()), lend(frames.end());
		for(;lit!=lend;++lit)
        {
            if((*lit)->isVisible())
            {
                Point relpt = Point(evt->button.x - (*lit)->getX(), evt->button.y - (*lit)->getY());
                (*lit)->onClick(&relpt);
            }

        }

        Uint8 mbutton = evt->button.button;
        mouseButtons.remove(mbutton);

		MouseButtonEventArgs mevt = MouseButtonEventArgs(evt);
		MouseButtonEventThrower::publish(this, &mevt);
    }
	else if(evt->type == SDL_MOUSEMOTION)
	{
		if(gameMenu != 0)
		{
			if(gameMenu->isVisible() && gameMenu->contains(evt->motion.x, evt->motion.y))
			{
				Point relpt = Point(evt->motion.x - gameMenu->getX(), evt->motion.y - gameMenu->getY());
				gameMenu->onMouseMotion(&relpt);
			}
		}

        std::list<Gui::OverlayFrame*>::iterator lit(frames.begin()), lend(frames.end());
		for(;lit!=lend;++lit)
        {
            if((*lit)->isVisible())
            {
                Point relpt = Point(evt->motion.x - (*lit)->getX(), evt->motion.y - (*lit)->getY());
                (*lit)->onMouseMotion(&relpt);
            }

        }

		MouseMotionEventArgs moevt = MouseMotionEventArgs(evt);
		MouseMotionEventThrower::publish(this, &moevt);
	}
	else if(evt->type == SDL_MOUSEWHEEL)
	{
		MouseWheelEventArgs mwevt = MouseWheelEventArgs(evt);
		MouseWheelEventThrower::publish(this, &mwevt);
	}
	else if(evt->type == SDL_CONTROLLERAXISMOTION)
	{
		ControllerAxisEventArgs args = ControllerAxisEventArgs(evt);
		ControllerAxisEventThrower::publish(this, &args);
	}
	else if(evt->type == SDL_CONTROLLERBUTTONUP || evt->type == SDL_CONTROLLERBUTTONDOWN)
	{
		ControllerButtonEventArgs args = ControllerButtonEventArgs(evt);
		ControllerButtonEventThrower::publish(this, &args);
	}
	else if(evt->type == SDL_CONTROLLERDEVICEADDED ||
			evt->type == SDL_CONTROLLERDEVICEREMOVED ||
			evt->type == SDL_CONTROLLERDEVICEREMAPPED
			)
	{
		ControllerDeviceEventArgs args = ControllerDeviceEventArgs(evt);
		ControllerDeviceEventThrower::publish(this, &args);
	}

    if(handleQuit && evt->type == SDL_QUIT)
    {
        onQuit(evt);
    }
}

void BaseGameState::openGameMenu(void)
{
	if(gameMenu != 0)
	{
		gameMenu->setVisible(true);
	}
}

void BaseGameState::closeGameMenu(void)
{
	if(gameMenu != 0)
	{
		gameMenu->setVisible(false);
	}
}

void BaseGameState::renderGameMenu(SDL_Renderer *renderer)
{
	if(gameMenu != 0)
	{
	    if(gameMenu->getX() == 0 && gameMenu->getY() == 0 && gameMenu->getPosition() != Gui::OP_TOP_LEFT_CORNER)
        {
            gameMenu->fixPosition(width, height);
        }

		if(gameMenu->isVisible())
		{
			Surface *sur = gameMenu->render();

			Texture *tex = new Texture(renderer, sur->getSDLSurface());

			SDL_Rect *src = sur->getRect();
			SDL_Rect *dst = sur->getRect(gameMenu->getX(), gameMenu->getY());

			tex->renderCopy(src, dst);

			//delete sur; //texture will deleted the surface itself
			delete tex;
			delete src;
			delete dst;
		}
	}
}

bool BaseGameState::isHandleQuit(void)
{
    return handleQuit;
}

BaseGameState::~BaseGameState(void)
{
	//todo
}
}
