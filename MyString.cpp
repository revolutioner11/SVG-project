#include "MyString.h"

MyString::MyString() : Data(nullptr) {}

MyString::MyString(char * str)
{
	Data = nullptr;
	if (str != nullptr)
		SetData(str);
}

MyString::MyString(const MyString & NewStr)
{
	Data = nullptr;
	if (NewStr.Data == nullptr)
	{
		delete[] Data;
		Data = nullptr;
		return;
	}
	SetData(NewStr.Data);
}

MyString & MyString::operator=(const MyString & NewStr)
{
	if (NewStr == *this)
		return *this;
	if (NewStr.Data == nullptr)
	{
		delete[] Data;
		Data = nullptr;
		return *this;
	}
	SetData(NewStr.Data);
	return *this;
}

MyString::~MyString()
{
	delete[] Data;
	Data = nullptr;
}

bool MyString::operator==(const MyString & NewStr) const
{
	size_t size = NewStr.StrLen();
	if (this->StrLen() != size)
		return false;
	for (size_t i = 0; i < size; ++i)
	{
		if (Data[i] != NewStr.Data[i])
			return false;
	}
	return true;
}

bool MyString::operator!=(const MyString & NewStr) const
{
	return !(*this == NewStr);
}

bool MyString::operator!=(char * NewStr) const
{
	MyString str(NewStr);
	return !(*this == str);
}

char MyString::operator[](size_t Index) const
{
	if (Index >= StrLen())
		return '\0';
	else
		return Data[Index];
}

size_t MyString::sizeofdata() const
{
	return sizeof(Data);
}

MyString::operator char*() const
{
	return Data;
}

size_t MyString::StrLen() const
{
	return StrLen(Data);
}

size_t MyString::StrLen(char * str) const
{
	if (str == nullptr)
		return 0;
	size_t size = 0;
	while (str[size] != '\0')
		++size;
	return size;
}

void MyString::Add(char C)
{
	size_t size = StrLen() + 2;
	MyString New_Str = *this;
	delete[] Data;
	Data = new char[size];
	for (size_t i = 0; i < size - 1; ++i)
		Data[i] = New_Str.Data[i];
	Data[size - 2] = C;
	Data[size - 1] = '\0';
}

char MyString::operator[](const size_t Index)
{
	return Data[Index];
}

void MyString::SetData(char * str)
{
	delete[] Data;
	size_t size = StrLen(str);
	Data = new char[size + 1];
	for (size_t i = 0; i < size; ++i)
		Data[i] = str[i];
	Data[size] = '\0';
}

std::ostream & operator<<(std::ostream & output, const MyString & NewStr)
{
	size_t size = NewStr.StrLen();
	for (size_t i = 0; i < size; ++i)
	{
		output << NewStr.Data[i];
	}
	return output;
}

std::istream & operator>>(std::istream & input, MyString & NewStr)
{
	char buffer[_MAX_PATH];
	input >> buffer;
	NewStr.SetData(buffer);
	return input;
}
