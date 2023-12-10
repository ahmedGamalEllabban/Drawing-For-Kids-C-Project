#pragma once
#include "Action.h"
class playByColorAction: public Action
{

public:

	playByColorAction(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
};

