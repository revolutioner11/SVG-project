#include "Circle.h"

Circle::Circle()
{
	Free();
}

Circle::Circle(const Point & Center, size_t Radius)
{
	this->Center = Center;
	this->Radius = Radius;
}

Circle::Circle(const Circle & New_Circle)
{
	Copy(New_Circle);
}

Circle::~Circle()
{
	Free();
}

Circle & Circle::operator=(const Circle & New_Circle)
{
	if (*this != New_Circle)
		Copy(New_Circle);
	return *this;
}

bool Circle::operator==(const Circle & New_Circle) const
{
	if (Center == New_Circle.Center
		&& Radius == New_Circle.Radius
		&& Figure::operator==(New_Circle))
		return true;
	return false;
}

bool Circle::operator!=(const Circle & New_Circle) const
{
	return !(*this == New_Circle);
}

void Circle::Print() const
{
	std::cout << "Circle: Center" << Center << ", Radius = " << Radius << ", ";
	Figure::Print();
}

void Circle::Translate(const Point & vec)
{
	Center += vec;
}

bool Circle::Within(const Figure & Within_Figure) const
{
	if (Within_Figure.GetArea() < this->GetArea())
		return false;
	return true;															/// WRONG !!!
}

double Circle::GetArea() const
{
	const float Pi = 3.14;
	return Pi*Radius*Radius;
}

void Circle::Free()
{
	Center.Free();
	Radius = 0;
	Figure::Free();
}

Figure & Circle::Copy(const Circle & New_Circle)
{
	Center = New_Circle.Center;
	Radius = New_Circle.Radius;
	Color = New_Circle.Color;
	Figure::Copy(New_Circle);
	return *this;
}

void Circle::SetCenter(const Point & Center)
{
	this->Center = Center;
}

void Circle::SetRadius(size_t Radius)
{
	this->Radius = Radius;
}

void Circle::SetColor(MyString Color)
{
	this->Color = Color;
}

Point Circle::GetCenter() const
{
	return Center;
}

size_t Circle::GetRadius() const
{
	return Radius;
}

MyString Circle::GetColor() const
{
	return Color;
}
