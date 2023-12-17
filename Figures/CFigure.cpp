#include "CFigure.h"

CFigure::CFigure()
{
}

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::RemoveFillClr(color PrevClr)
{
	FigGfxInfo.isFilled = false;
	FigGfxInfo.FillClr = PrevClr;
}

color CFigure::getFillColor()
{
	return FigGfxInfo.FillClr;
}

void CFigure::SetID(int id)
{
	ID = id;
}

int CFigure::GetID() const
{
	return ID;
}

