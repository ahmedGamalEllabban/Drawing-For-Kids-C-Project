#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool isFilled;
	GfxInfo FigGfxInfo;	//Figure graphis info
	
	/// Add more parameters if needed.

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual bool IsInside(int, int) const = 0;//Ahmed: checks whether a point in inside the figure or not 
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void RemoveFillClr(color PrevClr);
	virtual Point MoveFigure(Point P) = 0;
	GfxInfo getGfxInfo();
	void SetGfxinfo(GfxInfo);
	void SetID(int);
	color getFillColor();
	color getDrawColor();
	int GetID()const;
	void virtual save(ofstream& fout) = 0;
	void virtual load(ifstream& fin) = 0;

	bool getFillStats(); // ahmed kamal
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif