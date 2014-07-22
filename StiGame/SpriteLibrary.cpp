#include "SpriteLibrary.h"
#include "GamePath.h"

namespace StiGame
{

Sprite* SpriteLibrary::missing_sprite = NULL;

SpriteLibrary::SpriteLibrary()
{

}

SpriteLibrary::SpriteLibrary(SDL_Renderer *m_renderer)
{
    //ctor
    renderer = m_renderer;

    if(missing_sprite == NULL)
    {
        std::string path = GamePath::getFilepath(AssetSprite, "missing" + Sprite::FILE_EXTENSION);
        missing_sprite = new Sprite(path.c_str(), renderer);
    }
}

void SpriteLibrary::load(std::string name, SpriteType s_type)
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

void SpriteLibrary::loadSpriteFile(std::string sprite_file)
{
    SpriteFile sf = SpriteFile(GamePath::getFilepath(AssetSprite, sprite_file + SpriteFile::FILE_EXTENSION));
    Sprite *spr = new Sprite(&sf, renderer);
    sprites.insert(std::make_pair(sf.getName(), spr));
}

void SpriteLibrary::loadVarFile(std::string sprite_name)
{
    std::string path = GamePath::getFilepath(AssetSprite, sprite_name + Sprite::FILE_EXTENSION);
    Sprite *spr = new Sprite(path.c_str(), renderer);

    sprites.insert(std::make_pair(sprite_name, spr));
}

Sprite* SpriteLibrary::getSprite(std::string sprite_name)
{
    try
    {
        Sprite *spr = sprites.at(sprite_name);
        return spr;
    }
    catch(std::exception& e)
    {
        return missing_sprite;
    }
}

ClonedSprite* SpriteLibrary::clone(std::string sprite_name)
{
    return new ClonedSprite(getSprite(sprite_name));
}

SpriteLibrary::~SpriteLibrary()
{
    //dtor
}

}
