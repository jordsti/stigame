#include "MouseActionMap.h"

namespace StiGame
{
	MouseActionMap::MouseActionMap(void)
	{
		name = "no name";
		button = 0;
		inputType = IT_MOUSE;
		positionChecked = false;
		rect = Rectangle();
	}

	MouseActionMap::MouseActionMap(std::string m_name)
	{
		name = m_name;
		button = 0;
		inputType = IT_MOUSE;
		positionChecked = false;
		rect = Rectangle();
	}

	MouseActionMap::MouseActionMap(std::string m_name, Uint8 m_button)
	{
		name = m_name;
		button = m_button;
		inputType = IT_MOUSE;
		positionChecked = false;
		rect = Rectangle();
	}

	MouseActionMap::~MouseActionMap(void)
	{

	}

	std::string MouseActionMap::toString(void)
	{
		return "m" + GetStringValue(button);
	}

    int MouseActionMap::getIntValue(void)
    {
        return (int)button;
    }

	InputType MouseActionMap::getInputType(void)
	{
		return inputType;
	}
	
	void MouseActionMap::fromString(std::string str)
	{
		std::string action = str;
		std::string prefix = action.substr(0, 1);

		if(prefix == "m")
		{
			action = action.substr(1, action.size());
		}

		button = GetIntValue(action);
	}

	Uint8 MouseActionMap::getButton(void)
	{
		return button;
	}

    bool MouseActionMap::inputEquals(InputType it, int input)
    {
        if(it == inputType)
        {
            Uint8 mb = static_cast<Uint8>(input);
            if(mb == button)
            {
                return true;
            }
        }

        return false;
    }

	void MouseActionMap::setButton(Uint8 m_button)
	{
		button = m_button;
	}

    void MouseActionMap::setX(int r_x)
    {
        rect.setX(r_x);
    }

    void MouseActionMap::setY(int r_y)
    {
        rect.setY(r_y);
    }

    void MouseActionMap::setWidth(int r_w)
    {
        rect.setWidth(r_w);
    }

    void MouseActionMap::setHeight(int r_h)
    {
        rect.setHeight(r_h);
    }

    void MouseActionMap::setRect(int r_x, int r_y, int r_w, int r_h)
    {
        rect.setX(r_x);
        rect.setY(r_y);
        rect.setWidth(r_w);
        rect.setHeight(r_h);
    }

    void MouseActionMap::setPositionChecked(bool m_positionChecked)
    {
        positionChecked = m_positionChecked;
    }

    bool MouseActionMap::isPositionChecked(void)
    {
        return positionChecked;
    }

    bool MouseActionMap::inputMouseEquals(MouseButtonEventArgs *mbEvt)
    {
        if(positionChecked)
        {
            if(rect.contains(mbEvt->getX(), mbEvt->getY()) &&
               button == mbEvt->getButton() &&
               mbEvt->isDown() )
            {
                return true;
            }
        }
        else
        {
            if(mbEvt->isDown() && mbEvt->getButton() == button)
            {
                return true;
            }
        }

        return false;
    }

	std::string MouseActionMap::GetStringValue(Uint8 m_button)
	{
		//SDL_BUTTON_LEFT
		//SDL_BUTTON_MIDDLE
		//SDL_BUTTON_RIGHT
		//SDL_BUTTON_X1
		//SDL_BUTTON_X2
		std::string str = "unset";

		switch(m_button)
		{
			case SDL_BUTTON_LEFT:
				str = "left";
				break;
			case SDL_BUTTON_MIDDLE:
				str = "middle";
				break;
			case SDL_BUTTON_RIGHT:
				str = "right";
				break;
			case SDL_BUTTON_X1:
				str = "x1";
				break;
			case SDL_BUTTON_X2:
				str = "x2";
				break;
		}

		return str;
	}

	Uint8 MouseActionMap::GetIntValue(std::string m_str)
	{
		if(m_str == "left")
		{
			return SDL_BUTTON_LEFT;
		}
		else if(m_str == "middle")
		{
			return SDL_BUTTON_MIDDLE;
		}
		else if(m_str == "right")
		{
			return SDL_BUTTON_RIGHT;
		}
		else if(m_str == "x1")
		{
			return SDL_BUTTON_X1;
		}
		else
		{
			return SDL_BUTTON_X2;
		}
	}

}
