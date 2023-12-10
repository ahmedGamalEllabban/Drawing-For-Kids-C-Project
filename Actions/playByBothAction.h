#pragma once
#include "Action.h"
class playByBothAction: public Action
{

public: 
	playByBothAction(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
};

