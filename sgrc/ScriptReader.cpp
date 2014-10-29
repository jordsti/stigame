#include "ScriptReader.h"
#include <fstream>
#include <iostream>
#include "SGString.h"
#include "CreateSpriteContext.h"
#include "CreateDirectionSpriteContext.h"

namespace sgrc {

ScriptReader::ScriptReader(std::string m_filepath)
{
    filepath = m_filepath;
}


ScriptReader::~ScriptReader()
{
}


void ScriptReader::read(void)
{
    std::ifstream ins (filepath.c_str());
    std::string line;
    ScriptContext *current = nullptr;
    while(std::getline(ins, line))
    {
        SGString sg (line);
        if(line.length() > 0)
        {
            //comments start with #
            if(!sg.startsWith("#"))
            {
                if(sg.startsWith("sprite:"))
                {
                    //new context

                    //pushing last one
                    if(current != nullptr)
                    {
                        contexts.push_back(current);
                    }

                    current = new CreateSpriteContext();
                }
                else if(sg.startsWith("directionSprite:"))
                {
                    if(current != nullptr)
                    {
                        contexts.push_back(current);
                    }

                    current = new CreateDirectionSpriteContext();
                }
                else if(sg.startsWith("\t"))
                {
                    if(current == nullptr)
                    {
                        //error
                        //todo - to handle
                    }
                    else
                    {
                        current->parseInstruction(line);
                    }

                }
            }
        }
    }

    if(current != nullptr)
    {
        //pushing last context
        contexts.push_back(current);
    }

    ins.close();
}

int ScriptReader::getSize(void)
{
    return contexts.size();
}

ScriptContext* ScriptReader::getContext(int i)
{
    return contexts[i];
}

}
