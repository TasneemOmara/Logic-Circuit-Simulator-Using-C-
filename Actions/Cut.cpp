#include "Cut.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "Select.h"
#include"Delete.h"
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


Cut::Cut(ApplicationManager* pAppMan) : Action(pAppMan) {
	DeleteAct = new Delete(pManager);
}


void Cut::Execute() {
	UI* pUI = pManager->GetUI();

	Component** CompList = pManager->GetComponentList();

	

	Delete* dAct = new Delete(pManager, 1);
	dAct->Execute();
	GraphicsInfo Graphics(2);
	string compType = dAct->getDeleteInfo();
	GraphicsInfo* pGInfo = new GraphicsInfo(2);

	Component* pC = NULL;
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
	pManager->SetCopiedComp(pC);

}
void Cut::Undo() {
}
void Cut::Redo() {
}

Cut::~Cut()
{
}
