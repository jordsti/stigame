#ifndef INTFIELD_H
#define INTFIELD_H

#include "Field.h"

namespace StiGame
{

namespace Serialization
{

class IntField :
	public Field
{
public:
	const static int INT_FIELD;
	IntField(std::string m_name);
	virtual ~IntField();
	
	void setValue(int m_value);
	int getValue(void);
	
	char* getData(void);
	void setData(char* m_data, int m_length);
protected:
	int value;
};

}

}

#endif