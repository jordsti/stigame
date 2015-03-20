#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include "Item.h"
#include "CheckEventThrower.h"
#include <string>


namespace StiGame
{

namespace Gui
{

class RadioGroup;

/// \class RadioButton
/// \brief Gui Radio Button
class RadioButton :
    public Item,
    public CheckEventThrower
{
    public:
	/// \brief Create a new Gui Radio Button
        RadioButton();
	/// \brief Destructor
        virtual ~RadioButton();
	/// \brief Render GuiItem
	/// \return Rendered Surface
        virtual Surface* render(void);
	/// \brief Is checked
	/// \return Checked or not
        bool isChecked(void);
	/// \brief Set Checked value
	/// \param m_checked New checked value
        void setChecked(bool m_checked);
	/// \brief Get Radio Button Caption
	/// \return String value
        std::string getCaption(void);
	/// \brief Set Radio Button Caption
	/// \param m_caption New Caption
        void setCaption(std::string m_caption);
	/// \brief On Click Event
	/// \param relp Relative Cursor Position
        void onClick(Point *relp);
	/// \brief Set the Radio Group of a Radio Button
	/// \param m_group Radio Group
        void setGroup(RadioGroup *m_group);
    protected:
	/// \brief Radio Group
        RadioGroup *group;
	/// \brief Caption
        std::string caption;
	/// \brief Checked
        bool checked;
	/// \brief Not Checked Image
        Surface *surfaceEmpty;
	/// \brief Checked Image
        Surface *surfaceChecked;
	/// \brief Caption Image Buffer
        Surface *stringBuffer;
	/// \brief Font
        Font *font;
	/// \brief Render Text Caption
        void renderCaption(void);
	/// \brief Caption offset (pixels)
        int captionOffset;
	/// \brief Default Caption Offset
        static const int DefaultCaptionOffset;
    private:
};

}

}

#endif // GUIRADIOBUTTON_H
