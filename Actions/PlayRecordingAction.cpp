#include "PlayRecordingAction.h"
#include "ClearAllAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"

PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApp) : Action(pApp) { CanPlay = false; }

void PlayRecordingAction::ReadActionParameters()
{
	//Get a Pointer to Output Interface
	Output* pOut = pManager->GetOutput();
	if (pManager->GetRecordedActionsCount() == 0) {
	pOut->PrintMessage("There Is No Records To Play");
	}
	else if (pManager->IsRecording()) {
		pOut->PrintMessage("You Can't Play Record While Recording");
	}
	else if (!pManager->IsRecording() && pManager->GetRecordedActionsCount() > 0) {
		CanPlay = true;
		pOut->PrintMessage("Start Record Playing");
	}
}

void PlayRecordingAction::Execute()
{
	ReadActionParameters();
	if (CanPlay) {
	pManager->SetPlayingRecord(true);
	ClearAllAction clearAll(pManager);
	Action** RecordedActions = pManager->GetRecordedActions();
	clearAll.Execute();
	Pause(1000);
		for (int i = 0; i < pManager->GetRecordedActionsCount(); i++) {
			if (RecordedActions[i] != NULL) {
			RecordedActions[i]->PlayRecording();
			//pManager->AddToUndoList(RecordedActions[i]);
			pManager->UpdateInterface();
			Pause(1000);
			}

		}
	pManager->GetOutput()->PrintMessage("Record Have Ended");
	pManager->SetPlayingRecord(false);
	}
}


