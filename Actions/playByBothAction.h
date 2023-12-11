#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"

class playByBothAction: public Action
{
	Point p;
	int correct, wrong, numOfShapes, count;
	int Rects[6], Squares[6], Circles[6], Hexas[6], Triangles[6];

	// indexing  0: Black, 1: Yellow, 2: Red, 3: Orange, 4: Green, 5: Blue  ---------------*

	CFigure* randShape;
	color randColor;


public: 
	playByBothAction(ApplicationManager* app);
	virtual void ReadActionParameters();
	virtual void Execute();
	void playSquare();
	void playRectangle();
	void playHexagon();
	void playCircle();
	void playTriangle();
};

