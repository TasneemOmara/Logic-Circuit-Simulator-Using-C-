#include "Paste.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "Select.h"

#include "../Components/AND2.h"
#include "../Components/BUFF.h"
#include "../Components/INV2.h"
#include "../Components/LED.h"
#include "../Components/NAND2.h"
#include "../Components/NOR2.h"
#include "../Components/OR2.h"
#include "../Components/Switch.h"
#include "../Components/XNOR2.h"
#include "../Components/XOR2.h"
#include "../Components/Connection.h"


Paste::Paste(ApplicationManager* pApp): Action(pApp) {

}


void Paste::Execute() {
	Comp = pManager->GetCopiedComp();
	UI* pUI = pManager->GetUI();

	if (Comp == NULL)
	{
		pUI->PrintMsg("There is no copied/cut component, please copy one first");
	}
	else
	{
		pUI->PrintMsg("select where you want to paste");
		int Cx, Cy;
		pUI->GetPointClicked(Cx, Cy);
		Point SelectedP;
		SelectedP.x = Cx;
		SelectedP.y = Cy;

		int gateWidth = pUI->getGateWidth();
		int gateHeight = pUI->getGateHeight();

		GraphicsInfo* pGInfo = new GraphicsInfo(2); //Gfx info to be used to construct the AND2 gate

		pGInfo->PointsList[0].x = Cx - gateWidth / 2;
		pGInfo->PointsList[0].y = Cy - gateHeight / 2;
		pGInfo->PointsList[1].x = Cx + gateWidth / 2;
		pGInfo->PointsList[1].y = Cy + gateHeight / 2;

		Component* pC = NULL;

		string compType = Comp->GetAddActionType();

		if (compType == "AND2")
		{
			pC = new AND2(pGInfo, AND2_FANOUT);
		}
		else if (compType == "BUFF")
		{
			pC = new BUFF(pGInfo, BUFF_FANOUT);
		}
		else if (compType == "INV2")
		{
			pC = new INV2(pGInfo, INV2_FANOUT);

		}
		else if (compType == "LED")
		{
			pC = new LED(pGInfo);
		}
		else if (compType == "NAND2")
		{
			pC = new NAND2(pGInfo, NAND2_FANOUT);
		}
		else if (compType == "NOR2")
		{
			pC = new NOR2(pGInfo, NOR2_FANOUT);
		}
		else if (compType == "OR2")
		{
			pC = new OR2(pGInfo, OR2_FANOUT);
		}
		else if (compType == "Switch")
		{
			pC = new Switch(pGInfo, Switch_FANOUT);
		}
		else if (compType == "XNOR2")
		{
			pC = new XNOR2(pGInfo, XNOR2_FANOUT);
		}
		else if (compType == "XOR2")
		{
			pC = new XOR2(pGInfo, XOR2_FANOUT);
		}

		pManager->AddComponent(pC);
	}
	
	
}

void Paste::Undo() {
	
}
void Paste::Redo() {
	
}

Paste::~Paste() {
}