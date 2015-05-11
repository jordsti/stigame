#include "TableCell.h"

namespace StiGame
{

namespace Gui
{

TableCell::TableCell()
{
    value = str_renderer.getText();
}

TableCell::~TableCell()
{

}


Surface* TableCell::getSurface(void)
{
	return str_renderer.getSurface();
}


StringRenderer* TableCell::getStringRenderer(void)
{
	return &str_renderer;
}

std::string TableCell::getValue(void)
{
	return value;
}

void TableCell::setValue(std::string m_value)
{
	value = m_value;
	str_renderer.setText(value);
}


}

}
