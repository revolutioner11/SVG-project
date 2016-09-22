#include "Command.h"

void main()
{
	Point A(6, 8);
	Point B(1, 2);
	Point C(0, 15);
	Point D(3, 6);
	Point O(0, 0);

	Circle CCC(A, 6);
	Line LLL(B, C);
	Rect RRR(D, 10, 4);
	Circle X;
	X = CCC;

	CCC.Print();
	LLL.Print();
	RRR.Print();
	X.Print();

	Figure* F[4];
	F[0] = new Circle();
	F[0] = CCC;
	F[1] = new Rect;

	//Command C;

	//C.Open("D:\\Folder\\3.svg");

	char c;
	std::cin >> c;
}