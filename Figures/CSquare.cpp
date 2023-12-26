#include "CSquare.h"
#include <fstream>

CSquare::CSquare()
{
}

CSquare::CSquare(Point p, GfxInfo FigureGfxInfo, int l):CFigure(FigureGfxInfo)
{
	Center = p;
	length = l;
}
void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected, length);
}

bool CSquare::IsInside(int x, int y) const
{
	int x_min, x_max, y_min, y_max;

	x_min = Center.x - length / 2;
	x_max = Center.x + length / 2;
	y_min = Center.y - length / 2;
	y_max = Center.y + length / 2;

	if (y >= y_min && y <= y_max && x >= x_min && x <= x_max) return 1;
	return 0;
}

Point CSquare::MoveFigure(Point P)
{
	// Checks if it will be drawn over any of two bars or not
	// if it won't be drawn over the bars it will be moved
	if (P.y - length / 2 < UI.ToolBarHeight + UI.ToolBarBorderWidth || P.y + length / 2 > UI.height - UI.StatusBarHeight) {
		Point Temp;
		Temp.x = -1;
		Temp.y = -1;
		return Temp;
	} else {
		Point Center2 = Center;
		Center = P;
		return Center2;
	}
}

void CSquare::save(ofstream& fout)
{
	fout << "SQUARE" << " \t\t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << length << "\t";
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

void CSquare::load(ifstream& fin)
{
	string drawclr, fillclr;
	int len;
	fin >> ID >> Center.x >> Center.y >> len >>  drawclr >> fillclr;
	length = len;
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

void CSquare::Resize(Point)
{
}

void CSquare::DistanceFromCenter(Point P, double& DIFFx, double& DIFFy)
{
	DIFFx = Center.x - P.x;
	DIFFy = Center.y - P.y;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Sleceted A Square, ID: " + to_string(ID) + " | Center Point : (" + to_string(Center.x) + ", " + to_string(Center.y) + ") | Side Length : " + to_string(length));

}

