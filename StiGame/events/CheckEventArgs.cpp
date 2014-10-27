#include "CheckEventArgs.h"
namespace StiGame
{
CheckEventArgs::CheckEventArgs(bool m_checked, std::string m_caption) : EventArgs()
{
    //ctor
    checked = m_checked;
    caption = m_caption;
}

bool CheckEventArgs::isChecked(void)
{
    return checked;
}

std::string CheckEventArgs::getCaption(void)
{
    return caption;
}

CheckEventArgs::~CheckEventArgs()
{
    //dtor
}
}
