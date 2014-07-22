#include "IntField.h"

namespace StiGame
{

namespace Serialization
{

const int IntField::INT_FIELD = 2;

IntField::IntField(std::string m_name) : Field(m_name)
{
	type = INT_FIELD;
	value = 0;
	length = 4;
}

IntField::~IntField() {}

void IntField::setValue(int m_value)
{
	value = m_value;
}

int IntField::getValue(void)
{
	return value;
}

char* IntField::getData(void)
{
	return 0;
}

void IntField::setData(char* m_data, int m_length)
{
	length = m_length;
	
}

}

}