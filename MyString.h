#pragma once
#include <iostream>

///
///	Наподобяващ std::string клас, който поддържа само определени функционалности
///
class MyString
{
public:
	MyString();
	MyString(char*str);
	MyString(const MyString & NewStr);
	MyString & operator=(const MyString & NewStr);
	~MyString();
public:
	bool operator==(const MyString & NewStr) const;
	bool operator!=(const MyString & NewStr) const;
	bool operator!=(char * NewStr) const;
	char operator[](size_t Index) const;
	size_t sizeofdata() const;
	operator char*() const;
	size_t StrLen() const;
	friend std::ostream & operator<<(std::ostream & output, const MyString & NewStr);
	friend std::istream & operator>>(std::istream & input, MyString & NewStr);
	void Add(char C);
	char operator[](const size_t Index);
private:
	void SetData(char*str);
	size_t StrLen(char*str) const;
private:
	char* Data;
};