#pragma once
#include "Action.h"
class ChangeFillClrAction :public Action
{
	color FillingClr;
public:
	ChangeFillClrAction(ApplicationManager* pApp, color FC);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void PlayRecording();

};

