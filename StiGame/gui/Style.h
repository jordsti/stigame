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
	/// \brief Button Left Graphic
	Surface *buttonLeft;
	/// \brief Button Right Graphic
	Surface *buttonRight;
	/// \brief Button Background Graphic
	Surface *buttonBackground;
	/// \brief  Button Highlighted Left Graphic
	Surface *buttonHighlightLeft;
	/// \brief Button Highlighted Right Graphic
	Surface *buttonHighlightRight;
	/// \brief Button Highlighted Background Graphic
	Surface *buttonHighlightBackground;

    Surface *spinnerUpArrow;

    Surface *spinnerDownArrow;

	/// \brief Normal Font
	Font *normalFont;
	/// \brief Big Size Font
	Font *bigFont;
public:
	/// \brief Create a new GuiStyle
	Style(void);
	/// \brief Destructor
	virtual ~Style(void);
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
	/// \brief Get Button Left Graphic Pointer
	Surface *getButtonLeft(void);
	/// \brief Get Button Right Graphic Pointer
	Surface *getButtonRight(void);
	/// \brief Get Button Background Graphic Pointer
	Surface *getButtonBackground(void);
	/// \brief Get Button Highlighted Left Graphic Pointer
	Surface *getHighlightButtonLeft(void);
	/// \brief Get Button Highlighted Right Graphic Pointer
	Surface *getHighlightButtonRight(void);
	/// \brief Get Button Highlighted Background Graphic Pointer
	Surface *getHighlightButtonBackground(void);

    Surface *getSpinnerUpArrow(void);

    Surface *getSpinnerDownArrow(void);

	/// \brief Get Normal Font Pointer
	Font *getNormalFont(void);
	/// \brief Get the Big Font Pointer
	Font *getBigFont(void);
	/// \brief Unload Ressources
	void unload(void);
};

}

}

