#ifndef SPRITEFILECREATOR_H
#define SPRITEFILECREATOR_H

#include <string>
#include <vector>

namespace StiGame
{
	/// \class SpriteFileCreator
	/// \brief Class that help to generate a Sprite File
	class SpriteFileCreator
	{
		public:
			/// \brief Create a Sprite File Creator
			SpriteFileCreator(void);
			
			/// \brief Sprite File Creator Destructor
			virtual ~SpriteFileCreator(void);
			
			/// \brief Add a frame to the sprite
			/// \param path Image path
			void addFrame(std::string path);

			/// \brief Get Sprite Width
			/// \return width (px)
			int getWidth(void);
			
			/// \brief Get Sprite Height
			/// \return height (px)
			int getHeight(void);
			
			/// \brief Set Sprite Width
			/// \param m_width Width (px)
			void setWidth(int m_width);
			
			/// \brief Set Sprite Height
			/// \param m_height Height (px)
			void setHeight(int m_height);

			/// \brief Get Sprite Name
			/// \return Name
			std::string getName(void);
			
			/// \brief Set Sprite Name
			/// \param m_name Name
			void setName(std::string m_name);

			/// \brief Get number of frames
			/// \return Number of frames
			int getNbFrames(void);
			
			/// \brief Save this sprite to specified file
			/// \param destination output path
			void save(std::string destination);

		protected:
			/// \brief Sprite width
			int width;
			/// \brief Sprite height
			int height;
			/// \brief Number of frames
			int nbFrames;
			/// \brief Frame image path
			std::vector<std::string> frames_path;
			/// \brief Sprite Name
			std::string name;
			/// \brief Detect sprite dimension
			void detectDimension(void);
	};
}

#endif // SPRITEFILECREATOR_H
