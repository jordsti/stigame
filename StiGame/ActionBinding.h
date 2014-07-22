#ifndef ACTIONBINDING_H
#define ACTIONBINDING_H

#include "VarFile.h"
#include "ActionMap.h"

namespace StiGame {

/// \class ActionBinding
/// \brief Manage a Text file that contains Action Binding. Action Name associated to Key/Mouse Event
class ActionBinding :
    public VarFile
{
    public:
		/// \brief Default Filename
        static const std::string FILENAME;
        /// \brief Constructor of empty Action Binding
		ActionBinding();
		/// \brief Constructor of a existing file
		/// \param m_filepath Filepath
        ActionBinding(const char* m_filepath);
		/// \brief Read the file
        void read(void);
		/// \brief Write the file
        void write(void);
		/// \brief Add a binding
		/// \param bname Action Name
		/// \param amap Action Map
        void addBinding(std::string bname, ActionMap *amap);
		/// \brief Overwrite a binding
		/// \param bname Action Name
		/// \param nmap New Action Map
		void overwrite(std::string bname, ActionMap *nmap);
		/// \brief Get Action By Mouse Button
		/// \return Action Name
        std::string getActionByMouseButton(Uint8 button);
		/// \brief Get Action By Keycode
		/// \return Action Name
        std::string getActionByKeyCode(SDL_Keycode keycode);
		/// \brief Get Action Map by name
		/// \param bname Action Name
		/// \return Action Map
        ActionMap* getBinding(std::string bname);
		/// \brief Destructor
        virtual ~ActionBinding();
    protected:
		/// \brief Binding map
        std::map<std::string, ActionMap*> bindings;
    private:
};

}

#endif // ACTIONBINDING_H
