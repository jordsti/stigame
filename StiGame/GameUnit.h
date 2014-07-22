#ifndef GAMEUNIT_H
#define GAMEUNIT_H

#include "DirectionSprite.h"

#include <string>
namespace StiGame
{

class GameUnit
{
    public:
        GameUnit();
        virtual ~GameUnit();

        int getX(void);
        int getY(void);
        int getWidth(void);
        int getHeight(void);
        int getSpeed(void);
        std::string getName(void);
        std::string getGfxName(void);
        int getDirection(void);

        //pure virtual method
        virtual void moveUnit(SDirection m_direction) = 0;
        virtual void tick(void) = 0;

    protected:
        int x;
        int y;
        int width;
        int height;
        int speed;
        std::string name;
        std::string gfxName;
        int direction;
    private:
};

}

#endif // GAMEUNIT_H
