#include "../Actions/SwitchToSim.h"
#include "../ApplicationManager.h"

using namespace std;

SwitchToSim::SwitchToSim(ApplicationManager* pApp) :Action(pApp)
{
	flag_c = 0;
}

void SwitchToSim::Execute()
{
	/*
	Implementation Steps
	1. Check Validity of the circuit
	2. AppMode ----> Simulation  ---> create simulation toolbar
	*/
	int CompCount = pManager->getCompCount();
	Component** CompList = pManager->GetComponentList();
	UI* pUI = pManager->GetUI();

	for (size_t i = 0; i < CompCount; i++)
	{
		if (!CompList[i]->is_Connection())
		{
			int pin_num = CompList[i]->get_last_pin_input_connected();
			if (pin_num != CompList[i]->get_max_Inputs())
			{
				pUI->PrintMsg("One or more of the pins is not connected, please, recheck the pins and try again");
				flag_c = 1; // raise a flag that there are unconnected pins
				break;
			}
		}

	}


	if (flag_c == 0)
	{
		//pManager->ExecuteAction(SAVE);
		pUI->ClearSimulationToolBar();
		pUI->ClearStatusBar();
		//pUI->ClearDrawingArea();
		pUI->CreateSimulationToolBar();
		//pManager->ExecuteAction(LOAD);

	}
}

void SwitchToSim::Undo()
{}

void SwitchToSim::Redo()
{}
