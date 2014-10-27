#include "GamePath.h"
namespace StiGame
{


        #ifdef DEBUG
const std::string GamePath::assetsDir = "../../../assets/";
        #endif // DEBUG

        #ifdef RELEASE
const std::string GamePath::assetsDir = "assets/";
        #endif // RELEASE

GamePath::GamePath()
{
    //ctor
}

GamePath::~GamePath()
{
    //dtor
}

std::string GamePath::combine(std::string p1, std::string p2)
{
    if(p1.substr(p1.length() - 1, 1) != "/")
    {
        p1 += "/";
    }

    if(p2.substr(0, 1) == "/")
    {
        p2 = p2.substr(1);
    }

    std::string np = p1 + p2;

    return np;
}

std::string GamePath::getFilepath(Paths p, std::string p1)
{
    return combine(getPath(p), p1);
}


std::string GamePath::getPath(Paths p)
{

    if(p == AssetRoot)
    {
        return assetsDir;
    }
    else if(p == AssetGui)
    {
        return GamePath::combine(assetsDir, "gui");
    }
    else if(p == AssetSprite)
    {
        return GamePath::combine(assetsDir, "sprites");
    }

    return "";
}

}