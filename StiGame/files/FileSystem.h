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
    static std::vector<Entry*> ListDirectory(std::string m_path);

private:
    FileSystem();
};

}

}

#endif // FILESYSTEM_H
