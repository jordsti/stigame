#ifndef SBMISSILE_H
#define SBMISSILE_H

#include "BaseMissile.h"

namespace StiGame
{


struct MissileData
{
    int speed;
    int maxLength;
    int damage;
    std::string gfxName;

};

class SBMissile :
    public BaseMissile
{
    public:
        static const std::string FILE_EXTENSION;
        SBMissile();
        SBMissile(SDL_Renderer *m_renderer, MissileData *data, int m_startingX, int m_startingY, double m_angle);
        virtual ~SBMissile();
    protected:
    private:
};

}

#endif // SBMISSILE_H
