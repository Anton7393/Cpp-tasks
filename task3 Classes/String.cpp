#include "String.hpp"

#include <iostream>

using namespace std;

String::String()
{
    m_data = new char [m_size+1]();
    m_data[0] = '\0';
}

String::String(const char * _string)
{
    init(_string);
	m_data[m_size] = '\0';
}

String::String(const String & _copy)
{
    init(_copy.m_data);
}

void String::init(const char * newData)
	{
	    m_data = new char [m_size+1]();
		memcpy(m_data, newData, m_size+1);
	}

String &String::operator = (const String &_right)
{
    if (&_right != this)
    {
        delete [] m_data;
        init(_right.m_data);
        m_data[m_size] = '\0';
    }
	return *this;
}

String::~String()
{
	delete [] m_data;
}

void String::print()
{
	std::cout << m_data << std::endl;
}
