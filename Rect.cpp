#include "Rect.h"

Rect::Rect()
{
	Free();
}

Rect::Rect(const Point & TopLeft, size_t Width, size_t Height)
{
	this->TopLeft = TopLeft;
	this->Width = Width;
	this->Height = Height;
	RadX = 0;
	RadY = 0;
}

Rect::Rect(const Point & TopLeft, size_t Width, size_t Height, size_t RadX, size_t RadY)
{
	this->TopLeft = TopLeft;
	this->Width = Width;
	this->Height = Height;
	this->RadX = RadX;
	this->RadY = RadY;
}

Rect::Rect(const Rect & New_Rect)
{
	Copy(New_Rect);
}

Rect::~Rect()
{
	Free();
}

Rect & Rect::operator=(const Rect & New_Rect)
{
	if (*this != New_Rect)
		Copy(New_Rect);
	return *this;
}

bool Rect::operator==(const Rect & New_Rect) const
{
	if (TopLeft == New_Rect.TopLeft
		&& Width == New_Rect.Width
		&& Height == New_Rect.Height
		&& RadX == New_Rect.RadX
		&& RadY == New_Rect.RadY
		&& Color == New_Rect.Color
		&& Figure::operator==(New_Rect))
		return true;
	return false;
}

bool Rect::operator!=(const Rect & New_Rect) const
{
	return !(*this == New_Rect);
}

void Rect::Free()
{
	TopLeft.Free();
	Width = 0;
	Height = 0;
	RadX = 0;
	RadY = 0;
	Color = nullptr;
	Figure::Free();
}

Figure & Rect::Copy(const Rect & New_Rect)
{
	TopLeft = New_Rect.TopLeft;
	Width = New_Rect.Width;
	Height = New_Rect.Height;
	RadX = New_Rect.RadX;
	RadY = New_Rect.RadY;
	Color = New_Rect.Color;
	Figure::operator=(New_Rect);
	return *this;
}

void Rect::SetTopLeft(const Point & TopLeft)
{
	this->TopLeft = TopLeft;
}

void Rect::SetWidth(size_t Width)
{
	this->Width = Width;
}

void Rect::SetHeight(size_t Height)
{
	this->Height = Height;
}

void Rect::SetRadX(size_t RadX)
{
	this->RadX = RadX;
}

void Rect::SetRadY(size_t RadY)
{
	this->RadY = RadY;
}

void Rect::SetColor(const MyString & Color)
{
	this->Color = Color;
}

Point Rect::GetTopLeft() const
{
	return TopLeft;
}

size_t Rect::GetWidth() const
{
	return Width;
}

size_t Rect::GetHeight() const
{
	return Height;
}

size_t Rect::GetRadX() const
{
	return RadX;
}

size_t Rect::GetRadY() const
{
	return RadY;
}

MyString Rect::GetColor() const
{
	return Color;
}

void Rect::Print() const
{
	std::cout << "Rectangle: TopLeft" << TopLeft << ", Width = " << Width << ", Height = " << Height
		<< ", RadX = " << RadX << ", RadY = " << RadY
		<< ", Fill = \"" << Color
		<< ", " ;
	Figure::Print();
}

void Rect::Translate(const Point & vec)
{
	TopLeft += vec;
}

bool Rect::Within(const Figure & Within_Figure) const
{
	if (Within_Figure.GetArea() < this->GetArea())
		return false;
	return true;																	/// WRONG !!!
}

double Rect::GetArea() const
{
	return Width*Height;
}
