#include "ClearAllAction.h"
#include "..\ApplicationManager.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ClearAllAction::ReadActionParameters()
{
}

void ClearAllAction::Execute()
{
	pManager->DeleteAllFigures(); //Delete All Figures From FigList
	pManager->DeleteRedoList();
	pManager->DeleteUndoList();
	pManager->DeleteAllRecordedActions();
	pManager->GetOutput()->SetNonFilled(); //Set Nonfilled By Default
	pManager->GetOutput()->setDrawclr(BLUE);//Set The Drawing Color BLUE By Default
	pManager->SetRecordingStatus(false);
	pManager->SetSelectedFigure(NULL);
	if (pManager->IsPlayingRecord()) {
	pManager->GetOutput()->PrintMessage("The Application Has Been Reset And Playing Record Started");
	}
	else {
		pManager->GetOutput()->PrintMessage("The Application Has Been Reset");
	}
}
