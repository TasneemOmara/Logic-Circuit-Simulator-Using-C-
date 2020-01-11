#include "Cut.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "Select.h"
#include"Delete.h"


Cut::Cut(ApplicationManager* pAppMan) : Action(pAppMan) {
	DeleteAct = new Delete(pManager);
}


void Cut::Execute() {
	UI* pUI = pManager->GetUI();

	pUI->PrintMsg("select the component you want to cut");
	pUI->GetPointClicked(Cx, Cy);
	Point SelectedP;
	SelectedP.x = Cx;
	SelectedP.y = Cy;
	pUI->setlast_point_clicked(SelectedP);
	Select* pAct = new Select(pManager);
	pAct->Execute();

	int selected_index1 = pAct->getIndex();
	Component** CompList = pManager->GetComponentList();
	Component* Comp = CompList[selected_index1];

	pManager->SetCopiedComp(Comp);
	/*while (Comp != NULL) {


	}*/


}
void Cut::Undo() {
}
void Cut::Redo() {
}

Cut::~Cut()
{
}
