#include "StringField.h"

namespace StiGame
{

namespace Serialization
{

const int StringField::STRING_FIELD = 1;

StringField::StringField(std::string m_name) : Field(m_name)
{
	type = STRING_FIELD;
	str_data = "";
}

StringField::~StringField() {}

void StringField::setString(std::string m_str_data)
{
	str_data = m_str_data;
	length = str_data.size();
}

std::string StringField::getString(void)
{
	return str_data;
}

char* StringField::getData(void)
{
	char *buffer = new char[length+1];
	std::copy(str_data.begin(), str_data.end(), buffer);
	buffer[length] = '\0';
	return buffer;
}

void StringField::setData(char* m_data, int m_length)
{
	length = m_length;
	str_data = "";
	
	for(int i=0; i<length; i++)
	{
		str_data += m_data[i];
	}

}

//std::string str_data;

}

}