#ifndef RESOURCEFILE_H
#define RESOURCEFILE_H

#include <string>
#include <map>

#include "Surface.h"

namespace StiGame
{
	const int RESOURCE_NAME_MAX = 64;

	struct ResourceMarker
	{
		char name[RESOURCE_NAME_MAX];
		int length;
	};

	class ResourceFile
	{
	public:
		const static std::string FILE_EXTENSION;
		ResourceFile();
		virtual ~ResourceFile();
		void addResource(std::string r_name, std::string r_path);
		Surface* getSurface(std::string r_name);
		void save(std::string destination);
		void load(std::string source);
	protected:
		std::map<std::string, Surface*> resources;
		std::map<std::string, std::string> resourcesPath;
	};

}

#endif