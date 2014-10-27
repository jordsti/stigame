#include "Controller.h"

namespace StiGame
{

Controller::Controller()
{
	controller = 0;
}

Controller::Controller(int index)
{
	controller = 0;
	name = "";
	if(index < GetJoystickCount())
	{
		if(IsController(index))
		{
			controller = SDL_GameControllerOpen(index);
			name = SDL_GameControllerName(controller);
			joystick = SDL_GameControllerGetJoystick(controller);
		}
	}
	
}

Controller::Controller(SDL_GameController *m_controller)
{
	controller = 0;
	name = "";
	if(m_controller != 0)
	{
		controller = m_controller;
		name = SDL_GameControllerName(controller);
		joystick = SDL_GameControllerGetJoystick(controller);
	}
}

bool Controller::isAttached(void)
{
	return (SDL_TRUE == SDL_GameControllerGetAttached(controller));
}

Sint16 Controller::getAxis(SDL_GameControllerAxis m_axis)
{
	return SDL_GameControllerGetAxis(controller, m_axis);
}

Uint8 Controller::getButton(SDL_GameControllerButton m_button)
{
	return SDL_GameControllerGetButton(controller, m_button);
}


SDL_GameController* Controller::getController(void)
{
	return controller;
}

SDL_Joystick* Controller::getJoystick(void)
{
	return joystick;
}

SDL_JoystickID Controller::getJoystickId(void)
{
	return SDL_JoystickInstanceID(joystick);
}

Controller::~Controller()
{
	if(controller != 0)
	{
		SDL_GameControllerClose(controller);
	}
}


std::string Controller::getName(void)
{
	return name;
}

int Controller::GetJoystickCount(void)
{
	int count = 0;
	count = SDL_NumJoysticks();
	return count;
}

bool Controller::IsController(int index)
{
	return (SDL_IsGameController(index) == SDL_TRUE);
}

}