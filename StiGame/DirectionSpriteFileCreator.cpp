#include "DirectionSpriteFileCreator.h"
#include "DirectionSpriteFile.h"

#include "Surface.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>
namespace StiGame
{
	DirectionSpriteFileCreator::DirectionSpriteFileCreator()
	{
		width = 0;
		height = 0;
		name = "";
		for(int i=0; i<5; i++)
			nbFrames[i] = 0;
	}

	DirectionSpriteFileCreator::~DirectionSpriteFileCreator()
	{

	}

	void DirectionSpriteFileCreator::addFrame(SDirection direction, std::string path)
	{
		switch(direction)
		{
			case SD_UP:
				nbFrames[0]++;
				frames_pathUp.push_back(path);
				break;
			case SD_DOWN:
				nbFrames[1]++;
				frames_pathDown.push_back(path);
				break;
			case SD_LEFT:
				nbFrames[2]++;
				frames_pathLeft.push_back(path);
				break;
			case SD_RIGHT:
				nbFrames[3]++;
				frames_pathRight.push_back(path);
				break;
            case SD_IDLE:
                nbFrames[4]++;
                frames_pathIdle.push_back(path);
                break;
		}
	}

	int DirectionSpriteFileCreator::getWidth(void)
	{
		return width;
	}

	int DirectionSpriteFileCreator::getHeight(void)
	{
		return height;
	}
	void DirectionSpriteFileCreator::setWidth(int m_width)
	{
		width = m_width;
	}
	void DirectionSpriteFileCreator::setHeight(int m_height)
	{
		height = m_height;
	}

	std::string DirectionSpriteFileCreator::getName(void)
	{
		return name;
	}
	void DirectionSpriteFileCreator::setName(std::string m_name)
	{
		name = m_name;
	}

	int DirectionSpriteFileCreator::getNbFrames(SDirection direction)
	{
		switch(direction)
		{
			case SD_UP:
				return nbFrames[0];
			case SD_DOWN:
				return nbFrames[1];
			case SD_LEFT:
				return nbFrames[2];
			case SD_RIGHT:
				return nbFrames[3];
            case SD_IDLE:
                return nbFrames[4];
		}

		return 0;
	}
    std::string DirectionSpriteFileCreator::getFramePath(SDirection direction, int index)
    {
        switch(direction)
        {
        case SD_UP:
            return frames_pathUp[index];
        case SD_DOWN:
            return frames_pathDown[index];
        case SD_LEFT:
            return frames_pathLeft[index];
        case SD_RIGHT:
            return frames_pathRight[index];
        case SD_IDLE:
            return frames_pathIdle[index];
        default:
            return frames_pathUp[index];
        }
    }


	void DirectionSpriteFileCreator::save(std::string destination)
	{
        std::ofstream out (destination.c_str(), std::ofstream::binary | std::ofstream::trunc);

        DirectionSpriteFileHeader header = DirectionSpriteFileHeader();
        DirectionSpriteImageMarker marker = DirectionSpriteImageMarker();


        header.spriteName[name.size()] = 0;
        memcpy(header.spriteName, name.c_str(), name.size());

        if(width == 0 && height == 0)
        {
            detectDimension();
        }

        header.width = width;
        header.height = height;

        for(int i=0; i<5; i++)
        {
            header.nbFrames[i] = nbFrames[i];
        }

        out.write(reinterpret_cast<char*>(&header), sizeof(DirectionSpriteFileHeader));

        for(int i=0; i<5; i++)
        {
            int num_val = pow(2, i);

            SDirection dir = static_cast<SDirection>(num_val);
            for(int j=0; j<nbFrames[i]; j++)
            {
                std::string frpath = getFramePath(dir, j);
                std::ifstream in_img (frpath.c_str(), std::ofstream::binary);
                in_img.seekg(0, in_img.end);
                int length = in_img.tellg();

                in_img.seekg(0, in_img.beg);

                char * buffer = new char[length];

                in_img.read(buffer, length);

                in_img.close();

                DirectionSpriteImageMarker marker = DirectionSpriteImageMarker();
                marker.direction = dir;
                marker.length = length;

                out.write(reinterpret_cast<char*>(&marker), sizeof(DirectionSpriteImageMarker));

                out.write(buffer, length);

                delete buffer;
            }
        }

        out.close();
	}

	void DirectionSpriteFileCreator::detectDimension(void)
	{
		Surface *surface = 0;

		for(int i=0; i<5; i++)
		{
			if(nbFrames[i] != 0)
			{
				switch(i)
				{
					case 0:
						surface = new Surface(frames_pathUp[0].c_str());
						break;
					case 1:
						surface = new Surface(frames_pathDown[0].c_str());
						break;
					case 2:
						surface = new Surface(frames_pathLeft[0].c_str());
						break;
					case 3:
						surface = new Surface(frames_pathRight[0].c_str());
						break;
                    case 4:
                        surface = new Surface(frames_pathIdle[0].c_str());
				}
			}
		}

		if(surface != 0)
		{
			width = surface->getWidth();
			height = surface->getHeight();
			delete surface;
		}
	}

}



