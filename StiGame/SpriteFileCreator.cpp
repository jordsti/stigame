
#include "SpriteFileCreator.h"
#include "SpriteFile.h"

#include "Surface.h"

#include <iostream>
#include <fstream>

#include <cstring>

namespace StiGame
{
SpriteFileCreator::SpriteFileCreator(void)
{
	nbFrames = 0;
	name = "";
	width = 0;
	height = 0;
}

SpriteFileCreator::~SpriteFileCreator(void)
{

}

void SpriteFileCreator::addFrame(std::string path)
{
	nbFrames++;
	frames_path.push_back(path);
}

int SpriteFileCreator::getWidth(void)
{
	return width;
}

int SpriteFileCreator::getHeight(void)
{
	return height;
}

void SpriteFileCreator::setWidth(int m_width)
{
	width = m_width;
}

void SpriteFileCreator::setHeight(int m_height)
{
	height = m_height;
}

std::string SpriteFileCreator::getName(void)
{
	return name;
}

void SpriteFileCreator::setName(std::string m_name)
{
	name = m_name;
}

int SpriteFileCreator::getNbFrames(void)
{
	return nbFrames;
}

void SpriteFileCreator::save(std::string destination)
{
	//do the file here !!
	//we need to generate header first

	SpriteFileHeader header = SpriteFileHeader();

	header.spriteName[name.size()] = 0;
	memcpy(header.spriteName, name.c_str(), name.size());

	header.nbFrames = nbFrames;

	//if dimension is 0, need to take first image dim
	if(width == 0 && height == 0)
	{
		detectDimension();
	}

	header.width = width;
	header.height = height;

    std::ofstream out(destination.c_str(), std::ofstream::binary);

    out.write(reinterpret_cast<char*>(&header), sizeof(SpriteFileHeader));

    std::vector<std::string>::iterator lit(frames_path.begin()), lend(frames_path.end());

    for(;lit!=lend;++lit)
    {
        std::ifstream in_img (lit->c_str(), std::ofstream::binary);
        in_img.seekg(0, in_img.end);
        int length = in_img.tellg();

        in_img.seekg(0, in_img.beg);

        char * buffer = new char[length];

        in_img.read(buffer, length);

        in_img.close();

        SpriteImageMarker marker = SpriteImageMarker();

        marker.length = length;

        out.write(reinterpret_cast<char*>(&marker), sizeof(SpriteImageMarker));

        out.write(buffer, length);

        delete buffer;
    }

    out.close();
}

void SpriteFileCreator::detectDimension(void)
{
	if(nbFrames != 0)
	{
		//taking first image
		Surface sur = Surface(frames_path[0].c_str());
		width = sur.getWidth();
		height = sur.getHeight();
	}
}

}
