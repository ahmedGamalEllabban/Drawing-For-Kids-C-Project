#pragma once
#include "CFigure.h"
//#include "DEFS.h"
class CCircle :public CFigure
{
	Point P1, P2;
public:
	CCircle(Point p1, Point p2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual Point MoveFigure(Point P);
	virtual bool IsInside(int, int) const;
};

