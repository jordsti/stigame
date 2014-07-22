#ifndef BASEMISSILE_H
#define BASEMISSILE_H
#include <string>
#include <map>
#include "Texture.h"
#include "MathTK.h"
namespace StiGame
{

class BaseMissile
{

    typedef std::map<std::string, Texture*> MissileMap;

    public:
        BaseMissile();
        virtual ~BaseMissile();
        virtual void tick(void);
        int getCurrentX(void);
        int getCurrentY(void);
        int getStartingX(void);
        int getStartingY(void);
        std::string getGfxName(void);
        bool isEnded(void);
        double getAngle(void);
        double getAngle(Math::AngleUnit au);
        Texture* getTexture(void);
    protected:
        bool ended;
        Math::Angle* angle;
        int _tick;
        int currentX;
        int currentY;
        int startingX;
        int startingY;
        int maxLength;
        int speed;
        std::string gfxName;
        SDL_Renderer *renderer;
        static Texture* getTexture(std::string m_gfxName);
        void loadGfx(std::string m_gfxName);
    private:
        static MissileMap missiles_gfx;
        static std::string _defaultGfx;

};

}

#endif // BASEMISSILE_H
