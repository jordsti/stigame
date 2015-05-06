#ifndef FONTSUPPORT_H
#define FONTSUPPORT_H
#include "Font.h"
namespace StiGame
{

namespace Gui
{

class FontSupport
{
public:
    FontSupport();
    virtual ~FontSupport();

    virtual void setFont(Font *m_font);
    virtual Font* getFont(void);
protected:
    Font *font;
};


}
}

#endif // FONTSUPPORT_H
