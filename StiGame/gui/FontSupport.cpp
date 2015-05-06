#include "FontSupport.h"
#include "Runtime.h"
namespace StiGame
{

namespace Gui
{

FontSupport::FontSupport()
{
    font = StiGame::Gui::Runtime::getInstance()->getStyle()->getNormalFont();
}

FontSupport::~FontSupport()
{

}

void FontSupport::setFont(Font *m_font)
{
    font = m_font;
}

Font* FontSupport::getFont(void)
{
    return font;
}

}

}
