#ifndef DIRECTIONSPRITEFILE_H
#define DIRECTIONSPRITEFILE_H

#include <string>
#include <vector>
#include "DirectionSprite.h"

namespace StiGame
{

class DirectionSpriteFile
{
	public:
		const static std::string FILE_EXTENSION;
		const static int SPRITE_NAME_SIZE;
		DirectionSpriteFile();
		DirectionSpriteFile(std::string sprite_path);
		virtual ~DirectionSpriteFile();

		std::string getPath(void);
		std::string getName(void);
		int getWidth(void);
		int getHeight(void);
		int getNbFrames(SDirection direction);
		SDL_Surface* getSurface(SDirection direction, int index); //retrieve the surface with moduled (%) index
		DirectionSprite* getDirectionSprite(SDL_Renderer *renderer);
	protected:
		std::string path;
		std::string name;
		std::vector<SDL_Surface*> surfacesTop;
		std::vector<SDL_Surface*> surfacesDown;
		std::vector<SDL_Surface*> surfacesLeft;
		std::vector<SDL_Surface*> surfacesRight;
		std::vector<SDL_Surface*> surfacesIdle;
		int width;
		int height;
		int nbFrames[5];
		void readFile(void);
	private:
		void initialize(void);


};

struct DirectionSpriteFileHeader
{
	char spriteName[64];
	int nbFrames[5];
	int width;
	int height;
};

struct DirectionSpriteImageMarker
{
    SDirection direction;
    int length;
};


}
#endif // DIRECTIONSPRITEFILE_H
