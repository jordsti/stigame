#include "Entry.h"
namespace StiGame
{

namespace FS
{
Entry::Entry()
{
    name = "";
    parent = "";
}


Entry::~Entry()
{

}

bool Entry::endsWith(std::string m_suffix)
{
    if(m_suffix.size() < name.size())
    {
        std::string n_suffix = name.substr(name.size() - m_suffix.size(), m_suffix.size());
        return (n_suffix == m_suffix);
    }
    else
    {
        return false;
    }
}

std::string Entry::getNameWithoutExtension(void)
{
    size_t fs = name.find_last_of('.');
    if(fs != std::string::npos)
    {
        std::string rs = name.substr(0, fs);
        return rs;
    }

    return name;
}

std::string Entry::getName(void)
{
    return name;
}

std::string Entry::getParent(void)
{
    return parent;
}

std::string Entry::getPath(void)
{
    if(parent.size() == 0)
    {
        return name;
    }

    return parent+"/"+name;
}

}

}
