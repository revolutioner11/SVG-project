#include "Line.h"

Line::Line()
{
	Free();
}

Line::Line(const Point & Start, const Point & End)
{
	this->Start = Start;
	this->End = End;
}

Line::~Line()
{
	Free();
}

Line::Line(const Line & New_Line)
{
	Copy(New_Line);
}

Line & Line::operator=(const Line & New_Line)
{
	if (*this != New_Line)
		Copy(New_Line);
	return *this;
}

bool Line::operator==(const Line & New_Line) const
{
	if (Start == New_Line.Start
		&& End == New_Line.End
		&& Figure::operator==(New_Line))
		return true;
	return false;
}

bool Line::operator!=(const Line & New_Line) const
{
	return !(*this == New_Line);
}

void Line::Free()
{
	Start.Free();
	End.Free();
	Figure::Free();
}

Figure & Line::Copy(const Line & New_Line)
{
	Start = New_Line.Start;
	End = New_Line.End;
	Figure::Copy(New_Line);
	return *this;
}

void Line::SetStart(const Point & Start)
{
	this->Start = Start;
}

void Line::SetEnd(const Point & End)
{
	this->End = End;
}

Point Line::GetStart() const
{
	return Start;
}

Point Line::GetEnd() const
{
	return End;
}

void Line::Print() const
{
	std::cout << "Line: Start" << Start
		<< ", End" << End << ", ";
	Figure::Print();
}

void Line::Translate(const Point & vec)
{
	Start += vec;
	End += vec;
}

bool Line::Within(const Figure & Within_Figure) const
{
	return false;																				/// sth
}

double Line::GetArea() const
{
	return 0.0;
}
