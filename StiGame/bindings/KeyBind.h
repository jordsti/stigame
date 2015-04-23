#ifndef KEYBIND_H
#define KEYBIND_H

#include "HighlightItem.h"
#include "KeyEventListener.h"
#include "KeyActionMap.h"
#include <string>

namespace StiGame {
/* Note(s)
* Add the support for a mouse capture !
*
*/

namespace Gui
{


/// \class KeyBind
/// \brief GuiItem to capture Key Pressed for a Key Bind
class KeyBind :
    public HighlightItem,
    public KeyEventListener
{
    public:
		/// \brief Create a new Gui Key Bind
        KeyBind();
		/// \brief Destructor
        virtual ~KeyBind();
		/// \brief Render the Gui Key Bind
		/// \return Rendered Gui Key Bind
        Surface *render(void);
		/// \brief On Click event
		/// \param relp Relative Mouse position on the Gui Item
        void onClick(Point *relp);
		/// \brief Event Handling
		/// \param src Key Event Thrower
		/// \param args Key Event Arguments
        void handleEvent(KeyEventThrower *src, KeyEventArgs *args);
		/// \brief Default Width
        static const int DefaultWidth;
		/// \brief Default Height
		static const int DefaultHeight;
		/// \brief Get SDL Keycode
		/// \return Key Code
        SDL_Keycode getKey(void);
		/// \brief Set SDL Keycode
		/// \param m_key Key Code
        void setKey(SDL_Keycode m_key);
        /// \brief Create the Key Action Map from this KeyBind
        /// \param a_name Action Name
        /// \return Key Action Map
		KeyActionMap* createKeyActionMap(std::string a_name);
        /// \brief Set the field of this Key Bind from a Key Action Map
        /// \param amap Key Action Map
		void fromActionMap(ActionMap *amap);
    protected:
		/// \brief Keycode String Buffer
        Surface *stringBuffer;
		/// \brief Font
        Font *font;
		/// \brief Key Code
        SDL_Keycode key;
		/// \brief Key String Value
        std::string keyCaption;
		/// \brief Render Caption
        void renderCaption(void);
		/// \brief Is Focused
        bool focus;
    private:
};

}

}
#endif // GUIKEYBIND_H
