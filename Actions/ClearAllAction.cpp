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
	pManager->DeleteAllFigures();
	pManager->DeleteAllRecordedActions();
	pManager->DeleteRedoList();
	pManager->DeleteUndoList();
	pManager->GetOutput()->SetNonFilled();
	pManager->GetOutput()->setDrawclr(BLUE);
	pManager->SetRecordingStatus(false);
	pManager->GetOutput()->PrintMessage("The Application Has Been Reset");
}
