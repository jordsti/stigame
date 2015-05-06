#ifndef CAPTIONSUPPORT_H
#define CAPTIONSUPPORT_H
#include "FontSupport.h"
#include "StringRenderer.h"
namespace StiGame
{

namespace Gui
{

class CaptionSupport :
        public FontSupport
{
public:
    CaptionSupport();
    virtual ~CaptionSupport();

    virtual std::string getCaption(void);
    virtual void setCaption(std::string m_caption);
    virtual void setFont(Font *m_font);
protected:
    StringRenderer stringRenderer;
};


}

}

#endif // CAPTIONSUPPORT_H
