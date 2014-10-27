#ifndef KEYACTIONMAP_H
#define KEYACTIONMAP_H

#include "ActionMap.h"

namespace StiGame
{
	/// \class KeyActionMap
	/// \brief Mapping of a keyboard triggered action
	class KeyActionMap :
		public ActionMap
	{
		public:
			/// \brief Create a new Key Action Map
			KeyActionMap(void);
			/// \brief Create a new Key Action Map
			/// \param m_name Action Name
			KeyActionMap(std::string m_name);

			KeyActionMap(std::string m_name, SDL_Keycode m_keycode);
			/// \brief Destructor
			virtual ~KeyActionMap(void);
			/// \brief Get string value of the bind
			/// \return String value
			std::string toString(void);
			/// \brief Parse String to get bind
			/// \param str String value
			void fromString(std::string str);
			/// \brief Get SDL Key Code
			/// \return Key Code
			SDL_Keycode getKeycode(void);
			/// \brief Set SDL Key Code
			/// \param m_keycode Key Code
			void setKeycode(SDL_Keycode m_keycode);

			bool inputEquals(InputType it, int input);

			int getIntValue(void);
			
			InputType getInputType(void);
			
		protected:
			/// \brief Key Code
			SDL_Keycode keycode;
	};
}

#endif // KEYACTIONMAP_H
