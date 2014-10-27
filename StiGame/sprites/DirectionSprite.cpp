#include "DirectionSprite.h"
#include "DirectionSpriteFile.h"
#include "GamePath.h"
#include <cmath>
namespace StiGame
{

const std::string DirectionSprite::FILE_EXTENSION = ".dspr";

DirectionSprite::DirectionSprite()
{
    initialize();
}

DirectionSprite::DirectionSprite(SDL_Renderer *m_renderer)
{
    //ctor
    initialize();
    renderer = m_renderer;
}

DirectionSprite::DirectionSprite(DirectionSpriteFile *sprite_file, SDL_Renderer *m_renderer)
{
    initialize();
    renderer = m_renderer;

    fromFile(sprite_file);
}

void DirectionSprite::fromFile(DirectionSpriteFile *sprite_file)
{
    width = sprite_file->getWidth();
    height = sprite_file->getHeight();

    for(int i=0; i<5; i++)
    {
        int num_val = pow(2, i);
        SDirection dir = static_cast<SDirection>(num_val);
        Texture *tex;
        for(int j=0; j<sprite_file->getNbFrames(dir); j++)
        {

            switch(num_val)
            {
            case 1:
                tex = new Texture(renderer, sprite_file->getSurface(dir, j));
                textures_up.push_back(tex);
                frame_up++;
                break;
            case 2:
                tex = new Texture(renderer, sprite_file->getSurface(dir, j));
                textures_down.push_back(tex);
                frame_down++;
                break;
            case 4:
                tex = new Texture(renderer, sprite_file->getSurface(dir, j));
                textures_left.push_back(tex);
                frame_left++;
                break;
            case 8:
                tex = new Texture(renderer, sprite_file->getSurface(dir, j));
                textures_right.push_back(tex);
                frame_right++;
                break;
            case 16:
                tex = new Texture(renderer, sprite_file->getSurface(dir, j));
                textures_idle.push_back(tex);
                frame_idle++;
                break;
            }
        }
    }
}

DirectionSprite::DirectionSprite(SDL_Renderer *m_renderer, const char* sprite_nfo)
{
    initialize();
    renderer = m_renderer;
    readSpriteFile(sprite_nfo);
}

void DirectionSprite::setDirection(SDirection m_direction)
{
    direction = m_direction;
}

SDirection DirectionSprite::getDirection(void)
{
    return direction;
}

void DirectionSprite::readSpriteFile(const char* sprite_nfo)
{
    VarFile vf = VarFile(sprite_nfo);

    vf.read();

    //up# : starting with 0;
    //down# : starting with 0;
    //left# : starting with 0;
    //right# : starting with 0;

    parseDirection("up", SD_UP, &vf);
    parseDirection("down", SD_DOWN, &vf);
    parseDirection("left", SD_LEFT, &vf);
    parseDirection("right", SD_RIGHT, &vf);
    parseDirection("idle", SD_IDLE, &vf);
}

void DirectionSprite::parseDirection(std::string dir_prefix, SDirection pdirection, VarFile *vf)
{
    int i=0;
    while(true)
    {
        std::string vname = dir_prefix + toString(i);
        if(vf->isVarExists(vname))
        {
            loadTexture(pdirection, vf->getValue(vname));
        }
        else
        {
            break;
        }

        i++;
    }
}

Texture* DirectionSprite::getCurrentTexture(void)
{
    int i = 0;
    switch(direction)
    {
    case SD_UP:
        i = tick % frame_up;
        return textures_up[i];
    case SD_DOWN:
        i = tick % frame_down;
        return textures_down[i];
    case SD_LEFT:
        i = tick % frame_left;
        return textures_left[i];
    case SD_RIGHT:
        i = tick % frame_right;
        return textures_right[i];
    case SD_IDLE:
        i = tick % frame_idle;
        return textures_idle[i];
    default:
        i = tick % frame_right;
        return textures_right[i];
    }
}

void DirectionSprite::loadTexture(SDirection direction, std::string path)
{
    path = GamePath::getFilepath(AssetRoot, path);
    Texture *tx = new Texture(renderer, path.c_str());

    if(width == 0 && height == 0)
    {
        width = tx->getWidth();
        height = tx->getHeight();
    }

    switch(direction)
    {
    case SD_UP:
        textures_up.push_back(tx);
        frame_up++;
        break;
    case SD_DOWN:
        textures_down.push_back(tx);
        frame_down++;
        break;
    case SD_LEFT:
        textures_left.push_back(tx);
        frame_left++;
        break;
    case SD_RIGHT:
        textures_right.push_back(tx);
        frame_right++;
        break;
    case SD_IDLE:
        textures_idle.push_back(tx);
        frame_idle++;
        break;
    }
}

void DirectionSprite::initialize()
{
    direction = SD_UP;
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    tick = 0;
    renderer = 0;
    frame_up = 0;
    frame_down = 0;
    frame_left = 0;
    frame_right = 0;
    frame_idle = 0;
}

DirectionSprite::~DirectionSprite()
{
    //dtor
}


void DirectionSprite::render(void)
{
    Texture *tx = getCurrentTexture();

    SDL_Rect *src = getSDLRect();
    SDL_Rect *dst = getSDLRect();

    src->x = 0;
    src->y = 0;

    tx->renderCopy(src, dst);

    delete src;
    delete dst;

    tick++;
}

}
