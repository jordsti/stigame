#ifndef SPRITEFILE_H
#define SPRITEFILE_H

#include <string>
#include <vector>
#include "SDL.h"
#include "SDL_image.h"

/* Note(s)
* Need to add a constructor to Texture (SDL_Renderer *renderer, SDL_Surface *surface)
*	from surface
*
*
*/

namespace StiGame
{
	/// \class SpriteFile
	/// \brief Class that read a binary Sprite File
	class SpriteFile
	{
		public:
			/// \brief Sprite File extension
			const static std::string FILE_EXTENSION;
			
			/// \brief Name size
			const static int SPRITE_NAME_SIZE;
			
			/// \brief Create an empty Sprite File
			SpriteFile();
			
			/// \brief Create a Sprite File from the specified path
			/// \param sprite_path Sprite File path
			SpriteFile(std::string sprite_path);
			
			/// \brief Sprite File Destructor
			virtual ~SpriteFile(void);
			
			/// \brief Get Sprite File path
			/// \return path
			std::string getPath(void);
			
			/// \brief Get Sprite Name
			/// \param Name
			std::string getName(void);
			
			/// \brief Get width
			/// \return width
			int getWidth(void);
			
			/// \brief Get height
			/// \return height
			int getHeight(void);
			
			/// \brief Get number of frames
			/// \return number of frames
			int getNbFrames(void);
			
			/// \brief Get surface
			/// \param index Index
			/// \return SDL_Surface
			SDL_Surface* getSurface(int index);
		protected:
			/// \brief Sprite File path
			std::string path;
			
			/// \brief Name
			std::string name;
			
			/// \brief Sprite Frames
			std::vector<SDL_Surface*> surfaces;
			
			/// \brief Sprite Width
			int width;
			
			/// \brief Sprite Height
			int height;
			
			/// \brief Number of frames
			int nbFrames;
			
			/// \brief Read sprite file
			void readFile(void);
        private:
	};

	/// \struct SpriteFileHeader
	/// \brief Header of a SpriteFile
    struct SpriteFileHeader
	{
		/// \brief Name
		char spriteName[64];
		/// \brief Number of frames
		int nbFrames;
		/// \brief Sprite Width
		int width;
		/// \brief Sprite Height
		int height;
	};

	/// \struct SpriteImageMarker
	/// \brief Marker to delimit Sprite frame
	struct SpriteImageMarker
	{
		/// \brief Length of the frame
		int length;
	};
}


#endif // SPRITEFILE_H
