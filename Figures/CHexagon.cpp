#include "CHexagon.h"
#include <fstream>
CHexagon::CHexagon()
{
}
CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}


void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
}
double TrArea(int x1, int y1, int x2, int y2, int x3, int y3)//REQUIRED TO COMPUTE WHETHER THE POINT IS INSIDE THE HEXAGON
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool CHexagon::IsInside(int x1, int y1)const {
	const int vertices = 7;
	int X[vertices];
	int Y[vertices];

	// The Length Of The Hexagone Is 100
	X[0] = Center.x;
	X[1] = Center.x + 86;
	X[2] = Center.x + 86;
	X[3] = Center.x;
	X[4] = Center.x - 86;
	X[5] = Center.x - 86;
	X[6] = Center.x;
	
	Y[0] = Center.y + 100;
	Y[1] = Center.y + 50;
	Y[2] = Center.y - 50;
	Y[3] = Center.y - 100;
	Y[4] = Center.y - 50;
	Y[5] = Center.y + 50;
	Y[6] = Center.y + 100;
	double TotalArea = 0;
	for (int i = 1; i < vertices-2; i++) {
		TotalArea+=TrArea(X[0],Y[0],X[i],Y[i],X[i+1],Y[i+1]);
	}
	double PointArea = 0;
	for (int i = 0; i < vertices-1; i++) {
		PointArea += TrArea(x1, y1, X[i], Y[i], X[i + 1], Y[i + 1]);
	}
	return(abs(TotalArea-PointArea) < DBL_EPSILON);
}

Point CHexagon::MoveFigure(Point move) {
	Point Center2 = Center;
	Center = move;
	return Center2;
}

void CHexagon::save(ofstream& fout)
{
	fout << "HEXAGON" << " \t" << ID << "\t" << Center.x << "\t" << Center.y << "\t";
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

void CHexagon::load(ifstream& fin)
{
	string drawclr, fillclr;
	fin >> ID >> Center.x >> Center.y >> drawclr >> fillclr;
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
