#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::IsInside(int x, int y) const {
	//get the max and min x value
	int x_min;
	int x_max;
	if (Corner1.x > Corner2.x)
	{
		x_max = Corner1.x;
		x_min = Corner2.x;
	}
	else {
		x_max = Corner2.x;
		x_min = Corner1.x;
	}
	//get the max and min y value
	int y_min;
	int y_max;
	if (Corner1.y > Corner2.y)
	{
		y_max = Corner1.y;
		y_min = Corner2.y;
	}
	else {
		y_max = Corner2.y;
		y_min = Corner1.y;
	}
	if (y >= y_min && y <= y_max && x >= x_min && x <= x_max) // sees whether the point is inside it or not
		return 1;
	return 0;
}

Point CRectangle::MoveFigure(Point move) {
	Point c;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;

	int xDiff = move.x - c.x;
	int yDiff = move.y - c.y;

	Corner1.x += xDiff;
	Corner1.y += yDiff;

	Corner2.x += xDiff;
	Corner2.y += yDiff;
	return c;
}
