#include "ValueObject.h"

namespace StiGame {

namespace Gui
{

int ValueObject::_currentId = 0;

int ValueObject::incrementId()
{
    int _id = _currentId;
    _currentId++;
    return _id;
}

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

ValueObject::ValueObject(std::string m_text)
{
    id = incrementId();
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

#ifdef C_WRAPPER

extern "C" {

    StiGame::Gui::ValueObject* ValueObject_new(int id, char* text)
    {

        return new StiGame::Gui::ValueObject(id, text);
    }

    int ValueObject_getId(StiGame::Gui::ValueObject *vo)
    {
        return vo->getId();
    }

    const char* ValueObject_getText(StiGame::Gui::ValueObject *vo)
    {
        return vo->getText().c_str();
    }
}

#endif // C_WRAPPER
