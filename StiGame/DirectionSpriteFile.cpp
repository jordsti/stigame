#include "DirectionSpriteFile.h"
#include <iostream>
#include <fstream>
namespace StiGame
{
		const std::string DirectionSpriteFile::FILE_EXTENSION = ".bdspr";
		const int DirectionSpriteFile::SPRITE_NAME_SIZE = 64;

		DirectionSpriteFile::DirectionSpriteFile(std::string sprite_path)
		{
			path = sprite_path;
			readFile();
		}

		DirectionSpriteFile::~DirectionSpriteFile()
		{
			for(int i=0; i<nbFrames[0]; i++)
				SDL_FreeSurface(surfacesTop[i]);
			for(int i=0; i<nbFrames[1]; i++)
				SDL_FreeSurface(surfacesDown[i]);
			for(int i=0; i<nbFrames[2]; i++)
				SDL_FreeSurface(surfacesLeft[i]);
			for(int i=0; i<nbFrames[3]; i++)
				SDL_FreeSurface(surfacesRight[i]);
            for(int i=0; i<nbFrames[4]; i++)
				SDL_FreeSurface(surfacesIdle[i]);
		}

		void DirectionSpriteFile::initialize(void)
		{
			for(int i=0; i<5; i++)
				nbFrames[i] = 0;
			width = 0;
			height = 0;
			name = "";
			path = "";
		}

		DirectionSpriteFile::DirectionSpriteFile()
		{
			initialize();
		}

        DirectionSprite* DirectionSpriteFile::getDirectionSprite(SDL_Renderer *renderer)
        {
            DirectionSprite *sprite = new DirectionSprite(this, renderer);
            return sprite;
        }

		std::string DirectionSpriteFile::getPath(void)
		{
			return path;
		}

		std::string DirectionSpriteFile::getName(void)
		{
			return name;
		}

		int DirectionSpriteFile::getWidth(void)
		{
			return width;
		}

		int DirectionSpriteFile::getHeight(void)
		{
			return height;
		}

		int DirectionSpriteFile::getNbFrames(SDirection direction)
		{
			//nbFrames[]
			//0 - top
			//1 - down
			//2 - left
			//3 - right
			int val = 0;
			switch(direction)
			{
				case SD_UP:
					val = nbFrames[0];
					break;
				case SD_DOWN:
					val = nbFrames[1];
					break;
				case SD_LEFT:
					val = nbFrames[2];
					break;
				case SD_RIGHT:
					val = nbFrames[3];
					break;
                case SD_IDLE:
                    val = nbFrames[4];
                    break;
			}
			return val;
		}

		SDL_Surface* DirectionSpriteFile::getSurface(SDirection direction, int index)
		{
			int i = index % getNbFrames(direction);

			SDL_Surface *surface = 0;

			switch(direction)
			{
				case SD_UP:
					surface = surfacesTop[i];
					break;
				case SD_DOWN:
					surface = surfacesDown[i];
					break;
				case SD_LEFT:
					surface = surfacesLeft[i];
					break;
				case SD_RIGHT:
					surface = surfacesRight[i];
					break;
                case SD_IDLE:
                    surface = surfacesIdle[i];
                    break;
			}

			return surface;
		}

		void DirectionSpriteFile::readFile(void)
		{
			DirectionSpriteFileHeader header;
			DirectionSpriteImageMarker marker;

			std::ifstream is (path.c_str(), std::ifstream::binary);

			is.read((char*)&header, sizeof(DirectionSpriteFileHeader));

			name = header.spriteName;
			width = header.width;
			height = header.height;

			for(int i=0; i<5; i++)
			{
				nbFrames[i] = header.nbFrames[i];

			}

			while(!is.eof())
            {
				is.read((char*)&marker, sizeof(DirectionSpriteImageMarker));
				int frame_length = marker.length;
                SDirection sprDirection = marker.direction;
				char * buffer = new char[frame_length];

				is.read(buffer, frame_length);


				SDL_RWops *rw = SDL_RWFromMem(buffer, frame_length);

				SDL_Surface *surface = IMG_Load_RW(rw, 1);

                std::cout << IMG_GetError() << std::endl;

				delete buffer;

				switch((int)sprDirection)
				{
					case 1:
						surfacesTop.push_back(surface);
						break;
					case 2:
						surfacesDown.push_back(surface);
						break;
					case 4:
						surfacesLeft.push_back(surface);
						break;
					case 8:
						surfacesRight.push_back(surface);
						break;
                    case 16:
                        surfacesIdle.push_back(surface);
                        break;
				}

            }




			is.close();
		}

}
