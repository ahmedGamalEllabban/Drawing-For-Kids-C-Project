#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp):Action(pApp)
{
	CanDraw = true;
}

void AddSquareAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at a Point to draw");

	pIn->GetPointClicked(Center.x, Center.y);

	if (Center.y - 50 < UI.ToolBarHeight + UI.ToolBarBorderWidth || Center.y + 50 > UI.height - UI.StatusBarHeight)
		CanDraw = false;

	SquareGfxInfo.isFilled = pOut->checkisfilled(); // default is not filled

	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	ReadActionParameters();

	if (CanDraw) {


	CSquare* S = new CSquare(Center, SquareGfxInfo);

	pManager->AddFigure(S);
	ID = S->GetID();
	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		AddSquareAction* addAction = new AddSquareAction(pManager);
		*addAction = *this;
		pManager->AddActionToRecordingList(addAction);
	}

	
	pManager->DeleteRedoList();
	}
	else {
		pManager->GetOutput()->PrintMessage("You Can't Draw On Any Bar");
	}
}

void AddSquareAction::Undo()
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

void AddSquareAction::Redo()
{
	CSquare* S = new CSquare(Center, SquareGfxInfo);

	pManager->AddFigure(S);
	 S->SetID(ID);

}

void AddSquareAction::PlayRecording()
{
	CSquare* S = new CSquare(Center, SquareGfxInfo);

	pManager->AddFigure(S);
	ID = S->GetID();
	AddSquareAction* addAction = new AddSquareAction(pManager);
	*addAction = *this;
	pManager->AddToUndoList(addAction);
	pManager->DeleteRedoList();
}
