#include "Point.h"

Point::Point()
{
	Free();
}

Point::Point(size_t X, size_t Y)
{
	this->X = X;
	this->Y = Y;
}

Point::Point(const Point & New_Point)
{
	X = New_Point.X;
	Y = New_Point.Y;
}

Point & Point::operator=(const Point & New_Point)
{
	if (*this != New_Point)
	{
		X = New_Point.X;
		Y = New_Point.Y;
	}
	return *this;
}

Point::~Point()
{
	Free();
}

bool Point::operator==(const Point & New_Point) const
{
	if (X == New_Point.X && Y == New_Point.Y)
		return true;
	return false;
}

bool Point::operator!=(const Point & New_Point) const
{
	return !(New_Point == *this);
}

void Point::Free()
{
	X = 0;
	Y = 0;
}

Point Point::operator+(const Point & New_Point)
{
	Point Result = *this;
	Result += New_Point;
	return Result;
}

Point & Point::operator+=(const Point & New_Point)
{
	X += New_Point.X;
	Y += New_Point.Y;
	return *this;
}

void Point::SetX(int X)
{
	this->X = X;
}

void Point::SetY(int Y)
{
	this->Y = Y;
}

size_t Point::GetX() const
{
	return X;
}

size_t Point::GetY() const
{
	return Y;
}

std::ostream & operator<<(std::ostream & output, const Point & New_Point)
{
	output << "(" << New_Point.X << "," << New_Point.Y << ")";
	return output;
}
