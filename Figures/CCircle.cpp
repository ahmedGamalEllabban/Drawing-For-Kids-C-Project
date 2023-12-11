#include "CCircle.h"
#include <fstream>

CCircle::CCircle()
{
}

CCircle::CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo): CFigure(FigureGfxInfo)
{
	P1 = p1;
	P2 = p2;

}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCircle(P1, P2, FigGfxInfo, Selected); 
}

Point CCircle::MoveFigure(Point move) {
	int DiffX = P2.x - P1.x;
	int DiffY = P2.y - P1.y;
	Point Center2 = P1;
	P1 = move;
	P2.x = DiffX + P1.x;
	P2.y = DiffY + P1.y;
	return Center2;
}
bool CCircle::IsInside(int x, int y) const{
	int SR = (P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y);// NOTE: change the implementation if a member data of radius is added
	int SR1 = (P1.x - x) * (P1.x - x) + (P1.y - y) * (P1.y - y);//New Radius square
	if (SR>=SR1)// sees whether the square distance between the point and the Circle center is less than the radius 
		return true;
		return false;
}
void CCircle::save(ofstream& fout)
{
	fout << "CIRCLE" << " \t\t" << ID << "\t" << P1.x << "\t" << P1.y << "\t" << P2.x << "\t" << P2.y << "\t";
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
	fin >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> drawclr >> fillclr;
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