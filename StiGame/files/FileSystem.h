#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include "Directory.h"
#include "File.h"
#include <vector>
//this will be moved into StiGame in not that long

namespace StiGame
{

namespace FS
{

class FileSystem
{
public:
    /// \brief List the content of a directory
    /// \param m_path Path to list
    /// \return Vector of Entries
    static std::vector<Entry*> ListDirectory(std::string m_path);
    /// \brief Create a new folder
    /// \param d_path Folder Path
    static void CreateDir(std::string d_path);
private:
    FileSystem();
};

}

}

#endif // FILESYSTEM_H
