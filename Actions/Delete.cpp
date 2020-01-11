#include "Delete.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "Select.h"
#include "../Components/Connection.h"


Delete::Delete(ApplicationManager* pAppMan) : Action(pAppMan) {

}

void Delete::Execute() {

	UI* pUI = pManager->GetUI();
	Component** CompList = pManager->GetComponentList();
	int CompCount = pManager->getCompCount();
	pUI->PrintMsg("enter the component number you want to delete");
	choice = pUI->GetSrting();
	comp_num_todelete = stoi(choice);
	for (int i = 0; i < comp_num_todelete; i++) {
		pUI->PrintMsg("Select the component you want to Delete");

		pUI->GetPointClicked(Cx, Cy);
		Point SelectedP;
		SelectedP.x = Cx;
		SelectedP.y = Cy;
		pUI->setlast_point_clicked(SelectedP);

		Select* pAct = new Select(pManager);
		pAct->Execute();
		int selected_index = pAct->getIndex();
		bool valid = false;
		if (selected_index == -1)
		{
			pUI->PrintMsg("You didn't choose a component, please try again");
		}
		else
		{
			Component* ToDelete = CompList[selected_index];

			if (!CompList[selected_index]->is_Connection())
			{

				int ID = CompList[selected_index]->getID();
				GraphicsInfo* graphics = ToDelete->getGraphics();
				pUI->ClearDrawingGate(*graphics);
				for (size_t i = 0; i < CompCount; i++)
				{
					if (CompList[i]->is_Connection())
					{
						Component* src = CompList[i]->getSrcCmpnt();
						InputPin* in = CompList[i]->getInput();

						if (src->getID() == ID)
						{
							GraphicsInfo* r_GfxInfo = CompList[i]->getGraphics();
							pUI->DeleteConnection(*r_GfxInfo);

							delete CompList[i];
							pManager->decConnectCount(1);
							pManager->decCompCount();
							CompCount--;
							continue;
						}
						else if (in->getComponent()->getID() == ID)
						{
							GraphicsInfo* r_GfxInfo = CompList[i]->getGraphics();
							pUI->DeleteConnection(*r_GfxInfo);

							delete CompList[i];
							CompCount--;
							pManager->decConnectCount(1);
							pManager->decCompCount();
						}
					}
				}
				delete ToDelete;
				CompCount--;
				Component** TempCompList = new Component * [CompCount];
				CompList[selected_index] = nullptr;

				int j = 0;
				for (size_t i = 0; i < CompCount; i++)
				{
					if (CompList[i] != nullptr)
					{
						TempCompList[j++] = CompList[i];
					}
				}

				for (size_t i = 0; i < CompCount; i++)
				{
					CompList[i] = TempCompList[i];
				}

				pManager->decCompCount();
				pManager->decGatesCount();
				delete[] TempCompList;
			}
			else
			{
				GraphicsInfo* r_GfxInfo = CompList[selected_index]->getGraphics();
				pUI->DeleteConnection(*r_GfxInfo);

				delete ToDelete;
				CompCount--;

				Component** TempCompList = new Component * [CompCount];
				CompList[selected_index] = nullptr;

				int j = 0;
				for (size_t i = 0; i < CompCount; i++)
				{
					if (CompList[i] != nullptr)
					{
						TempCompList[j++] = CompList[i];
					}
				}

				for (size_t i = 0; i < CompCount; i++)
				{
					CompList[i] = TempCompList[i];
				}

				pManager->decCompCount();
				pManager->decConnectCount(1);
				delete[] TempCompList;
			}

		}
	}
}
void Delete::Undo() {
}

void Delete::Redo() {
}

Delete::~Delete()
{

}
