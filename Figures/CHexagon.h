#pragma once
#include "CFigure.h"
class CHexagon :
    public CFigure
{
private:
	Point Center;
	int length;
public:
	CHexagon();
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsInside(int, int)const;
	virtual Point MoveFigure(Point P);
	virtual void save(ofstream& fout);
	virtual void load(ifstream& fin);
	virtual void Resize(Point);

	virtual void DistanceFromCenter(Point, double &DIFFx, double& DIFFy);

	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

};

