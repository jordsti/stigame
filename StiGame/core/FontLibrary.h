#ifndef FONTLIBRARY_H
#define FONTLIBRARY_H

#include <map>
#include "Font.h"

namespace StiGame
{

class FontLibrary
{
public:
    FontLibrary();
    FontLibrary(std::string m_fontsFolder);
    virtual ~FontLibrary();

    void loadFont(std::string m_name, std::string m_path, int m_size);

    Font* getFont(std::string m_name);

    unsigned int fontsCount(void);

protected:
    void unload(void);

private:
    std::string fontsFolder;
    std::map<std::string, Font*> fonts;
};

}

#endif // FONTLIBRARY_H
