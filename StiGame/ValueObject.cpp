#include "ValueObject.h"

namespace StiGame {

namespace Gui
{

ValueObject::ValueObject()
{
    id = 0;
    text = "empty";
}

ValueObject::ValueObject(int m_id, std::string m_text)
{
    id = m_id;
    text = m_text;
}

int ValueObject::getId(void)
{
    return id;
}

std::string ValueObject::getText(void)
{
    return text;
}

ValueObject::~ValueObject()
{

}

}

}
