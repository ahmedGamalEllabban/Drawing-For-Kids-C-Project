#include "SaveAction.h"
#include "../GUI/Input.h"
#include <fstream>
#include "../GUI/UI_Info.h"
#include "../DEFS.h"
#include "../ApplicationManager.h"


SaveAction::SaveAction(ApplicationManager* pApp):Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Input* pIn;
	Output* pOut; 
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	pOut->PrintMessage("plese enter the file name to save in: ");
	File_Name=pIn->GetSrting(pOut);
}

void SaveAction::Execute()
{
	Input* pIn;
	Output* pOut;
	pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	color CDrawClr = pOut->getCrntDrawColor();
	color CFillClr = pOut->getCrntFillColor();
	ReadActionParameters();
	ofstream Fout(File_Name+".txt");
	if (CDrawClr == BLACK) Fout << "BLACK\t";
	else if (CDrawClr == RED) Fout << "RED\t";
	else if (CDrawClr == BLUE) Fout << "BLUE\t";
	else if (CDrawClr == GREEN) Fout << "GREEN\t";
	else if (CDrawClr == YELLOW) Fout << "YELLOW\t";
	else if (CDrawClr == ORANGE) Fout << "ORANGE\t";
	if (pOut->checkisfilled()) {
		if (CFillClr == BLACK) Fout << "BLACK\n";
		else if (CFillClr == RED) Fout << "RED\n";
		else if (CFillClr == BLUE) Fout << "BLUE\n";
		else if (CFillClr == GREEN) Fout << "GREEN\n";
		else if (CFillClr == YELLOW) Fout << "YELLOW\n";
		else if (CFillClr == ORANGE) Fout << "ORANGE\n";
	}
	else Fout << "NOT_FILLED\n";
	


	Fout << pManager->GetFigCount()<<endl;
	pManager->Saveall(Fout);
	Fout.close();
}
