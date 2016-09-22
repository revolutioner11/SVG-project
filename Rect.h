#pragma once

#include "Figure.h"

///
///	Клас Правоъгълник наследяващ Фигура
///
class Rect : public Figure
{
public:
	Rect();
	Rect(const Point & TopLeft, size_t Width, size_t Height);
	Rect(const Point & TopLeft, size_t Width, size_t Height, size_t RadX, size_t RadY);
	Rect(const Rect & New_Rect);
	virtual ~Rect();
	Rect & operator=(const Rect & New_Rect);
public:
	bool operator==(const Rect & New_Rect) const;
	bool operator!=(const Rect & New_Rect) const;
private:
	Figure &  Copy(const Rect & New_Rect);
public:
	void SetTopLeft(const Point & TopLeft);
	void SetWidth(size_t Width);
	void SetHeight(size_t Height);
	void SetRadX(size_t RadX);
	void SetRadY(size_t RadY);
	void SetColor(const MyString & Color);
public:
	Point GetTopLeft() const;
	size_t GetWidth() const;
	size_t GetHeight() const;
	size_t GetRadX() const;
	size_t GetRadY() const;
	MyString GetColor() const;
public:
	virtual void Print() const;
	virtual void Translate(const Point & vec);
	virtual bool Within(const Figure & Within_Figure) const;
	virtual double GetArea() const;
	virtual void Free();
private:
	Point TopLeft;
	size_t Width;
	size_t Height;
	size_t RadX;
	size_t RadY;
	MyString Color;
};

