#ifndef DIRECTIONSPRITELIBRARY_H
#define DIRECTIONSPRITELIBRARY_H

#include "SpriteLibrary.h"
#include "DirectionSprite.h"
#include "ClonedDirectionSprite.h"

namespace StiGame {
/// \class DirectionSpriteLibrary
/// \brief Class to handle Direction Sprite into a map and load missing sprite
class DirectionSpriteLibrary
{
public:
    /// \brief Constructor
    DirectionSpriteLibrary();
    /// \brief Create a new Direction Sprite Library
    /// \param m_renderer SDL Renderer
    DirectionSpriteLibrary(SDL_Renderer *m_renderer);
    /// \brief Destructor
    virtual ~DirectionSpriteLibrary();
    /// \brief Set the SDL Renderer
    /// \param m_renderer SDL Renderer
    void setRenderer(SDL_Renderer *m_renderer);
    /// \brief Load a Direction Sprite from a Var File
    /// \param vfPath Var File Path
    void loadVarFile(std::string vfPath);
    /// \brief Load a Direction Sprite from a Sprite File
    /// \param sprPath Sprite File Path
    void loadSpriteFile(std::string sprPath);
    /// \brief Load a Direction Sprite
    /// \param name Sprite Name
    /// \param s_type File type
    void load(std::string name, SpriteType s_type = ST_VARFILE);
    /// \brief Get a Direction Sprite with the specified name, if not found, try to load it
    /// \param name Sprite Name
    /// \return Direction Sprite
    DirectionSprite* getSprite(std::string name);
    /// \brief Clone a Direction Sprite with the specified name, if not found, try to load it
    /// \param name Sprite Name
    /// \return New Instance of a Cloned Direction Sprite
    ClonedDirectionSprite* clone(std::string name);

protected:
    /// \brief SDL Renderer
    SDL_Renderer *renderer;
    /// \brief Loaded Direction Sprites
    std::map< std::string, DirectionSprite* > sprites;
};

}

#endif // DIRECTIONSPRITELIBRARY_H
