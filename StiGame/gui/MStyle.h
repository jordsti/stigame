#ifndef MSTYLE_H
#define MSTYLE_H

#include "Style.h"

namespace StiGame
{

namespace Gui
{
/// \class MStyle
/// \brief Mutable Style
class MStyle :
    public Style
{
    public:
	/// \brief Constructor
        MStyle();
	/// \brief Destructor
        virtual ~MStyle();
	/// \brief Set the foreground color
	/// \param r Red
	/// \param g Green
	/// \param b Blue
	/// \param a Alpha
        void setForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	/// \brief Set the background color
	/// \param r Red
	/// \param g Green
	/// \param b Blue
	/// \param a Alpha
        void setBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	/// \brief Set the highlight foreground color
	/// \param r Red
	/// \param g Green
	/// \param b Blue
	/// \param a Alpha
        void setHighlightForeground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	/// \brief Set the highlight background color
	/// \param r Red
	/// \param g Green
	/// \param b Blue
	/// \param a Alpha
        void setHighlightBackground(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	/// \brief Set Droplist Arrow Image
	/// \param surface Pointer to the image
        void setDropListArrow(Surface *surface);
	/// \brief Set Up Arrow Image
	/// \param surface Pointer to the image
        void setUpArrow(Surface *surface);
	/// \brief Set Down Arrow Image
	/// \param surface Pointer to the image
        void setDownArrow(Surface *surface);
	/// \brief Set the Checkbox Image
	/// \param surface Pointer to the image
        void setCheckBox(Surface *surface);
	/// \brief Set the Checkbox checked Image
	/// \param surface Pointer to the image
        void setCheckBoxChecked(Surface *surface);
	/// \brief Set RadioButton Image
	/// \param surface Pointer to the image
        void setRadio(Surface *surface);
	/// \brief Set RadioButton checked Image
	/// \param surface Pointer to the image
        void setRadioChecked(Surface *surface);
	/// \brief Set the Decorated Button Left Image
	/// \param surface Pointer to the image
        void setButtonLeft(Surface *surface);
	/// \brief Set the Decorated Button Right Image
	/// \param surface Pointer to the image
        void setButtonRight(Surface *surface);
	/// \brief Set the Decorated Button Background Image
	/// \param surface Pointer to the image
        void setButtonBackground(Surface *surface);
	/// \brief Set the Highlight Decorated Button Left Image
	/// \param surface Pointer to the image
        void setHighlightButtonLeft(Surface *surface);
	/// \brief Set the Highlight Decorated Button Right Image
	/// \param surface Pointer to the image
        void setHighlightButtonRight(Surface *surface);
	/// \brief Set the Highlight Decorated Button Background Image
	/// \param surface Pointer to the image
        void setHighlightButtonBackground(Surface *surface);
	/// \brief Set Normal Font
	/// \param font Font pointer
        void setNormalFont(Font *font);
	/// \brief Set Big Font
	/// \param font Font pointer
        void setBigFont(Font *font);
    protected:
    private:
};

}

}

#endif // MSTYLE_H
