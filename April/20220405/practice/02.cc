#include <iostream>
#include <cctype>
#include <cstring>

class String 
{
public:
	String();//finish
	String(const char *);//finish
	String(const String &);//finish
	~String();//finish
	String &operator=(const String &);//finish
	String &operator=(const char *);//finish

	String &operator+=(const String &);//finish
	String &operator+=(const char *);//finish
	
	char &operator[](std::size_t index);//finish
	const char &operator[](std::size_t index) const;//finish
	
	std::size_t size() const;//finish
	const char* c_str() const;//finish
	
	friend bool operator==(const String &, const String &);
	friend bool operator!=(const String &, const String &);
	
	friend bool operator<(const String &, const String &);
	friend bool operator>(const String &, const String &);
	friend bool operator<=(const String &, const String &);
	friend bool operator>=(const String &, const String &);
	
	friend std::ostream &operator<<(std::ostream &os, const String &s);
	friend std::istream &operator>>(std::istream &is, String &s);

private:
	char * _pstr;
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);

String::String()
:_pstr(new char[1])
{
	strcpy(_pstr, "");
}
String::String(const char *str)
:_pstr(new char[strlen(str) + 1])
{
	strcpy(_pstr, str);
}
String::String(const String &str)
:_pstr(new char[strlen(str._pstr) + 1])
{
	strcpy(_pstr, str._pstr);
}
String::~String()
{
	if(_pstr)
	{
		delete [] _pstr;
		_pstr = nullptr;
	}
}
String &String::operator=(const String &str)
{
	if(_pstr)
	{
		delete [] _pstr;
	}
	_pstr = new char[strlen(str._pstr) + 1];
	strcpy(_pstr, str._pstr);
	return *this;
}
String &String::operator=(const char *str)
{
	if(_pstr)
	{
		delete [] _pstr;
	}
	_pstr = new char[strlen(str) + 1];
	strcpy(_pstr, str);
	return *this;
}
String &String::operator+=(const String &str)
{
	char *ptemp = new char[strlen(_pstr) + strlen(str._pstr) + 1];
	strcpy(ptemp, _pstr);
	strcat(ptemp, str._pstr);
	delete [] _pstr;
	_pstr = ptemp;
	return *this;
}
String &String::operator+=(const char *str)
{
	char *ptemp = new char[strlen(_pstr) + strlen(str) + 1];
	strcpy(ptemp, _pstr);
	strcat(ptemp, str);
	delete [] _pstr;
	_pstr = ptemp;
	return *this;
}
char &String::operator[](std::size_t index)
{
	
	if(index >= 0 && index <= strlen(_pstr))
	return _pstr[index];
	else
	return _pstr[strlen(_pstr)];
}
const char &String::operator[](std::size_t index) const
{
	if(index >= 0 && index <= strlen(_pstr))
	return _pstr[index];
	else
	return _pstr[strlen(_pstr)];
}
std::size_t String::size() const
{
	return static_cast<std::size_t>(strlen(_pstr));
}
const char* String::c_str() const
{
	return _pstr;
}
bool operator==(const String &str1, const String &str2)
{
	if(strcmp(str1._pstr, str2._pstr))
	return false;
	else
	return true;
}
bool operator!=(const String &str1, const String &str2)
{
	if(strcmp(str1._pstr, str2._pstr))
	return true;
	else
	return false;
}
bool operator<(const String &str1, const String &str2)
{
	if(strcmp(str1._pstr, str2._pstr) > 0)
	return false;
	else
	return true;
}
bool operator>(const String &str1, const String &str2)
{
	if(strcmp(str1._pstr, str2._pstr) > 0)
	return true;
	else
	return false;
}
bool operator<=(const String &str1, const String &str2)
{
	if(strcmp(str1._pstr, str2._pstr) >= 0)
	return false;
	else
	return true;
}
bool operator>=(const String &str1, const String &str2)
{
	if(strcmp(str1._pstr, str2._pstr) >= 0)
	return true;
	else
	return false;
}

std::ostream &operator<<(std::ostream &os, const String &s)
{
	os << s._pstr;
	return os;
}
std::istream &operator>>(std::istream &is, String &s)
{
	char buff[1024] = {0};
	is >> buff;
	delete [] s._pstr;
	s._pstr = new char[strlen(buff) + 1];
	strcpy(s._pstr, buff);
	return is;
}
String operator+(const String &str1, const String &str2)
{
	String str3 = str1;
	str3 += str2;
	return str3;
}
String operator+(const String &str1, const char *str2)
{
	String str3 = str1;
	str3 += str2;
	return str3;
}
String operator+(const char *str1, const String &str2)
{
	String str3 = str1;
	str3 += str2;
	return str3;
}
void test()
{
	String s1, s2("World"), s3("Hello");
	s1 = s3 + " " + s2;
	std::cout << s1 << std::endl;
}
int main()
{
    test();
    return 0;
}