#include "ActionMap.h"
#include "KeyActionMap.h"
#include "MouseActionMap.h"
#include "CompActionMap.h"

namespace StiGame
{
	ActionMap::ActionMap(void)
	{
		name = "no name";
		inputType = IT_DEFAULT;
	}

	ActionMap::~ActionMap(void)
	{

	}

	std::string ActionMap::getName(void)
	{
		return name;
	}

	void ActionMap::setName(std::string m_name)
	{
		name = m_name;
	}

	void ActionMap::fromString(std::string str)
	{
		//to override
	}

	std::string ActionMap::toString(void)
	{
		return "to override";
	}

	InputType ActionMap::getInputType(void)
	{
		return inputType;
	}

    bool ActionMap::isPositionChecked()
    {
        return false;
    }

	bool ActionMap::isInput(InputType it)
	{
        return (inputType == it);
	}

	bool ActionMap::inputMouseEquals(MouseButtonEventArgs *mbEvt)
	{
	    return false;
	}

    int ActionMap::getIntValue(void)
    {
        return 0;
    }

	ActionMap* ActionMap::FromString(std::string a_name, std::string action)
	{
        //need to rework this method, to add Composite Action, with a split on the str
		ActionMap *amap = 0;

		//action start with k ->key
		//					m ->mouse
		// 					j ->joystick
		//                  c -> Composite (Multiple binds)

		std::string prefix = action.substr(0, 1);
		std::string map_value = action.substr(1, action.size() - 1);
		if(prefix == "c")
        {
            CompActionMap *cmap = new CompActionMap(a_name);
            //composite action binding !
            size_t comma_pos = map_value.find(",");
            std::string sub_action = map_value.substr(0, comma_pos - 1);
            cmap->push(FromString(a_name, sub_action));

            std::string left_str = map_value.substr(comma_pos, map_value.size());

            while(left_str.size() > 1)
            {
                left_str = left_str.substr(1, left_str.size());

                comma_pos = left_str.find(",");

                if(comma_pos != std::string::npos)
                {
                    sub_action = left_str.substr(0, comma_pos - 1);

                    left_str = left_str.substr(comma_pos, left_str.size());
                    cmap->push(FromString(a_name, sub_action));
                }
                else
                {
                    cmap->push(FromString(a_name, left_str));
                    left_str = ";";
                }
            }

            return cmap;
        }
		else if(prefix == "k")
		{
			amap = new KeyActionMap(a_name);
			amap->fromString(map_value);
		}
		else if(prefix == "m")
		{
			amap = new MouseActionMap(a_name);
			amap->fromString(map_value);
		}
		else if(prefix == "j")
		{

		}

		return amap;
	}
}
