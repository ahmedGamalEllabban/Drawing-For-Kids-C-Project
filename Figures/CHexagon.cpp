#include "CHexagon.h"
#include <fstream>
CHexagon::CHexagon()
{
}
CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo, int l) :CFigure(FigureGfxInfo)
{
	Center = P;
	length = l;
}


void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexa(Center, FigGfxInfo, Selected, length);
}
double TrArea(int x1, int y1, int x2, int y2, int x3, int y3)//REQUIRED TO COMPUTE WHETHER THE POINT IS INSIDE THE HEXAGON
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}
bool CHexagon::IsInside(int x1, int y1)const {
	const int vertices = 7;
	int X[vertices];
	int Y[vertices];

	X[0] = Center.x;
	X[1] = Center.x + length * 0.866;
	X[2] = Center.x + length * 0.866;
	X[3] = Center.x;
	X[4] = Center.x - length * 0.866;
	X[5] = Center.x - length * 0.866;
	X[6] = Center.x;
	
	Y[0] = Center.y + length;
	Y[1] = Center.y + length / 2;
	Y[2] = Center.y - length / 2;
	Y[3] = Center.y - length;
	Y[4] = Center.y - length / 2;
	Y[5] = Center.y + length / 2 ;
	Y[6] = Center.y + length;
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
	if (move.y - length < UI.ToolBarHeight + UI.ToolBarBorderWidth || move.y + length > UI.height - UI.StatusBarHeight) {
		Point Temp;
		Temp.x = -1;
		Temp.y = -1;
		return Temp;
	}
	else {
		Center = move;
		return Center2;
	}
}

void CHexagon::save(ofstream& fout)
{
	fout << "HEXAGON" << " \t" << ID << "\t" << Center.x << "\t" << Center.y << "\t" << length << "\t";
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
	int len;
	fin >> ID >> Center.x >> Center.y >> len >> drawclr >> fillclr;
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

void CHexagon::Resize(Point)
{
}

void CHexagon::DistanceFromCenter(Point P, double& DIFFx, double& DIFFy)
{
	DIFFx = Center.x - P.x;
	DIFFy = Center.y - P.y;
}

void CHexagon::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Sleceted A Hexagon, ID: " + to_string(ID) + " | Center Point : (" + to_string(Center.x) + ", " + to_string(Center.y) + ") | Side Length : " + to_string(length));

}
