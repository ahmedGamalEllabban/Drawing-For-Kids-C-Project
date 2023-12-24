#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxRecords = 20};	//Max no of figures
	enum { MaxActionsCount = 5 };
private:
	int FigCount;		//Actual number of figures
	int loopCount;  // ahmed kamal
	int ID;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	bool isPlayMode; // ahmed kamal
	bool isPlaying; // ahmed kamal
	Action* UndoList[MaxActionsCount];
	Action* RedoList[MaxActionsCount];
	int RedoCount;
	int ActionsCount;//Actual Actions in the 
	int RecordedActionsCount;
	Action* RecordingActionList[MaxRecords]; // Array Of Recorded Actions
	bool RecordStarted;
	bool PlayingRecord;

	
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* GetFigure(int id); //Searches for a Figure given its ID
	CFigure* GetSelectedFigure() const;
	void SetSelectedFigure(CFigure*);
	int GetFigureCount() const;
	void DeleteAllFigures();
	void DeleteAllRecordedActions();
	void SetPlayingRecord(bool b);
	bool IsPlayingRecord();
	Action* GetLastAction();
	Action* GetLastAction_Redo();
	void AddToUndoList(Action*);
	void AddToRedoList(Action*);
	void DeleteRedoList();
	void DeleteUndoList();
	void AddActionToRecordingList(Action*);
	Action** GetRecordedActions();
	bool IsRecording(); // Return true if we start recording and false if we didn't
	void SetRecordingStatus(bool s); // Turns On and of recording
	int GetRecordedActionsCount();


	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	int GetSelectedFigureIndex();
	CFigure* DeleteFigure();

	// -- Play Related functions ***** ahmed kamal
	void createPlayArea() const;
	int getFigCount() const;
	CFigure* getRandomFig() const;
	void getShapesCount(int &RC, int& SC, int& CC, int& HC, int& TC) const;
	void getColorsCount(int& BlackC, int& YC, int& OC, int& RC, int& GC, int& BlueC);
	void deleteChosenFig(Point p);
	int countShapeColors(string shape, color c);
	int getFillCount();
	int getNonFillCount();
	color getRandomColor();
	int GetFigCount();
	void Saveall(ofstream& fout);
	
};

#endif