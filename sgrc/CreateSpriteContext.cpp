#include "CreateSpriteContext.h"
#include "SGString.h"
#include <GamePath.h>
#include <SpriteFileCreator.h>

#include <iostream>
namespace sgrc
{
CreateSpriteContext::CreateSpriteContext() :
    ScriptContext("CreateSprite")
{
    spriteName = "unnamed";
    fileOutput = "unnamed.bspr";
    useAssetsPath = true;
    width = 0;
    height = 0;
}

void CreateSpriteContext::execute(void)
{
    message("Creating script : "+spriteName);
    std::string _output = fileOutput;

    if(useAssetsPath)
        _output = StiGame::GamePath::getFilepath(StiGame::AssetSprite, fileOutput);

    //creating sprite file
    StiGame::SpriteFileCreator spc;
    spc.setName(spriteName);

    if(width > 0 && height > 0)
    {
        spc.setWidth(width);
        spc.setHeight(height);
    }

    auto fit(frames.begin()), fend(frames.end());
    for(;fit!=fend;++fit)
    {
        std::string frame = (*fit);
        if(useAssetsPath)
        {
            frame = StiGame::GamePath::getFilepath(StiGame::AssetSprite, frame);
        }

        spc.addFrame(frame);
    }

    spc.save(_output);
}

void CreateSpriteContext::parseInstruction(std::string ins)
{
    SGString sg (ins);
    sg.removeEndLine();
    sg.removeTrailingSpaces();
    if(sg.startsWith("\tname:"))
    {
        spriteName = sg.getStdString().substr(6, sg.length() - 6);
    }
    else if(sg.startsWith("\tframe:"))
    {
        std::string frame = sg.getStdString().substr(7, sg.length() - 7);
        if(frame.length() > 0)
        {
            frames.push_back(frame);
        }
    }
    else if(sg.startsWith("\toutput:"))
    {
        fileOutput = sg.getStdString().substr(8, sg.length() - 8);
    }
    else if(sg.startsWith("\tassetsPath:"))
    {
        std::string val = sg.getStdString().substr(12, sg.length() - 12);
        useAssetsPath = (val == "true");
    }
    else if(sg.startsWith("\twidth:"))
    {
        std::string _width = sg.getStdString().substr(7, sg.length() - 7);
        width = atoi(_width.c_str());
    }
    else if(sg.startsWith("\theight:"))
    {
        std::string _height = sg.getStdString().substr(8, sg.length() - 8);
        height = atoi(_height.c_str());
    }
}

CreateSpriteContext::~CreateSpriteContext()
{
}

}
