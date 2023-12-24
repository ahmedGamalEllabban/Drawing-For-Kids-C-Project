#include "ResizeAction.h"
#include "Action.h"
#include "../Figures/CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include "../GUI/UI_Info.h"
ResizeAction::ResizeAction(ApplicationManager* pApp):Action(pApp)
{
	IsDone = true;
}

void ResizeAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Click on the vertex of the figure you want to resize");
	//Read the point and stores it in p
	pIn->GetPointClicked(P.x, P.y);
	if (P.y <= UI.ToolBarHeight + UI.ToolBarBorderWidth && P.y >= UI.height - UI.StatusBarHeight)
		IsDone = false;
}

void ResizeAction::Execute()
{
	ReadActionParameters();
	if (IsDone) {
		CFigure* FIG = pManager->GetFigure(P.x, P.y);
		if (FIG) {
			Input* pIn = pManager->GetInput();
			ID = FIG->GetID();
			Point pTemp;
			while (pIn->GetMouseClick(pTemp.x,pTemp.y)==NO_CLICK) {
				pIn->GetMouseCoordinates(pTemp.x,pTemp.y);
				FIG->Resize(pTemp);
				Pause(10);
				pManager->UpdateInterface();
			}
			P2 = pTemp;
		}
		else
			IsDone = false;

	}
}

bool ResizeAction::CanUndo()
{
	return IsDone;
}

void ResizeAction::Undo()
{
	CFigure* FIG = pManager->GetFigure(ID);
	if (FIG) {
		FIG->Resize(P);
	}
}

void ResizeAction::Redo()
{
	CFigure* FIG = pManager->GetFigure(ID);
	if (FIG) {
		FIG->Resize(P2);
	}
}

void ResizeAction::PlayRecording()
{
	CFigure* figure = pManager->GetFigure(ID);
	if (figure) {
		ResizeAction* ReAction = new ResizeAction(pManager);
		*ReAction = *this;
		pManager->AddToUndoList(ReAction);
		pManager->DeleteRedoList();
	}
}
