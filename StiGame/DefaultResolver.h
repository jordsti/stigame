#ifndef DEFAULTRESOLVER_H
#define DEFAULTRESOLVER_H

#include "FieldResolver.h"

namespace StiGame
{

namespace Serialization
{

class DefautResolver :
	public FieldResolver
{
public:
	DefaultResolver();
	virtual ~DefaultResolver();
	virtual Field* createField(int type, std::string name, char* data, int length);
};

}

}

#endif