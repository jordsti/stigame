#include "CreateDirectionSpriteContext.h"
#include "SGString.h"
#include <DirectionSpriteFileCreator.h>
#include <GamePath.h>

namespace sgrc
{

CreateDirectionSpriteContext::CreateDirectionSpriteContext() :
    ScriptContext("CreateDirectionSprite")
{
    useAssetsPath = true;
    width = 0;
    height = 0;
    spriteName = "unnamed";
    fileOutput = "unnamed.bdspr";
}

CreateDirectionSpriteContext::~CreateDirectionSpriteContext()
{

}

void CreateDirectionSpriteContext::execute(void)
{
    message("Creating Direction Sprite : " + spriteName);
    std::string _output = fileOutput;

    if(useAssetsPath)
        _output = StiGame::GamePath::getFilepath(StiGame::AssetSprite, fileOutput);

    //creating sprite file
    StiGame::DirectionSpriteFileCreator dspc;
    dspc.setName(spriteName);

    if(width > 0 && height > 0)
    {
        dspc.setWidth(width);
        dspc.setHeight(height);
    }

    auto fit(framesUp.begin()), fend(framesUp.end());
    for(;fit!=fend;++fit)
    {
        std::string frame = (*fit);
        if(useAssetsPath)
        {
            frame = StiGame::GamePath::getFilepath(StiGame::AssetSprite, frame);
        }

        dspc.addFrame(StiGame::SD_UP, frame);
    }

    auto fit2(framesDown.begin()), fend2(framesDown.end());
    for(;fit2!=fend2;++fit2)
    {
        std::string frame = (*fit2);
        if(useAssetsPath)
        {
            frame = StiGame::GamePath::getFilepath(StiGame::AssetSprite, frame);
        }

        dspc.addFrame(StiGame::SD_DOWN, frame);
    }

    auto fit3(framesLeft.begin()), fend3(framesLeft.end());
    for(;fit3!=fend3;++fit3)
    {
        std::string frame = (*fit3);
        if(useAssetsPath)
        {
            frame = StiGame::GamePath::getFilepath(StiGame::AssetSprite, frame);
        }

        dspc.addFrame(StiGame::SD_LEFT, frame);
    }

    auto fit4(framesRight.begin()), fend4(framesRight.end());
    for(;fit4!=fend4;++fit4)
    {
        std::string frame = (*fit4);
        if(useAssetsPath)
        {
            frame = StiGame::GamePath::getFilepath(StiGame::AssetSprite, frame);
        }

        dspc.addFrame(StiGame::SD_RIGHT, frame);
    }

    dspc.save(_output);
}

void CreateDirectionSpriteContext::parseInstruction(std::string ins)
{
    SGString sg (ins);
    sg.removeEndLine();
    sg.removeTrailingSpaces();

    if(sg.startsWith("\tname:"))
    {
        spriteName = sg.getStdString().substr(6, sg.length() - 6);
    }
    else if(sg.startsWith("\tframeUp:"))
    {
        std::string frame = sg.getStdString().substr(9, sg.length() - 9);
        if(frame.length() > 0)
        {
            framesUp.push_back(frame);
        }
    }
    else if(sg.startsWith("\tframeDown:"))
    {
        std::string frame = sg.getStdString().substr(11, sg.length() - 11);
        if(frame.length() > 0)
        {
            framesDown.push_back(frame);
        }
    }
    else if(sg.startsWith("\tframeLeft:"))
    {
        std::string frame = sg.getStdString().substr(11, sg.length() - 11);
        if(frame.length() > 0)
        {
            framesLeft.push_back(frame);
        }
    }
    else if(sg.startsWith("\tframeUp:"))
    {
        std::string frame = sg.getStdString().substr(12, sg.length() - 12);
        if(frame.length() > 0)
        {
            framesRight.push_back(frame);
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

}
