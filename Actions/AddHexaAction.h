#pragma once
#include "Action.h"
class AddHexaAction :
    public Action
{
private:
	Point P;
	GfxInfo HexaGfxInfo;
	int ID;
public:
	AddHexaAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual bool CanUndo() { return true; }
	virtual void PlayRecording();


};

