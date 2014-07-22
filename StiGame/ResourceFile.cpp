#include "ResourceFile.h"

#include <iostream>
#include <fstream>
#include <cstring>

#include "SDL_image.h"

namespace StiGame
{

const std::string ResourceFile::FILE_EXTENSION = ".res";

ResourceFile::ResourceFile()
{

}

ResourceFile::~ResourceFile()
{

}

void ResourceFile::addResource(std::string r_name, std::string r_path)
{
	resourcesPath.insert(std::make_pair(r_name, r_path));
}


Surface* ResourceFile::getSurface(std::string r_name)
{
	resources[r_name];
}

void ResourceFile::save(std::string destination)
{
	std::ofstream of (destination.c_str(), std::ofstream::binary);

	std::map<std::string, std::string>::iterator lit(resourcesPath.begin()), lend(resourcesPath.end());

	for(;lit!=lend;++lit)
	{
		ResourceMarker marker = ResourceMarker();

		std::ifstream img (lit->second.c_str(), std::ifstream::binary);

		img.seekg(0, img.end);
		int length = img.tellg();

		img.seekg(0, img.beg);

		char * buffer = new char[length];

		img.read(buffer, length);

		img.close();

		marker.length = length;
		marker.name[lit->first.size()] = 0;
		memcpy(marker.name, lit->first.c_str(), lit->first.size());

		of.write(reinterpret_cast<char*>(&marker), sizeof(ResourceMarker));

		of.write(buffer, length);

		delete buffer;
	}

	of.close();
}

void ResourceFile::load(std::string source)
{
	std::ifstream is(source.c_str(), std::ifstream::binary);
	ResourceMarker marker = ResourceMarker();

	while(!is.eof())
	{
		is.read( (char*) &marker, sizeof(ResourceMarker) );
		int rlength = marker.length;
		std::string rname = marker.name;

		char * buffer = new char[rlength];

		is.read(buffer, rlength);

		SDL_RWops *rw = SDL_RWFromMem(buffer, rlength);

		SDL_Surface *sdlSurface = IMG_Load_RW(rw, 1);

		Surface *surface = new Surface(sdlSurface);
		surface->setReleaseSurface(true);
		std::cout << IMG_GetError() << std::endl;

		//some error handling to do here

		delete buffer;

		resources.insert(std::make_pair(rname, surface));
	}

	is.close();
}

}