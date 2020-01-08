#include"EditLabel.h"
#include "..\ApplicationManager.h"
#include "Select.h"




EditLabel::EditLabel(ApplicationManager* pApp) :Action(pApp) {
}
EditLabel::~EditLabel(void) {
}



void EditLabel::Execute() {
    int count = pManager->getCompCount();
    Component** CompList = pManager->GetComponentList();

    UI* pUI = pManager->GetUI();
    pUI->PrintMsg(" Click to select the gate that you want to edit its label");
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




    if (x != -1)
    {
        //Request the required label from the user 
        pUI->PrintMsg(CompList[x]->getLabel());
        string Label = pUI->GetSrting();
        CompList[x]->setLabel(Label);

    }

}


void EditLabel::Undo()
{

}
void EditLabel::Redo()
{

}