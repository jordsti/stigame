#ifndef SPRITE_H
#define SPRITE_H
#include <list>
#include <vector>
#include <string>
#include "SDL.h"

#include "Point.h"
#include "Dimension.h"
#include "Texture.h"

#include "ISprite.h"
#include "SpriteFile.h"

namespace StiGame
{
/// \class Sprite
/// \brief Generic Sprite
class Sprite :
    public ISprite
{
    public:
		/// \brief Sprite File extension
        const static std::string FILE_EXTENSION;

        /// \brief Create an empty Sprite
		Sprite(void);

		/// \brief Create a new Sprite
		/// \param m_renderer SDL_Renderer
        Sprite(SDL_Renderer *m_renderer); //empty

		/// \brief Create a new sprite
		/// \param sprite_nfo VarFile path
		/// \param m_renderer SDL_Renderer
        Sprite(const char* sprite_nfo, SDL_Renderer *m_renderer); //from sprite file, using VarFile

		/// \brief Create a new sprite
		/// \param sprite_file Sprite File
		/// \param m_renderer SDL_Renderer
        Sprite(SpriteFile *sprite_file, SDL_Renderer *m_renderer); //from sprite file, using SpriteFile

		/// \brief Sprite destructor
        virtual ~Sprite();

		/// \brief Get current Texture
		/// \return Texture pointer
        Texture* getCurrentTexture(void);
        /// \brief Get texture with specified index
        /// \return Texture
        Texture* getTexture(unsigned int index);
        /// \brief Get current Surface
        /// \return Surface Pointer
        Surface* getCurrentSurface(void);
        /// \brief Get Surface with specified index
        /// \return Surface Pointer
        Surface* getSurface(unsigned int index);
        /// \brief Increment the Tick number
        void tick(void);

		/// \brief render sprite
        void render(void);
        //void move(int dx, int dy);
        //void move(SVector *d_vector);
    protected:
		/// \brief Initialization
        void initialize(void);
		/// \brief Load sprite image
        void loadImages(void);
		/// \brief Read sprite from a Sprite File
        void readSpriteFileObject(SpriteFile *sprite_file);
		/// \brief Read sprite from a Var File
        void readSpriteFile(const char* sprite_nfo);
		/// \brief frame image path
        std::list<std::string> frame_images;
		/// \brief frame textures
        std::vector<Texture*> frame_textures;
        /// \brief frame surfaces
        std::vector<Surface*> frame_surfaces;

        //Texture frame_textures[];
		/// \brief number of frames
        int frame_count;
    private:
       /// \brief Sprite tick
       unsigned long _tick;
	   /// \brief SDL_Renderer
       SDL_Renderer *renderer;

};

}
#endif // SPRITE_H
