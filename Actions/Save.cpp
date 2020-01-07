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

	int CompCount = pManager->getCompCount();
	Component** CompList = pManager->GetComponentList();

	if (fileToSave.is_open())
	{
		fileToSave << CompCount << endl;
		for (size_t i = 0; i < CompCount; i++)
		{
			CompList[i]->SaveComponent(i, fileToSave);
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