#include"AddLabel.h"
#include "..\ApplicationManager.h"
#include "Select.h"




AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp) {
}
AddLabel::~AddLabel(void) {
}



void AddLabel::Execute() {
    int count = pManager->getCompCount();
    Component** CompList = pManager->GetComponentList();
    //bool selected;

    UI* pUI = pManager->GetUI();
    pUI->PrintMsg(" Click to select the gate where you want add your label");
    int Cx, Cy;
    pUI->GetPointClicked(Cx, Cy);
    Point SelectedP;
    SelectedP.x = Cx;
    SelectedP.y = Cy;
    pUI->setlast_point_clicked(SelectedP);

    Select* pselect = new Select(pManager);
    pselect->Execute();
    int x = pselect->getIndex();

    //Clear Status Bar
    pUI->ClearStatusBar();

    //Request the required label from the user 
    pUI->PrintMsg("Please Enter the label you want here");
    string Label = pUI->GetSrting();


    if (x != -1)
    {
        CompList[x]->setLabel(Label);

    }

}


void AddLabel::Undo()
{

}
void AddLabel::Redo()
{

}