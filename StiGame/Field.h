#ifndef OBJECTFIELD_H
#define OBJECTFIELD_H

#include <string>

namespace StiGame
{

namespace Serialization
{

struct FieldMarker {
	int dataLength;
	int nameLength;
	int type;
};

class Field
{
public:
	const static int UNDEFINED;
	Field();
	Field(std::string m_name);
	virtual ~ObjectField();
	
	std::string getName(void);
	
	int getLength(void);
	int getType(void);
	
	//pure virtual
	virtual char* getData(void) = 0;
	virtual void setData(char* m_data, int m_length) = 0;
	
	virtual void updateMarker(FieldMarker *marker);
	
protected:
	std::string name;
	int length;
	int type;
};

}

}

#endif