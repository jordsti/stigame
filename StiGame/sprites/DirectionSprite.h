#ifndef DIRECTIONSPRITE_H
#define DIRECTIONSPRITE_H
#include <vector>
#include "IDirectionSprite.h"
#include "Texture.h"
#include "VarFile.h"

namespace StiGame {

class DirectionSpriteFile;
/// \class DirectionSprite
/// \brief Sprite with frames separated by their direction
class DirectionSprite :
    public IDirectionSprite
{
    public:
        /// \brief Default File Extension
        const static std::string FILE_EXTENSION;
        /// \brief Empty Constructor
        DirectionSprite();
        /// \brief Create a new Direction Sprite
        /// \param m_renderer SDL_Renderer
        DirectionSprite(SDL_Renderer *m_renderer);
        /// \brief Create a new Direction Sprite from a Var File
        /// \param m_renderer SDL Renderer
        /// \param sprite_nfo Sprite Var File
        DirectionSprite(SDL_Renderer *m_renderer, const char* sprite_nfo);
        /// \brief Create a new Direction Sprite from a Direction Sprite File
        /// \param sprite_file Direction Sprite File
        /// \param m_renderer SDL Renderer
        DirectionSprite(DirectionSpriteFile *sprite_file, SDL_Renderer *m_renderer);
        /// \brief Destructor
        virtual ~DirectionSprite();

        void render(void);
        void render(SDirection m_direction, int m_frameTick);
        /// \brief Get Current Direction
        /// \return Sprite Direction
        SDirection getDirection(void);
        /// \brief Set Direction
        /// \param m_direction Sprite Direction
        void setDirection(SDirection m_direction);
        /// \brief Get Current Texture
        /// \return Texture Pointer
        Texture* getCurrentTexture(void);
        /// \brief Get Texture with specified Direction and tick
        /// \param m_direction Sprite Direction
        /// \param m_frameTick Tick
        /// \return Texture Pointer
        Texture* getTexture(SDirection m_direction, int m_frameTick);

        void tick(void);

    protected:
        /// \brief Read vaule from a Direction Sprite File
        void fromFile(DirectionSpriteFile *sprite_file);
        /// \brief Load a image file
        /// \param direction Sprite Direction
        /// \param path Image Path
        void loadTexture(SDirection direction, std::string path);
        /// \brief Parse Direction Frame from a Var File
        /// \param dir_prefix Direction prefix
        /// \param pdirection Direction Enum Value
        /// \param vf Var File Instance
        void parseDirection(std::string dir_prefix, SDirection pdirection, VarFile *vf);
        /// \brief Read Direction Sprite from a Var File
        /// \param sprite_nfo Var File Path
        void readSpriteFile(const char* sprite_nfo);
        void initialize(void);
        /// \brief SDL Renderer
        SDL_Renderer *renderer;
        /// \brief Frames Up Count
        int frame_up;
        /// \brief Frames Down Count
        int frame_down;
        /// \brief Frames Left Count
        int frame_left;
        /// \brief Frames Right count
        int frame_right;
        /// \brief Frames Idle Count
        int frame_idle;
        /// \brief Textures Up
        std::vector<Texture*> textures_up;
        /// \brief Textures Down
        std::vector<Texture*> textures_down;
        /// \brief Textures Left
        std::vector<Texture*> textures_left;
        /// \brief Textures Right
        std::vector<Texture*> textures_right;
        /// \brief Textures Idle
        std::vector<Texture*> textures_idle;
        int _tick;
        /// \brief Current Sprite Direction
        SDirection direction;
    private:
};

}

#endif // DIRECTIONSPRITE_H
