#ifndef TEXTLOGGER_H
#define TEXTLOGGER_H

#include <string>

namespace StiGame
{

/// \class TextLogger
/// \brief To handle log file and console output
class TextLogger
{
    public:
		/// \brief Create a new TextLogger with specified path
		/// \param m_filepath File path
        TextLogger(const char* m_filepath);
		
		/// \brief Publish a message
		/// \param message Message
        void publish(std::string message);
		
		/// \brief TextLogger Destructor
        virtual ~TextLogger();
		
		/// \brief If the message should be publish to std::cout too
		/// \param m_consoleout Console Out
        void setConsoleOut(bool m_consoleout);
    protected:
	
		/// \brief Console output
        bool consoleout;
		/// \brief Log file path
        const char* filepath;

    private:
};

}

#endif // TEXTLOGGER_H
