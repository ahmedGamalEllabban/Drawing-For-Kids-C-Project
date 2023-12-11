#include "CTriangle.h"
#include <cmath>
#include <fstream>




CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo) {
	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;
}

CTriangle::CTriangle()
{
}
void CTriangle::Draw(Output* pOut) const {
	pOut->DrawTriangle(Corner1,Corner2,Corner3,FigGfxInfo,Selected);
}

	double TriangleArea(int x1, int y1, int x2, int y2, int x3, int y3)//REQUIRED TO COMPUTE WHETHER THE POINT IS INSIDE THE TRIANGLE
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}


bool CTriangle::IsInside(int x, int y)const {
	
	double A = TriangleArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);


	double A1 = TriangleArea(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);

	
	double A2 = TriangleArea(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);

	
	double A3 = TriangleArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);

	/* Check if sum of A1, A2 and A3 is same as A */
	if (A != 0) {
		return ( std::abs(A - (A1 + A2 + A3)) < DBL_EPSILON);
	}
	else {//if the three points are collinear the previous line won't be enough to tell if the point is inside or not
		int x_min;
		int y_min;
		int x_max;
		int y_max;
		//the following code get the max and min x
		if (Corner1.x > Corner2.x)
		{
			x_max = Corner1.x;
			x_min = Corner2.x;
		}
		else {
			x_max = Corner2.x;
			x_min = Corner1.x;
		}
		if (Corner3.x > x_max) {
			x_max = Corner3.x;
		}
		else if (Corner3.x < x_min) {
			x_min = Corner3.x;
		}
		//the following code get the max and min y
		if (Corner1.y > Corner2.y)
		{
			y_max = Corner1.y;
			y_min = Corner2.y;
		}
		else {
			y_max = Corner2.y;
			y_min = Corner1.y;
		}
		if (Corner3.y > y_max) {
			y_max = Corner3.y;
		}
		else if (Corner3.y < y_min) {
			y_min = Corner3.y;
		}
		if (y >= y_min && y <= y_max && x >= x_min && x <= x_max) // sees whether the point is inside it or not
			return 1;
		return 0;
	}

	}

Point CTriangle::MoveFigure(Point move) {
	Point c;
	c.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	c.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

	int xDiff = move.x - c.x;
	int yDiff = move.y - c.y;

	Corner1.x += xDiff;
	Corner1.y += yDiff;

	Corner2.x += xDiff;
	Corner2.y += yDiff;

	Corner3.x += xDiff;
	Corner3.y += yDiff;
	return c;
}

void CTriangle::save(ofstream& fout)
{
	fout << "TRIANGLE" << "\t" << ID << "  \t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x << "\t" << Corner2.y << "\t" << Corner3.x << "\t" << Corner3.y << "\t";
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

void CTriangle::load(ifstream& fin)
{
	string drawclr, fillclr;
	fin >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> drawclr >> fillclr;
	if (drawclr == "BLACK") { FigGfxInfo.DrawClr = BLACK; }
	else if (drawclr == "BLUE") { FigGfxInfo.DrawClr = BLUE; }
	else if (drawclr == "RED") { FigGfxInfo.DrawClr = RED; }
	else if (drawclr == "ORANGE") { FigGfxInfo.DrawClr = ORANGE; }
	else if (drawclr == "YELLOW") { FigGfxInfo.DrawClr = YELLOW; }
	else if (drawclr == "GREEN") { FigGfxInfo.DrawClr = GREEN; }

	if (fillclr == "NOT_FILLED") { FigGfxInfo.FillClr = NULL; FigGfxInfo.isFilled = false; }
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