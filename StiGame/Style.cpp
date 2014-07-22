#include <iostream>
#include "Style.h"

#include "GamePath.h"

namespace StiGame
{

namespace Gui
{

Style::Style(void)
{
	//foreground = Color(200, 250, 250);
	//background = Color(15, 15, 15);
    foreground = Color(25, 25, 25);
	background = Color(245, 245, 245);
	highlightForeground = Color(255, 255, 255);
	highlightBackground = Color(120, 120, 120);

	normalFont = new Font(GamePath::getFilepath(AssetRoot, "font.ttf").c_str(), 16);
	dropListArrow = new Surface(GamePath::getFilepath(AssetGui, "droplist_arrow.png").c_str());
	upArrow = new Surface(GamePath::getFilepath(AssetGui, "uparrow.png").c_str());
	downArrow = new Surface(GamePath::getFilepath(AssetGui, "downarrow.png").c_str());
	checkbox = new Surface(GamePath::getFilepath(AssetGui, "checkbox.png").c_str());
	checkboxChecked = new Surface(GamePath::getFilepath(AssetGui, "checkbox_checked.png").c_str());
	radio = new Surface(GamePath::getFilepath(AssetGui, "radio.png").c_str());
	radioChecked = new Surface(GamePath::getFilepath(AssetGui, "radio_true.png").c_str());
}

Surface *Style::getRadio(void)
{
    return radio;
}

Surface *Style::getRadioChecked(void)
{
    return radioChecked;
}

Surface *Style::getCheckbox(void)
{
    return checkbox;
}

Surface *Style::getCheckboxChecked(void)
{
    return checkboxChecked;
}

Surface *Style::getDropListArrow(void)
{
    return dropListArrow;
}

Color *Style::getBackground(void)
{
	return &background;
}

Color *Style::getForeground(void)
{
	return &foreground;
}

Color *Style::getHighlightBackground(void)
{
	return &highlightBackground;
}

Color *Style::getHighlightForeground(void)
{
	return &highlightForeground;
}

Font *Style::getNormalFont(void)
{
	return normalFont;
}

Surface *Style::getUpArrow(void)
{
    return upArrow;
}

Surface *Style::getDownArrow(void)
{
    return downArrow;
}

void Style::unload(void)
{
	delete normalFont;
}

Style::~Style(void)
{
}

}

}
