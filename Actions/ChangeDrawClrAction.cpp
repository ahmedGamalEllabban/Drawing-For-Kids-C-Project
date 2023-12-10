#include "ChangeDrawClrAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI/UI_Info.h"
ChangeDrawClrAction::ChangeDrawClrAction(ApplicationManager* pApp, color DC) : Action(pApp)
{
	DrawingClr = DC;
}

void ChangeDrawClrAction::ReadActionParameters()
{
}

void ChangeDrawClrAction::Execute()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetSelectedFigure();
	if (FIG) {
		op->setDrawclr(DrawingClr);
		FIG->ChngDrawClr(DrawingClr);
		FIG->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}

	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		ChangeDrawClrAction* ChangeColorAction = new ChangeDrawClrAction(pManager, DrawingClr);
		*ChangeColorAction = *this;
		pManager->AddActionToRecordingList(ChangeColorAction);
	}

}

void ChangeDrawClrAction::PlayRecording()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetSelectedFigure();
	if (FIG) {
		op->setDrawclr(DrawingClr);
		FIG->ChngDrawClr(DrawingClr);
		FIG->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}
}
