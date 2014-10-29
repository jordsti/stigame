#include "ScriptContext.h"
#include <iostream>

namespace sgrc {

int ScriptContext::currentId = 0;

ScriptContext::ScriptContext(std::string m_name)
{
    _id = CurrentId();
    name = m_name;
}

ScriptContext::~ScriptContext()
{

}

void ScriptContext::message(std::string msg)
{
    std::cout << msg << std::endl;
}

void ScriptContext::error(std::string msg)
{
    std::cerr << msg << std::endl;
}

std::string ScriptContext::getName(void)
{
    return name;
}

int ScriptContext::getId(void)
{
    return _id;
}

int ScriptContext::CurrentId(void)
{
    currentId++;
    int id = currentId;
    return id;
}

}
