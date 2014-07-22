#include "SpriteFile.h"

#include <iostream>
#include <fstream>
namespace StiGame
{
	const std::string SpriteFile::FILE_EXTENSION = ".bspr";
	const int SpriteFile::SPRITE_NAME_SIZE = 64;

	SpriteFile::SpriteFile(void)
	{

	}

	SpriteFile::SpriteFile(std::string sprite_path)
	{
		path = sprite_path;
		readFile();
	}


	void SpriteFile::readFile(void)
	{
		SpriteFileHeader header;
		SpriteImageMarker marker;

		std::ifstream is(path.c_str(), std::ifstream::binary);

		//first we read SpriteFileHeader
		is.read((char*) &header, sizeof(SpriteFileHeader));

		nbFrames = header.nbFrames;
		name = header.spriteName;
		width = header.width;
		height = header.height;

		for(int i=0; i<nbFrames; i++)
		{
			//reading marker for length
			is.read( (char*) &marker, sizeof(SpriteImageMarker));

			int frame_length = marker.length;

			char * buffer = new char[frame_length];

			is.read(buffer, frame_length);

			//creating surface from char array

			SDL_RWops *rw = SDL_RWFromMem(buffer, frame_length);

			SDL_Surface *surface = IMG_Load_RW(rw, 1); //1 to release/free RWops
            std::cout << IMG_GetError() << std::endl;
            //exceptio here, ... todo
            delete buffer;

			surfaces.push_back(surface);
		}

		is.close();
	}

    std::string SpriteFile::getPath(void)
    {
        return path;
    }

    std::string SpriteFile::getName(void)
    {
        return name;
    }

    int SpriteFile::getWidth(void)
    {
        return width;
    }

    int SpriteFile::getHeight(void)
    {
        return height;
    }

    int SpriteFile::getNbFrames(void)
    {
        return nbFrames;
    }

    SDL_Surface* SpriteFile::getSurface(int index)
    {
        return surfaces[index];
    }


	SpriteFile::~SpriteFile()
	{
		std::vector<SDL_Surface*>::iterator lit(surfaces.begin()), lend(surfaces.end());
		for(;lit!=lend;++lit)
		{
			SDL_FreeSurface((*lit));
		}
	}
}
