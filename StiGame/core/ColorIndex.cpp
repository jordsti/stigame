#include "ColorIndex.h"
namespace StiGame {

ColorIndex::ColorIndex()
{

}

ColorIndex::~ColorIndex()
{
    auto lit(colors.begin()), lend(colors.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }
}

void ColorIndex::add(Color *color)
{
    colors.push_back(color);
}

void ColorIndex::remove(Color *color)
{
    colors.remove(color);
}

size_t ColorIndex::size(void)
{
    return colors.size();
}

void ColorIndex::clear(void)
{
    auto lit(colors.begin()), lend(colors.end());
    for(;lit!=lend;++lit)
    {
        delete (*lit);
    }

    colors.clear();
}

Color* ColorIndex::at(unsigned int index)
{
    auto lit(colors.begin()), lend(colors.end());
    unsigned int i = 0;
    for(;lit!=lend;++lit)
    {
        if(i == index)
        {
            return (*lit);
        }
        i++;
    }

    return nullptr;
}


}
