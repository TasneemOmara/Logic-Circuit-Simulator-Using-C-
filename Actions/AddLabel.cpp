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

    if (x != -1)
    {
        GraphicsInfo* pGraphics = CompList[x]->getGraphics();
        int Cx1, Cy1, Cx2, Cy2;
        Cx1 = pGraphics->PointsList[0].x;
        Cy1 = pGraphics->PointsList[0].y;
        Cx2 = pGraphics->PointsList[1].x;
        Cy2 = pGraphics->PointsList[1].y;

        int width = pUI->getGateWidth();
        int height = pUI->getGateHeight();

        int label_x = Cx1 + (width);
        int label_y = Cy1 + (height);

        //Clear Status Bar
        pUI->ClearStatusBar();

        //Request the required label from the user 
        pUI->PrintMsg("Please Enter the label you want here");

        //Get the string the user inputs u=in the status bar
        string Label = pUI->GetSrting();

        //Print the string into the desired location
        pUI->PrintMsg2(Label, label_x, label_y);

    }

}


void AddLabel::Undo()
{

}
void AddLabel::Redo()
{

}