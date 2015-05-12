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
    if(value != m_value)
    {
        CellValueChangedEventArgs args (this, value);
        value = m_value;
        str_renderer.setText(value);

        publish(this, &args);
    }

}


Color* TableCell::getForeground(void)
{
    return str_renderer.getColor();
}

void TableCell::setForeground(Color *m_foreground)
{
    str_renderer.setColor(m_foreground);
}

Font* TableCell::getFont(void)
{
    return str_renderer.getFont();
}

void TableCell::setFont(Font *m_font)
{
    str_renderer.setFont(m_font);
}

int TableCell::getWidth(void)
{
    return str_renderer.getWidth();
}

int TableCell::getHeight(void)
{
    return str_renderer.getHeight();
}


}

}
