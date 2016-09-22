#pragma once

#include "Figure.h"

class Line : public Figure
{
public:
	Line();
	Line(const Point & Start, const Point & End);
	virtual ~Line();
	Line(const Line & New_Line);
	Line & operator=(const Line & New_Line);
public:
	bool operator==(const Line & New_Line) const;
	bool operator!=(const Line & New_Line) const;
public:
	void SetStart(const Point & Start);
	void SetEnd(const Point & End);
	Point GetStart() const;
	Point GetEnd() const;
public:
	virtual void Print() const;
	virtual void Translate(const Point & vec);
	virtual bool Within(const Figure & Within_Figure) const;
	virtual double GetArea() const;
	virtual void Free();
private:
	Figure & Copy(const Line & New_Line);
private:
	Point Start;
	Point End;
};

