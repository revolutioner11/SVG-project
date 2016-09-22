#pragma once

#include "Point.h"

const MyString NoColor = "transparent";					//	������ �� ���� ������� �������� ���� - ���������
//	???		const MyString UndefColor = "black";		//	������ �� ���� ������� ���� �� ������� - �����		???

///
/// Base class for all the figures
///
class Figure
{
protected:
	Figure();
	Figure(MyString Color, MyString StrokeColor, size_t StrokeWidth);
public:			//	��������� ������� ����� �� ����� ������������� �� ����� ��������� �� Figure
	virtual ~Figure();
	bool operator==(const Figure & New_Figure) const;
	virtual void Print() const;
	virtual void Translate(const Point & vec) = 0;
	virtual bool Within(const Figure & Within_Figure) const = 0;
	virtual double GetArea() const = 0;
	virtual void Free();
protected:
	virtual Figure & Copy(const Figure & New_Figure);
public:
	void SetStrokeColor(const MyString & StrokeColor);
	void SetStrokeWidth(size_t StrokeWidth);
	MyString GetStrokeColor() const;
	size_t GetStrokeWidth() const;
protected:
	MyString StrokeColor;
	size_t StrokeWidth;
};
