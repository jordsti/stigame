#ifndef CLONEDSPRITE_H
#define CLONEDSPRITE_H

#include "Sprite.h"

namespace StiGame
{

/// \class ClonedSprite
/// \brief Sprite that contains his own position but use the frames of another sprite instance (rework this class)
class ClonedSprite :
    public ISprite
{
    public:
        /// \brief Empty Constructor
        ClonedSprite(void);
        /// \brief Create a new Cloned Sprite with the specified sprite
        /// \param m_baseSprite Base Sprite
        ClonedSprite(Sprite* m_baseSprite);
        /// \brief Destructor
        virtual ~ClonedSprite();
        void render(void);

        /// \brief Get the Base Sprite
        /// \return Base Sprite
        Sprite* getBaseSprite(void);

        void tick(void);
    protected:
        void initialize(void);
    private:
        /// \brief Base Sprite
        Sprite* baseSprite;
        /// \brief Tick Number
        unsigned int _tick;
};

}

#endif // CLONEDSPRITE_H
