#pragma once

#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include <fstream>

///
///	���� ���������� ������ �������
///
class Command
{
public:
	Command();
	//Command(MyString Path);
	~Command();
	void Free();
	void Open(MyString Path);

private:
	Figure** Data;
	MyString Path;
};

