#include "ItemAttribute.h"
#include "ItemEquation.h"

#include <iostream>

namespace StiGame
{

namespace Gui
{

ItemAttribute::ItemAttribute(std::string m_name, std::string m_value)
{
    name = m_name;
    value = m_value;
}

ItemAttribute::~ItemAttribute()
{

}

std::string ItemAttribute::getName(void)
{
    return name;
}

std::string ItemAttribute::getValue(void)
{
    return value;
}

int ItemAttribute::getInt(void)
{
    return atoi(value.c_str());
}

int ItemAttribute::getInt(std::map<std::string, int> variables)
{
    if(isEquation())
    {
        ItemEquation eq (value.substr(1), variables);
        eq.evaluate();
        return eq.getResult();
    }
    else
    {
        return getInt();
    }
}

Color* ItemAttribute::getColor(void)
{
    std::vector<int> colors;
    std::vector< std::string > splitted;
    std::string _value = value;
    size_t pos = _value.find_first_of(",");
    while(_value.length() > 0)
    {
        std::string split = _value.substr(0, pos);
        splitted.push_back(split);

        if(_value.length() > pos + 1)
        {
            _value = _value.substr(pos + 1);
        }
        else
        {
            _value = _value.substr(_value.length());
        }

        pos = _value.find_first_of(",");

        if(pos == std::string::npos)
        {
            splitted.push_back(_value);
            break;
        }
    }

    auto lit(splitted.begin()), lend(splitted.end());
    for(;lit!=lend;++lit)
    {
        colors.push_back(atoi((*lit).c_str()));
    }


    if(colors.size() == 3)
    {
        return new Color(colors[0], colors[1], colors[2]);
    }
    else if(colors.size() == 4)
    {
        return new Color(colors[0], colors[1], colors[2], colors[3]);
    }
    else
    {
        return nullptr;
    }

}

void ItemAttribute::setName(std::string m_name)
{
    name = m_name;
}

void ItemAttribute::setValue(std::string m_value)
{
    value = m_value;
}

bool ItemAttribute::isEquation(void)
{
    if(value.length() > 0)
    {
        return value[0] == '=';
    }

    return false;
}

}

}
