#include "playByColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"
#include "..\Figures\CFigure.h"
#include "time.h"

playByColorAction::playByColorAction(ApplicationManager* app) :Action(app)
{
	numOfShapes = pManager->getFigCount();
	correct = 0;
	wrong = 0;
	blackCount = yellowCount = orangeCount = redCount = greenCount = blueCount = 0;
	pManager->getColorsCount(blackCount, yellowCount, orangeCount, redCount, greenCount, blackCount);

}

void playByColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Playing Pick and hide By Color ");

	pOut->ClearPickHideToolBar();

	randColor = pManager->getRandomColor();

	startGame();

	pOut->ClearDrawArea();

	pOut->PrintMessage("Game Ended. Final Results -----> Correct: " + to_string(correct) + "  " + "Wrong: " + to_string(wrong));
}

void playByColorAction::Execute()
{
	ReadActionParameters();
}

void playByColorAction::startGame()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int count = 0;

	pManager->createPlayArea();

	if (randColor == BLACK) {
		pOut->PrintMessage("Select all Black shapes :) ");
		count = blackCount;
	}
	else if (randColor == YELLOW) {
		pOut->PrintMessage("Select all Yellow shapes :) ");
		count = yellowCount;
	}
	else if (randColor == ORANGE) {
		pOut->PrintMessage("Select all Orange shapes :) ");
		count = orangeCount;
	}
	else if (randColor == RED) {
		pOut->PrintMessage("Select all RED shapes :) ");
		count = redCount;
	}
	else if (randColor == GREEN) {
		pOut->PrintMessage("Select all Green shapes :) ");
		count = greenCount;
	}
	else if (randColor == BLUE) {
		pOut->PrintMessage("Select all Blue shapes :) ");
		count = blueCount;
	}

	while (numOfShapes > 0)
	{
		pIn->GetPointClicked(p.x, p.y);

		if (pManager->GetFigure(p.x, p.y) == NULL) continue;

		else numOfShapes--;

		if (randColor == pManager->GetFigure(p.x, p.y)->getFillColor()) {
			correct++;
			if (correct == count) break;
		}

		else wrong++;

		pManager->deleteChosenFig(p);

		pOut->PrintMessage("Correct: " + to_string(correct) + "\t" + "Wrong: " + to_string(wrong));

	}



}
