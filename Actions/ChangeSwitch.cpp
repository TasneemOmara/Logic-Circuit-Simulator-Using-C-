#include "../ApplicationManager.h"
#include "../UI/UI.h"
#include "ChangeSwitch.h"

ChangeSwitch::ChangeSwitch(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeSwitch::Execute() 
{
	bool is_switch;
	int CompCount = pManager->getCompCount();
	Component** CompList = pManager->GetComponentList();
	Switch_State s;

	UI* pUI = pManager->GetUI();
	for (int i = 0; i < CompCount; i++)
	{
		is_switch = CompList[i]->get_switch();
		if (is_switch)
		{
			s = 
			if ()
			{

			}
		}
	}
}

void ChangeSwitch::Undo() 
{
}

void ChangeSwitch::Redo()
{
}