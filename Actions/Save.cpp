#include "Save.h"
#include "..\ApplicationManager.h"


Save::Save(ApplicationManager* pApp) : Action(pApp) {
}

Save::~Save(void) {

}

void Save::Execute()
{
	fstream fileToSave("SavedCircuit.txt", ios::out);
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("Saving new file, it's name is SavedCircuit.txt");
	int CompCount = pManager->getCompCount();
	int GatesCount = pManager->getGatesCount();
	int ConnectCount = pManager->getConnectCount();

	Component** CompList = pManager->GetComponentList();

	if (fileToSave.is_open())
	{
		fileToSave << GatesCount << endl;
		for (size_t i = 0; i < CompCount; i++)
		{
			if (!(CompList[i]->is_Connection()))
			{
				CompList[i]->SaveComponent(fileToSave);
			}
			
		}

		fileToSave << "Connections" << endl;
		fileToSave << ConnectCount << endl;
		
		for (size_t i = 0; i < CompCount; i++)
		{
			if ((CompList[i]->is_Connection()))
			{
				CompList[i]->SaveComponent(fileToSave);
			}

		}
	}
	else
	{
		pUI->PrintMsg("Unable to open the file");
	}

	fileToSave.close();
}


void Save::Undo() {};
void Save::Redo() {};