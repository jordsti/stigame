#include "Spacer.h"

namespace StiGame
{
namespace Gui
{

Spacer::Spacer()
    : Item("Spacer")
{
    //ctor
}

Spacer::~Spacer()
{
    //dtor
}

Surface* Spacer::render(void)
{
    Surface *buffer = new Surface(width, height);
    buffer->fill(background);
    return buffer;
}

}

}
