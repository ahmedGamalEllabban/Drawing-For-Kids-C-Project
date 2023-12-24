#pragma once
#include "CFigure.h"

class CSquare : public CFigure
{
	Point Center;
	int length;
public:
	CSquare();
	CSquare(Point p, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int) const;
	virtual Point MoveFigure(Point P);
	virtual void save(ofstream& fout);
	virtual void load(ifstream& fin);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

