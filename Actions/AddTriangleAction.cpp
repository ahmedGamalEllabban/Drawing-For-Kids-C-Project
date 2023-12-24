#include "AddTriangleAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
AddTriangleAction::AddTriangleAction(ApplicationManager *pApp): Action(pApp)
{
	CanDraw = true;
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	int MinY = 0;
	int MaxY = 0;

	MaxY = P1.y;
	MinY = P1.y;
	if (P1.y > P2.y) {
		if (P1.y > P3.y) {
			MaxY = P1.y;
		}
		else {
			MaxY = P3.y;
		}
		if (P2.y < P3.y) {
			MinY = P2.y;
		}
		else {
			MinY = P3.y;
		}
	}
	else {
		if (P2.y > P3.y) {
			MaxY = P2.y;
		}
		else {
			MaxY = P3.y;
		}
		if (P1.y < P3.y) {
			MinY = P1.y;
		}
		else {
			MinY = P3.y;
		}
	}

	if (MinY < UI.ToolBarHeight + UI.ToolBarBorderWidth || MaxY > UI.height - UI.StatusBarHeight) {
		CanDraw = false;
	}

	TriangleGfxInfo.isFilled = pOut->checkisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}
void AddTriangleAction::Execute() {
	//This action needs to read some parameters first
	ReadActionParameters();

	if (CanDraw) {

		//Create a rectangle with the parameters read from the user
		CTriangle* T = new CTriangle(P1, P2, P3, TriangleGfxInfo);

		//Add the Triangle to the list of figures
		pManager->AddFigure(T);
		ID = T->GetID();
		// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
		if (pManager->IsRecording()) {
			AddTriangleAction* addAction = new AddTriangleAction(pManager);
			*addAction = *this;
			pManager->AddActionToRecordingList(addAction);
		}
		pManager->DeleteRedoList();
	} else {
		pManager->GetOutput()->PrintMessage("You Can't Draw On Any Bar");
	}
}

void AddTriangleAction::Undo()
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

void AddTriangleAction::Redo()
{
	CTriangle* T = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
	 T->SetID(ID);

}

void AddTriangleAction::PlayRecording()
{
	//Create a rectangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriangleGfxInfo);

	//Add the Triangle to the list of figures
	pManager->AddFigure(T);
	ID = T->GetID();
	AddTriangleAction* addAction = new AddTriangleAction(pManager);
	*addAction = *this;
	pManager->AddToUndoList(addAction);
	pManager->DeleteRedoList();
}
