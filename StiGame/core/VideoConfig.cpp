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
    width = getInt("width");
    height = getInt("height");
    fullscreen = getBool("fullscreen");
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

void VideoConfig::setWidth(int m_width)
{
    width = m_width;
}

void VideoConfig::setHeight(int m_height)
{
    height = m_height;
}

void VideoConfig::setFullscreen(bool m_fullscreen)
{
    fullscreen = m_fullscreen;
}

bool VideoConfig::getBoolValue(std::string key)
{
	std::string val = getValue(key);
	return ParseBool(val);
}


}
