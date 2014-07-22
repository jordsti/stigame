#ifndef CONTROLLER_H
#define CONTROLLER_H

//temporary maybe
#include "SDL.h"
#include <string>

namespace StiGame
{

class Controller
{
public:
	Controller();
	Controller(int index);
	Controller(SDL_GameController *m_controller);
	virtual ~Controller();
	
	std::string getName(void);
	bool isAttached(void);
	
	Sint16 getAxis(SDL_GameControllerAxis m_axis);
	Uint8 getButton(SDL_GameControllerButton m_button);
	
	SDL_GameController* getController(void);
	SDL_Joystick* getJoystick(void);
	SDL_JoystickID getJoystickId(void);
	
	static int GetJoystickCount(void);
	static bool IsController(int index);
protected:
	SDL_GameController *controller;
	SDL_Joystick *joystick;
	std::string name;
private:


};

}


#endif