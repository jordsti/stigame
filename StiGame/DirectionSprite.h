#ifndef DIRECTIONSPRITE_H
#define DIRECTIONSPRITE_H
#include <vector>
#include "ISprite.h"
#include "Texture.h"
#include "VarFile.h"

namespace StiGame {

enum SDirection { SD_UP = 1, SD_DOWN = 2, SD_LEFT = 4, SD_RIGHT = 8, SD_IDLE = 16 }    ;

class DirectionSpriteFile;

class DirectionSprite :
    public ISprite
{
    public:
        const static std::string FILE_EXTENSION;
        DirectionSprite();
        DirectionSprite(SDL_Renderer *m_renderer);
        DirectionSprite(SDL_Renderer *m_renderer, const char* sprite_nfo);
        DirectionSprite(DirectionSpriteFile *sprite_file, SDL_Renderer *m_renderer);
        virtual ~DirectionSprite();
        void render(void);
        SDirection getDirection(void);
        void setDirection(SDirection m_direction);
        Texture* getCurrentTexture(void);
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
        int tick;
        SDirection direction;
    private:
};

}

#endif // DIRECTIONSPRITE_H
