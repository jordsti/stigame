#ifndef COMPUTER_H
#define COMPUTER_H

#include "SDL.h"
#include <string>
#include <list>

namespace StiGame
{

class Computer
{
public:
	static int SystemRAM(void);
	static std::string CurrentVideoDriver(void);
	static std::string CurrentAudioDriver(void);
	static std::list<std::string> GetAudioDrivers(void);
	static std::list<std::string> GetVideoDrivers(void);
	static std::string GetPlatform(void);
	static int GetCPUCacheSize(void);
	static int GetCPUCount(void);
protected:
	Computer();
	virtual ~Computer();


};

}

#endif