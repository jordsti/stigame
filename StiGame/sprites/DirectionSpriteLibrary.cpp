#include "DirectionSpriteLibrary.h"
#include "GamePath.h"
#include "DirectionSpriteFile.h"

namespace StiGame {

DirectionSpriteLibrary::DirectionSpriteLibrary()
{
    renderer = nullptr;
}

DirectionSpriteLibrary::DirectionSpriteLibrary(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;
}

DirectionSpriteLibrary::~DirectionSpriteLibrary()
{
    auto mit(sprites.begin()), mend(sprites.end());
    for(;mit!=mend;++mit)
    {
        delete mit->second;
    }
}

void DirectionSpriteLibrary::setRenderer(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;
}

void DirectionSpriteLibrary::loadVarFile(std::string name)
{
    std::string fullpath = GamePath::getFilepath(AssetSprite, name + DirectionSprite::FILE_EXTENSION);
    DirectionSprite *dspr = new DirectionSprite(renderer, fullpath.c_str());
    sprites.insert(std::make_pair(name, dspr));
}

void DirectionSpriteLibrary::loadSpriteFile(std::string name)
{
    std::string fullpath = GamePath::getFilepath(AssetSprite, name + DirectionSpriteFile::FILE_EXTENSION);
    DirectionSpriteFile spf (fullpath);
    DirectionSprite *dspr = new DirectionSprite(&spf, renderer);
    sprites.insert(std::make_pair(name, dspr));
}

void DirectionSpriteLibrary::load(std::string name, SpriteType s_type)
{
    if(s_type == ST_VARFILE)
    {
        loadVarFile(name);
    }
    else if(s_type == ST_SPRITEFILE)
    {
        loadSpriteFile(name);
    }
}

DirectionSprite* DirectionSpriteLibrary::getSprite(std::string name)
{
    //todo exception catching
    return sprites[name];
}

ClonedDirectionSprite* DirectionSpriteLibrary::clone(std::string name)
{
    //same as ^
    ClonedDirectionSprite *cloned = new ClonedDirectionSprite(sprites[name]);
    return cloned;
}

}
