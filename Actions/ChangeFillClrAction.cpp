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
		op->setfilled();
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
}

