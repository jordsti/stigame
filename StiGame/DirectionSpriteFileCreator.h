#ifndef DIRECTIONSPRITEFILECREATOR_H
#define DIRECTIONSPRITEFILECREATOR_H

#include <string>
#include <vector>
#include "DirectionSprite.h"

namespace StiGame
{
	class DirectionSpriteFileCreator
	{
		public:
			DirectionSpriteFileCreator();
			virtual ~DirectionSpriteFileCreator();

			void addFrame(SDirection direction, std::string path);

			int getWidth(void);
			int getHeight(void);
			void setWidth(int m_width);
			void setHeight(int m_height);

			std::string getName(void);
			void setName(std::string m_name);

			int getNbFrames(SDirection direction);

			void save(std::string destination);

		protected:
		    std::string getFramePath(SDirection direction, int index);
			int width;
			int height;
			int nbFrames[5];
			std::vector<std::string> frames_pathUp;
			std::vector<std::string> frames_pathDown;
			std::vector<std::string> frames_pathLeft;
			std::vector<std::string> frames_pathRight;
			std::vector<std::string> frames_pathIdle;
			std::string name;
			void detectDimension(void);
	};
}

#endif // DIRECTIONSPRITEFILECREATOR_H
