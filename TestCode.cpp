#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Drawing all the Figures with all possible states: 
	//			Non-filled, Filled, and highlighted in both cases			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMessage("TEST2: Now we will show that Output class can draw any figure in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GfxInfo gfxInfo;//to be used with draw function of the class Ouput
	Point P1, P2, P3;

	/// 2.1- Rectangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Rectangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	// 2.1.1 - Drawing non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> non-filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawRect(P1, P2, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);


	// 2.1.3 - Drawing a filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> filled,  Click two points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawRect(P1, P2, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled rectangle
	pOut->PrintMessage("Drawing a Rectangle ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->DrawRect(P1, P2, gfxInfo, true);



	pOut->PrintMessage("Drawing a Rectangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.2- Square Test ///
	/// ============== 
	pOut->PrintMessage("Drawing a Square, normal and Highlighted, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Square, Normal and Highlighted


	// 2.1.1 - Drawing non-filled square
	pOut->PrintMessage("Drawing a Square ==> non-filled,  Click The Center Point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawSquare(P1, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(P1, gfxInfo, true);



	// 2.1.3 - Drawing a filled squre
	pOut->PrintMessage("Drawing a Square ==> filled,  Click Center Point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawSquare(P1, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled square
	pOut->PrintMessage("Drawing a Square ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawSquare(P1, gfxInfo, true);

	pOut->PrintMessage("Drawing a Square Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	/// 2.3- Triangle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Triangle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Triangle in all possible states

	//2.3.1 Drawing non-highlighted non-filled triangle
	pOut->PrintMessage("Drawing a traiangle==>non-highlighted non-filled ,click to choose 3 points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);

	//2.3.2 Drawing Hihglighted non-filled triangle
	pOut->PrintMessage("Drawing a traiangle==>Highlighted non-filled ,click to highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	gfxInfo.BorderWdth = 6;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	//2.3.3 Drawing non-highlighted filled triangle
	pOut->PrintMessage("Drawing a traiangle==>non-highlighted Filled ,click to choose 3 points");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->GetPointClicked(P3.x, P3.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.isFilled = true;	//Figure is NOT filled
	gfxInfo.FillClr = GREEN;
	gfxInfo.DrawClr = BLUE;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, false);


	//2.3.4 Drawing highlighted filled triangle
	pOut->PrintMessage("Drawing a traiangle==>Highlighted Filled ,click to highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	gfxInfo.BorderWdth = 6;
	pOut->DrawTriangle(P1, P2, P3, gfxInfo, true);

	pOut->PrintMessage("Drawing a Triangle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.4- Hexagon Test ///
	/// =================== 
	pOut->PrintMessage("Drawing a Hexagon, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Hexagon in all possible states
			// 2.1.1 - Drawing non-filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> non-filled,  Click The Center Point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawHexa(P1, gfxInfo, false);

	// 2.1.2 - Drawing highlighted non-filled Hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted non-filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHexa(P1, gfxInfo, true);



	// 2.1.3 - Drawing a filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> filled,  Click Center Point");
	pIn->GetPointClicked(P1.x, P1.y);

	gfxInfo.BorderWdth = 6;
	gfxInfo.DrawClr = BLUE;	//any color for border
	gfxInfo.FillClr = GREEN;//any color for filling
	gfxInfo.isFilled = true;//Figure is filled
	pOut->DrawHexa(P1, gfxInfo, false);


	// 2.1.4 - Drawing a highlighted filled hexagon
	pOut->PrintMessage("Drawing a Hexagon ==> Highlighted filled, Click to Highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->DrawHexa(P1, gfxInfo, true);



	pOut->PrintMessage("Drawing a Hexagon Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	/// 2.5- Circle Test ///
	/// =================== 
	pOut->PrintMessage("Drawing an Circle, filled/non-filled and Highlighted filled/non-filled,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///TODO: Add code to draw Circle in all possible states

	//2.5.1 Drawing a circle --> non-highlighted non-filled
	pOut->PrintMessage("Drawing a Circle==>non-Highlighted non-Filled , choose the center and any point on the circle");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = false;	//Figure is NOT filled
	pOut->DrawCircle(P1, P2, gfxInfo, false);

	//2.5.2  Drawing a circle -->Highlighted non-filled
	pOut->PrintMessage("Drawing a Circle==>Highlighted non-Filled , click to highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click

	gfxInfo.BorderWdth = 6;

	pOut->DrawCircle(P1, P2, gfxInfo, true);

	//2.5.3  Drawing a circle -->non-Highlighted Filled
	pOut->PrintMessage("Drawing a Circle==>non-Highlighted Filled , choose the center and any point on the circle");
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->GetPointClicked(P2.x, P2.y);
	gfxInfo.BorderWdth = 5;
	gfxInfo.DrawClr = BLACK;	//any color for border
	gfxInfo.isFilled = true;	//Figure is NOT filled
	pOut->DrawCircle(P1, P2, gfxInfo, false);


	//2.5.4  Drawing a circle -->Highlighted and Filled
	pOut->PrintMessage("Drawing a Circle==>Highlighted and Filled , click anyhwere to highlight");
	pIn->GetPointClicked(x, y);	//Wait for any click
	gfxInfo.BorderWdth = 6;
	pOut->DrawCircle(P1, P2, gfxInfo, true);

	pOut->PrintMessage("Drawing a Circle Test ==> OK,  Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();
	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMessage("Testing Input ability to read strings");
	pOut->PrintMessage("You Entered: " + pIn->GetSrting(pOut)+", Click anywhere to continue");// reading a string from the user

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered" then print the string

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: 
	//			Input Class : Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  
	//You must add a case for each action (both Draw mode and Play mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case DRAW_RECT:
				pOut->PrintMessage("Action: Draw a Rectangle , Click anywhere");
				break;

		case DRAW_SQUARE:
			pOut->PrintMessage("Action: Draw a Square , Click anywhere");
			break;

		case DRAW_HEXA:
			pOut->PrintMessage("Action: Draw a Hexagon , Click anywhere");
			break;

		case DRAW_TRIANGLE:
			pOut->PrintMessage("Action: Draw a Triangle , Click anywhere");
			break;

		case DRAW_CIRCLE:
			pOut->PrintMessage("Action: Draw a Circle , Click anywhere");
			break;

		case STATUS:
				pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DRAWING_AREA:
				pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
				break;
		
		case SELECT_SHAPE:
			pOut->PrintMessage("Action: Select one shape, click on the shape you want to select");
			break;
		
		case CHANGE_BORDERCLR:
			pOut->CreateColorlist();
			pOut->PrintMessage("Action: Change Border color, Please select a color From the color list");
			
			break;

		case CHANGE_FILLCLR:
			pOut->CreateColorlist();
			pOut->PrintMessage("Action: Change fill color, Please select a color From the color list");
			
			break;

			// COLORS LIST
		case CHNGCLR_BLACK:
			pOut->PrintMessage("Action: Color changed to Black, Click anywhere");
			pOut->ClearColorListToolBar();
			break;
		
		case CHNGCLR_YELLOW:
			pOut->PrintMessage("Action: Color changed to Yellow, Click anywhere");
			pOut->ClearColorListToolBar();
			break;
		
		case CHNGCLR_ORANGE:
			pOut->PrintMessage("Action: Color changed to Orange, Click anywhere");
			pOut->ClearColorListToolBar();
			break;

		case CHNGCLR_RED:
			pOut->PrintMessage("Action: Color changed to Red, Click anywhere");
			pOut->ClearColorListToolBar();
			break;

		case CHNGCLR_GREEN:
			pOut->PrintMessage("Action: Color changed to Green, Click anywhere");
			pOut->ClearColorListToolBar();
			break;

		case CHNGCLR_BLUE:
			pOut->PrintMessage("Action: Color changed to Blue, Click anywhere");
			pOut->ClearColorListToolBar();
			break;
			////////////////////////////
	
		
		case DELETE_FIGURE:
			pOut->PrintMessage("Action: Delete Figure, Click on the figure you want to delete");
			break;

		
		case MOVE_FIGURE:
			pOut->PrintMessage("Action: Move figure, click on where you want to move the selected figure");
			break;
		
		case UNDO:
			pOut->PrintMessage("Action: Undo, Click anywhere to continue");
			break;

		case REDO:
			pOut->PrintMessage("Action: Redo, Click anywhere to continue");
			break;
			
		case CLEAR_ALL:
			pOut->PrintMessage("Action: CLear all. The drawing area is cleared. Click anywhere to continue");
			break;
		case START_RECORDING:
			pOut->PrintMessage("Action: Start Recording. Recording in progress. CLick anywhere to continue");
			break;
		case STOP_RECORDING:
			pOut->PrintMessage("Action: Recording stopped. CLick anywhere to continue");
			break;
		case PLAY_RECORDING:
			pOut->PrintMessage("Action: Playing the current Recording. CLick anywhere to continue");
			break;
		
		case SAVE_GRAPH:
			pOut->PrintMessage("Action: Save graph, saving the current graph");
			break;
		case LOAD_GRAPH:
			pOut->PrintMessage("Action: Load graph, loading the current graph");
			break;
			//

		case EMPTY:
				pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		
		case TO_DRAW:
				pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
				pOut->ClearPlayToolBar();  
				pOut->CreateDrawToolBar();
				break;

		case TO_PLAY:
				pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
				pOut->ClearDrawToolBar();
				pOut->CreatePlayToolBar();
				break;


		///TODO: Add more cases for the other action types
		// (play mode cases)

		case PickHideGame: 
			pOut->PrintMessage("Action: Pick and hide Game is now runing, Spawning Shapes");
			pOut->CreatePickHideToolBar();
			break;

		case PLAYINGAREA:
			pOut->PrintMessage("Action: A Click on the playing Area, Click anywhere");
			break;

		case PLAYBYCOLOR:
			pOut->PrintMessage("Action: Playing Pick and hide by color, Spawning Shapes");
			pOut->ClearPickHideToolBar();
			break;

		case PLAYBYSHAPE:
			pOut->PrintMessage("Action: Playing Pick and hide by shape , Spawning Shapes");
			pOut->ClearPickHideToolBar();
			break;

		case PLAYBYBOTH:
			pOut->PrintMessage("Action: Playing Pick and hide by both Shape and color, Spawning Shapes");
			pOut->ClearPickHideToolBar();
			break;

		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


