#include "FrameFile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Label.h"
#include "Button.h"

namespace StiGame
{

namespace Gui
{

ItemEquation::ItemEquation(std::string m_equation, std::map<std::string, int> m_variables)
{
    equation = m_equation;
    variables = m_variables;
    result = 0;
}

ItemEquation::~ItemEquation()
{

}

std::string ItemEquation::getEquation(void)
{
    return equation;
}

void ItemEquation::replaceVars(void)
{
    //vars must not have the same prefix
    //vars char is '$' so looking for that chars
    auto lit(variables.begin()), lend(variables.end());
    for(;lit!=lend;++lit)
    {
        std::string var_name = lit->first;
        std::string value = std::to_string(lit->second);

        size_t pos = equation.find('$');
        while(pos != std::string::npos)
        {
            if(pos + var_name.length() <= equation.length())
            {
                //finding the end with the op_symbol
                size_t end_var = equation.find_first_of("-+*/", pos);

                if(end_var == std::string::npos)
                {
                    end_var = equation.size();
                }

                std::string eq_var_name = equation.substr(pos + 1, end_var - (pos+1));
                if(eq_var_name == var_name)
                {
                    if(pos == 0)
                    {
                        equation = value + equation.substr(pos + 1 + var_name.length());
                    }
                    else
                    {
                        //replacing
                        equation = equation.substr(0, pos) + value + equation.substr(pos + 1 + var_name.length());
                    }
                }
            }

            pos = equation.find('$', pos + 1);
        }
    }

}

void ItemEquation::evaluate(void)
{
    //replace the var by their value
    replaceVars();
    //do the equation
    //only -,+,*,/ supported
    int _result = 0;
    std::string _equation = equation;
    size_t index = _equation.find_first_of("-+*/");
    int i = 0;
    while(index != std::string::npos)
    {
        if(i == 0)
        {
            //getting the first value
            std::string init_int = _equation.substr(0, index);
            std::cout << init_int << std::endl;
            _result = atoi(init_int.c_str());
        }

        char op_symbol = _equation[index];
        _equation = _equation.substr(0, index) + '!' + _equation.substr(index + 1);
        std::cout << op_symbol << std::endl;
        size_t end_value = _equation.find_first_of("-+*/");
        if(end_value == std::string::npos)
        {
            end_value = _equation.size();
        }

        std::string str_int = _equation.substr(index+1, end_value - (index + 1));

        if(op_symbol == '+')
        {
            _result += atoi(str_int.c_str());
        }
        else if(op_symbol == '-')
        {
            _result -= atoi(str_int.c_str());
        }
        else if(op_symbol == '*')
        {
            _result *= atoi(str_int.c_str());
        }
        else if(op_symbol == '/')
        {
            _result /= atoi(str_int.c_str());
        }

        //replacing the symbol

        std::cout << "Eq : " << _equation << std::endl;
        index = _equation.find_first_of("-+*/");
        i++;
    }
    result = _result;
    //store the result
}

int ItemEquation::getResult(void)
{
    return result;
}

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

ItemDefinition::ItemDefinition(std::string m_type)
{
    type = m_type;
    name = "not set";
}

ItemAttribute* ItemDefinition::findAttribute(std::string m_name)
{
    auto lit(attributes.begin()), lend(attributes.end());
    for(;lit!=lend;++lit)
    {
        ItemAttribute *attr = (*lit);
        if(attr->getName() == m_name)
        {
            return attr;
        }
    }

    return nullptr;
}

Item* ItemDefinition::create(std::map<std::string, int> variables)
{
    if(name != "not set")
    {
        Item *item = nullptr;

        if(type == "Label")
        {
            Label *lbl = new Label();
            // trying to set label attribute, caption here
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                lbl->setCaption(attr->getValue());
            }

            item = lbl;
        }
        else if(type == "Button")
        {
            Button *btn = new Button();
            ItemAttribute *attr = findAttribute("caption");
            if(attr != nullptr)
            {
                btn->setCaption(attr->getValue());
            }
            item = btn;
        }

        //generic attributes
        if(item != nullptr)
        {
            applyGenericAttributes(item, variables);
        }

        return item;
    }
    else
    {
        //todo
        //error message here
        return nullptr;
    }
}

void ItemDefinition::applyGenericAttributes(Item *item, std::map<std::string, int> variables)
{
    auto lit(attributes.begin()), lend(attributes.end());
    for(;lit!=lend;++lit)
    {
        ItemAttribute *attr = (*lit);

        if(attr->getName() == "x")
        {
            item->setX(attr->getInt(variables));
        }
        else if(attr->getName() == "y")
        {
            item->setY(attr->getInt(variables));
        }
        else if(attr->getName() == "width")
        {
            item->setWidth(attr->getInt(variables));
        }
        else if(attr->getName() == "height")
        {
            item->setHeight(attr->getInt(variables));
        }
        else if(attr->getName() == "visible")
        {
            item->setVisible(attr->getValue() == "true");
        }
    }
}

std::string ItemDefinition::getName(void)
{
    return name;
}

ItemDefinition::~ItemDefinition()
{
    //todo
    //delete attributes
}

std::string ItemDefinition::getType(void)
{
    return type;
}

void ItemDefinition::setAttribute(std::string m_name, std::string m_value)
{
    if(m_name == "name")
    {
        name = m_value;
    }
    else
    {
        ItemAttribute *attr = new ItemAttribute(m_name, m_value);
        attributes.push_back(attr);
    }
}


FrameFile::FrameFile(std::string m_path)
{
    path = m_path;
    readFile();
}

FrameFile::~FrameFile()
{
    //todo
    //clear all the items
}

void FrameFile::readFile(void)
{
    std::ifstream infile (path.c_str());
    std::string line;
    ItemDefinition *current = nullptr;

    if(infile.is_open())
    {
        while(std::getline(infile, line))
        {


            //removing end of line
            if(line[line.length()-1] == '\n')
            {
                line = line.substr(0, line.length() - 1);
            }

            // windows \r
            if(line[line.length()-1] == '\r')
            {
                line = line.substr(0, line.length() - 1);
            }

            if(line.length() > 1)
            {

                if(line[0] == '\t' && line[0] != '#')
                {
                    //item attributes
                    if(current != nullptr)
                    {
                        std::string attr = line.substr(1, line.length() - 1);
                        //finding data sep ':'
                        //or searching for a '=' for equation
                        size_t index = attr.find(':');
                        if(index != std::string::npos)
                        {
                            std::string attr_name = attr.substr(0, index);
                            std::string attr_val = attr.substr(index + 1, line.length() - index - 2);
                            current->setAttribute(attr_name, attr_val);
                        }
                        else
                        {
                            size_t index = attr.find('=');
                            if(index != std::string::npos)
                            {
                                //equation
                                std::string attr_name = attr.substr(0, index);
                                std::string attr_val = attr.substr(index, line.length() - index - 1);
                                current->setAttribute(attr_name, attr_val);
                            }
                        }

                    }
                }
                else if(line[0] != '#')
                {
                    //item type
                    //new definition
                    current = new ItemDefinition(line);
                    definitions.push_back(current);
                }
            }
        }

        infile.close();
    }
}

void FrameFile::createItems(Viewport *viewport)
{
    std::map<std::string, int> variables;
    variables.insert(std::make_pair("VIEWPORT_WIDTH", viewport->getWidth()));
    variables.insert(std::make_pair("VIEWPORT_HEIGHT", viewport->getHeight()));

    auto lit(definitions.begin()), lend(definitions.end());
    for(;lit!=lend;++lit)
    {
        ItemDefinition *def = (*lit);

        Item *item = def->create(variables);
        if(item != nullptr)
        {
            items.insert(std::make_pair(def->getName(), item));
        }
    }
}

Item* FrameFile::operator[](const std::string key)
{
    return items[key];
}

std::vector<std::string>& FrameFile::getItemNames(void)
{
    std::vector<std::string> names;
    auto lit(items.begin()), lend(items.end());
    for(;lit!=lend;++lit)
    {
        names.push_back(lit->first);
    }

    return names;
}

}

}
