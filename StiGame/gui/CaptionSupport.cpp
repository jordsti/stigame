#include "CaptionSupport.h"
namespace StiGame
{

namespace Gui
{

CaptionSupport::CaptionSupport() :
    FontSupport()
{
    stringRenderer.setFont(font);
    stringRenderer.setText("");
}

CaptionSupport::~CaptionSupport()
{

}

std::string CaptionSupport::getCaption(void)
{
    return stringRenderer.getText();
}

void CaptionSupport::setCaption(std::string m_caption)
{
    stringRenderer.setText(m_caption);
}

void CaptionSupport::setFont(Font *m_font)
{
    FontSupport::setFont(m_font);
    stringRenderer.setFont(m_font);
}

}

}
