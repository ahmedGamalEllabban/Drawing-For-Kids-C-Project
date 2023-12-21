#include "ChangeFillClrAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
ChangeFillClrAction::ChangeFillClrAction(ApplicationManager* pApp, color FC) :Action(pApp)
{
	FillingClr = FC;
}

void ChangeFillClrAction::ReadActionParameters()
{
}

void ChangeFillClrAction::Execute()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetSelectedFigure();
	if (FIG) {
		IsFilled = op->checkisfilled();
		op->setfilled();
		PrevFillingClr = FIG->getFillColor();
		ID = FIG->GetID();
		op->setFillclr(FillingClr);
		FIG->ChngFillClr(FillingClr);
		FIG->SetSelected(false);
		
		pManager->SetSelectedFigure(NULL);
	}

	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		ChangeFillClrAction* ChangeColorAction = new ChangeFillClrAction(pManager, FillingClr);
		*ChangeColorAction = *this;
		pManager->AddActionToRecordingList(ChangeColorAction);
	}
}

void ChangeFillClrAction::PlayRecording()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetSelectedFigure();
	if (FIG) {
		op->setfilled();
		op->setFillclr(FillingClr);
		FIG->ChngFillClr(FillingClr);
		FIG->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}
	ChangeFillClrAction* ChangeColorAction = new ChangeFillClrAction(pManager, FillingClr);
	*ChangeColorAction = *this;
	pManager->AddToUndoList(ChangeColorAction);
}


void ChangeFillClrAction::Undo()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetFigure(ID);
	if (FIG) {
		if (IsFilled) {
			op->setfilled();
			FIG->ChngFillClr(PrevFillingClr);
		}
		else {
			op->SetNonFilled();
			
			FIG->RemoveFillClr(PrevFillingClr);
		}
		FIG->SetSelected(false);
		op->setFillclr(PrevFillingClr);
		pManager->SetSelectedFigure(NULL);
	}
}

void ChangeFillClrAction::Redo()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetFigure(ID);
	if (FIG) {
		IsFilled = op->checkisfilled();
		op->setfilled();
		PrevFillingClr = FIG->getFillColor();
		ID = FIG->GetID();
		op->setFillclr(FillingClr);
		FIG->ChngFillClr(FillingClr);
		FIG->SetSelected(false);

		pManager->SetSelectedFigure(NULL);
	}
}


bool ChangeFillClrAction::CanUndo()
{
	return true;
}

