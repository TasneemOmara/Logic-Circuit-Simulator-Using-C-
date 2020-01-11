#include"Copy.h"
#include "..\ApplicationManager.h"
#include "..\UI\UI.h"
#include "Select.h"

Copy::Copy(ApplicationManager* pAppMan) : Action(pAppMan) {
}
void Copy::Execute() {
	UI* pUI = pManager->GetUI();
	pUI->PrintMsg("select the component you want to copy");
	int Cx, Cy;
	pUI->GetPointClicked(Cx, Cy);
	Point SelectedP;
	SelectedP.x = Cx;
	SelectedP.y = Cy;
	pUI->setlast_point_clicked(SelectedP);
	Select* pAct = new Select(pManager);
	pAct->Execute();
	 int selected_index1 = pAct->getIndex();
	 pManager->SetCopiedComp(Comp);
	}
  void Copy::Redo() {

}
  void Copy::Undo() {

  }
  Copy::~Copy() {
  }