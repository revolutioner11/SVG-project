#pragma once

#include "Figure.h"

///
///	Клас Кръг наследяващ Фигура
///
class Circle : public Figure
{
public:
	Circle();
	Circle(const Point & Center, size_t Radius);
	Circle(const Circle & New_Circle);
	virtual ~Circle();
	Circle & operator=(const Circle & New_Circle);
public:
	bool operator==(const Circle & New_Circle) const;
	bool operator!=(const Circle & New_Circle) const;
public:
	void SetCenter(const Point & Center);
	void SetRadius(size_t Radius);
	void SetColor(MyString Color);
	Point GetCenter() const;
	size_t GetRadius() const;
	MyString GetColor() const;
public:
	virtual void Print() const;
	virtual void Translate(const Point & vec);
	virtual bool Within(const Figure & Within_Figure) const;
	virtual double GetArea() const;
	virtual void Free();
private:
	Figure &  Copy(const Circle & New_Circle);
private:
	Point Center;
	size_t Radius;
	MyString Color;
};

