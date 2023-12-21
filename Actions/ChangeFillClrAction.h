#pragma once
#include "Action.h"
class ChangeFillClrAction :public Action
{
	GfxInfo FillingClr, PrevFillingClr;
	GfxInfo PrevDefault;
	int ID;
public:
	ChangeFillClrAction(ApplicationManager* pApp, color FC);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRecording();
	virtual void Undo();
	virtual void Redo();
	virtual bool CanUndo();
};

