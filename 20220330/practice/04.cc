#include <iostream>
#include <string.h>
class String
{
public:
	String();
	String(const char *pstr);
	String(const String &rhs);
	String &operator=(const String &rhs);
	~String();
	void print();

private:
	char *_pstr;
};

int main()
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}

//类外实现
String::String()
	: _pstr(nullptr)
{
}

String::String(const char *pstr)
	: _pstr(new char[strlen(pstr) + 1])
{
	strcpy(_pstr, pstr);
}

String::String(const String &rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1])
{
	strcpy(_pstr, rhs._pstr);
}

String &String::operator=(const String &rhs)
{
	if (this != &rhs)
	{
		if(_pstr != nullptr)
		{
			delete[] _pstr;
		}
		_pstr = new char[strlen(rhs._pstr) + 1];
		strcpy(_pstr, rhs._pstr);
	}
	return *this;
}

String::~String()
{
	delete[] _pstr;
	_pstr = nullptr;
}

void String::print()
{
	if (_pstr != nullptr)
		std::cout << _pstr << std::endl;
}