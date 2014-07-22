#include "BaseMissile.h"
#include "GamePath.h"
#include <cmath>

namespace StiGame
{

BaseMissile::BaseMissile()
{
    //ctor
    _tick = 0;
    renderer = 0;
    gfxName = _defaultGfx;
    currentX = 0;
    currentY = 0;
    startingX = 0;
    startingY = 0;
    speed = 0;
    maxLength = 0;
    ended = true;
    angle = 0;

}

BaseMissile::MissileMap BaseMissile::missiles_gfx;


std::string BaseMissile::_defaultGfx = "default";

BaseMissile::~BaseMissile()
{
    //dtor
    if(angle != 0)
    {
        delete angle;
    }
}

void BaseMissile::loadGfx(std::string m_gfxName)
{
    try
    {
        Texture *tex = missiles_gfx.at(m_gfxName);
    }
    catch(std::exception &e)
    {
        Texture *tex = new Texture(renderer, GamePath::getFilepath(AssetSprite, "missile/" + m_gfxName + ".png").c_str());
        missiles_gfx.insert(std::make_pair(m_gfxName, tex));
    }

}

double BaseMissile::getAngle(void)
{
    return angle->getAngle(Math::AU_RADIAN);
}

double BaseMissile::getAngle(Math::AngleUnit au)
{
    return angle->getAngle(au);
}

Texture* BaseMissile::getTexture(void)
{
    return getTexture(gfxName);
}

Texture* BaseMissile::getTexture(std::string m_gfxName)
{
    try
    {
        return missiles_gfx.at(m_gfxName);
    }
    catch(std::exception &e)
    {
        return missiles_gfx.at(_defaultGfx);
    }
}

void BaseMissile::tick()
{
    _tick++;
    int new_x = (int)((double)currentX + ((double)speed)*cos(angle->getAngle(Math::AU_RADIAN)));
    int new_y = (int)((double)currentY + ((double)speed)*sin(angle->getAngle(Math::AU_RADIAN)));

    double dist = Math::TK::DistanceBetween(startingX, startingY, new_x, new_y);
    //double dist = sqrt(pow(new_x-startingX, 2) + pow(new_y-startingY, 2));
    if(dist > maxLength)
    {
        ended = true;
        return;
    }

    currentX = new_x;
    currentY = new_y;
}

int BaseMissile::getCurrentX()
{
    return currentX;
}

int BaseMissile::getCurrentY()
{
    return currentY;
}

int BaseMissile::getStartingX()
{
    return startingX;
}

int BaseMissile::getStartingY()
{
    return startingY;
}

std::string BaseMissile::getGfxName()
{
    return gfxName;
}

bool BaseMissile::isEnded()
{
    bool v_ended = ended;
    return v_ended;
}

}
