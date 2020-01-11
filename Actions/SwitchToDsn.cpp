#include"SwitchToDsn.h"
#include "../ApplicationManager.h"

using namespace std;

SwitchToDsn::SwitchToDsn(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchToDsn::Execute()
{
	/*
	Implementation Steps
	1. LOAD the saved circuit
	2. AppMode ----> Design  ---> create design toolbar
	*/
	int CompCount = pManager->getCompCount();
	Component** CompList = pManager->GetComponentList();
	UI* pUI = pManager->GetUI();

	pUI->ClearSimulationToolBar();
	pUI->ClearStatusBar();
	pUI->ClearDrawingArea();
	pUI->CreateDesignToolBar();
	pManager->ExecuteAction(LOAD);

	
}

void SwitchToDsn::Undo()
{}

void SwitchToDsn::Redo()
{}