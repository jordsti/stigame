#ifndef VALUEOBJECT_H
#define VALUEOBJECT_H

#include <string>
#include <map>
#include <vector>
namespace StiGame {

namespace Gui
{

/// \class ValueObject
/// \brief Class for Value contained into Items like List and ComboBox
class ValueObject
{
    public:
        /// \brief Constructor
        ValueObject();
        /// \brief Constructor
        /// New value object with specified param
        /// \param m_id Value Id
        /// \param m_text Value Text
        ValueObject(int m_id, std::string m_text);

        ValueObject(std::string m_text);

        /// \brief Destructor
        virtual ~ValueObject();
        /// \brief Get the value text
        /// \return value text
        std::string getText(void);
        /// \brief Get he value id
        /// \return value id
        int getId(void);

        std::vector<std::string> getFieldsName(void);

        void put(std::string m_name, std::string m_value);

        std::string get(std::string m_name);

    protected:
        /// \brief Value Id
        int id;
        /// \brief Value Text
        std::string text;
    private:
        static int _currentId;
        int incrementId(void);
        std::map<std::string, std::string> fields;
};

}

}

#endif // VALUEOBJECT_H
