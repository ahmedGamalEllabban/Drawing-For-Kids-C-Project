#include "CCircle.h"

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