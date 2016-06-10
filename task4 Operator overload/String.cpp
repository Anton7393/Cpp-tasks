#include "String.hpp"

using namespace std;

String::String()
{
    m_size = 0;
    m_data = new char [m_size + 1]();
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

void String::init(const char * _newData)
	{
	    m_size = strlen(_newData);
	    m_data = new char [m_size+1]();
		memcpy(m_data, _newData, m_size+1);
	}

String & String::operator = (const String & _right)
{
    if (&_right != this)
    {
        delete [] m_data;
        init(_right.m_data);
        m_data[m_size] = '\0';
    }
	return *this;
}

String String::operator + (const String & _right) const
{
    int tmp_size = m_size + _right.m_size;
    char * tmp_data = new char [tmp_size + 1]();
    strcpy(tmp_data, m_data);
    strcat(tmp_data, _right.m_data);
    tmp_data[tmp_size] = '\0';
    String tmp_String(tmp_data);
    delete [] tmp_data;
    return tmp_String;
}

String String::operator + (const char * _right) const
{
    int tmp_size = m_size + strlen(_right);
    char * tmp_data = new char [tmp_size + 1]();
    strcpy(tmp_data, m_data);
    strcat(tmp_data, _right);
    tmp_data[tmp_size] = '\0';
    String tmp_String(tmp_data);
    delete [] tmp_data;
    return tmp_String;
}

bool String::operator == (const String & _right) const
{
    return (m_size == _right.m_size);
}

bool String::operator != (const String & _right) const
{
    return (m_size != _right.m_size);
}

bool String::operator >= (const String & _right) const
{
    return (m_size >= _right.m_size);
}

bool String::operator <= (const String & _right) const
{
    return (m_size <= _right.m_size);
}

bool String::operator > (const String & _right) const
{
    return (m_size > _right.m_size);
}

bool String::operator < (const String & _right) const
{
    return (m_size < _right.m_size);
}
bool String::operator ! () const
{
    if (m_data[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void String::operator += (const String & _right)
{
    *this = *this + _right;
}

void String::operator += (const char * _right)
{
    *this = *this + _right;
}

void String::operator += (const char & _right)
{
    char tmp_str[2];
    tmp_str[0] = _right;
    tmp_str[1] = '\0';
    *this = *this + tmp_str;

}

 String::operator char* () const
{
    return m_data;
}

String::~String()
{
	delete [] m_data;
}

void String::print()
{
	cout << m_data <<endl;
}

String operator + (const char * _left, const String & _right)
{
    String tmp_String(_left);
    tmp_String += _right;
    return tmp_String;
}

ostream & operator << (ostream & out, const String & _right)
{
    out << _right.m_data;
    return out;
}

istream & operator >> (istream & in, const String & _right)
{
    in >> _right.m_data;
    return in;
}

