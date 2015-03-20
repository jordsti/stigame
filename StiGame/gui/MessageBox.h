#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include "SDL.h"
#include <string>

namespace StiGame
{

namespace Gui
{

enum MessageBoxType {
	MBT_ERROR,
	MBT_WARNING,
	MBT_INFORMATION
};

/// \class MessageBox
/// \brief Class that draw a Message Box [WIP]
class MessageBox
{
public:
	/// \brief Default Message Box Constructor
	MessageBox();
	/// \brief Constructor
	/// \param m_type Message Box Type
	/// \param m_title Title
	/// \param m_message Message
	MessageBox(MessageBoxType m_type, std::string m_title, std::string m_message);
	/// \brief Destructor
	virtual ~MessageBox();
	/// \brief Show the message box
	void show(void);
	/// \brief Get Button Id
	int getButtonId(void);
	/// \brief Get Message Box Type
	MessageBoxType getType(void);
	/// \brief Get Message Box Title
	std::string getTitle(void);
	/// \brief Get Message
	std::string getMessage(void);
	/// \brief Get SDL Window related to this message box
	SDL_Window* getWindow(void);
	/// \brief Set Message Box Title
	/// \param m_title New Title
	void setTitle(std::string m_title);
	/// \brief Set Message Text
	/// \param m_message New Message Text
	void setMessage(std::string m_message);
	/// \brief Set Message Box Type
	/// \param m_type New Message Box Type
	void setType(MessageBoxType m_type);
	/// \brief Set the Message Box Window
	/// \param m_window SDL_Window
	void setWindow(SDL_Window *m_window);
	
protected:
	/// \brief Message Box Title
	std::string title;
	/// \brief Message Text
	std::string message;
	/// \brief Button Id
	int buttonId;
	/// \brief SDL_Window
	SDL_Window *window;
	/// \brief Message Box Type
	MessageBoxType type;
};

}

}


#endif