#include "FrameFile.h"
#include <iostream>
#include <fstream>
#include <vector>

namespace StiGame
{

namespace Gui
{

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
                else if(line[0] == '$')
                {
                    //global variables
                    std::string workset = line.substr(1);
                    size_t pos = workset.find_first_of('=');
                    if(pos != std::string::npos)
                    {
                        if(pos + 1 <= workset.length())
                        {
                            std::string var_name = workset.substr(0, pos);
                            std::string var_value = workset.substr(pos + 1);

                            if(var_value.length() > 0)
                            {
                                globalVariables.insert(std::make_pair(var_name, atoi(var_value.c_str())));
                            }
                        }
                    }
                }
                else if(line[0] != '#')
                {
                    //item type
                    //new definition
                    current = new ItemDefinition(line);
                    current->setColorIndex(&colorIndex);
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

    //adding global vars
    auto mit(globalVariables.begin()), mend(globalVariables.end());
    for(;mit!=mend;++mit)
    {
        variables.insert(std::make_pair(mit->first, mit->second));
    }

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
            //adding new var to variables %ITEM_NAME%_%ITEM_FIELD%
            //adding x,y,width and height
            variables.insert(std::make_pair(def->getName()+"_X", item->getX()));
            variables.insert(std::make_pair(def->getName()+"_Y", item->getY()));
            variables.insert(std::make_pair(def->getName()+"_WIDTH", item->getWidth()));
            variables.insert(std::make_pair(def->getName()+"_HEIGHT", item->getHeight()));
        }
    }
}

Item* FrameFile::operator[](std::string key)
{
    return items[key];
}

Item* FrameFile::operator[](const char* key)
{
    std::string _key (key);
    return items[_key];
}

Item* FrameFile::getItemByKey(std::string key)
{
    return items[key];
}

std::vector<std::string> FrameFile::getItemNames(void)
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
