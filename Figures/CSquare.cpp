#include "CSquare.h"


CSquare::CSquare(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = p;
}
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::IsInside(int x, int y) const
{
	int x_min, x_max, y_min, y_max;

	x_min = Center.x - 50;
	x_max = Center.x + 50;
	y_min = Center.y - 50;
	y_max = Center.y + 50;

	if (y >= y_min && y <= y_max && x >= x_min && x <= x_max) return 1;
	return 0;
}

Point CSquare::MoveFigure(Point P)
{
	Point Center2 = Center;
	Center = P;
	return Center2;
}
