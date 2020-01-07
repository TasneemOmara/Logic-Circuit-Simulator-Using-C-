#include "ADD_BUFF.h"
#include "..\ApplicationManager.h"


ADD_BUFF::ADD_BUFF(ApplicationManager* pApp) :Action(pApp)
{
}

ADD_BUFF::~ADD_BUFF(void) {

}

void ADD_BUFF::Execute() {
	//Get a Pointer to the user Interfaces
	UI* pUI = pManager->GetUI();

	//Print Action Message
	pUI->PrintMsg("Input BUFFER Gate: Click to add the gate");

	//Get Center point of the Gate
	pUI->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pUI->ClearStatusBar();
	//Calculate the rectangle Corners
	int gateWidth = pUI->getGateWidth();
	int gateHeight = pUI->getGateHeight();

	GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the OR gate

	pGInfo->PointsList[0].x = Cx - gateWidth / 2;
	pGInfo->PointsList[0].y = Cy - gateHeight / 2;
	pGInfo->PointsList[1].x = Cx + gateWidth / 2;
	pGInfo->PointsList[1].y = Cy + gateHeight / 2;
	BUFF* pA = new BUFF(pGInfo, BUFF_FANOUT);
	pManager->AddComponent(pA);
}

void ADD_BUFF::Undo()
{}

void ADD_BUFF::Redo()
{}