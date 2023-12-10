#pragma once
#include "Action.h"

class AddSquareAction : public Action
{
	Point Center;
	GfxInfo SquareGfxInfo;
	int ID;

public:
	AddSquareAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual bool CanUndo() { return true; }
	virtual void PlayRecording();


};

