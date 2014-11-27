#ifndef DIRECTIONSPRITE_H
#define DIRECTIONSPRITE_H
#include <vector>
#include "IDirectionSprite.h"
#include "Texture.h"
#include "VarFile.h"

namespace StiGame {

class DirectionSpriteFile;

class DirectionSprite :
    public IDirectionSprite
{
    public:
        const static std::string FILE_EXTENSION;
        DirectionSprite();
        DirectionSprite(SDL_Renderer *m_renderer);
        DirectionSprite(SDL_Renderer *m_renderer, const char* sprite_nfo);
        DirectionSprite(DirectionSpriteFile *sprite_file, SDL_Renderer *m_renderer);
        virtual ~DirectionSprite();
        void render(void);
        void render(SDirection m_direction, int m_frameTick);
        SDirection getDirection(void);
        void setDirection(SDirection m_direction);
        Texture* getCurrentTexture(void);
        Texture* getTexture(SDirection m_direction, int m_frameTick);

        void tick(void);

    protected:
        void fromFile(DirectionSpriteFile *sprite_file);
        void loadTexture(SDirection direction, std::string path);
        void parseDirection(std::string dir_prefix, SDirection pdirection, VarFile *vf);
        void readSpriteFile(const char* sprite_nfo);
        void initialize(void);
        SDL_Renderer *renderer;
        int frame_up;
        int frame_down;
        int frame_left;
        int frame_right;
        int frame_idle;
        std::vector<Texture*> textures_up;
        std::vector<Texture*> textures_down;
        std::vector<Texture*> textures_left;
        std::vector<Texture*> textures_right;
        std::vector<Texture*> textures_idle;
        int _tick;
        SDirection direction;
    private:
};

}

#endif // DIRECTIONSPRITE_H
