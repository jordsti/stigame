#include "Field.h"

namespace StiGame
{

namespace Serialization
{

const int Field::UNDEFINED = -1;

Field::Field()
{
	name = ""
	type = UNDEFINED
	length = 0;
}
Field::Field(std::string m_name)
{
	name = m_name
	type = UNDEFINED;
	length = 0;
}

Field::~Field() {}
	
std::string Field::getName(void)
{
	return name;
}
	
int Field::getLength(void)
{
	return length;
}

int Field::getType(void)
{
	return type;
}

void Field::updateMarker(FieldMarker *marker)
{
	marker->dataLength = length;
	marker->nameLength = name.size();
	marker->type = type;
}
	
	//pure virtual
	//virtual char* getData(void) = 0;
	//virtual void setData(char* m_data, int length) = 0;
	
	//members
	//std::string name;
	//int length;
	//int type;

}

}