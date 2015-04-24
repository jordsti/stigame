#ifndef DIRECTIONSPRITEFILE_H
#define DIRECTIONSPRITEFILE_H

#include <string>
#include <vector>
#include "DirectionSprite.h"

namespace StiGame
{
/// \class DirectionSpriteFile
/// \brief Read A Direction Sprite from a file
class DirectionSpriteFile
{
	public:
        /// \brief Default File Extension
		const static std::string FILE_EXTENSION;
        /// \brief Sprite name field size
        const static int SPRITE_NAME_SIZE;
        /// \brief Empty Constructor
		DirectionSpriteFile();
        /// \brief Create a new Direction Sprite File from a filename
        /// \param sprite_path Sprite Path
		DirectionSpriteFile(std::string sprite_path);
        /// \brief Destructor
        virtual ~DirectionSpriteFile();
        /// \brief Get the Sprite File path
        /// \return Sprite Path
		std::string getPath(void);
        /// \brief Get the Sprite name
        /// \return Sprite Name
		std::string getName(void);
        /// \brief Get Sprite Width
        /// \return Width (px)
		int getWidth(void);
        /// \brief Get Sprite Height
        /// \return Height (px)
		int getHeight(void);
        /// \brief Get the number of frames by direction
        /// \param direction Sprite Direction
        /// \return Number of frames
		int getNbFrames(SDirection direction);
        /// \brief Get the frame with the specified direction and index
        /// \param direction Sprite Direction
        /// \param index Index
		SDL_Surface* getSurface(SDirection direction, int index); //retrieve the surface with moduled (%) index
        /// \brief Create a Direction Sprite Instance with the object value
        /// \param renderer SDL Renderer
        /// \return Direction Sprite Instance
        DirectionSprite* getDirectionSprite(SDL_Renderer *renderer);
	protected:
        /// \brief File path
		std::string path;
        /// \brief Sprite Name
		std::string name;
        /// \brief Top Direction Frames
		std::vector<SDL_Surface*> surfacesTop;
        /// \brief Down Direction Frames
		std::vector<SDL_Surface*> surfacesDown;
        /// \brief Left Direction Frames
		std::vector<SDL_Surface*> surfacesLeft;
        /// \brief Right Direction Frames
		std::vector<SDL_Surface*> surfacesRight;
        /// \brief Idle Frames
		std::vector<SDL_Surface*> surfacesIdle;
        /// \brief Width (px)
        int width;
        /// \brief Height (px)
        int height;
        /// \brief Frames numbers
		int nbFrames[5];
        /// \brief Read the file
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
