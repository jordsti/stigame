#include "VideoConfig.h"
#include <string>
namespace StiGame
{
VideoConfig::VideoConfig()
{
	filepath = "";
}
VideoConfig::VideoConfig(const char* m_filepath) :
	VarFile(m_filepath)
{

}

VideoConfig::~VideoConfig()
{

}

void VideoConfig::read(void)
{
	VarFile::read();
	width = ParseInt(getValue("width"));
	height = ParseInt(getValue("height"));
	fullscreen = getBoolValue("fullscreen");
}

void VideoConfig::write(void)
{
	variables.clear();
	
	put("width", std::to_string(width));
	put("height", std::to_string(height));
	put("fullscreen", BoolToString(fullscreen));

	VarFile::write();
}

int VideoConfig::getWidth(void)
{
	return width;
}

int VideoConfig::getHeight(void)
{
	return height;
}

bool VideoConfig::isFullscreen(void)
{
	return fullscreen;
}

bool VideoConfig::getBoolValue(std::string key)
{
	std::string val = getValue(key);
	return ParseBool(val);
}


}