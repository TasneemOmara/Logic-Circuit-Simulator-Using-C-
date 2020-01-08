#include "AddINV2.h"
#include "..\ApplicationManager.h"

AddINV2::AddINV2(ApplicationManager* pApp) :Action(pApp)
{
}

AddINV2::~AddINV2(void)
{
}

void AddINV2::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input INV2 Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the INV2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	INV2* pA = new INV2(pGInfo, INV2_FANOUT);
	pManager->AddComponent(pA);
}

void AddINV2::Undo()
{}

void AddINV2::Redo()
{}

