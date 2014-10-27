#ifndef LOGGER_H
#define LOGGER_H

#include <string>

namespace StiGame
{

enum VerbosityLevel {
	VL_ERROR_FILE = 1,
	VL_CONSOLE_FILE = 2,
	VL_ERROR_OUT = 4,
	VL_CONSOLE_OUT = 8,
	
	VL_ERROR_ONLY = VL_ERROR_FILE + VL_ERROR_OUT,
	VL_CONSOLE_ONLY = VL_CONSOLE_FILE + VL_CONSOLE_OUT,
	
	VL_FILE_ONLY = VL_ERROR_FILE + VL_CONSOLE_FILE,
	
	VL_STD_OUT_ONLY = VL_ERROR_OUT + VL_CONSOLE_OUT,
	
	VL_ALL = VL_ERROR_FILE + 
			 VL_CONSOLE_FILE + 
			 VL_ERROR_OUT + 
			 VL_CONSOLE_OUT
};

class Logger
{
public:
	static int GetVerbosity(void);
	static void SetVerbosity(int level);
    static void Error(std::string message);
	static void Console(std::string message);
	
protected:
	const static std::string CONSOLE_OUT;
	const static std::string ERROR_OUT;
	static int Verbosity;

	static void Print(std::string message);
	static void AppendFile(std::string file, std::string message);
	
	Logger();
	virtual ~Logger();
};

}

#endif