#pragma once
#include "Action.h"

class AddCircleAction :public Action
{
	Point Center, P2;
	GfxInfo CircleGfxInfo;
	bool CanDraw;
	int ID;
public:
	AddCircleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual bool CanUndo() { return CanDraw; }
	virtual void PlayRecording();
};

