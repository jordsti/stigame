
#include "Runtime.h"

namespace StiGame
{

namespace Gui
{

Runtime::Runtime(void)
{
	style = new Style();
}


Runtime::~Runtime(void)
{
}

Gui::Style *Runtime::getStyle(void)
{
	return style;
}



Runtime *Runtime::_instance = NULL;

}

}
