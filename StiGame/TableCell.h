#ifndef TABLECELL_H
#define TABLECELL_H

#include <string>
#include "StringRenderer.h"

namespace StiGame
{

namespace Gui
{

class TableCell
{
public:
	TableCell();
	virtual ~TableCell();
	std::string getValue(void);
	void setValue(std::string m_value);
	StringRenderer* getStringRenderer(void);
	Surface* getSurface(void);
protected:
	std::string value;
	StringRenderer str_renderer;
};


}


}

#endif