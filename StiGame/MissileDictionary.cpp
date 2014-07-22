#include "MissileDictionary.h"
#include "VarFile.h"
#include "GamePath.h"
namespace StiGame
{

MissileDictionary::MissileDictionary()
{
    //ctor
}

MissileDictionary::~MissileDictionary()
{
    //dtor
}

void MissileDictionary::loadMissileFile(std::string m_name)
{
    VarFile vf = VarFile(GamePath::getFilepath(AssetRoot, m_name + SBMissile::FILE_EXTENSION).c_str());
    vf.read();

    MissileData *mdata = new MissileData();
    mdata->damage = VarFile::ParseInt(vf.getValue("damage"));
    mdata->maxLength = VarFile::ParseInt(vf.getValue("maxLength"));
    mdata->speed = VarFile::ParseInt(vf.getValue("speed"));
    mdata->gfxName = vf.getValue("gfxName");

    missileMaps.insert(std::make_pair(m_name, mdata));
}

 BaseMissile* MissileDictionary::createMissile(SDL_Renderer *renderer, std::string m_name, int x, int y, double angle)
 {
     MissileData *mdata = missileMaps[m_name];

     BaseMissile *missile = new SBMissile(renderer, mdata, x, y, angle);

     return missile;
 }

}
