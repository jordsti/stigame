#include "GameUnit.h"
namespace StiGame
{
GameUnit::GameUnit()
{
    //ctor
    name = "";
    gfxName = "";
    x = 0;
    y = 0;
    speed = 0;
    direction = SD_IDLE;
}

int GameUnit::getX(void)
{
    return x;
}

int GameUnit::getY(void)
{
    return y;
}

int GameUnit::getWidth(void)
{
    return width;
}

int GameUnit::getHeight(void)
{
    return height;
}

int GameUnit::getSpeed(void)
{
    return speed;
}

int GameUnit::getDirection(void)
{
    return direction;
}

std::string GameUnit::getName(void)
{
    return name;
}

std::string GameUnit::getGfxName(void)
{
    return gfxName;
}

GameUnit::~GameUnit()
{
    //dtor
}
}
