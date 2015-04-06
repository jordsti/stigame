#ifndef ENTRY_H
#define ENTRY_H
#include <string>

namespace StiGame
{

namespace FS
{

enum EntryType  {
    ET_File,
    ET_Directory
};

/// \class Entry
/// \brief Filesystem Element, files and directories are entries
class Entry
{
public:
    /// \brief Get the entry name
    std::string getName(void);
    /// \brief Get the parent path
    std::string getParent(void);
    /// \brief Get full path
    std::string getPath(void);
    /// \brief Get the entry type
    virtual EntryType type(void) = 0;
    /// \brief Is the entry endswith (useful for extension check)
    /// \param m_suffix Entry name suffix
    bool endsWith(std::string m_suffix);
    /// \brief Get the entry name with the file extension stripped
    std::string getNameWithoutExtension(void);
    /// \brief Destructor
    virtual ~Entry();

protected:
    /// \brief Constructor
    Entry();
    /// \brief Entry name
    std::string name;
    /// \brief Parent
    std::string parent;
};

}

}

#endif // ENTRY_H
