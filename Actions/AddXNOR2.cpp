#include "AddXNOR2.h"
#include "..\ApplicationManager.h"

AddXNOR2::AddXNOR2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXNOR2::~AddXNOR2(void)
{
}

void AddXNOR2::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input XNOR2 Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the XNOR2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	XNOR2* pA = new XNOR2(pGInfo, XNOR2_FANOUT);
	pManager->AddComponent(pA);
}

void AddXNOR2::Undo()
{}

void AddXNOR2::Redo()
{}

