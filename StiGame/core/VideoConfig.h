#ifndef VIDEOCONFIG_H
#define VIDEOCONFIG_H

#include "VarFile.h"

namespace StiGame
{

class VideoConfig :
	public VarFile
{
public:
	VideoConfig();
	VideoConfig(const char* m_filepath);
	virtual ~VideoConfig();
	void read(void);
	void write(void);
	bool getBoolValue(std::string key);
	
	int getWidth(void);
	int getHeight(void);
	bool isFullscreen(void);

    void setWidth(int m_width);
    void setHeight(int m_height);
    void setFullscreen(bool m_fullscreen);
	
protected:
	int width;
	int height;
	bool fullscreen;
};

}

#endif
