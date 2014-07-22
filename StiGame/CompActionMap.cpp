#include "CompActionMap.h"

namespace StiGame
{

CompActionMap::CompActionMap()
{
    //ctor
    name = "composite action";
    inputType = IT_COMP;
}

CompActionMap::CompActionMap(std::string m_name)
{
    //ctor
    name = m_name;
    inputType = IT_COMP;
}

int CompActionMap::getIntValue(void)
{
    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        //to investigate
        return (*lit)->getIntValue();
    }
    return 0;
}

int CompActionMap::getCount(void)
{
	return actions.size();
}


InputType CompActionMap::getInputType(void)
{
	return inputType;
}

ActionMap* CompActionMap::getMap(int index)
{
	std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
	
	ActionMap *amap = 0;
	
	int i = 0;
	for(;lit!=lend;++lit)
	{
		if(i == index)
		{
			amap = (*lit);
			break;
		}
		
		amap = (*lit);
		
		i++;
	}
	
	return amap;
}

bool CompActionMap::isInput(InputType it)
{
	if(it == IT_COMP)
	{
		return true;
	}


    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        if((*lit)->isInput(it))
        {
            return true;
        }
    }

    return false;
}

std::string CompActionMap::toString(void)
{
    std::string comp_str = "c";

    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        std::string a_str = (*lit)->toString();
        a_str += ",";
        comp_str += a_str;
    }

    return comp_str.substr(0, comp_str.size() - 1);
}

bool CompActionMap::inputEquals(InputType it, int input)
{
    std::list<ActionMap*>::iterator lit(actions.begin()), lend(actions.end());
    for(;lit!=lend;++lit)
    {
        if((*lit)->inputEquals(it, input))
        {
            return true;
        }
    }

    return false;
}

void CompActionMap::push(ActionMap *p_map)
{
	if(p_map->getInputType() != IT_COMP)
	{
		p_map->setName(name);
		actions.push_back(p_map);
	}
}

void CompActionMap::remove(ActionMap *r_map)
{
    actions.remove(r_map);
}

CompActionMap::~CompActionMap()
{
    //dtor
}

}
