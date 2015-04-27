#ifndef COLORINDEX_H
#define COLORINDEX_H

#include <list>
#include "Color.h"

namespace StiGame
{

class ColorIndex
{
public:
    ColorIndex();
    virtual ~ColorIndex();

    void add(Color *color);
    void remove(Color *color);

    size_t size(void);
    void clear(void);

    Color* at(unsigned int index);

private:
    std::list<Color*> colors;
};

}

#endif // COLORINDEX_H
