#include"ExitProgram.h"
#include "..\ApplicationManager.h"
#include "Save.h"

ExitProgram::ExitProgram(ApplicationManager* pApp) :Action(pApp) {
}

ExitProgram::~ExitProgram(void) {
}



void ExitProgram::Execute() {
    int count = pManager->getCompCount();
    Component** CompList = pManager->GetComponentList();

    UI* pUI = pManager->GetUI();
    pUI->PrintMsg(" Do you want to save? y/n");
    
    bool valid = false;

    Save* pS = new Save(pManager);

    while (valid == false)
    {
        string save = pUI->GetSrting();
        if (save == "y" || save == "Y")
        {
            pS->Execute();
            valid = true;
        }
        else if (save != "N" || save != "n")
        {
            pUI->PrintMsg("Invalid input, Do you want to save? y/n ");
        }
    }
    delete pS;



    //Clear Status Bar
    pUI->ClearStatusBar();


}


void ExitProgram::Undo()
{

}
void ExitProgram::Redo()
{

}