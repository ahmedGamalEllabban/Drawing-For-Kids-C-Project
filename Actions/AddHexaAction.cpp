#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center Point");

	//Read center and store in point P
	pIn->GetPointClicked(P.x, P.y);


	HexaGfxInfo.isFilled = pOut->checkisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		AddHexaAction* addAction = new AddHexaAction(pManager);
		*addAction = *this;
		pManager->AddActionToRecordingList(addAction);
	}

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P, HexaGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	ID = H->GetID();
	pManager->DeleteRedoList();
}

void AddHexaAction::Undo()
{
	CFigure* Fig = pManager->GetFigure(ID);
	CFigure* Fig2 = pManager->GetSelectedFigure();
	if (Fig2) {
		Fig2->SetSelected(false);
	}
	pManager->SetSelectedFigure(Fig);
	pManager->DeleteFigure();
	delete Fig;
	Fig = NULL;

}

void AddHexaAction::Redo()
{
	CHexagon* H = new CHexagon(P, HexaGfxInfo);
	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	H->SetID(ID);
}

void AddHexaAction::PlayRecording()
{
	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P, HexaGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	ID = H->GetID();
	pManager->DeleteRedoList();
}
