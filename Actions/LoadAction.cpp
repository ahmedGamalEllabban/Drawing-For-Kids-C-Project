#include "LoadAction.h"
#include "ClearAllAction.h"
#include <string>
#include <fstream>
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
#include "../ApplicationManager.h"




LoadAction::LoadAction(ApplicationManager* pApp): Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{ 
	Input* pIn;
	Output* pOut;
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	pOut->PrintMessage("plese enter the File Name to load from: ");
	FileName = pIn->GetSrting(pOut);
}

void LoadAction::Execute()
{
	ReadActionParameters();
	ClearAllAction CA(pManager);
	CA.Execute();
	int figsnumber;
	Input* pIn;
	Output* pOut;
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	ifstream Fin;
	Fin.open(FileName+".txt");
	

	string CDrawClr, CFillClr,type;

	if (Fin.is_open()) {
		Fin >> CDrawClr >> CFillClr;
		if (CDrawClr == "BLACK") pOut->setDrawclr(BLACK);
		else if (CDrawClr == "RED") pOut->setDrawclr(RED);
		else if (CDrawClr == "BLUE") pOut->setDrawclr(BLUE);
		else if (CDrawClr == "ORANGE") pOut->setDrawclr(ORANGE);
		else if (CDrawClr == "YELLOW") pOut->setDrawclr(YELLOW);
		else if (CDrawClr == "GREEN") pOut->setDrawclr(GREEN);
		if (CFillClr == "NOT_FILLED") pOut->SetNonFilled();
		else if (CFillClr == "BLACK") pOut->setFillclr(BLACK);
		else if (CFillClr == "RED") pOut->setFillclr(RED);
		else if (CFillClr == "BLUE") pOut->setFillclr(BLUE);
		else if (CFillClr == "ORANGE") pOut->setFillclr(ORANGE);
		else if (CFillClr == "YELLOW") pOut->setFillclr(YELLOW);
		else if (CFillClr == "GREEN") pOut->setFillclr(GREEN);
		Fin >> figsnumber;
		CFigure* myfig = NULL;
		for (int i = 0; i < figsnumber; i++) {
			Fin >> type;
			if (type == "RECT") { myfig = new CRectangle; }
			else if (type == "SQUARE") { myfig = new CSquare; }
			else if (type == "HEXAGON") { myfig = new CHexagon; }
			else if (type == "TRIANGLE") { myfig = new CTriangle; }
			else if (type == "CIRCLE") { myfig = new CCircle; }
			else continue;
			myfig->load(Fin);
			pManager->AddFigure(myfig);
			myfig->SetSelected(false);

		}

		Fin.close();

	}
	
	

}

