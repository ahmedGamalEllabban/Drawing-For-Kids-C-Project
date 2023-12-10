#include "playByColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"
#include "..\Figures\CFigure.h"

playByColorAction::playByColorAction(ApplicationManager* app):Action(app)
{
}

void playByColorAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Playing Pick and hide By Color ");
	pOut->ClearPickHideToolBar();

	pManager->createPlayArea();

}

void playByColorAction::Execute()
{
	ReadActionParameters();
}
