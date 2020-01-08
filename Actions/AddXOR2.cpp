#include "AddXOR2.h"
#include "..\ApplicationManager.h"

AddXOR2::AddXOR2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXOR2::~AddXOR2(void)
{
}

void AddXOR2::Execute()
{

	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("2-Input XOR2 Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the XOR2 gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	XOR2* pA = new XOR2(pGInfo, XOR2_FANOUT);
	pManager->AddComponent(pA);
}

void AddXOR2::Undo()
{}

void AddXOR2::Redo()
{}

