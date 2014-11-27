#ifndef DIRECTIONSPRITELIBRARY_H
#define DIRECTIONSPRITELIBRARY_H

#include "SpriteLibrary.h"
#include "DirectionSprite.h"
#include "ClonedDirectionSprite.h"

namespace StiGame {

class DirectionSpriteLibrary
{
public:
    DirectionSpriteLibrary();
    DirectionSpriteLibrary(SDL_Renderer *m_renderer);
    virtual ~DirectionSpriteLibrary();

    void setRenderer(SDL_Renderer *m_renderer);

    void loadVarFile(std::string vfPath);
    void loadSpriteFile(std::string sprPath);
    void load(std::string name, SpriteType s_type = ST_VARFILE);

    DirectionSprite* getSprite(std::string name);
    ClonedDirectionSprite* clone(std::string name);

protected:
    SDL_Renderer *renderer;
    std::map< std::string, DirectionSprite* > sprites;
};

}

#endif // DIRECTIONSPRITELIBRARY_H
