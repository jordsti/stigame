#include "SBMissile.h"
namespace StiGame
{

const std::string SBMissile::FILE_EXTENSION = ".mis";

SBMissile::SBMissile()
{
    //ctor
}

SBMissile::SBMissile(SDL_Renderer *m_renderer, MissileData *data, int m_startingX, int m_startingY, double m_angle)
{
    renderer = m_renderer;
    angle = Math::TK::CreateAngle(Math::AU_RADIAN, m_angle);
    startingX = m_startingX;
    startingY = m_startingY;
    currentX = startingX;
    currentY = startingY;
    speed = data->speed;
    maxLength = data->maxLength;
    gfxName = data->gfxName;

}

SBMissile::~SBMissile()
{
    //dtor
}

}
