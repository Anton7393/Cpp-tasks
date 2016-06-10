#ifndef STRING_HPP
#define STRING_HPP

#include <cstring>

#include <iostream>

class String
{
	char * m_data;
	const int m_size = 100;

	void init(const char * newData);

public:
	String();
	String(const char *);
	String(const String &);

	~String();

	String & operator =(const String &);

	void print();
};

#endif // STRING_HPP
