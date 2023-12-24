#include "CRectangle.h"
#include <fstream>
CRectangle::CRectangle()
{
}
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
	Point c, P1, P2;
	c.x = (Corner1.x + Corner2.x) / 2;
	c.y = (Corner1.y + Corner2.y) / 2;

	int xDiff = move.x - c.x;
	int yDiff = move.y - c.y;

	P1.y = Corner1.y + yDiff;
	P2.y = Corner2.y + yDiff;

	if  (
		P1.y < UI.ToolBarHeight + UI.ToolBarBorderWidth 
		|| P2.y < UI.ToolBarHeight + UI.ToolBarBorderWidth 
		|| P1.y > UI.height - UI.StatusBarHeight 
		|| P2.y > UI.height - UI.StatusBarHeight
		)
	{
		Point T;
		T.x = -1;
		T.y = -1;
		return T;
	}
	else {
		Corner1.x += xDiff;
		Corner1.y += yDiff;

		Corner2.x += xDiff;
		Corner2.y += yDiff;
		return c;
	}
}

void CRectangle::save(ofstream& fout)
{
	fout << "RECT" << " \t\t" << ID << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t";
	if (FigGfxInfo.DrawClr == BLACK) fout << "BLACK" << "\t";
	else if (FigGfxInfo.DrawClr == BLUE) fout << "BLUE" << "\t";
	else if (FigGfxInfo.DrawClr == RED) fout << "RED" << "\t";
	else if (FigGfxInfo.DrawClr == GREEN) fout << "GREEN" << "\t";
	else if (FigGfxInfo.DrawClr == YELLOW) fout << "YELLOW" << "\t";
	else if (FigGfxInfo.DrawClr == ORANGE) fout << "ORANGE" << "\t";

	if (FigGfxInfo.isFilled == true) {
		if (FigGfxInfo.FillClr == BLACK) fout << "BLACK" << "\n";
		else if (FigGfxInfo.FillClr == BLUE) fout << "BLUE" << "\n";
		else if (FigGfxInfo.FillClr == RED) fout << "RED" << "\n";
		else if (FigGfxInfo.FillClr == GREEN) fout << "GREEN" << "\n";
		else if (FigGfxInfo.FillClr == YELLOW) fout << "YELLOW" << "\n";
		else if (FigGfxInfo.FillClr == ORANGE)fout << "ORANGE" << "\n";
	}
	else { fout << "NOT_FILLED" << endl; }

}

void CRectangle::load(ifstream& fin)
{
	string drawclr, fillclr;
	fin >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> drawclr >> fillclr;
	if (drawclr == "BLACK") { FigGfxInfo.DrawClr = BLACK; }
	else if (drawclr == "BLUE") { FigGfxInfo.DrawClr = BLUE; }
	else if (drawclr == "RED") { FigGfxInfo.DrawClr = RED; }
	else if (drawclr == "ORANGE") { FigGfxInfo.DrawClr = ORANGE; }
	else if (drawclr == "YELLOW") { FigGfxInfo.DrawClr = YELLOW; }
	else if (drawclr == "GREEN") { FigGfxInfo.DrawClr = GREEN; }


	if (fillclr == "NOT_FILLED")(FigGfxInfo.FillClr = NULL);
	else {
		FigGfxInfo.isFilled = true;
		if (fillclr == "BLACK") { FigGfxInfo.FillClr = BLACK; }
		else if (fillclr == "BLUE") { FigGfxInfo.FillClr = BLUE; }
		else if (fillclr == "RED") { FigGfxInfo.FillClr = RED; }
		else if (fillclr == "ORANGE") { FigGfxInfo.FillClr = ORANGE; }
		else if (fillclr == "YELLOW") { FigGfxInfo.FillClr = YELLOW; }
		else if (fillclr == "GREEN") { FigGfxInfo.FillClr = GREEN; }
	}

}

