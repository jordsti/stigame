#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "FieldResolver.h"
#include <list>

namespace StiGame
{

namespace Serialization
{

class Serializable
{
public:
	Serializable();
	virtual ~Serializable();
	
	virtual void save(std::string path);
	virtual void load(std::string path);
protected:
	//pure virtual
	virtual void populateFields(void) = 0;
	virtual void fillObject(void) = 0;
	//member
	//maybe add a version int, will see...
	std::list<ObjectField*> fields;
	FieldResolver *resolver;
	
};

}

}

#endif