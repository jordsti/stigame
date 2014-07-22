#ifndef ACTIONMAP_H
#define ACTIONMAP_H

#include "SDL.h"
#include <string>
#include "MouseButtonEventArgs.h"

namespace StiGame
{
	enum InputType { IT_KEYBOARD, IT_MOUSE, IT_JOYSTICK, IT_DEFAULT, IT_COMP };

	/// \class ActionMap
	/// \brief Abstract Class to inherit to provide binding mapping support
	class ActionMap
	{
		public:
			/// \brief Constructor
			ActionMap(void);
			/// \brief Destructor
			virtual ~ActionMap(void);
			/// \brief Get Action Name
			/// \return Action Name
			std::string getName(void);
			/// \brief Set Action Name
			/// \param m_name Action Name
			void setName(std::string m_name);
			/// \brief Fill the object from a String
			/// \param str String Value
			virtual void fromString(std::string str);
			/// \brief To String Value
			/// \return String Value
			virtual std::string toString(void);
			/// \brief Get the Input Type
			/// \return Input Type
			virtual InputType getInputType(void);
			/// \brief Test if this map contains this type of Input
			/// \param it InputType
			/// \return Contains it or not
			virtual bool isInput(InputType it);
			/// \brief Create an Action Map from a String
			/// \param a_name Action Name
			/// \param action Action value
			/// \return Action Map
			static ActionMap* FromString(std::string a_name, std::string action);
			/// \brief Test a specific Input
			/// \param it Input Type
			/// \param input Int value
			/// \return Contains it or not
			virtual bool inputEquals(InputType it, int input) = 0;
			/// \brief Test a Mouse Event
			/// \param mbEvt Mouse Button Event
			/// \return Input is equals or not
			virtual bool inputMouseEquals(MouseButtonEventArgs *mbEvt);
			/// \brief Need a position check
			/// \return Position Check
			virtual bool isPositionChecked(void);
			/// \brief Get the Int Value
			/// \return Int Value
			virtual int getIntValue(void);
		protected:
			/// \brief Input Type
		    InputType inputType;
			/// \brief Action Name
			std::string name;
	};


}

#endif // ACTIONMAP_H
