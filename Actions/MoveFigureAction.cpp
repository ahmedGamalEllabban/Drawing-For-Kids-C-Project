#include "MoveFigureAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
MoveFigureAction::MoveFigureAction(ApplicationManager* pApp) : Action(pApp) {
	IsReady = true;
}
void MoveFigureAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Move Figure: Click at New Place");

	//Read center and store in point P
	pIn->GetPointClicked(P.x, P.y);
	if (P.y > UI.ToolBarHeight + UI.ToolBarBorderWidth && P.y < UI.height - UI.StatusBarHeight) {
		pOut->ClearStatusBar();
	}
	else {
		IsReady = false;
	}
}

void MoveFigureAction::Execute() {
	ReadActionParameters();


	CFigure* figure = pManager->GetSelectedFigure();
	if (figure) {
		figure->SetSelected(false);
		PB = figure->MoveFigure(P);
		if (PB.y != -1) {
			ID = figure->GetID();
			pManager->DeleteRedoList();
			pManager->SetSelectedFigure(NULL);
		} else {
			IsReady = false;
			pManager->SetSelectedFigure(NULL);
			pManager->GetOutput()->PrintMessage("You Can't Move This Figure Over Any Bar");
		}
		// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
		if (pManager->IsRecording()) {
			MoveFigureAction* mAction = new MoveFigureAction(pManager);
			*mAction = *this;
			pManager->AddActionToRecordingList(mAction);
		}
	}
}

void MoveFigureAction::Undo()
{
	CFigure* Fig = pManager->GetFigure(ID);
	CFigure* Fig2 = pManager->GetSelectedFigure();
	if (Fig2) {
		Fig2->SetSelected(false);
	}
	Fig->MoveFigure(PB);

}

void MoveFigureAction::Redo()
{
	CFigure* figure = pManager->GetFigure(ID);
	figure->SetSelected(false);
	figure->MoveFigure(P);

}

void MoveFigureAction::PlayRecording()
{
	CFigure* figure = pManager->GetSelectedFigure();
	if (figure) {
		figure->SetSelected(false);
		PB = figure->MoveFigure(P);
		ID = figure->GetID();
		MoveFigureAction* mAction = new MoveFigureAction(pManager);
		*mAction = *this;
		pManager->AddToUndoList(mAction);
		pManager->DeleteRedoList();
	}
}
