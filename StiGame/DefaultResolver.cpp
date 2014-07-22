#include "DefaultResolver.h"

#include "StringField.h"
#include "IntField.h"

namespace StiGame
{

namespace Serialization
{

DefaultResolver::DefaultResolver() {}
DefaultResolver::~DefaultResolver() {}

Field* DefaultResolver::createField(int type, std::string name, char* data, int length)
{
	Field *field = 0;
	
	if(type == StringField::STRING_FIELD)
	{
		field = new StringField(name);
		field->setData(data, length);
	}
	else if(type == IntField::INT_FIELD)
	{
		field = new IntField(name);
		field->setData(data, length);
	}
	
	return field;
	
}

}

}