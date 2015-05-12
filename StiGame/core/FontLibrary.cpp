#include "FontLibrary.h"
#include "GamePath.h"
namespace StiGame
{

FontLibrary::FontLibrary()
{
    fontsFolder = GamePath::getPath(AssetRoot);
}

FontLibrary::FontLibrary(std::string m_fontsFolder)
{
    fontsFolder = m_fontsFolder;
}

FontLibrary::~FontLibrary()
{
    unload();
}

void FontLibrary::loadFont(std::string m_name, std::string m_path, int m_size)
{
    std::string filepath = GamePath::combine(fontsFolder, m_path);

    Font *font = new Font(filepath.c_str(), m_size);

    fonts.insert(std::make_pair(m_name, font));
}

Font* FontLibrary::getFont(std::string m_name)
{
    return fonts[m_name];
}

unsigned int FontLibrary::fontsCount(void)
{
    return fonts.size();
}

void FontLibrary::unload(void)
{
    //clear all fonts!
    auto fit(fonts.begin()), fend(fonts.end());
    for(;fit!=fend;++fit)
    {
        delete fit->second;
    }
}

}
