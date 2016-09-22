#pragma once
#include "MyString.h"

///
///	Точка, определяна от координати (Х,У)
///
class Point
{
public:
	Point();
	Point(size_t X, size_t Y);
	Point(const Point & New_Point);
	Point & operator=(const Point & New_Point);
	~Point();
public:
	bool operator==(const Point & New_Point) const;
	bool operator!=(const Point & New_Point) const;
	void Free();
	friend std::ostream & operator<<(std::ostream & output, const Point & New_Point);
	Point operator+(const Point & New_Point);
	Point & operator+=(const Point & New_Point);
public:
	void SetX(int X);
	void SetY(int Y);
	size_t GetX() const;
	size_t GetY() const;
private:
	size_t X;
	size_t Y;
};
