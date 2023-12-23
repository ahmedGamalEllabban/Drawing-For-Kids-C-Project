#pragma once
#include "CFigure.h"
//#include "DEFS.h"
class CCircle :public CFigure
{
	Point center, P2;
public:
	CCircle();
	CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual Point MoveFigure(Point P);
	virtual bool IsInside(int, int) const;
	virtual void save(ofstream& fout);
	virtual void load(ifstream& fin);
};

