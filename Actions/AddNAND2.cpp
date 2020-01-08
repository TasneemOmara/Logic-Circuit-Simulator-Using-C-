#include "AddNAND2.h"
#include "..\ApplicationManager.h"

AddNAND2::AddNAND2(ApplicationManager* pApp) :Action(pApp)
{
}

AddNAND2::~AddNAND2(void)
{
}

void AddNAND2::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input NAND2 Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the NAND2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	NAND2* pA = new NAND2(pGInfo, NAND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddNAND2::Undo()
{}

void AddNAND2::Redo()
{}

