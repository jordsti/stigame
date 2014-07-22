#ifndef MOUSEACTIONMAP_H
#define MOUSEACTIONMAP_H

#include "Rectangle.h"
#include "ActionMap.h"

namespace StiGame
{
	/// \class MouseActionMap
	/// \brief Mapping of a mouse triggered action
	class MouseActionMap :
		public ActionMap
	{
		public:
			/// \brief Create a new Mouse Action Map
			MouseActionMap(void);
			/// \brief Create a new Mouse Action Map
			/// \param m_name Action Name
			MouseActionMap(std::string m_name);

			MouseActionMap(std::string m_name, Uint8 m_button);

			/// \brief Destructor
			virtual ~MouseActionMap(void);
			/// \brief Get string value of the bind
			/// \return String value
			std::string toString(void);
			/// \brief Parse String to get bind
			/// \param str String value
			void fromString(std::string str);
			/// \brief Get Mouse button
			/// \return Mouse button
			Uint8 getButton(void);
			/// \brief Set the mouse button
			/// \param m_button Mouse Button
			void setButton(Uint8 m_button);
			/// \brief Get Mouse Button String value
			/// \param m_button Mouse Button
			/// \return String value
			static std::string GetStringValue(Uint8 m_button);
			///  \brief Parse a string to get Mouse Button
			///  \param m_str String Value
			///  \return Mouse button
			static Uint8 GetIntValue(std::string m_str);

			bool inputEquals(InputType it, int input);
            bool inputMouseEquals(MouseButtonEventArgs *mbEvt);

			void setX(int r_x);
			void setY(int r_y);
			void setWidth(int r_w);
			void setHeight(int r_h);

			void setRect(int r_x, int r_y, int r_w, int r_h);

			void setPositionChecked(bool m_positionChecked);

			bool isPositionChecked(void);

            int getIntValue(void);
			
			InputType getInputType(void);
			
		protected:
			/// \brief Mouse Button
			Uint8 button;
			Rectangle rect;
            bool positionChecked;
	};
}

#endif // MOUSEACTIONMAP_H
