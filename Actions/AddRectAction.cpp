#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = pOut->checkisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	ID = R->GetID();
	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		AddRectAction* addAction = new AddRectAction(pManager);
		*addAction = *this;
		pManager->AddActionToRecordingList(addAction);
	}
	
	pManager->DeleteRedoList();
}

void AddRectAction::Undo()
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

void AddRectAction::Redo()
{
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	 R->SetID(ID);
}

void AddRectAction::PlayRecording()
{
	//Create a rectangle with the parameters read from the user
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	ID = R->GetID();
	pManager->DeleteRedoList();
}
