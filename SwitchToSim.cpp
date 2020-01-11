#include "Actions/SwitchToSim.h"
#include "ApplicationManager.h"

using namespace std;

SwitchToSim::SwitchToSim(ApplicationManager* pApp) :Action(pApp)
{
	flag_c = 0;
}

void SwitchToSim ::Execute ()
{
	/*
	Implementation Steps
	1. Check Validity of the circuit
	2. AppMode ----> Simulation  ---> create simulation toolbar
	*/
	int CompCount = pManager->getCompCount() ;
	Component **CompList = pManager->GetComponentList();
	UI* pUI = pManager->GetUI();

	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->Operate();

		if (CompList[i]->get_connect_state() == false)
		{
				pUI->PrintMsg("One or more of the pins is not connected, please, recheck the pins and try again");
				flag_c = 1; // raise a flag that there are unconnected pins
				break;
		}
		
		// CompList[i]-> get_connect_state()  ; // a getter to check the connection of each component
	}
	if (flag_c == 0)
	{
		pManager->ExecuteAction(SAVE);
		pUI->ClearDesignToolBar();
		pUI->ClearStatusBar();
		pUI->ClearDrawingArea();
		pUI->CreateSimulationToolBar();
		pManager->ExecuteAction(LOAD);

	}
}

void SwitchToSim::Undo()
{}

void SwitchToSim::Redo()
{}
