#include "playByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\GUI\UI_Info.h"
#include "..\Figures\CFigure.h"
#include <ctime>
#include <string>
#include "..\Figures\CSquare.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRectangle.h"



using namespace std;

playByShapeAction::playByShapeAction(ApplicationManager* app) :Action(app)
{
	numOfShapes = pManager->getFigCount();
	correct = 0;
	wrong = 0;
	RectCount = SquareCount = CircleCount = HexCount = TriangleCount = 0;
	pManager->getShapesCount(RectCount, SquareCount, CircleCount, HexCount, TriangleCount);
}

void playByShapeAction::ReadActionParameters()
{
	Shapes randomShape;
	CFigure* shape;

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Playing Pick and hide By Shape ");

	pOut->ClearPickHideToolBar();


	// Enum Values, Square:0 , Rectngle: 1, Hexagon: 2, Circle: 3, Triangle: 4 

	shape = pManager->getRandomFig();

	if (dynamic_cast<CSquare*>(shape)) randomShape = SQUARE;
	else if (dynamic_cast<CRectangle*>(shape)) randomShape = RECTANGLE;
	else if (dynamic_cast<CHexagon*>(shape)) randomShape = HEXAGON;
	else if (dynamic_cast<CCircle*>(shape)) randomShape = CIRCLE;
	else if (dynamic_cast<CTriangle*>(shape)) randomShape = TRIANGLE;

	Sleep(1000);

	switch (randomShape)
	{

	case SQUARE:
		playSquare();
		break;

	case RECTANGLE:
		playRectangle();
		break;

	case HEXAGON:
		playHexagon();
		break;

	case CIRCLE:
		playCircle();
		break;

	case TRIANGLE:
		playTriangle();
		break;

	default:
		break;

	}

	pOut->ClearDrawArea();

	pOut->PrintMessage("Game Ended. Final Result ----> Correct: " + to_string(correct) + "  " + "Wrong: " + to_string(wrong));

}

void playByShapeAction::Execute()
{
	ReadActionParameters();
}

void playByShapeAction::playSquare()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->createPlayArea();

	pOut->PrintMessage("Select All the Squares :) ");


	while (numOfShapes > 0) {

		pIn->GetPointClicked(p.x, p.y);

		if (pManager->GetFigure(p.x, p.y) == NULL) continue;

		else numOfShapes--;

		if (dynamic_cast<CSquare*>(pManager->GetFigure(p.x, p.y))) {
			correct++;
			if (correct == SquareCount) break;
		}

		else wrong++;

		pManager->deleteChosenFig(p);

		pOut->PrintMessage("Correct: " + to_string(correct) + "\t" + "Wrong: " + to_string(wrong));


	}

	pOut->PrintMessage("Game Ended ");
}

void playByShapeAction::playRectangle()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->createPlayArea();

	pOut->PrintMessage("Select All the Rectangles :) ");

	while (numOfShapes > 0) {

		pIn->GetPointClicked(p.x, p.y);

		if (pManager->GetFigure(p.x, p.y) == NULL) continue;

		else numOfShapes--;

		if (dynamic_cast<CRectangle*>(pManager->GetFigure(p.x, p.y))) {
			correct++;
			if (correct == RectCount) break;
		}

		else wrong++;

		pManager->deleteChosenFig(p);

		pOut->PrintMessage("Correct: " + to_string(correct) + "\t" + "Wrong: " + to_string(wrong));
	}

	pOut->PrintMessage("Game Ended ");
}

void playByShapeAction::playHexagon()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->createPlayArea();

	pOut->PrintMessage("Select All the Hexagons :) ");

	while (numOfShapes-- > 0) {

		pIn->GetPointClicked(p.x, p.y);

		if (pManager->GetFigure(p.x, p.y) == NULL) continue;

		else numOfShapes--;

		if (dynamic_cast<CHexagon*>(pManager->GetFigure(p.x, p.y))) {
			correct++;
			if (correct == HexCount) break;
		}

		else wrong++;

		pManager->deleteChosenFig(p);

		pOut->PrintMessage("Correct: " + to_string(correct) + "\t" + "Wrong: " + to_string(wrong));
	}

	pOut->PrintMessage("Game Ended ");
}

void playByShapeAction::playCircle()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->createPlayArea();

	pOut->PrintMessage("Select All the Circles :) ");

	while (numOfShapes > 0) {

		pIn->GetPointClicked(p.x, p.y);

		if (pManager->GetFigure(p.x, p.y) == NULL) continue;

		else numOfShapes--;

		if (dynamic_cast<CCircle*>(pManager->GetFigure(p.x, p.y))) {
			correct++;
			if (correct == CircleCount) break;
		}

		else wrong++;

		pManager->deleteChosenFig(p);

		pOut->PrintMessage("Correct: " + to_string(correct) + "\t" + "Wrong: " + to_string(wrong));
	}

	pOut->PrintMessage("Game Ended ");

}

void playByShapeAction::playTriangle()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->createPlayArea();

	pOut->PrintMessage("Select All the Triangles :) ");

	while (numOfShapes > 0) {

		pIn->GetPointClicked(p.x, p.y);

		if (pManager->GetFigure(p.x, p.y) == NULL) continue;

		else numOfShapes--;

		if (dynamic_cast<CTriangle*>(pManager->GetFigure(p.x, p.y))) {
			correct++;
			if (correct == TriangleCount) break;
		}

		else wrong++;

		pManager->deleteChosenFig(p);

		pOut->PrintMessage("Correct: " + to_string(correct) + "\t" + "Wrong: " + to_string(wrong));
	}

	pOut->PrintMessage("Game Ended ");
}
