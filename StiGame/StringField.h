#ifndef STRINGFIELD_H
#define STRINGFIELD_H

#include "ObjectField.h"

namespace StiGame
{

namespace Serialization
{

class StringField :
	public Field
{
public:
	const static int STRING_FIELD;

	StringField(std::string m_name);
	virtual ~StringField();
	
	void setString(std::string m_str_data);
	std::string getString(void);
	
	char* getData(void);
	void setData(char* m_data, int m_length);
protected:
	std::string str_data;
};

}

}


#endif