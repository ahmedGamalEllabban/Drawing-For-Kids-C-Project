#include "CCircle.h"
#include <fstream>

CCircle::CCircle()
{
}

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo)
{
	center = p1;
	P2 = p2;

}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(center, P2, FigGfxInfo, Selected);
}

Point CCircle::MoveFigure(Point move) {
	double radius;
	int DiffX = P2.x - center.x;
	int DiffY = P2.y - center.y;
	radius = sqrt(DiffX * DiffX + DiffY * DiffY);
	if (radius < (UI.height - UI.StatusBarHeight) - move.y && radius < move.y - (UI.ToolBarHeight + UI.ToolBarBorderWidth)) {
	Point Center2 = center;
	center = move;
	P2.x = DiffX + center.x;
	P2.y = DiffY + center.y;
	return Center2;
	}
	else{
		Point Temp1;
		Temp1.x = -1;
		Temp1.y = -1;
		return Temp1;
	}
}
bool CCircle::IsInside(int x, int y) const{
	int SR = (center.x - P2.x) * (center.x - P2.x) + (center.y - P2.y) * (center.y - P2.y);// NOTE: change the implementation if a member data of radius is added
	int SR1 = (center.x - x) * (center.x - x) + (center.y - y) * (center.y - y);//New Radius square
	if (SR>=SR1)// sees whether the square distance between the point and the Circle center is less than the radius 
		return true;
		return false;
}
void CCircle::save(ofstream& fout)
{
	fout << "CIRCLE" << " \t\t" << ID << "\t" << center.x << "\t" << center.y << "\t" << P2.x << "\t" << P2.y << "\t";
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

void CCircle::load(ifstream& fin)
{
	string drawclr, fillclr;
	fin >> ID >> center.x >> center.y >> P2.x >> P2.y >> drawclr >> fillclr;
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