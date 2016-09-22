#include "Figure.h"

Figure::Figure()
{
	Free();
}

Figure::Figure(MyString Color, MyString StrokeColor, size_t StrokeWidth)
{
	this->StrokeColor = StrokeColor;
	this->StrokeWidth = StrokeWidth;
}

Figure::~Figure()
{
	Free();
}

bool Figure::operator==(const Figure & New_Figure) const
{
	if (StrokeColor == New_Figure.StrokeColor
		&& StrokeWidth == New_Figure.StrokeWidth)
		return true;
	return false;
}

void Figure::Print() const
{
	std::cout << "Stroke Color = \"";
	if (StrokeColor == nullptr)
		std::cout << "none";
	else
		std::cout << StrokeColor;
	std::cout << "\", Stroke Width = " << StrokeWidth << "\n";
}

void Figure::Free()
{
	StrokeColor = nullptr;
	StrokeWidth = 0;
}

Figure & Figure::Copy(const Figure & New_Figure)
{
	StrokeColor = New_Figure.StrokeColor;
	StrokeWidth = New_Figure.StrokeWidth;
	return *this;
}

void Figure::SetStrokeColor(const MyString & StrokeColor)
{
	this->StrokeColor = StrokeColor;
}

void Figure::SetStrokeWidth(size_t StrokeWidth)
{
	this->StrokeWidth = StrokeWidth;
}

MyString Figure::GetStrokeColor() const
{
	return StrokeColor;
}

size_t Figure::GetStrokeWidth() const
{
	return StrokeWidth;
}