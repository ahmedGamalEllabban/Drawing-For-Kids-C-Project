#pragma once
#include "Action.h"
class AddTriangleAction :
    public Action
{
private: Point P1, P2, P3;
       GfxInfo TriangleGfxInfo;
	   int ID;
	   bool CanDraw;
public:
    AddTriangleAction(ApplicationManager*);
	//Reads Triangle parameters
	virtual void ReadActionParameters();

	//Add Triangle to the ApplicationManager
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	virtual bool CanUndo() { return CanDraw; }
	virtual void PlayRecording();


};

