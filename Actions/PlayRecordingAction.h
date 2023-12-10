#pragma once
#include "Action.h"
class PlayRecordingAction :
	public Action
{
	bool CanPlay;
public:
	PlayRecordingAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};

