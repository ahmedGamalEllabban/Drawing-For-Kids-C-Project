#pragma once
#include "Action.h"
class MoveFigureAction :
    public Action
{
	Point P,PB;
	int ID;
public:
	MoveFigureAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual bool CanUndo() { return true; }
	virtual void PlayRecording();

};

