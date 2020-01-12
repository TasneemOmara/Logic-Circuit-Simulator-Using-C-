#include "../Actions/Simulate.h"
#include "../ApplicationManager.h"

using namespace std;

Simulate::Simulate(ApplicationManager* pApp) :Action(pApp)
{
	
}

void Simulate::Execute()
{
	/*
	Implementation Steps
	1. Check Validity of the circuit
	2. AppMode ----> Simulation  ---> create simulation toolbar
	*/
	int CompCount = pManager->getCompCount();
	Component** CompList = pManager->GetComponentList();
	UI* pUI = pManager->GetUI();

	//loop for connection
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->is_Connection())
		{
			CompList[i]->Operate();

		}
		// CompList[i]-> get_connect_state()  ; // a getter to check the connection of each component
	}

	//loop for components
	for (int i = 0; i < CompCount; i++)
	{
		if (!CompList[i]->is_Connection())
		{
			CompList[i]->Operate();

		}
		// CompList[i]-> get_connect_state()  ; // a getter to check the connection of each component
	}

	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Operate();

		// CompList[i]-> get_connect_state()  ; // a getter to check the connection of each component
	}

}

void Simulate::Undo()
{}

void Simulate::Redo()
{}
