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

            /// \brief Set X Position
            /// \param r_x X (px)
			void setX(int r_x);
            /// \brief Set Y Position
            /// \param r_y Y (px)
			void setY(int r_y);
            /// \brief Set Width
            /// \param r_w Width (px)
			void setWidth(int r_w);
            /// \brief Set Height
            /// \param r_h Height (px)
			void setHeight(int r_h);
            /// \brief Set the rectangle attributes
            /// \param r_x X (px)
            /// \param r_y Y (px)
            /// \param r_w Width (px)
            /// \param r_h Height (px)
			void setRect(int r_x, int r_y, int r_w, int r_h);
            /// \brief Set Position Checked
            /// \param m_positionChecked Position Checked
			void setPositionChecked(bool m_positionChecked);
            /// \brief Is Position Checked
            /// \return checked or not
			bool isPositionChecked(void);

            int getIntValue(void);
			
			InputType getInputType(void);
			
		protected:
			/// \brief Mouse Button
			Uint8 button;
            /// \brief Position rectangle
			Rectangle rect;
            /// \brief Position Check
            bool positionChecked;
	};
}

#endif // MOUSEACTIONMAP_H
