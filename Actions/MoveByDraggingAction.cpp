#include "MoveByDraggingAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"

MoveByDraggingAction::MoveByDraggingAction(ApplicationManager* pApp):Action(pApp)
{
	IsReady = true;
}

void MoveByDraggingAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on a point inside the Figure you want to move");
	//Read the point and stores it in p
	pIn->GetPointClicked(P.x, P.y);
	if (P.y <= UI.ToolBarHeight + UI.ToolBarBorderWidth && P.y >= UI.height - UI.StatusBarHeight)
		IsReady = false;
}

void MoveByDraggingAction::Execute()
{
	ReadActionParameters();
	if (IsReady) {
		CFigure* FIG = pManager->GetFigure(P.x, P.y);
		if (FIG) {
			Input* pIn = pManager->GetInput();
			ID = FIG->GetID();
			Point pTemp;
			Point CTemp;
			double xDIFF, yDIFF;
			FIG->DistanceFromCenter(P, xDIFF, yDIFF);
			PB.x = P.x + xDIFF;
			PB.y = P.y + yDIFF;
			while (pIn->GetMouseClick(pTemp.x, pTemp.y) == NO_CLICK) {
				pIn->GetMouseCoordinates(pTemp.x, pTemp.y);
				CTemp.x = pTemp.x + xDIFF;
				CTemp.y = pTemp.y + yDIFF;
				FIG->MoveFigure(CTemp);
				Pause(10);
				pManager->UpdateInterface();
			}
			P = CTemp;
			if (pManager->IsRecording()) {
				MoveByDraggingAction* mAction = new MoveByDraggingAction(pManager);
				*mAction = *this;
				pManager->AddActionToRecordingList(mAction);
			}
		}
		else
			IsReady = false;

	}
}

void MoveByDraggingAction::Undo()
{
	CFigure* Fig = pManager->GetFigure(ID);
	
	Fig->MoveFigure(PB);
}

void MoveByDraggingAction::Redo()
{
	CFigure* figure = pManager->GetFigure(ID);

	figure->MoveFigure(P);
}

void MoveByDraggingAction::PlayRecording()
{
	// Gets The Last Point And Moves To It In While Playing The Record
	CFigure* figure = pManager->GetFigure(ID);
	if (figure) {
		PB = figure->MoveFigure(P);
		ID = figure->GetID();
		MoveByDraggingAction* mAction = new MoveByDraggingAction(pManager);
		*mAction = *this;
		pManager->AddToUndoList(mAction);
		pManager->DeleteRedoList();
	}
}
