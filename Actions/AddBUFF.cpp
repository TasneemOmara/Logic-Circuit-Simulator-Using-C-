#include "AddBUFF.h"
#include "..\ApplicationManager.h"

AddBUFF::AddBUFF(ApplicationManager* pApp) :Action(pApp)
{
}

AddBUFF::~AddBUFF(void)
{
}

void AddBUFF::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input BUFF Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the BUFF gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	BUFF* pA = new BUFF(pGInfo, BUFF_FANOUT);
	pManager->AddComponent(pA);
}

void AddBUFF::Undo()
{}

void AddBUFF::Redo()
{}

