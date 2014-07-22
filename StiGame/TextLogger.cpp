#include "TextLogger.h"
#include <iostream>
#include <fstream>
#include <ctime>

namespace StiGame
{

TextLogger::TextLogger(const char* m_filepath)
{
    //ctor
    consoleout = false;
    filepath = m_filepath;
}

void TextLogger::publish(std::string message)
{
    std::ofstream outfile (filepath, std::ios::out | std::ios::app);

    time_t now = std::time(0);
    char* dt = std::ctime(&now);

    //show the timeinfo too ; todo
    outfile << dt << " | " << message << std::endl;

    outfile.close();

    if(consoleout)
    {
        std::cout << message << std::endl;
    }
}

void TextLogger::setConsoleOut(bool m_consoleout)
{
    consoleout = m_consoleout;
}


TextLogger::~TextLogger()
{
    //dtor
}

}
