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
<<<<<<< HEAD
	pManager->DeleteAllFigures();

=======
	pManager->DeleteAllFigures(); //Delete All Figures From FigList
>>>>>>> e7101e7f2697d47d05ef78ebc2de079f97f729ee
	pManager->DeleteRedoList();

	pManager->DeleteUndoList();

	pManager->DeleteAllRecordedActions();
<<<<<<< HEAD

	// resets the drawing style to nonfilled
	pManager->GetOutput()->SetNonFilled();

	pManager->GetOutput()->setDrawclr(BLUE);

	// Stops Recording if enabled
=======
	pManager->GetOutput()->SetNonFilled(); //Set Nonfilled By Default
	pManager->GetOutput()->setDrawclr(BLUE);//Set The Drawing Color BLUE By Default
>>>>>>> e7101e7f2697d47d05ef78ebc2de079f97f729ee
	pManager->SetRecordingStatus(false);

	pManager->SetSelectedFigure(NULL);

	if (pManager->IsPlayingRecord()) {
	pManager->GetOutput()->PrintMessage("The Application Has Been Reset And Playing Record Started");
	}
	else {
		pManager->GetOutput()->PrintMessage("The Application Has Been Reset");
	}
}
