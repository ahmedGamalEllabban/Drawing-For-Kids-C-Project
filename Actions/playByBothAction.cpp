#include "playByBothAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"
#include "..\Figures\CFigure.h"

playByBothAction::playByBothAction(ApplicationManager* app):Action(app)
{
}

void playByBothAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Playing Pick and hide By Both Shape and Color ");
	pOut->ClearPickHideToolBar();

	pManager->createPlayArea();

}

void playByBothAction::Execute()
{
	ReadActionParameters();
}
