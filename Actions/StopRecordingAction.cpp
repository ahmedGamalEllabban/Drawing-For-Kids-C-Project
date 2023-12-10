#include "StopRecordingAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) : Action(pApp) {}

void StopRecordingAction::ReadActionParameters()
{
	//Get a Pointer to Output Interface
	Output* pOut = pManager->GetOutput();

	if (pManager->IsRecording()) {
		pOut->PrintMessage("Record Have Stopped");
		pManager->SetRecordingStatus(false);
	}
	else {
		pOut->PrintMessage("You Didn't Start Record Yet");
	}

}


void StopRecordingAction::Execute()
{
	ReadActionParameters();
}

