#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <string>

namespace StiGame
{

class Clipboard
{
public:
	Clipboard();
	virtual ~Clipboard();
	
	//static
	static bool HasText(void);
	static std::string GetText(void);
	static void SetText(std::string text);

};


}

#endif