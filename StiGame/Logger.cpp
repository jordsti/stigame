#include "Logger.h"
#include <iostream>
#include <fstream>
#include <ctime>

namespace StiGame
{

const std::string Logger::CONSOLE_OUT = "console.log";
const std::string Logger::ERROR_OUT = "error.log";
int Logger::Verbosity = VL_ERROR_ONLY;

void Logger::Error(std::string message)
{
	if((Verbosity & VL_ERROR_OUT) == VL_ERROR_OUT)
	{
		Print("Error: " + message);
	}

	if((Verbosity & VL_ERROR_FILE) == VL_ERROR_FILE)
	{
		AppendFile(ERROR_OUT, message);
	}
}

void Logger::Console(std::string message)
{
	if((Verbosity & VL_CONSOLE_OUT) == VL_CONSOLE_OUT)
	{
		Print(message);
	}

	if((Verbosity & VL_CONSOLE_FILE) == VL_CONSOLE_FILE)
	{
		AppendFile(CONSOLE_OUT, message);
	}
}

void Logger::Print(std::string message)
{
	std::cout << message << std::endl;
}

void Logger::AppendFile(std::string file, std::string message)
{
	std::ofstream outfile (file.c_str(), std::ios::out | std::ios::app);

    time_t now = std::time(0);
    char* dt = std::ctime(&now);

    //show the timeinfo too ; todo
    outfile << dt << " : " << message << std::endl;

    outfile.close();
}

int Logger::GetVerbosity(void)
{
	return Verbosity;
}

void Logger::SetVerbosity(int level)
{
	Verbosity = level;
}

Logger::Logger() {}
Logger::~Logger() {}

}
