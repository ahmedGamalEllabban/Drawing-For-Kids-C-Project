#include "AddCircleAction.h"
#include "Action.h"
#include "../Figures/CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../GUI/UI_Info.h"


AddCircleAction::AddCircleAction(ApplicationManager* pApp):Action(pApp)
{
}

void AddCircleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput(); 
	Input* pIn = pManager->GetInput(); 
	pOut->PrintMessage("New Circle: Click at Center Point");

	//Read center and store in Center
	pIn->GetPointClicked(Center.x, Center.y);

	
	pOut->PrintMessage("Click any point on the Circle");

	//Read another point P2 to calc the radius
	pIn->GetPointClicked(P2.x, P2.y);



	CircleGfxInfo.isFilled = pOut->checkisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();


}

void AddCircleAction::Execute()
{//This action needs to read some parameters first
	ReadActionParameters();


	//Create a Circle with the parameters read from the user
	CCircle* C = new CCircle(Center, P2, CircleGfxInfo);

	//Add the Circle to the list of figures
	pManager->AddFigure(C);
	ID = C->GetID();
	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		AddCircleAction* addAction = new AddCircleAction(pManager);
		*addAction = *this;
		pManager->AddActionToRecordingList(addAction);
	}
	
	pManager->DeleteRedoList();
}

void AddCircleAction::Undo()
{
	CFigure* Fig=pManager->GetFigure(ID);
	CFigure* Fig2 = pManager->GetSelectedFigure();
	if (Fig2) {
		Fig2->SetSelected(false);
	}
	pManager->SetSelectedFigure(Fig);
	pManager->DeleteFigure();
	delete Fig;
	Fig = NULL;
	
}

void AddCircleAction::Redo()
{
	CCircle* C = new CCircle(Center, P2, CircleGfxInfo);
	//Add the Circle to the list of figures
	pManager->AddFigure(C);
	C->SetID(ID);
}

void AddCircleAction::PlayRecording()
{
	CCircle* C = new CCircle(Center, P2, CircleGfxInfo);
	//Add the Circle to the list of figures
	pManager->AddFigure(C);
	ID = C->GetID();

	pManager->DeleteRedoList();

}