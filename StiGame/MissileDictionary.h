#ifndef MISSILEDICTIONARY_H
#define MISSILEDICTIONARY_H

#include "SBMissile.h"
#include <map>
namespace StiGame
{
//to create missile from varfile loaded into a struct

class MissileDictionary
{
    public:
        MissileDictionary();
        virtual ~MissileDictionary();

        void loadMissileFile(std::string m_name);
        BaseMissile* createMissile(SDL_Renderer *renderer, std::string m_name, int x, int y, double angle);
    protected:
        std::map<std::string, MissileData*> missileMaps;
    private:
};

}

#endif // MISSILEDICTIONARY_H
