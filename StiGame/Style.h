#pragma once
#include "Color.h"
#include "Font.h"

namespace StiGame
{

namespace Gui
{
/// \class Style
/// \brief Default Color for Gui Element
class Style
{
protected:
	/// \brief Foreground Color
	Color foreground;
	/// \brief Background Color
	Color background;
	/// \brief Highlight Foreground Color
	Color highlightForeground;
	/// \brief Highlight Background Color
	Color highlightBackground;
	/// \brief Drop List Arrow Image
	Surface *dropListArrow;
	/// \brief Up Arrow Image
	Surface *upArrow;
	/// \brief Down Arrow Image
	Surface *downArrow;
	/// \brief Check Box Image
	Surface *checkbox;
	/// \brief Checked Check Box Image
	Surface *checkboxChecked;
	/// \brief Radio Button Image
	Surface *radio;
	/// \brief Checked Radio Button Image
	Surface *radioChecked;

	Surface *buttonLeft;

	Surface *buttonRight;

	Surface *buttonBackground;

	Surface *buttonHighlightLeft;

	Surface *buttonHighlightRight;

	Surface *buttonHighlightBackground;

	/// \brief Normal Font
	Font *normalFont;

	Font *bigFont;
public:
	/// \brief Create a new GuiStyle
	Style(void);
	/// \brief Destructor
	~Style(void);
	/// \brief Get Foreground Pointer
	Color *getForeground(void);
	/// \brief Get Background Pointer
	Color *getBackground(void);
	/// \brief Get Highlight Background Pointer
	Color *getHighlightBackground(void);
	/// \brief Get Highlight Foreground Pointer
	Color *getHighlightForeground(void);
	/// \brief Get Up Arrow Image Pointer
	Surface *getUpArrow(void);
	/// \brief Get Down Arrow Image Pointer
	Surface *getDownArrow(void);
	/// \brief Get Drop List Arrow Image Pointer
	Surface *getDropListArrow(void);
	/// \brief Get Checkbox Image Pointer
	Surface *getCheckbox(void);
	/// \brief Get Checked Checkbox Image Pointer
	Surface *getCheckboxChecked(void);
	/// \brief Get Radio Button Image Pointer
	Surface *getRadio(void);
	/// \brief Get Check Radio Button Pointer
	Surface *getRadioChecked(void);
	/// \brief Get Normal Font Pointer

	Surface *getButtonLeft(void);

	Surface *getButtonRight(void);

	Surface *getButtonBackground(void);

    Surface *getHighlightButtonLeft(void);

	Surface *getHighlightButtonRight(void);

	Surface *getHighlightButtonBackground(void);

	Font *getNormalFont(void);

	Font *getBigFont(void);
	/// \brief Unload Ressources
	void unload(void);
};

}

}

