#include "ProgressBar.h"
#include "PRect.h"

namespace StiGame
{

namespace Gui
{

const int ProgressBar::DEFAULT_HEIGHT = 20;
const int ProgressBar::DEFAULT_WIDTH = 100;
Color* ProgressBar::DEFAULT_BAR_COLOR = new Color(0, 0, 240);

ProgressBar::ProgressBar()
    : Item("ProgressBar")
{
	current = 0;
	max = 1;
	drawBorder = true;
	barColor = DEFAULT_BAR_COLOR;
	height = DEFAULT_HEIGHT;
	width = DEFAULT_WIDTH;
}

ProgressBar::~ProgressBar()
{

}

Surface* ProgressBar::render(void)
{
	Surface *buffer = new Surface(width, height);
	buffer->fill(background);


	int x_current = (current * width) / max;

	PRect rect = PRect();
	rect.setX(0);
	rect.setY(0);
	rect.setHeight(height);
	rect.setWidth(x_current);

	rect.fill(buffer->getSDLSurface(), barColor);


	if(drawBorder)
	{
		rect.setWidth(width);
		rect.draw(buffer->getSDLSurface(), foreground);
	}

	return buffer;
}

Color* ProgressBar::getBarColor(void)
{
	return barColor;
}

void ProgressBar::setBarColor(Color *m_barColor)
{
	barColor = m_barColor;
}

bool ProgressBar::getDrawBorder(void)
{
	return drawBorder;
}

void ProgressBar::setDrawBorder(bool m_drawBorder)
{
	drawBorder = m_drawBorder;
}

int ProgressBar::getMax(void)
{
	return max;
}

void ProgressBar::setMax(int m_max)
{
	max = m_max;
}

int ProgressBar::getCurrent(void)
{
	return current;
}

void ProgressBar::setCurrent(int m_current)
{
	current = m_current;
}

void ProgressBar::increment(int step)
{
    if(current < max)
    {
        current += step;
    }

    if(current > max)
    {
        current = max;
    }
}

}

}
