#ifndef SPRITELIBRARY_H
#define SPRITELIBRARY_H
#include <map>
#include "Sprite.h"
#include "ClonedSprite.h"
#include "SpriteFile.h"

namespace StiGame
{

enum SpriteType { ST_VARFILE, ST_SPRITEFILE };

/// \class SpriteLibrary
/// \brief Sprite instance manager
class SpriteLibrary
{
    public:
		/// \brief Create a new Sprite library
        SpriteLibrary();
		
		/// \brief Create a new Sprite library
		/// \param m_renderer SDL_Renderer
        SpriteLibrary(SDL_Renderer *m_renderer);
		
		/// \brief Sprite library destructor
        virtual ~SpriteLibrary();
		
		/// \brief Load a sprite
		/// \param name Sprite name
		/// \param s_type Sprite type
        void load(std::string name, SpriteType s_type = ST_VARFILE);
		
		/// \brief Load a sprite from a VarFile
		/// \param sprite_name Sprite Name
        void loadVarFile(std::string sprite_name);
		
		/// \brief Load a sprite from a SpriteFile
		/// \param sprite_file Sprite file
        void loadSpriteFile(std::string sprite_file);
		
		/// \brief Get loaded sprite
		/// \param sprite_name Sprite Name
		/// \return Sprite pointer
        Sprite* getSprite(std::string sprite_name);
		
		/// \brief Get a new cloned sprite
		/// \param sprite_name Sprite Name
		/// \return Cloned Sprite pointer
        ClonedSprite* clone(std::string sprite_name);
    protected:
		/// \brief Sprites map
        std::map<std::string, Sprite*> sprites;
        /// \brief SDL_Renderer
		SDL_Renderer *renderer;
		/// \brief Default sprite
        static Sprite* missing_sprite;
    private:
};

}

#endif // SPRITELIBRARY_H
