#ifndef STRING_HPP
#define STRING_HPP

#include <cstring>
#include <iostream>
#include <iostream>

class String
{
	char * m_data;
	int m_size;

	void init(const char * newData);

public:
	String();
	String(const char *);
	String(const String &);

	~String();

	String & operator = (const String &);
	String operator + (const String &) const;
	String operator + (const char *) const;
	bool operator == (const String &) const;
    bool operator != (const String &) const;
    bool operator >= (const String &) const;
    bool operator <= (const String &) const;
    bool operator > (const String &) const;
    bool operator < (const String &) const;
    bool operator ! () const;
    void operator += (const String &);
	void operator += (const char *);
	void operator += (const char &);
	operator char* () const;

    friend String operator + (const char *, const String &);
	friend std::ostream & operator << (std::ostream &, const String &);
    friend std::istream & operator >> (std::istream &, const String &);

	void print();
};




#endif // STRING_HPP
