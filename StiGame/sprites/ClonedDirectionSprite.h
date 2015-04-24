#ifndef CLONEDDIRECTIONSPRITE_H
#define CLONEDDIRECTIONSPRITE_H

#include "DirectionSprite.h"

namespace StiGame {

/// \class ClonedDirectionSprite
/// \brief Direction Sprite that has his own tick number but use the frame of an another Direction Sprite
class ClonedDirectionSprite :
        public IDirectionSprite
{
public:
    /// \brief Create a new Cloned Direction Sprite with the specified Direction Sprite
    ClonedDirectionSprite(DirectionSprite *m_sprite);
    /// \brief Destructor
    virtual ~ClonedDirectionSprite();
    /// \brief Set Sprite Direction
    /// \param m_direction Sprite Direction
    void setDirection(SDirection m_direction);
    /// \brief Get the Current Direction
    /// \return Sprite Direction
    SDirection getDirection(void);

    void render(void);
    void render(SDirection m_direction, int m_frameTick);
    /// \brief Get he Base Direction Sprite
    /// \return Direction Sprite
    DirectionSprite* getDirectionSprite(void);

    void tick(void);
protected:
    /// \brief Base Direction Sprite
    DirectionSprite *sprite;
    /// \brief Tick number
    int _tick;
    /// \brief Current Sprite Direction
    SDirection direction;
};

}

#endif // CLONEDDIRECTIONSPRITE_H
