#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\Select.h"
#include "Actions\Save.h"

/*#include "Actions\ADD_connection.h"
#include "Actions\ADD_BUFF.h"
#include "Actions\ADD_INV2.h"
#include "Actions\ADD_Label.h"
#include "Actions\ADD_LED2.h"
#include "Actions\ADD_switch.h"
#include "Actions\AddNANDgate.h"
#include "Actions\AddNORgate.h"
#include "Actions\AddORgate.h"
#include "Actions\AddXNORgate.h"
#include "Actions\AddXORgate.h"
<<<<<<< HEAD
#include "Actions\Save.h"
=======
#include "Actions\Select.h"
>>>>>>> 9f6e56281879f4d1c304283cc60adb3213e21b49
#include "Actions\Load.h"
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
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		break;


		/*case ADD_CONNECTION:
			pAct = new ADD_connection(this);
			break;


		case ADD_Buff:
			pAct = new ADD_BUFF(this);
			break;
		case ADD_INV:
			pAct = new ADD_INV2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate(this);
			break;
		case ADD_Switch:
			pAct = new ADD_switch(this);
			break;
		case ADD_LED:
			pAct = new ADD_LED2(this);
			break;
			*/
		case SAVE:
			pAct = new Save(this);
			break;
			/*
		case LOAD:
			pAct = new Load(this);
			break;*/
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
