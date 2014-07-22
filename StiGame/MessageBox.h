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


class MessageBox
{
public:
	MessageBox();
	MessageBox(MessageBoxType m_type, std::string m_title, std::string m_message);
	virtual ~MessageBox();
	
	void show(void);
	
	int getButtonId(void);
	MessageBoxType getType(void);
	std::string getTitle(void);
	std::string getMessage(void);
	SDL_Window* getWindow(void);
	
	void setTitle(std::string m_title);
	void setMessage(std::string m_message);
	void setType(MessageBoxType m_type);
	void setWindow(SDL_Window *m_window);
	
protected:
	std::string title;
	std::string message;
	int buttonId;
	SDL_Window *window;
	MessageBoxType type;
};

}

}


#endif