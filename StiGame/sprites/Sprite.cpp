#include "Sprite.h"
#include <climits>
#include <sstream>
#include "VarFile.h"
#include <iostream>
#include "GamePath.h"

namespace StiGame
{
//inital tick value
unsigned long Sprite::tick = 0;

const std::string Sprite::FILE_EXTENSION = ".spr";

void Sprite::tickSprites(void)
{
    tick++;

    if(tick == ULONG_MAX)
    {
        tick = 0;
    }
}

Sprite::Sprite(void)
{
    renderer = 0;
    initialize();
}

Sprite::Sprite(SDL_Renderer *m_renderer)
{
    renderer = m_renderer;
    initialize();
}

Sprite::Sprite(const char* sprite_nfo, SDL_Renderer *m_renderer)
{
    renderer = m_renderer;
    initialize();
    readSpriteFile(sprite_nfo);
    loadImages();
}

Sprite::Sprite(SpriteFile *sprite_file, SDL_Renderer *m_renderer)
{
    initialize();
    renderer = m_renderer;
    readSpriteFileObject(sprite_file);

}

void Sprite::initialize(void)
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    frame_count = 0;
}


void Sprite::readSpriteFile(const char* sprite_nfo)
{
    VarFile vf = VarFile(sprite_nfo);

    vf.read();

    //sprite# : starting with 0;

    std::string base_fr = "sprite";
    int i = 0;
    while(true)
    {
        std::string fr_name = base_fr + toString(i);

        if(vf.isVarExists(fr_name))
        {
            std::string img_path = vf.getValue(fr_name);
            frame_images.push_back(img_path);
            frame_count++;
            i++;
        }
        else
        {
            break;
        }
    }

}

void Sprite::readSpriteFileObject(SpriteFile *sprite_file)
{
    frame_count = sprite_file->getNbFrames();

    width = sprite_file->getWidth();
    height = sprite_file->getHeight();

    for(int i=0; i<frame_count; i++)
    {
        SDL_Surface *surface = sprite_file->getSurface(i);
        Surface *sur = new Surface(surface);
        sur->setReleaseSurface(true);

        Texture *tx = new Texture(renderer, surface);

        frame_textures.push_back(tx);
        frame_surfaces.push_back(sur);
    }
}

void Sprite::loadImages()
{
    std::list<std::string>::iterator lit(frame_images.begin()), lend(frame_images.end());
    for(;lit!=lend;++lit)
    {
        std::string path =  GamePath::combine(GamePath::getPath(AssetRoot), (*lit) );
        Surface *sur = new Surface(path.c_str());
        Texture *tx = new Texture(renderer, sur);

        frame_surfaces.push_back(sur);
        frame_textures.push_back(tx);

        if(width == 0 && height == 0)
        {
            width = tx->getWidth();
            height = tx->getHeight();
        }
    }

}

Texture* Sprite::getCurrentTexture(void)
{
    int id = (tick % frame_count);

    return frame_textures[id];
}

Surface* Sprite::getCurrentSurface(void)
{
    int id = (tick % frame_count);

    return frame_surfaces[id];

}

void Sprite::render(void)
{
    if(renderer != 0)
    {
        Texture *texture = getCurrentTexture();

        SDL_Rect *src = getSDLRect();
        SDL_Rect *dst = getSDLRect();

        src->x = 0;
        src->y = 0;

        texture->renderCopy(src, dst);

        delete dst;
        delete src;
    }

}


Sprite::~Sprite()
{
    //dtor
    for(int i=0; i<frame_count; i++)
    {
        delete frame_textures[i];
    }
}


}
