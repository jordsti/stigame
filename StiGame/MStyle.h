#ifndef MSTYLE_H
#define MSTYLE_H

#include "Style.h"

namespace StiGame
{

namespace Gui
{

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
	/// \brief Normal Font
	Font *normalFont;

class MStyle :
    public Style
{
    public:
        MStyle();
        virtual ~MStyle();
        void setForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setHighlightForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setHighlightBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        void setDropListArrow(Surface *surface);
        void setUpArrow(Surface *surface);
        void setDownArrow(Surface *surface);
        void setCheckBox(Surface *surface);
        void setCheckBoxChecked(Surface *surface);
        void setRadio(Surface *surface);
        void setRadioChecked(Surface *surface);
        void setNormalFont(Font *font);
    protected:
    private:
};

}

}

#endif // MSTYLE_H
