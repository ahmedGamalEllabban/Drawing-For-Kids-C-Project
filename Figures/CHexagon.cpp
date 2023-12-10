#include "CHexagon.h"
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