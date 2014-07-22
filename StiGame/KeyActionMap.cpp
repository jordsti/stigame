#include "KeyActionMap.h"

namespace StiGame
{
	KeyActionMap::KeyActionMap(void)
	{
		name = "no name";
		keycode = 0;
		inputType = IT_KEYBOARD;
	}

	KeyActionMap::KeyActionMap(std::string m_name)
	{
		name = m_name;
		keycode = 0;
		inputType = IT_KEYBOARD;
	}

	KeyActionMap::KeyActionMap(std::string m_name, SDL_Keycode m_keycode)
	{
		name = m_name;
		keycode = m_keycode;
		inputType = IT_KEYBOARD;
	}

	KeyActionMap::~KeyActionMap(void)
	{

	}

	int KeyActionMap::getIntValue(void)
    {
        return (int)keycode;
    }
	
	InputType KeyActionMap::getInputType(void)
	{
		return inputType;
	}

	std::string KeyActionMap::toString(void)
	{
		std::string str (SDL_GetKeyName(keycode));
		return "k"+str;
	}

	void KeyActionMap::fromString(std::string str)
	{
		std::string prefix = str.substr(0, 1);
		std::string action = str;
		if(prefix == "k")
		{
			action = action.substr(1, action.size() - 1);
		}

		keycode = SDL_GetKeyFromName(action.c_str());
	}

    bool KeyActionMap::inputEquals(InputType it, int input)
    {
        if(it == inputType)
        {
            SDL_Keycode kc = static_cast<SDL_Keycode>(input);

            if(keycode == kc)
            {
                return true;
            }
        }

        return false;
    }

	SDL_Keycode KeyActionMap::getKeycode(void)
	{
		return keycode;
	}

	void KeyActionMap::setKeycode(SDL_Keycode m_keycode)
	{
		keycode = m_keycode;
	}

}
