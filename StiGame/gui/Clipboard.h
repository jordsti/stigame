#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <string>

namespace StiGame
{

/// \class Clipboard
/// \brief This class offer static method to fetch and set the date stored into the clipboard
class Clipboard
{
public:
	Clipboard();
	virtual ~Clipboard();
	
	/// \brief Is the clipboard contain text
	static bool HasText(void);
	/// \brief Get the text contained into the clipboard
	/// \return Text value of the clipboard
	static std::string GetText(void);
	/// \brief Set the text value of the clipboard
	/// \param text Text value
	static void SetText(std::string text);

};


}

#endif