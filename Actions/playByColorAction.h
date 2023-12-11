#pragma once
#include "Action.h"
class playByColorAction : public Action
{
	int correct, wrong, numOfShapes;
	int blackCount, yellowCount, orangeCount, redCount, greenCount, blueCount;
	Point p;
	color randColor;


public:

	playByColorAction(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
	void startGame();
	virtual bool CanUndo() { return false; }
	virtual void Undo() {}
	virtual void Redo() {}

};


