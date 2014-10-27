#include "ActionBinding.h"
#include "KeyActionMap.h"

namespace StiGame {

const std::string ActionBinding::FILENAME = "bindings.cfg";

ActionBinding::ActionBinding()
{
    filepath = FILENAME;
}

ActionBinding::ActionBinding(std::string m_filepath)
    : VarFile(m_filepath)
{
    //ctor
}

void ActionBinding::addBinding(std::string bname, ActionMap *amap)
{
    bindings.insert(std::make_pair(bname, amap));
}

void ActionBinding::addBinding(ActionMap *amap)
{
    addBinding(amap->getName(), amap);
}

void ActionBinding::overwrite(std::string bname, ActionMap *nmap)
{
	ActionMap *omap = bindings[bname];
	
	bindings[bname] = nmap;
	
	delete omap;
}

std::string ActionBinding::getActionByMouseButton(Uint8 button)
{
    std::map<std::string, ActionMap*>::iterator lit(bindings.begin()), lend(bindings.end());
    for(;lit!=lend;++lit)
    {
        /*if(lit->second->getInputType() == IT_MOUSE)
        {
            return lit->first;
        }*/

        if(lit->second->isInput(IT_MOUSE))
        {
            return lit->first;
        }
    }

    return "none";
}

std::string ActionBinding::getActionByKeyCode(SDL_Keycode keycode)
{
    std::map<std::string, ActionMap*>::iterator lit(bindings.begin()), lend(bindings.end());
    for(;lit!=lend;++lit)
    {
        /*if(lit->second->getInputType() == IT_KEYBOARD)
        {
            KeyActionMap * kmap = dynamic_cast<KeyActionMap*>(lit->second);
            if(kmap->getKeycode() == keycode)
            {
                return lit->first;
            }
        }*/

        if(lit->second->isInput(IT_KEYBOARD))
        {
            KeyActionMap * kmap = dynamic_cast<KeyActionMap*>(lit->second);
            if(kmap->getKeycode() == keycode)
            {
                return lit->first;
            }
        }
    }

    return "none";
}

ActionMap* ActionBinding::getBinding(std::string bname)
{
    //todo
    //try/catch
    return bindings[bname];
}

void ActionBinding::write(void)
{
    variables.clear();

    std::map<std::string, ActionMap*>::iterator lit(bindings.begin()), lend(bindings.end());

    for(;lit!=lend;++lit)
    {
        std::string kval = lit->second->toString();
        variables.insert(std::make_pair(lit->first, kval));
    }

    VarFile::write();
}

void ActionBinding::read(void)
{
    VarFile::read();

    std::map<std::string, std::string>::iterator lit(variables.begin()), lend(variables.end());
    for(;lit!=lend;++lit)
    {
        ActionMap *amap = ActionMap::FromString(lit->first, lit->second);
        bindings.insert(std::make_pair(lit->first, amap));
    }

}

ActionBinding::~ActionBinding()
{
    //dtor
}


}
