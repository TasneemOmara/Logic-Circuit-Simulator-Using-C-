#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\Select.h"
#include "Actions\Save.h"
#include "Actions\Load.h"
#include "Actions\AddBUFF.h"
#include "Actions\AddINV2.h"
#include "Actions\AddLED.h"
#include "Actions\AddNAND2.h"
#include "Actions\AddNOR2.h"
#include "Actions\AddOR2.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddXNOR2.h"
#include "Actions\AddXOR2.h"
#include "Actions\AddConnection.h"
/*


#include "Actions\ADD_Label.h"







*/
ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;


	//Creates the UI Object & Initialize the UI
	pUI = new UI;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component * pComp)
{
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return pUI->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	pUI->ClearStatusBar();
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;
	case ADD_Buff:
		pAct = new AddBUFF(this);
		break;
	case ADD_INV:
		pAct = new AddINV2(this);
		break;
	case ADD_LED:
		pAct = new AddLED(this);
		break;
	case ADD_NAND_GATE_2:
		pAct = new AddNAND2(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new AddNOR2(this);
		break;
	case ADD_OR_GATE_2:
		pAct = new AddOR2(this);
		break;
	case ADD_Switch:
		pAct = new AddSwitch(this);
		break;
	case ADD_XNOR_GATE_2:
		pAct = new AddXNOR2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXOR2(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;
	case ADD_CONNECTION:
		pAct = new AddConnection(this);
		break;

		/*


			*/
		case SAVE:
			pAct = new Save(this);
			break;
		case LOAD:
			pAct = new Load(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->Draw(pUI);
}

////////////////////////////////////////////////////////////////////
UI* ApplicationManager::GetUI()
{
	return pUI;
}

////////////////////////////////////////////////////////////////////
void ApplicationManager::GetCompList(int& Count, Component * *Complist) {
	Complist = CompList;
	Count = CompCount;
}

////////////////////////////////////////////////////////////////////

int ApplicationManager::getCompCount() const
{
	return CompCount;
}

////////////////////////////////////////////////////////////////////
Component** ApplicationManager::GetComponentList()
{
	return CompList;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete pUI;

}
