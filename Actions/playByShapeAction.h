#pragma once
#include "Action.h"
class playByShapeAction : public Action
{
	int correct, wrong, numOfShapes;
	int RectCount, SquareCount, HexCount, TriangleCount, CircleCount;
	Point p;

	enum Shapes
	{
		SQUARE,
		RECTANGLE,
		HEXAGON,
		CIRCLE,
		TRIANGLE,
		COUNT
	};

public :
	playByShapeAction(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
	void playSquare();
	void playRectangle();
	void playHexagon();
	void playCircle();
	void playTriangle();
};

