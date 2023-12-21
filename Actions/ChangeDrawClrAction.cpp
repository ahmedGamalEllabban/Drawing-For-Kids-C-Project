#include "ChangeDrawClrAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI/UI_Info.h"
ChangeDrawClrAction::ChangeDrawClrAction(ApplicationManager* pApp, color DC) : Action(pApp)
{
	DrawingClr.DrawClr = DC;
}

void ChangeDrawClrAction::ReadActionParameters()
{
}

void ChangeDrawClrAction::Execute()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetSelectedFigure();
	if (FIG) {
		PrevDefault.isFilled = op->checkisfilled();
		PrevDefault.DrawClr = op->getCrntDrawColor();
		PrevDefault.FillClr = op->getCrntFillColor();
		PrevDefault.BorderWdth = op->getCrntPenWidth();
		PrevDrawingClr=FIG->getGfxInfo();
		ID = FIG->GetID();
		op->setDrawclr(DrawingClr.DrawClr);
		FIG->ChngDrawClr(DrawingClr.DrawClr);
		FIG->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}

	// If Recording Is Enabled This Will Add Current Recording To RecordedActionsList
	if (pManager->IsRecording()) {
		ChangeDrawClrAction* ChangeColorAction = new ChangeDrawClrAction(pManager, DrawingClr.DrawClr);
		*ChangeColorAction = *this;
		pManager->AddActionToRecordingList(ChangeColorAction);
	}

}

void ChangeDrawClrAction::PlayRecording()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetSelectedFigure();
	if (FIG) {
		op->setDrawclr(DrawingClr.DrawClr);
		FIG->ChngDrawClr(DrawingClr.DrawClr);
		FIG->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}
	ChangeDrawClrAction* ChangeColorAction = new ChangeDrawClrAction(pManager, DrawingClr.DrawClr);
	*ChangeColorAction = *this;
	pManager->AddToUndoList(ChangeColorAction);
}

bool ChangeDrawClrAction::CanUndo()
{
	return true;
}

void ChangeDrawClrAction::Undo()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetFigure(ID);
	if (FIG) {
		if (PrevDefault.isFilled)
			op->setfilled();
		else
			op->SetNonFilled();
		op->setDrawclr(PrevDrawingClr.DrawClr);
		FIG->SetGfxinfo(PrevDrawingClr);
		FIG->SetSelected(false);

		op->setFillclr(PrevDefault.FillClr);
		op->setDrawclr(PrevDefault.DrawClr);
		pManager->SetSelectedFigure(NULL);
	}
}

void ChangeDrawClrAction::Redo()
{
	Output* op = pManager->GetOutput();
	CFigure* FIG = pManager->GetFigure(ID);
	if (FIG) {
		op->setDrawclr(DrawingClr.DrawClr);
		FIG->ChngDrawClr(DrawingClr.DrawClr);
		FIG->SetSelected(false);
		pManager->SetSelectedFigure(NULL);
	}
}
