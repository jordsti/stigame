#ifndef VARFILE_H
#define VARFILE_H

#include <string>
#include <list>
#include <map>

namespace StiGame
{
/// \class VarFile
/// \brief Class that parse a text file for variable
class VarFile
{
    public:
        VarFile();

		/// \brief Create a new VarFile with specified path
        VarFile(const char* m_filepath);
		/// \brief Destructor
        virtual ~VarFile();
		/// \brief Read the file
        virtual void read(void);
		/// \brief Write to the file
        virtual void write(void);
		/// \brief Get the value of this specified variable
		/// \param varname Variable Name
		/// \return Variable value
        std::string getValue(std::string varname);
		/// \brief Put a new variable into VarFile
		/// \param varname Variable name
		/// \param value Variable value
        void put(std::string varname, std::string value);
		/// \brief Is the variable exists in VarFile
		/// \param varname Variable Name
		/// \return Exists or not
        bool isVarExists(std::string varname);
		
		std::list<std::string> getKeys(void);

        static int ParseInt(std::string i_str);
		static bool ParseBool(std::string b_str);
		static std::string BoolToString(bool b_val);
    protected:
		/// \brief File path
        const char* filepath;
		/// \brief Parse a line
		/// \param line Line
        void parseLine(std::string line);
		/// \brief Variable map
        std::map<std::string, std::string> variables;
    private:
};

}

#endif // VARFILE_H
