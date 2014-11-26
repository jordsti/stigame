#include "VarFile.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

namespace StiGame
{

VarFile::VarFile()
{
    filepath = "";
}

VarFile::VarFile(std::string m_filepath)
{
    //ctor
    filepath = m_filepath;
}

int VarFile::ParseInt(std::string i_str)
{
    return atoi(i_str.c_str());
}

std::string VarFile::BoolToString(bool b_val)
{
	if(b_val)
	{
		return "True";
	}
	else
	{
		return "False";
	}
}


bool VarFile::getBool(std::string varname)
{
    std::string var = getValue(varname);

    if(var == "true")
    {
        return true;
    }

    return false;
}

bool VarFile::ParseBool(std::string b_str)
{
	if(b_str == "True")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void VarFile::read(void)
{
    std::string line;
    std::ifstream infile (filepath.c_str());

    if(infile.is_open())
    {
        while(std::getline(infile, line))
        {
            parseLine(line);
        }

        infile.close();
    }

}


void VarFile::put(std::string varname, std::string value)
{
    variables.insert(std::make_pair(varname, value));
}

std::list<std::string> VarFile::getKeys(void)
{
	std::list<std::string> keys;

	std::map<std::string, std::string>::iterator lit(variables.begin()), lend(variables.end());

	for(;lit!=lend;++lit)
	{
		keys.push_back(lit->first);
	}

	return keys;
}

std::string VarFile::getValue(std::string varname)
{
    std::string value = "";

    try
    {
        value = variables.at(varname);
    }
    catch(std::exception& e)
    {
        std::cout << varname << " wasn't found !" << std::endl;
    }

    return value;
}

int VarFile::getInt(std::string varname)
{
    std::string val = getValue(varname);
    int i = atoi(val.c_str());
    return i;
}

bool VarFile::isVarExists(std::string varname)
{
    try
    {
        std::string value = variables.at(varname);
    }
    catch(std::exception& e)
    {
        return false;
    }

    return true;
}

void VarFile::parseLine(std::string line)
{
    size_t sep_pos = line.find_first_of('=');
    char first_char = ' ';

    if(line.length() >= 1)
    {
        first_char = line.at(0);
    }

    if(sep_pos != std::string::npos && first_char != '#')
    {
        std::string varName = line.substr(0, sep_pos);
        std::string value = line.substr(sep_pos + 1, line.length() - sep_pos - 2);

        variables.insert(std::make_pair(varName, value));
    }
}

void VarFile::write(void)
{
    std::ofstream outfile (filepath.c_str(), std::ios::out | std::ios::trunc);

    //headers
    outfile << "#StiGame varfile" << std::endl;

    std::map<std::string, std::string>::iterator lit(variables.begin()), lend(variables.end());

    for(;lit!=lend;++lit)
    {
        outfile << (*lit).first << "=" << (*lit).second << ";" << std::endl;
    }

    outfile.close();
}


int VarFile::getCount()
{
    return variables.size();
}

VarFile::~VarFile()
{
    //dtor
}

}
