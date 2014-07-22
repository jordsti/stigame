#include "Serializable.h"
#include <iostream>
#include <fstream>
namespace StiGame
{

namespace Serialization
{

Serializable::Serializable()
{
	resolver = new DefaultResolver();
}

Serializable::~Serializable()
{
	delete resolver;
}

void Serializable::save(std::string path)
{
	std::ofstream out (path.c_str(), std::ofstream::binary);
	
	std::list<ObjectField*>::iterator lit(fields.begin()), lend(fields.end());
	
	FieldMarker marker = FieldMarker();
	
	for(;lit!=lend;++lit)
	{
		(*lit)->updateMarker(&marker);
		
		out.write(reinterpret_cast<char*>(&marker), sizeof(FieldMarker));
		
		//writing field name
		std::string fname = (*lit)->getName()
		char* bufname = new char[fname.size()+1];
		std::copy(fname.begin(), fname.end(), bufname);
		bufname[fname.size()] = '\0';
		
		out.write(bufname, fname.size() + 1);
		
		//writing field data
		char* data = (*lit)->getData();
		int length = (*lit)->getLength();
		
		out.write(data, length);
		
		delete data;
		delete bufname;
	}
	
	out.close();
}

void Serializable::load(std::string path)
{
	std::ifstream in (path.c_str(), std::ifstream::binary);
	
	FieldMarker marker = FieldMarker();
	
	while(!in.eof())
	{
		in.read((char*)&marker, sizeof(FieldMarker));
		
		char* buffer = new char[marker.dataLength];
		int nameLength = marker.nameLength;
		int type = marker.type;
		
		
	
		ObjectField *field = resolver->createField(type, );
	
	}
	
	in.close();
	
}

}

}