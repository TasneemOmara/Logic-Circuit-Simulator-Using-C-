#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "UI\UI.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include <fstream>
#include <iostream>
using namespace std;

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };

private:
	int CompCount;		//Actual number of Components

	Component* CopiedComp;		// Pointer to the last copied/cut component

	int GatesCount;      //gates number of components
	int ConnecCount;    //connections number of components

	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	UI* pUI; //pointer to the UI



public:

	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to UI Object
	UI* GetUI();

	void SetCopiedComp(Component* pComp);
                                
Component* GetCopiedComp() const;

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//getter for the component list and the count
	int getCompCount() const;
	Component** GetComponentList();

	// getting the components and the connections number
	int getGatesCount() const;
	int getConnectCount() const;

	//destructor
	~ApplicationManager();
};

#endif